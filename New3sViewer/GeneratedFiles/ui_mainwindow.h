/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGraphicsView *graphicsView;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QStringLiteral("mainwindowClass"));
        mainwindowClass->resize(650, 507);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(mainwindowClass->sizePolicy().hasHeightForWidth());
        mainwindowClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(mainwindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 23));
        mainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainwindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainwindowClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(mainwindowClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidget->setMinimumSize(QSize(279, 346));
        dockWidget->setMaximumSize(QSize(350, 524287));
        dockWidget->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(treeView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(0, 23));
        pushButton->setMaximumSize(QSize(16777215, 23));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(dockWidgetContents);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);
        graphicsView->setMinimumSize(QSize(198, 198));
        graphicsView->setSizeIncrement(QSize(1, 1));
        graphicsView->setLayoutDirection(Qt::LeftToRight);
        graphicsView->setAutoFillBackground(true);
        graphicsView->setFrameShape(QFrame::WinPanel);

        verticalLayout->addWidget(graphicsView);

        dockWidget->setWidget(dockWidgetContents);
        mainwindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_3 = new QDockWidget(mainwindowClass);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidget_3->setAcceptDrops(true);
        dockWidget_3->setAutoFillBackground(true);
        dockWidget_3->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
        dockWidget_3->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listWidget = new QListWidget(dockWidgetContents_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(0, 60));
        listWidget->setMaximumSize(QSize(16777215, 60));
        listWidget->setFlow(QListView::TopToBottom);

        horizontalLayout_3->addWidget(listWidget);

        dockWidget_3->setWidget(dockWidgetContents_3);
        mainwindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_3);

        retranslateUi(mainwindowClass);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QApplication::translate("mainwindowClass", "New3sViewer", 0));
        pushButton->setText(QApplication::translate("mainwindowClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("mainwindowClass", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("mainwindowClass", "PushButton", 0));
        dockWidget_3->setWindowTitle(QApplication::translate("mainwindowClass", "\350\276\223\345\207\272\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
