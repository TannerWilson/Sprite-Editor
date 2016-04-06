/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionQuit;
    QWidget *centralWidget;
    QWidget *toolsContainer;
    QVBoxLayout *verticalLayout;
    QPushButton *brushButton;
    QPushButton *eraserButton;
    QPushButton *bucketButton;
    QScrollArea *frameContainer;
    QWidget *frameContents;
    QPushButton *deleteFrameButton;
    QPushButton *addFrameButton;
    QPushButton *secondaryColorButton;
    QPushButton *primaryColorButton;
    QFrame *graphicsframe;
    QPushButton *StartPreview;
    QPushButton *StopPreview;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1199, 963);
        MainWindow->setMouseTracking(true);
        MainWindow->setAnimated(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolsContainer = new QWidget(centralWidget);
        toolsContainer->setObjectName(QStringLiteral("toolsContainer"));
        toolsContainer->setGeometry(QRect(10, 10, 104, 252));
        verticalLayout = new QVBoxLayout(toolsContainer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        brushButton = new QPushButton(toolsContainer);
        brushButton->setObjectName(QStringLiteral("brushButton"));
        brushButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imgs/Resources_External/brush_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon);
        brushButton->setIconSize(QSize(64, 64));
        brushButton->setAutoDefault(false);
        brushButton->setFlat(false);

        verticalLayout->addWidget(brushButton);

        eraserButton = new QPushButton(toolsContainer);
        eraserButton->setObjectName(QStringLiteral("eraserButton"));
        eraserButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgs/Resources_External/eraser_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon1);
        eraserButton->setIconSize(QSize(64, 64));
        eraserButton->setAutoDefault(false);
        eraserButton->setFlat(false);

        verticalLayout->addWidget(eraserButton);

        bucketButton = new QPushButton(toolsContainer);
        bucketButton->setObjectName(QStringLiteral("bucketButton"));
        bucketButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imgs/Resources_External/fill_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        bucketButton->setIcon(icon2);
        bucketButton->setIconSize(QSize(64, 64));
        bucketButton->setAutoDefault(false);
        bucketButton->setFlat(false);

        verticalLayout->addWidget(bucketButton);

        frameContainer = new QScrollArea(centralWidget);
        frameContainer->setObjectName(QStringLiteral("frameContainer"));
        frameContainer->setGeometry(QRect(5, 381, 111, 275));
        frameContainer->setMaximumSize(QSize(16777215, 16777215));
        frameContainer->setLayoutDirection(Qt::LeftToRight);
        frameContainer->setWidgetResizable(true);
        frameContents = new QWidget();
        frameContents->setObjectName(QStringLiteral("frameContents"));
        frameContents->setGeometry(QRect(0, 0, 109, 273));
        frameContainer->setWidget(frameContents);
        deleteFrameButton = new QPushButton(centralWidget);
        deleteFrameButton->setObjectName(QStringLiteral("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(10, 740, 104, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imgs/Resources_External/trash_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFrameButton->setIcon(icon3);
        deleteFrameButton->setIconSize(QSize(24, 24));
        addFrameButton = new QPushButton(centralWidget);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setGeometry(QRect(10, 680, 104, 48));
        addFrameButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imgs/Resources_External/add_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFrameButton->setIcon(icon4);
        addFrameButton->setIconSize(QSize(24, 24));
        addFrameButton->setFlat(false);
        secondaryColorButton = new QPushButton(centralWidget);
        secondaryColorButton->setObjectName(QStringLiteral("secondaryColorButton"));
        secondaryColorButton->setGeometry(QRect(40, 300, 61, 51));
        primaryColorButton = new QPushButton(centralWidget);
        primaryColorButton->setObjectName(QStringLiteral("primaryColorButton"));
        primaryColorButton->setGeometry(QRect(20, 270, 61, 51));
        primaryColorButton->setAutoFillBackground(false);
        graphicsframe = new QFrame(centralWidget);
        graphicsframe->setObjectName(QStringLiteral("graphicsframe"));
        graphicsframe->setGeometry(QRect(120, 20, 851, 871));
        graphicsframe->setFrameShape(QFrame::StyledPanel);
        graphicsframe->setFrameShadow(QFrame::Raised);
        StartPreview = new QPushButton(centralWidget);
        StartPreview->setObjectName(QStringLiteral("StartPreview"));
        StartPreview->setGeometry(QRect(10, 820, 90, 26));
        StopPreview = new QPushButton(centralWidget);
        StopPreview->setObjectName(QStringLiteral("StopPreview"));
        StopPreview->setGeometry(QRect(10, 850, 90, 26));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 880, 48, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 800, 61, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 880, 31, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1199, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        brushButton->setDefault(false);
        eraserButton->setDefault(false);
        bucketButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0));
        actionImport->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        actionExport->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        brushButton->setText(QString());
        eraserButton->setText(QString());
        bucketButton->setText(QString());
        deleteFrameButton->setText(QString());
        addFrameButton->setText(QApplication::translate("MainWindow", "Add a\n"
"frame", 0));
        secondaryColorButton->setText(QString());
        primaryColorButton->setText(QString());
        StartPreview->setText(QApplication::translate("MainWindow", "Start", 0));
        StopPreview->setText(QApplication::translate("MainWindow", "Stop", 0));
        label->setText(QApplication::translate("MainWindow", "Preview", 0));
        label_2->setText(QApplication::translate("MainWindow", "FPS", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
