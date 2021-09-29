/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table_widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *import_button;
    QPushButton *save_button;
    QPushButton *new_table;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *max_mistakes;
    QPushButton *min_mistakes;
    QPushButton *edit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *add_key;
    QPushButton *delete_key;
    QPushButton *delete_all;
    QMenuBar *menubar;
    QMenu *menuHashTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(521, 551);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        table_widget = new QTableWidget(centralwidget);
        table_widget->setObjectName(QString::fromUtf8("table_widget"));

        verticalLayout_4->addWidget(table_widget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        import_button = new QPushButton(centralwidget);
        import_button->setObjectName(QString::fromUtf8("import_button"));

        horizontalLayout_2->addWidget(import_button);

        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        horizontalLayout_2->addWidget(save_button);


        verticalLayout_3->addLayout(horizontalLayout_2);

        new_table = new QPushButton(centralwidget);
        new_table->setObjectName(QString::fromUtf8("new_table"));

        verticalLayout_3->addWidget(new_table);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        max_mistakes = new QPushButton(centralwidget);
        max_mistakes->setObjectName(QString::fromUtf8("max_mistakes"));

        horizontalLayout_3->addWidget(max_mistakes);

        min_mistakes = new QPushButton(centralwidget);
        min_mistakes->setObjectName(QString::fromUtf8("min_mistakes"));

        horizontalLayout_3->addWidget(min_mistakes);


        verticalLayout_3->addLayout(horizontalLayout_3);

        edit = new QPushButton(centralwidget);
        edit->setObjectName(QString::fromUtf8("edit"));

        verticalLayout_3->addWidget(edit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        add_key = new QPushButton(centralwidget);
        add_key->setObjectName(QString::fromUtf8("add_key"));

        horizontalLayout_4->addWidget(add_key);

        delete_key = new QPushButton(centralwidget);
        delete_key->setObjectName(QString::fromUtf8("delete_key"));

        horizontalLayout_4->addWidget(delete_key);


        verticalLayout_3->addLayout(horizontalLayout_4);

        delete_all = new QPushButton(centralwidget);
        delete_all->setObjectName(QString::fromUtf8("delete_all"));

        verticalLayout_3->addWidget(delete_all);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 521, 26));
        menuHashTable = new QMenu(menubar);
        menuHashTable->setObjectName(QString::fromUtf8("menuHashTable"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHashTable->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        import_button->setText(QCoreApplication::translate("MainWindow", "Import table", nullptr));
        save_button->setText(QCoreApplication::translate("MainWindow", "Save table", nullptr));
        new_table->setText(QCoreApplication::translate("MainWindow", "NewTable", nullptr));
        max_mistakes->setText(QCoreApplication::translate("MainWindow", "MAX mistakes", nullptr));
        min_mistakes->setText(QCoreApplication::translate("MainWindow", "MIN mistakes", nullptr));
        edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        add_key->setText(QCoreApplication::translate("MainWindow", "add key", nullptr));
        delete_key->setText(QCoreApplication::translate("MainWindow", "delete key", nullptr));
        delete_all->setText(QCoreApplication::translate("MainWindow", "delete all", nullptr));
        menuHashTable->setTitle(QCoreApplication::translate("MainWindow", "HashTable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
