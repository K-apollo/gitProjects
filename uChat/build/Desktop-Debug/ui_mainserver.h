/********************************************************************************
** Form generated from reading UI file 'mainserver.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSERVER_H
#define UI_MAINSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainServer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButtonTcpIp;
    QRadioButton *radioButtonUdp;
    QLineEdit *lineEdit01IpNum;
    QLineEdit *lineEdit02PortNum;
    QPushButton *pushButton;
    QPushButton *pushButtonIpList;

    void setupUi(QMainWindow *MainServer)
    {
        if (MainServer->objectName().isEmpty())
            MainServer->setObjectName(QString::fromUtf8("MainServer"));
        MainServer->resize(600, 40);
        MainServer->setMinimumSize(QSize(600, 40));
        centralwidget = new QWidget(MainServer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        radioButtonTcpIp = new QRadioButton(centralwidget);
        radioButtonTcpIp->setObjectName(QString::fromUtf8("radioButtonTcpIp"));

        gridLayout->addWidget(radioButtonTcpIp, 0, 0, 1, 1);

        radioButtonUdp = new QRadioButton(centralwidget);
        radioButtonUdp->setObjectName(QString::fromUtf8("radioButtonUdp"));

        gridLayout->addWidget(radioButtonUdp, 0, 1, 1, 1);

        lineEdit01IpNum = new QLineEdit(centralwidget);
        lineEdit01IpNum->setObjectName(QString::fromUtf8("lineEdit01IpNum"));

        gridLayout->addWidget(lineEdit01IpNum, 0, 2, 1, 1);

        lineEdit02PortNum = new QLineEdit(centralwidget);
        lineEdit02PortNum->setObjectName(QString::fromUtf8("lineEdit02PortNum"));

        gridLayout->addWidget(lineEdit02PortNum, 0, 3, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 4, 1, 1);

        pushButtonIpList = new QPushButton(centralwidget);
        pushButtonIpList->setObjectName(QString::fromUtf8("pushButtonIpList"));

        gridLayout->addWidget(pushButtonIpList, 0, 5, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 10);
        gridLayout->setColumnStretch(3, 10);
        gridLayout->setColumnStretch(4, 4);
        gridLayout->setColumnStretch(5, 4);
        gridLayout->setColumnMinimumWidth(0, 2);
        gridLayout->setColumnMinimumWidth(1, 2);
        gridLayout->setColumnMinimumWidth(2, 10);
        gridLayout->setColumnMinimumWidth(3, 10);
        gridLayout->setColumnMinimumWidth(4, 4);
        gridLayout->setColumnMinimumWidth(5, 4);
        MainServer->setCentralWidget(centralwidget);

        retranslateUi(MainServer);

        QMetaObject::connectSlotsByName(MainServer);
    } // setupUi

    void retranslateUi(QMainWindow *MainServer)
    {
        MainServer->setWindowTitle(QCoreApplication::translate("MainServer", "MainWindow", nullptr));
        radioButtonTcpIp->setText(QCoreApplication::translate("MainServer", "TCP/IP", nullptr));
        radioButtonUdp->setText(QCoreApplication::translate("MainServer", "UDP", nullptr));
        pushButton->setText(QCoreApplication::translate("MainServer", "Connect", nullptr));
        pushButtonIpList->setText(QCoreApplication::translate("MainServer", "IP List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainServer: public Ui_MainServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSERVER_H
