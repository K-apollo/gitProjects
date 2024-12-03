/********************************************************************************
** Form generated from reading UI file 'mainclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLIENT_H
#define UI_MAINCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainClient
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButtonTcpIp;
    QRadioButton *radioButtonUdp;
    QLineEdit *lineEdit01IpNum;
    QLineEdit *lineEdit02PortNum;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainClient)
    {
        if (MainClient->objectName().isEmpty())
            MainClient->setObjectName(QString::fromUtf8("MainClient"));
        MainClient->resize(600, 40);
        MainClient->setMinimumSize(QSize(600, 40));
        centralwidget = new QWidget(MainClient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 40));
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

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 3);
        gridLayout->setColumnStretch(2, 10);
        gridLayout->setColumnStretch(3, 10);
        gridLayout->setColumnStretch(4, 4);
        gridLayout->setColumnMinimumWidth(0, 3);
        gridLayout->setColumnMinimumWidth(1, 3);
        gridLayout->setColumnMinimumWidth(2, 10);
        gridLayout->setColumnMinimumWidth(3, 10);
        gridLayout->setColumnMinimumWidth(4, 4);
        MainClient->setCentralWidget(centralwidget);

        retranslateUi(MainClient);

        QMetaObject::connectSlotsByName(MainClient);
    } // setupUi

    void retranslateUi(QMainWindow *MainClient)
    {
        MainClient->setWindowTitle(QCoreApplication::translate("MainClient", "MainWindow", nullptr));
        radioButtonTcpIp->setText(QCoreApplication::translate("MainClient", "TCP/IP", nullptr));
        radioButtonUdp->setText(QCoreApplication::translate("MainClient", "UDP", nullptr));
        pushButton->setText(QCoreApplication::translate("MainClient", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainClient: public Ui_MainClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLIENT_H
