/********************************************************************************
** Form generated from reading UI file 'collectipport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLECTIPPORT_H
#define UI_COLLECTIPPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollectIpPort
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *hLA;
    QLineEdit *leClientIpList;
    QLineEdit *leClientPortList;
    QHBoxLayout *hLB;
    QPushButton *pAdd;
    QPushButton *pRemove;

    void setupUi(QWidget *CollectIpPort)
    {
        if (CollectIpPort->objectName().isEmpty())
            CollectIpPort->setObjectName(QString::fromUtf8("CollectIpPort"));
        CollectIpPort->resize(400, 480);
        CollectIpPort->setMinimumSize(QSize(400, 480));
        gridLayout = new QGridLayout(CollectIpPort);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        tableWidget = new QTableWidget(CollectIpPort);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        hLA = new QHBoxLayout();
        hLA->setSpacing(5);
        hLA->setObjectName(QString::fromUtf8("hLA"));
        hLA->setContentsMargins(5, 5, 5, 5);
        leClientIpList = new QLineEdit(CollectIpPort);
        leClientIpList->setObjectName(QString::fromUtf8("leClientIpList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leClientIpList->sizePolicy().hasHeightForWidth());
        leClientIpList->setSizePolicy(sizePolicy);
        leClientIpList->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hLA->addWidget(leClientIpList);

        leClientPortList = new QLineEdit(CollectIpPort);
        leClientPortList->setObjectName(QString::fromUtf8("leClientPortList"));
        sizePolicy.setHeightForWidth(leClientPortList->sizePolicy().hasHeightForWidth());
        leClientPortList->setSizePolicy(sizePolicy);
        leClientPortList->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hLA->addWidget(leClientPortList);

        hLA->setStretch(0, 7);
        hLA->setStretch(1, 3);

        gridLayout->addLayout(hLA, 1, 0, 1, 1);

        hLB = new QHBoxLayout();
        hLB->setSpacing(5);
        hLB->setObjectName(QString::fromUtf8("hLB"));
        hLB->setContentsMargins(5, 5, 5, 5);
        pAdd = new QPushButton(CollectIpPort);
        pAdd->setObjectName(QString::fromUtf8("pAdd"));

        hLB->addWidget(pAdd);

        pRemove = new QPushButton(CollectIpPort);
        pRemove->setObjectName(QString::fromUtf8("pRemove"));

        hLB->addWidget(pRemove);

        hLB->setStretch(0, 10);
        hLB->setStretch(1, 10);

        gridLayout->addLayout(hLB, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowMinimumHeight(0, 10);

        retranslateUi(CollectIpPort);

        QMetaObject::connectSlotsByName(CollectIpPort);
    } // setupUi

    void retranslateUi(QWidget *CollectIpPort)
    {
        CollectIpPort->setWindowTitle(QCoreApplication::translate("CollectIpPort", "Form", nullptr));
        pAdd->setText(QCoreApplication::translate("CollectIpPort", "Add", nullptr));
        pRemove->setText(QCoreApplication::translate("CollectIpPort", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollectIpPort: public Ui_CollectIpPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLECTIPPORT_H
