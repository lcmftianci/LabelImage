/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenImage;
    QAction *actionSaveXml;
    QAction *actionLoadXml;
    QAction *actionResetConfig;
    QAction *actionReTry;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOpenPic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(984, 696);
        MainWindow->setMouseTracking(true);
        actionOpenImage = new QAction(MainWindow);
        actionOpenImage->setObjectName(QStringLiteral("actionOpenImage"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icon/openfile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenImage->setIcon(icon);
        actionSaveXml = new QAction(MainWindow);
        actionSaveXml->setObjectName(QStringLiteral("actionSaveXml"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icon/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveXml->setIcon(icon1);
        actionLoadXml = new QAction(MainWindow);
        actionLoadXml->setObjectName(QStringLiteral("actionLoadXml"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/icon/open.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadXml->setIcon(icon2);
        actionResetConfig = new QAction(MainWindow);
        actionResetConfig->setObjectName(QStringLiteral("actionResetConfig"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/icon/reset.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetConfig->setIcon(icon3);
        actionReTry = new QAction(MainWindow);
        actionReTry->setObjectName(QStringLiteral("actionReTry"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/icon/retry.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionReTry->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMouseTracking(true);
        label->setLineWidth(40);
        label->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(0, 7);

        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 984, 26));
        menuOpenPic = new QMenu(menuBar);
        menuOpenPic->setObjectName(QStringLiteral("menuOpenPic"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionOpenImage);
        mainToolBar->addAction(actionSaveXml);
        mainToolBar->addAction(actionLoadXml);
        mainToolBar->addAction(actionResetConfig);
        mainToolBar->addAction(actionReTry);
        mainToolBar->addSeparator();
        menuBar->addAction(menuOpenPic->menuAction());
        menuOpenPic->addAction(actionOpenImage);
        menuOpenPic->addAction(actionSaveXml);
        menuOpenPic->addAction(actionLoadXml);
        menuOpenPic->addAction(actionResetConfig);
        menuOpenPic->addAction(actionReTry);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpenImage->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        actionSaveXml->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230XML", Q_NULLPTR));
        actionLoadXml->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275XML", Q_NULLPTR));
        actionResetConfig->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\351\205\215\347\275\256", Q_NULLPTR));
        actionReTry->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\274\224\347\244\272\345\214\272\345\237\237", Q_NULLPTR));
        menuOpenPic->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
