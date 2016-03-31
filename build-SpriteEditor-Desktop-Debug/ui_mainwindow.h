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
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
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
    QWidget *previewContainer;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *previewView;
    QSlider *fpsSlider;
    QPushButton *secondaryColorButton;
    QPushButton *primaryColorButton;
    QFrame *graphicsframe;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1199, 933);
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
        frameContainer->setGeometry(QRect(10, 381, 104, 291));
        frameContainer->setWidgetResizable(true);
        frameContents = new QWidget();
        frameContents->setObjectName(QString::fromUtf8("frameContents"));
        frameContents->setGeometry(QRect(0, 0, 102, 289));
        frameContainer->setWidget(frameContents);
        deleteFrameButton = new QPushButton(centralWidget);
        deleteFrameButton->setObjectName(QString::fromUtf8("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(10, 895, 104, 40));
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
        previewContainer = new QWidget(centralWidget);
        previewContainer->setObjectName(QString::fromUtf8("previewContainer"));
        previewContainer->setGeometry(QRect(980, 10, 210, 245));
        verticalLayout_2 = new QVBoxLayout(previewContainer);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        previewView = new QGraphicsView(previewContainer);
        previewView->setObjectName(QString::fromUtf8("previewView"));

        verticalLayout_2->addWidget(previewView);

        fpsSlider = new QSlider(previewContainer);
        fpsSlider->setObjectName(QString::fromUtf8("fpsSlider"));
        fpsSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(fpsSlider);

        secondaryColorButton = new QPushButton(centralWidget);
        secondaryColorButton->setObjectName(QString::fromUtf8("secondaryColorButton"));
        secondaryColorButton->setGeometry(QRect(40, 300, 61, 51));
        primaryColorButton = new QPushButton(centralWidget);
        primaryColorButton->setObjectName(QString::fromUtf8("primaryColorButton"));
        primaryColorButton->setGeometry(QRect(20, 270, 61, 51));
        primaryColorButton->setAutoFillBackground(false);
        graphicsframe = new QFrame(centralWidget);
        graphicsframe->setObjectName(QString::fromUtf8("graphicsframe"));
        graphicsframe->setGeometry(QRect(120, 20, 851, 871));
        graphicsframe->setFrameShape(QFrame::StyledPanel);
        graphicsframe->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1199, 25));
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
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
