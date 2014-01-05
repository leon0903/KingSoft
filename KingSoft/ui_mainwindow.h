/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jan 5 18:37:21 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(758, 177);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 2, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit_2);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reject Duplicates", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "File&1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "File&2", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "&Choose", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "C&hoose", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "\350\257\267\345\205\210\351\200\211\346\213\251\346\226\207\344\273\266\357\274\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "&Process", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
