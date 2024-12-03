#include "collectipport.h"
#include "ui_collectipport.h"

CollectIpPort::CollectIpPort(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::CollectIpPort),
    allChecked(new bool(false)),
    displayTimer(new QTimer(this))
{
    ui->setupUi(this);
    initializeUI();
    setupTable();
    connectSignals();
    displayTimer->setInterval(10000);
    connect(displayTimer, &QTimer::timeout, this, &CollectIpPort::showIpPortInMainWindow);
    displayTimer->start();
}

CollectIpPort::~CollectIpPort()
{
    delete ui;
    delete allChecked;
    delete displayTimer;
}

void CollectIpPort::initializeUI()
{
    tableWidget = ui->tableWidget;
    leClientIpList = ui->leClientIpList;
    leClientPortList = ui->leClientPortList;
    pAdd = ui->pAdd;
    pRemove = ui->pRemove;
}

void CollectIpPort::connectSignals(bool withLineEdit, bool withTable)
{
    connect(pAdd, &QPushButton::clicked, this, &CollectIpPort::addEntry);
    connect(pRemove, &QPushButton::clicked, this, &CollectIpPort::removeSelectedEntries);

    if (withLineEdit) {
        connect(leClientIpList, &QLineEdit::textChanged, this, &CollectIpPort::on_leClientIpList_textChanged);
        connect(leClientPortList, &QLineEdit::textChanged, this, &CollectIpPort::on_leClientPortList_textChanged);
    }

    if (withTable) {
        connect(tableWidget, &QTableWidget::cellClicked, this, &CollectIpPort::handleCellClick);
        connect(tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &CollectIpPort::toggleAllCheckBoxes);
    }
}

void CollectIpPort::showIpPortInMainWindow()
{
    for (int row = 0; row < tableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *statusItem = tableWidget->item(row, 4);
        if (statusItem && statusItem->text() == "Connected")
        {
            displayIp = tableWidget->item(row, 1)->text();
            displayPort = tableWidget->item(row, 2)->text();
            emit ipPortSelected(displayIp, displayPort);
            break;
        }
    }
}

void CollectIpPort::clearInputs()
{
    leClientIpList->clear();
    leClientPortList->clear();
}

void CollectIpPort::removeSelectedEntries()
{
    for (int row = tableWidget->rowCount() - 1; row >= 0; --row)
    {
        QCheckBox *itemCheckBox = qobject_cast<QCheckBox *>(tableWidget->cellWidget(row, 0));
        if (itemCheckBox && itemCheckBox->isChecked())
            tableWidget->removeRow(row);
    }
}

void CollectIpPort::toggleAllCheckBoxes()
{
    *allChecked = !*allChecked;
    updateTable();
}

void CollectIpPort::handleCellClick(int row, int column)
{
    if (column == 0)
    {
        QCheckBox *itemCheckBox = qobject_cast<QCheckBox *>(tableWidget->cellWidget(row, column));
        if (itemCheckBox)
        {
            itemCheckBox->setChecked(!itemCheckBox->isChecked());
            toggleConnectionStatus(row);
        }
    }
}

void CollectIpPort::updateTable()
{
    for (int row = 0; row < tableWidget->rowCount(); ++row)
    {
        QCheckBox *itemCheckBox = qobject_cast<QCheckBox *>(tableWidget->cellWidget(row, 0));
        if (itemCheckBox)
            itemCheckBox->setChecked(*allChecked);
    }
}

void CollectIpPort::setIp(const QString &ip)
{
    leClientIpList->setText(ip);
}

void CollectIpPort::setPort(const QString &port)
{
    leClientPortList->setText(port);
}

void CollectIpPort::toggleConnectionStatus(int row)
{
    QTableWidgetItem *statusItem = tableWidget->item(row, 4);
    if (statusItem)
    {
        if (statusItem->text() == "Disconnected")
        {
            statusItem->setText("Connecting...");
            statusItem->setBackground(Qt::yellow);
            statusItem->setForeground(Qt::black);
        }
        else if (statusItem->text() == "Connecting...")
        {
            statusItem->setText("Connected");
            statusItem->setBackground(Qt::green);
            statusItem->setForeground(Qt::white);
        }
        else
        {
            statusItem->setText("Disconnected");
            statusItem->setBackground(Qt::red);
            statusItem->setForeground(Qt::white);
        }
    }
}

void CollectIpPort::initializeTableWidget()
{
    QTableWidgetItem *headerItem = new QTableWidgetItem("All");
    headerItem->setTextAlignment(Qt::AlignCenter);

    selectAllCheckBox = new QCheckBox(this);
    connect(selectAllCheckBox, &QCheckBox::stateChanged, this, &CollectIpPort::onSelectAllToggled);

    tableWidget->setHorizontalHeaderItem(0, headerItem);
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void CollectIpPort::onSelectAllToggled(int state)
{
    bool isChecked = (state == Qt::Checked);
    for (int row = 0; row < tableWidget->rowCount(); ++row)
    {
        QCheckBox *itemCheckBox = qobject_cast<QCheckBox *>(tableWidget->cellWidget(row, 0));
        if (itemCheckBox)
        {
            itemCheckBox->setChecked(isChecked);
            toggleConnectionStatus(row);
        }
    }
}

void CollectIpPort::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}

void CollectIpPort::setupTable()
{
    tableWidget->setColumnCount(5);
    QStringList headers = {"All", "IP", "Port", "Date & Time", "Status"};
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->setSelectionBehavior(QTableWidget::SelectRows);
    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);

    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Interactive);
    tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Interactive);
    tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

void CollectIpPort::addEntry()
{
    QString ip = leClientIpList->text();
    QString port = leClientPortList->text();

    if (!ip.isEmpty() && !port.isEmpty())
    {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        QTableWidgetItem *statusItem = new QTableWidgetItem("Disconnected");
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setBackground(Qt::red);
        statusItem->setForeground(Qt::white);

        QCheckBox *checkBox = new QCheckBox(this);
        tableWidget->setCellWidget(row, 0, checkBox);

        QTableWidgetItem *ipItem = new QTableWidgetItem(ip);
        QTableWidgetItem *portItem = new QTableWidgetItem(port);
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd (ddd) AP hh : mm : ss");
        QTableWidgetItem *dateTimeItem = new QTableWidgetItem(formattedDateTime);

        ipItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        portItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        dateTimeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        tableWidget->setItem(row, 1, ipItem);
        tableWidget->setItem(row, 2, portItem);
        tableWidget->setItem(row, 3, dateTimeItem);
        tableWidget->setItem(row, 4, statusItem);

        clearInputs();
    }
}

void CollectIpPort::updateStatusDisplay(int row, const QString &status)
{
    QTableWidgetItem *statusItem = tableWidget->item(row, 4);
    if (status == "Connecting...")
    {
        statusItem->setText("Connecting...");
        statusItem->setBackground(Qt::yellow);
        statusItem->setForeground(Qt::black);
    }
    else if (status == "Connected")
    {
        statusItem->setText("Connected");
        statusItem->setBackground(Qt::green);
        statusItem->setForeground(Qt::white);
    }
    else
    {
        statusItem->setText("Disconnected");
        statusItem->setBackground(Qt::red);
        statusItem->setForeground(Qt::white);
    }
}

void CollectIpPort::on_leClientIpList_textChanged(const QString &text)
{
    QString formattedText = text;
    formattedText.remove(QRegExp("[^0-9.]"));

    QStringList segments = formattedText.split('.');
    QStringList newSegments;

    for (QString &segment : segments)
    {
        int segmentValue = segment.toInt();
        segment = (segmentValue > 255) ? "255" : (segmentValue < 0 ? "" : segment.left(3));
        newSegments.append(segment);
    }

    formattedText = newSegments.join('.');

    QStringList finalSegments = formattedText.split('.');
    if (finalSegments.size() > 4)
        formattedText = finalSegments.mid(0, 4).join('.');

    leClientIpList->blockSignals(true);
    leClientIpList->setText(formattedText);
    leClientIpList->blockSignals(false);
}

void CollectIpPort::on_leClientIpList_textChanged_Numeric(const QString &text)
{
    QString formattedText = text;
    formattedText.remove(QRegExp("[^0-9]"));

    QStringList segments;
    for (int i = 0; i < formattedText.length(); i += 3)
    {
        QString segment = formattedText.mid(i, 3);
        int segmentValue = segment.toInt();
        segments.append((segmentValue > 255) ? "255" : (segmentValue < 0 ? "" : segment));
    }

    formattedText = segments.join('.');

    if (segments.size() > 4)
        formattedText = segments.mid(0, 4).join('.');

    leClientIpList->blockSignals(true);
    leClientIpList->setText(formattedText);
    leClientIpList->blockSignals(false);
}

void CollectIpPort::on_leClientPortList_textChanged(const QString &text)
{
    QString formattedText = text;
    formattedText.remove(QRegExp("[^0-9]"));
    if (formattedText.length() > 5) formattedText.truncate(5);

    int portNumber = formattedText.toInt();
    if (portNumber < 1 || portNumber > 65535) formattedText.clear();

    leClientPortList->blockSignals(true);
    leClientPortList->setText(formattedText);
    leClientPortList->blockSignals(false);
}
