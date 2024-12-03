#include "client.h"
#include <QDebug>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    portNumber(10000),
    ipAddress("127.0.0.1")
{
    initializeClient();
}

void Client::initializeClient()
{
    radioButtonClientTcpIp = new QRadioButton("TCP/IP 클라이언트", this);
    radioButtonClientTcpIp->setChecked(true);
    radioButtonClientUdp = new QRadioButton("UDP 클라이언트", this);

    connect(radioButtonClientTcpIp, &QRadioButton::toggled, [=](bool checked) {
        if (checked) {
            qDebug() << "TCP/IP 클라이언트 모드 활성화";
        }
    });

    connect(radioButtonClientUdp, &QRadioButton::toggled, [=](bool checked) {
        if (checked)
        {
            qDebug() << "UDP 클라이언트 모드 활성화";
        }
    });

    testIpPort();
}

void Client::testIpPort()
{
    static int ipIncrement = 1;
    ipAddress = QString("127.0.0.%1").arg(ipIncrement);
    ipIncrement++;
    portNumber += 1;

    qDebug() << "IP 주소:" << ipAddress;
    qDebug() << "포트 번호:" << portNumber;
}
