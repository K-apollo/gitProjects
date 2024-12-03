/********************************************************************************
** Form generated from reading UI file 'mainClient.ui'
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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit02PortNum;
    QLineEdit *lineEdit01IpNum;
    QRadioButton *radioButtonTcpIp;
    QPushButton *pushButton;
    QRadioButton *radioButtonUdp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(746, 46);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit02PortNum = new QLineEdit(centralwidget);
        lineEdit02PortNum->setObjectName(QString::fromUtf8("lineEdit02PortNum"));

        gridLayout->addWidget(lineEdit02PortNum, 0, 3, 1, 1);

        lineEdit01IpNum = new QLineEdit(centralwidget);
        lineEdit01IpNum->setObjectName(QString::fromUtf8("lineEdit01IpNum"));

        gridLayout->addWidget(lineEdit01IpNum, 0, 2, 1, 1);

        radioButtonTcpIp = new QRadioButton(centralwidget);
        radioButtonTcpIp->setObjectName(QString::fromUtf8("radioButtonTcpIp"));

        gridLayout->addWidget(radioButtonTcpIp, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 4, 1, 1);

        radioButtonUdp = new QRadioButton(centralwidget);
        radioButtonUdp->setObjectName(QString::fromUtf8("radioButtonUdp"));

        gridLayout->addWidget(radioButtonUdp, 0, 1, 1, 1);

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
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButtonTcpIp->setText(QCoreApplication::translate("MainWindow", "TCP/IP", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        radioButtonUdp->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLIENT_H
