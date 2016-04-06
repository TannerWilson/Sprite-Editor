/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *stopPreview;
    QLabel *label_2;
    QPushButton *startPreview;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1199, 963);
        MainWindow->setMouseTracking(true);
        MainWindow->setAnimated(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolsContainer = new QWidget(centralWidget);
        toolsContainer->setObjectName(QString::fromUtf8("toolsContainer"));
        toolsContainer->setGeometry(QRect(10, 10, 104, 252));
        verticalLayout = new QVBoxLayout(toolsContainer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        brushButton = new QPushButton(toolsContainer);
        brushButton->setObjectName(QString::fromUtf8("brushButton"));
        brushButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/Resources_External/brush_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon);
        brushButton->setIconSize(QSize(64, 64));
        brushButton->setAutoDefault(false);
        brushButton->setDefault(false);
        brushButton->setFlat(false);

        verticalLayout->addWidget(brushButton);

        eraserButton = new QPushButton(toolsContainer);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));
        eraserButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/Resources_External/eraser_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon1);
        eraserButton->setIconSize(QSize(64, 64));
        eraserButton->setAutoDefault(false);
        eraserButton->setDefault(false);
        eraserButton->setFlat(false);

        verticalLayout->addWidget(eraserButton);

        bucketButton = new QPushButton(toolsContainer);
        bucketButton->setObjectName(QString::fromUtf8("bucketButton"));
        bucketButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/Resources_External/fill_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        bucketButton->setIcon(icon2);
        bucketButton->setIconSize(QSize(64, 64));
        bucketButton->setAutoDefault(false);
        bucketButton->setDefault(false);
        bucketButton->setFlat(false);

        verticalLayout->addWidget(bucketButton);

        frameContainer = new QScrollArea(centralWidget);
        frameContainer->setObjectName(QString::fromUtf8("frameContainer"));
        frameContainer->setGeometry(QRect(5, 381, 111, 275));
        frameContainer->setMaximumSize(QSize(16777215, 16777215));
        frameContainer->setLayoutDirection(Qt::LeftToRight);
        frameContainer->setWidgetResizable(true);
        frameContents = new QWidget();
        frameContents->setObjectName(QString::fromUtf8("frameContents"));
        frameContents->setGeometry(QRect(0, 0, 109, 273));
        frameContainer->setWidget(frameContents);
        deleteFrameButton = new QPushButton(centralWidget);
        deleteFrameButton->setObjectName(QString::fromUtf8("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(10, 740, 104, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/Resources_External/trash_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFrameButton->setIcon(icon3);
        deleteFrameButton->setIconSize(QSize(24, 24));
        addFrameButton = new QPushButton(centralWidget);
        addFrameButton->setObjectName(QString::fromUtf8("addFrameButton"));
        addFrameButton->setGeometry(QRect(10, 680, 104, 48));
        addFrameButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/Resources_External/add_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFrameButton->setIcon(icon4);
        addFrameButton->setIconSize(QSize(24, 24));
        addFrameButton->setFlat(false);
        secondaryColorButton = new QPushButton(centralWidget);
        secondaryColorButton->setObjectName(QString::fromUtf8("secondaryColorButton"));
        secondaryColorButton->setGeometry(QRect(40, 300, 61, 51));
        primaryColorButton = new QPushButton(centralWidget);
        primaryColorButton->setObjectName(QString::fromUtf8("primaryColorButton"));
        primaryColorButton->setGeometry(QRect(20, 270, 61, 51));
        primaryColorButton->setAutoFillBackground(false);
        graphicsframe = new QFrame(centralWidget);
        graphicsframe->setObjectName(QString::fromUtf8("graphicsframe"));
        graphicsframe->setGeometry(QRect(150, 40, 851, 871));
        graphicsframe->setFrameShape(QFrame::StyledPanel);
        graphicsframe->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(1060, 120, 48, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1040, 40, 61, 15));
        stopPreview = new QPushButton(centralWidget);
        stopPreview->setObjectName(QString::fromUtf8("stopPreview"));
        stopPreview->setGeometry(QRect(1020, 90, 90, 26));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1020, 120, 31, 16));
        startPreview = new QPushButton(centralWidget);
        startPreview->setObjectName(QString::fromUtf8("startPreview"));
        startPreview->setGeometry(QRect(1020, 60, 90, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1199, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0, QApplication::UnicodeUTF8));
        actionImport->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        actionExport->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        brushButton->setText(QString());
        eraserButton->setText(QString());
        bucketButton->setText(QString());
        deleteFrameButton->setText(QString());
        addFrameButton->setText(QApplication::translate("MainWindow", "Add a\n"
"frame", 0, QApplication::UnicodeUTF8));
        secondaryColorButton->setText(QString());
        primaryColorButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Preview", 0, QApplication::UnicodeUTF8));
        stopPreview->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "FPS", 0, QApplication::UnicodeUTF8));
        startPreview->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
