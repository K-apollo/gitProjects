#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ipListWidget(nullptr),
    displayTimer(new QTimer(this)),
    server(new Server(this)),
    client(new Client(this)),
    conversationModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    initializeUi();
    setIpPortValidation();
    connectSignals();
    updateServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeUi()
{
    radioButtonServerTcpIp = ui->pageServer->findChild<QRadioButton*>("radioButtonServerTcpIp");
    radioButtonServerUdp = ui->pageServer->findChild<QRadioButton*>("radioButtonServerUdp");
    lineEditServerIpNum = ui->pageServer->findChild<QLineEdit*>("lineEditServerIpNum");
    lineEditServerPortNum = ui->pageServer->findChild<QLineEdit*>("lineEditServerPortNum");
    pushButtonServer = ui->pageServer->findChild<QPushButton*>("pushButtonServer");
    pushButtonIpList = ui->pageServer->findChild<QPushButton*>("pushButtonIpList");

    radioButtonClientTcpIp = ui->pageClient->findChild<QRadioButton*>("radioButtonClientTcpIp");
    radioButtonClientUdp = ui->pageClient->findChild<QRadioButton*>("radioButtonClientUdp");
    lineEditClientIpNum = ui->pageClient->findChild<QLineEdit*>("lineEditClientIpNum");
    lineEditClientPortNum = ui->pageClient->findChild<QLineEdit*>("lineEditClientPortNum");
    pushButtonClient = ui->pageClient->findChild<QPushButton*>("pushButtonClient");

    radioButtonServerTcpIp->setChecked(true);
    radioButtonClientTcpIp->setChecked(true);

    ui->stackedWidget->setCurrentWidget(ui->pageServer);
    ui->checkBoxServerClient->setChecked(false);

    displayTimer->start(500);
    ui->listViewConversation->setModel(conversationModel);
}

void MainWindow::connectSignals()
{
    connect(ui->checkBoxServerClient, &QCheckBox::stateChanged, this, &MainWindow::onCheckBoxStateChanged);
    connect(ui->pushButtonConfirm, &QPushButton::clicked, this, &MainWindow::onConfirmButtonClicked);
    connect(radioButtonServerTcpIp, &QRadioButton::toggled, [=](bool checked){ onConnectionTypeChanged(true, checked); });
    connect(pushButtonServer, &QPushButton::clicked, [=]{ handleConnection(true); });
    connect(radioButtonClientTcpIp, &QRadioButton::toggled, [=](bool checked){ onConnectionTypeChanged(false, checked); });
    connect(pushButtonClient, &QPushButton::clicked, [=]{ handleConnection(false); });
    connect(pushButtonIpList, &QPushButton::clicked, this, &MainWindow::onPushButtonIpListClicked);
    connect(displayTimer, &QTimer::timeout, this, &MainWindow::updateIpDisplay);
    connect(server, &Server::statusMessage, this, &MainWindow::updateStatusMessage);
}

void MainWindow::setIpPortValidation()
{
    QRegularExpression ipRegex("^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|0?[1-9][0-9]?|0{2}[1-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|0?[1-9][0-9]?|0{2}[1-9])$");
    QRegularExpressionValidator *ipValidator = new QRegularExpressionValidator(ipRegex, this);

    ui->lineEditServerIpNum->setValidator(ipValidator);
    ui->lineEditClientIpNum->setValidator(ipValidator);

    QRegularExpression portRegex("^([1-9][0-9]{0,4})$");
    QRegularExpressionValidator *portValidator = new QRegularExpressionValidator(portRegex, this);

    ui->lineEditServerPortNum->setValidator(portValidator);
    ui->lineEditClientPortNum->setValidator(portValidator);
}

void MainWindow::updateServer()
{
    conversationModel->clear();
}

void MainWindow::onPushButtonIpListClicked()
{
    if (!ipListWidget)
    {
        ipListWidget = new CollectIpPort();
        ipListWidget->setWindowTitle("IP List");

        connect(ipListWidget->findChild<QTableWidget *>("tableWidget"), &QTableWidget::cellClicked,
                [this](int row, int column) {
                    if (column == 0) {
                        ipToDisplay = ipListWidget->findChild<QTableWidget*>("tableWidget")->item(row, column)->text();
                    } else if (column == 1) {
                        portToDisplay = ipListWidget->findChild<QTableWidget*>("tableWidget")->item(row, column)->text();
                    }
                });
        ipListWidget->setAttribute(Qt::WA_DeleteOnClose, true);
        ipListWidget->resize(360, 480);
    }

    QRect mainWindowGeometry = this->geometry();
    QPoint mainWindowPos = this->pos();
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();

    int xPosition = mainWindowPos.x() + mainWindowGeometry.width() + 10;
    int yPosition = mainWindowPos.y();

    if (xPosition + ipListWidget->width() > screenGeometry.width()) {
        xPosition = mainWindowPos.x() - ipListWidget->width() - 10;
    }
    if (yPosition + ipListWidget->height() > screenGeometry.height()) {
        yPosition = screenGeometry.height() - ipListWidget->height() - 10;
    }

    ipListWidget->move(xPosition, yPosition);
    ipListWidget->show();
}

void MainWindow::updateIpDisplay()
{
    ui->lineEditServerIpNum->setText(ipToDisplay);
    ui->lineEditServerPortNum->setText(portToDisplay);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (ipListWidget)
    {
        ipListWidget->close();
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::onCheckBoxStateChanged(int state)
{
    ui->stackedWidget->setCurrentWidget(state == Qt::Unchecked ? ui->pageServer : ui->pageClient);
}

void MainWindow::onConnectionTypeChanged(bool isServer, bool isTcp)
{
    qDebug() << (isServer ? (isTcp ? "서버 TCP/IP" : "서버 UDP") : (isTcp ? "클라이언트 TCP/IP" : "클라이언트 UDP"));
}

void MainWindow::onConfirmButtonClicked()
{
    QString message = ui->lineEditInput->text();
    if (!message.isEmpty())
    {
        updateStatusMessage(message);
        ui->lineEditInput->clear();
    }
}

void MainWindow::updateStatusMessage(const QString &message)
{
    QStandardItem *item = new QStandardItem(message);
    conversationModel->appendRow(item);
}

void MainWindow::handleConnection(bool isServer)
{
    if (isServer)
    {
        QList<QPair<QString, int>> clientList;

        if (ipListWidget)
        {
            QTableWidget *table = ipListWidget->findChild<QTableWidget*>("tableWidget");
            if (table)
            {
                for (int i = 0; i < table->rowCount(); ++i)
                {
                    QCheckBox *checkBox = qobject_cast<QCheckBox*>(table->cellWidget(i, 0));
                    if (checkBox && checkBox->isChecked())
                    {
                        QString ip = table->item(i, 1)->text();
                        int port = table->item(i, 2)->text().toInt();
                        clientList.append(qMakePair(ip, port));
                    }
                }
            }
        }

        QString connectionType = radioButtonServerTcpIp->isChecked() ? "TCP/IP" : "UDP";

        if (!clientList.isEmpty())
        {
            server->startServer(connectionType, clientList);
            qDebug() << "서버가 다음 클라이언트에 연결 시도 중:" << clientList;
        }
        else
        {
            qDebug() << "선택된 클라이언트가 없습니다.";
            emit server->statusMessage("선택된 클라이언트가 없습니다. 연결을 선택해 주세요.");
        }
    }
    else
    {
        QString ip = lineEditClientIpNum->text();
        int port = lineEditClientPortNum->text().toInt();
        qDebug() << "클라이언트가 연결 중:" << ip << "포트:" << port;
    }
}
