#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QListView>
#include <QDebug>
#include <QRegularExpressionValidator>
#include <QScreen>
#include <QGuiApplication>
#include <QTimer>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "collectipport.h"
#include "server.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onCheckBoxStateChanged(int state);
    void updateStatusMessage(const QString &message);
    void onConfirmButtonClicked();
    void onConnectionTypeChanged(bool isServer, bool isTcp);
    void handleConnection(bool isServer);
    void onPushButtonIpListClicked();
    void updateIpDisplay();

private:
    void initializeUi();
    void connectSignals();
    void setIpPortValidation();
    void updateServer();

    Ui::MainWindow *ui;
    QRadioButton *radioButtonServerTcpIp;
    QRadioButton *radioButtonServerUdp;
    QLineEdit *lineEditServerIpNum;
    QLineEdit *lineEditServerPortNum;
    QPushButton *pushButtonServer;
    QPushButton *pushButtonIpList;

    QRadioButton *radioButtonClientTcpIp;
    QRadioButton *radioButtonClientUdp;
    QLineEdit *lineEditClientIpNum;
    QLineEdit *lineEditClientPortNum;
    QPushButton *pushButtonClient;

    CollectIpPort *ipListWidget;
    QTimer *displayTimer;
    QString ipToDisplay;
    QString portToDisplay;
    Server *server;
    Client *client;
    QStandardItemModel *conversationModel;
};

#endif // MAINWINDOW_H
