/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxServerClient;
    QStackedWidget *stackedWidget;
    QWidget *pageServer;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButtonServerTcpIp;
    QRadioButton *radioButtonServerUdp;
    QLineEdit *lineEditServerIpNum;
    QLineEdit *lineEditServerPortNum;
    QPushButton *pushButtonServer;
    QPushButton *pushButtonIpList;
    QWidget *pageClient;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButtonClientTcpIp;
    QRadioButton *radioButtonClientUdp;
    QLineEdit *lineEditClientIpNum;
    QLineEdit *lineEditClientPortNum;
    QPushButton *pushButtonClient;
    QListView *listViewConversation;
    QHBoxLayout *hL02;
    QLineEdit *lineEditInput;
    QPushButton *pushButtonConfirm;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(420, 480);
        MainWindow->setMinimumSize(QSize(420, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxServerClient = new QCheckBox(centralwidget);
        checkBoxServerClient->setObjectName(QString::fromUtf8("checkBoxServerClient"));

        horizontalLayout->addWidget(checkBoxServerClient);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        pageServer = new QWidget();
        pageServer->setObjectName(QString::fromUtf8("pageServer"));
        gridLayout_2 = new QGridLayout(pageServer);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        radioButtonServerTcpIp = new QRadioButton(pageServer);
        radioButtonServerTcpIp->setObjectName(QString::fromUtf8("radioButtonServerTcpIp"));

        gridLayout_2->addWidget(radioButtonServerTcpIp, 0, 0, 1, 1);

        radioButtonServerUdp = new QRadioButton(pageServer);
        radioButtonServerUdp->setObjectName(QString::fromUtf8("radioButtonServerUdp"));

        gridLayout_2->addWidget(radioButtonServerUdp, 0, 1, 1, 1);

        lineEditServerIpNum = new QLineEdit(pageServer);
        lineEditServerIpNum->setObjectName(QString::fromUtf8("lineEditServerIpNum"));

        gridLayout_2->addWidget(lineEditServerIpNum, 0, 2, 1, 1);

        lineEditServerPortNum = new QLineEdit(pageServer);
        lineEditServerPortNum->setObjectName(QString::fromUtf8("lineEditServerPortNum"));

        gridLayout_2->addWidget(lineEditServerPortNum, 0, 3, 1, 1);

        pushButtonServer = new QPushButton(pageServer);
        pushButtonServer->setObjectName(QString::fromUtf8("pushButtonServer"));

        gridLayout_2->addWidget(pushButtonServer, 0, 4, 1, 1);

        pushButtonIpList = new QPushButton(pageServer);
        pushButtonIpList->setObjectName(QString::fromUtf8("pushButtonIpList"));

        gridLayout_2->addWidget(pushButtonIpList, 0, 5, 1, 1);

        gridLayout_2->setColumnStretch(2, 10);
        gridLayout_2->setColumnStretch(3, 10);
        gridLayout_2->setColumnMinimumWidth(2, 10);
        gridLayout_2->setColumnMinimumWidth(3, 10);
        stackedWidget->addWidget(pageServer);
        pageClient = new QWidget();
        pageClient->setObjectName(QString::fromUtf8("pageClient"));
        gridLayout_3 = new QGridLayout(pageClient);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        radioButtonClientTcpIp = new QRadioButton(pageClient);
        radioButtonClientTcpIp->setObjectName(QString::fromUtf8("radioButtonClientTcpIp"));

        gridLayout_3->addWidget(radioButtonClientTcpIp, 0, 0, 1, 1);

        radioButtonClientUdp = new QRadioButton(pageClient);
        radioButtonClientUdp->setObjectName(QString::fromUtf8("radioButtonClientUdp"));

        gridLayout_3->addWidget(radioButtonClientUdp, 0, 1, 1, 1);

        lineEditClientIpNum = new QLineEdit(pageClient);
        lineEditClientIpNum->setObjectName(QString::fromUtf8("lineEditClientIpNum"));

        gridLayout_3->addWidget(lineEditClientIpNum, 0, 2, 1, 1);

        lineEditClientPortNum = new QLineEdit(pageClient);
        lineEditClientPortNum->setObjectName(QString::fromUtf8("lineEditClientPortNum"));

        gridLayout_3->addWidget(lineEditClientPortNum, 0, 3, 1, 1);

        pushButtonClient = new QPushButton(pageClient);
        pushButtonClient->setObjectName(QString::fromUtf8("pushButtonClient"));

        gridLayout_3->addWidget(pushButtonClient, 0, 4, 1, 1);

        gridLayout_3->setColumnStretch(2, 10);
        gridLayout_3->setColumnStretch(3, 10);
        gridLayout_3->setColumnMinimumWidth(2, 10);
        gridLayout_3->setColumnMinimumWidth(3, 10);
        stackedWidget->addWidget(pageClient);

        horizontalLayout->addWidget(stackedWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listViewConversation = new QListView(centralwidget);
        listViewConversation->setObjectName(QString::fromUtf8("listViewConversation"));

        gridLayout->addWidget(listViewConversation, 1, 0, 1, 1);

        hL02 = new QHBoxLayout();
        hL02->setSpacing(5);
        hL02->setObjectName(QString::fromUtf8("hL02"));
        hL02->setContentsMargins(5, 5, 5, 5);
        lineEditInput = new QLineEdit(centralwidget);
        lineEditInput->setObjectName(QString::fromUtf8("lineEditInput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditInput->sizePolicy().hasHeightForWidth());
        lineEditInput->setSizePolicy(sizePolicy1);

        hL02->addWidget(lineEditInput);

        pushButtonConfirm = new QPushButton(centralwidget);
        pushButtonConfirm->setObjectName(QString::fromUtf8("pushButtonConfirm"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonConfirm->sizePolicy().hasHeightForWidth());
        pushButtonConfirm->setSizePolicy(sizePolicy2);

        hL02->addWidget(pushButtonConfirm);

        hL02->setStretch(0, 10);

        gridLayout->addLayout(hL02, 2, 0, 1, 1);

        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowMinimumHeight(1, 10);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBoxServerClient->setText(QString());
        radioButtonServerTcpIp->setText(QCoreApplication::translate("MainWindow", "TCP/IP", nullptr));
        radioButtonServerUdp->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        pushButtonServer->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonIpList->setText(QCoreApplication::translate("MainWindow", "IP List", nullptr));
        radioButtonClientTcpIp->setText(QCoreApplication::translate("MainWindow", "TCP/IP", nullptr));
        radioButtonClientUdp->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        pushButtonClient->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonConfirm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
