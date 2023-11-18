/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *translateField;
    QLineEdit *rotateField;
    QLineEdit *scaleField;
    QComboBox *translateAx;
    QComboBox *rotateAx;
    QPushButton *scaleButton;
    QPushButton *rotateButton;
    QPushButton *translateButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *fileInfoTop;
    QPushButton *fileDialogButton;
    QSpacerItem *horizontalSpacer;
    QLabel *fileNameLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *vLable;
    QLabel *vLabelCount;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *eLabel;
    QLabel *eLabelCount;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *openGLlayout;
    QPushButton *vertex_empty;
    QPushButton *vertex_circle;
    QPushButton *vertex_square;
    QLabel *label;
    QPushButton *edg_line;
    QPushButton *edg_dotted;
    QLabel *label_2;
    QComboBox *Color_B_V_E;
    QSlider *slider_green;
    QSlider *slider_blue;
    QSlider *slider_red;
    QSlider *slider_size_v_e;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *scaleAx;
    QPushButton *button_screenshot;
    QComboBox *format_screenshot;
    QComboBox *type_projection;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(948, 597);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        translateField = new QLineEdit(centralwidget);
        translateField->setObjectName("translateField");
        translateField->setGeometry(QRect(580, 80, 201, 38));
        rotateField = new QLineEdit(centralwidget);
        rotateField->setObjectName("rotateField");
        rotateField->setGeometry(QRect(580, 135, 201, 38));
        scaleField = new QLineEdit(centralwidget);
        scaleField->setObjectName("scaleField");
        scaleField->setGeometry(QRect(580, 195, 201, 38));
        translateAx = new QComboBox(centralwidget);
        translateAx->addItem(QString());
        translateAx->addItem(QString());
        translateAx->addItem(QString());
        translateAx->setObjectName("translateAx");
        translateAx->setGeometry(QRect(790, 80, 51, 38));
        rotateAx = new QComboBox(centralwidget);
        rotateAx->addItem(QString());
        rotateAx->addItem(QString());
        rotateAx->addItem(QString());
        rotateAx->setObjectName("rotateAx");
        rotateAx->setGeometry(QRect(790, 135, 51, 38));
        scaleButton = new QPushButton(centralwidget);
        scaleButton->setObjectName("scaleButton");
        scaleButton->setGeometry(QRect(850, 195, 81, 38));
        rotateButton = new QPushButton(centralwidget);
        rotateButton->setObjectName("rotateButton");
        rotateButton->setGeometry(QRect(850, 135, 81, 38));
        translateButton = new QPushButton(centralwidget);
        translateButton->setObjectName("translateButton");
        translateButton->setGeometry(QRect(850, 80, 81, 38));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 661, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        fileInfoTop = new QHBoxLayout();
        fileInfoTop->setObjectName("fileInfoTop");
        fileDialogButton = new QPushButton(layoutWidget);
        fileDialogButton->setObjectName("fileDialogButton");

        fileInfoTop->addWidget(fileDialogButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        fileInfoTop->addItem(horizontalSpacer);

        fileNameLabel = new QLabel(layoutWidget);
        fileNameLabel->setObjectName("fileNameLabel");

        fileInfoTop->addWidget(fileNameLabel);


        horizontalLayout_3->addLayout(fileInfoTop);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        vLable = new QLabel(layoutWidget);
        vLable->setObjectName("vLable");
        vLable->setMinimumSize(QSize(67, 0));

        horizontalLayout_2->addWidget(vLable);

        vLabelCount = new QLabel(layoutWidget);
        vLabelCount->setObjectName("vLabelCount");
        vLabelCount->setMinimumSize(QSize(67, 0));

        horizontalLayout_2->addWidget(vLabelCount);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        eLabel = new QLabel(layoutWidget);
        eLabel->setObjectName("eLabel");

        horizontalLayout->addWidget(eLabel);

        eLabelCount = new QLabel(layoutWidget);
        eLabelCount->setObjectName("eLabelCount");

        horizontalLayout->addWidget(eLabelCount);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 50, 551, 521));
        openGLlayout = new QVBoxLayout(verticalLayoutWidget);
        openGLlayout->setObjectName("openGLlayout");
        openGLlayout->setContentsMargins(0, 0, 0, 0);
        vertex_empty = new QPushButton(centralwidget);
        vertex_empty->setObjectName("vertex_empty");
        vertex_empty->setGeometry(QRect(599, 540, 85, 26));
        vertex_circle = new QPushButton(centralwidget);
        vertex_circle->setObjectName("vertex_circle");
        vertex_circle->setGeometry(QRect(700, 540, 85, 26));
        vertex_square = new QPushButton(centralwidget);
        vertex_square->setObjectName("vertex_square");
        vertex_square->setGeometry(QRect(800, 540, 85, 26));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(703, 510, 90, 21));
        QFont font;
        font.setItalic(true);
        label->setFont(font);
        edg_line = new QPushButton(centralwidget);
        edg_line->setObjectName("edg_line");
        edg_line->setGeometry(QRect(600, 470, 85, 26));
        edg_dotted = new QPushButton(centralwidget);
        edg_dotted->setObjectName("edg_dotted");
        edg_dotted->setGeometry(QRect(700, 470, 85, 26));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(661, 440, 95, 21));
        label_2->setFont(font);
        Color_B_V_E = new QComboBox(centralwidget);
        Color_B_V_E->addItem(QString());
        Color_B_V_E->addItem(QString());
        Color_B_V_E->addItem(QString());
        Color_B_V_E->setObjectName("Color_B_V_E");
        Color_B_V_E->setGeometry(QRect(800, 350, 110, 40));
        Color_B_V_E->setStyleSheet(QString::fromUtf8("#comboBox {\n"
"	border: 1px solid #ced4da;\n"
"	padding-left: 15px;\n"
"}"));
        slider_green = new QSlider(centralwidget);
        slider_green->setObjectName("slider_green");
        slider_green->setGeometry(QRect(600, 399, 180, 15));
        slider_green->setMaximum(255);
        slider_green->setOrientation(Qt::Horizontal);
        slider_blue = new QSlider(centralwidget);
        slider_blue->setObjectName("slider_blue");
        slider_blue->setGeometry(QRect(600, 420, 180, 15));
        slider_blue->setMaximum(255);
        slider_blue->setPageStep(1);
        slider_blue->setOrientation(Qt::Horizontal);
        slider_red = new QSlider(centralwidget);
        slider_red->setObjectName("slider_red");
        slider_red->setGeometry(QRect(600, 377, 180, 15));
        slider_red->setMaximum(255);
        slider_red->setSingleStep(1);
        slider_red->setPageStep(10);
        slider_red->setOrientation(Qt::Horizontal);
        slider_size_v_e = new QSlider(centralwidget);
        slider_size_v_e->setObjectName("slider_size_v_e");
        slider_size_v_e->setGeometry(QRect(600, 337, 180, 15));
        slider_size_v_e->setMinimum(1);
        slider_size_v_e->setMaximum(100);
        slider_size_v_e->setPageStep(1);
        slider_size_v_e->setTracking(true);
        slider_size_v_e->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(600, 312, 141, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(600, 354, 81, 21));
        label_4->setFont(font);
        scaleAx = new QComboBox(centralwidget);
        scaleAx->addItem(QString());
        scaleAx->addItem(QString());
        scaleAx->addItem(QString());
        scaleAx->setObjectName("scaleAx");
        scaleAx->setGeometry(QRect(790, 195, 51, 38));
        button_screenshot = new QPushButton(centralwidget);
        button_screenshot->setObjectName("button_screenshot");
        button_screenshot->setGeometry(QRect(839, 260, 90, 30));
        format_screenshot = new QComboBox(centralwidget);
        format_screenshot->addItem(QString());
        format_screenshot->addItem(QString());
        format_screenshot->setObjectName("format_screenshot");
        format_screenshot->setGeometry(QRect(760, 260, 70, 30));
        type_projection = new QComboBox(centralwidget);
        type_projection->addItem(QString());
        type_projection->addItem(QString());
        type_projection->setObjectName("type_projection");
        type_projection->setGeometry(QRect(790, 40, 140, 33));
        type_projection->setStyleSheet(QString::fromUtf8("#comboBox {\n"
"	border: 1px solid #ced4da;\n"
"	padding-left: 15px;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        translateField->setPlaceholderText(QCoreApplication::translate("MainWindow", "translate value...", nullptr));
        rotateField->setPlaceholderText(QCoreApplication::translate("MainWindow", "rotate value...", nullptr));
        scaleField->setPlaceholderText(QCoreApplication::translate("MainWindow", "scale value...", nullptr));
        translateAx->setItemText(0, QCoreApplication::translate("MainWindow", "X", nullptr));
        translateAx->setItemText(1, QCoreApplication::translate("MainWindow", "Y", nullptr));
        translateAx->setItemText(2, QCoreApplication::translate("MainWindow", "Z", nullptr));

        translateAx->setCurrentText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotateAx->setItemText(0, QCoreApplication::translate("MainWindow", "X", nullptr));
        rotateAx->setItemText(1, QCoreApplication::translate("MainWindow", "Y", nullptr));
        rotateAx->setItemText(2, QCoreApplication::translate("MainWindow", "Z", nullptr));

        rotateAx->setCurrentText(QCoreApplication::translate("MainWindow", "X", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        translateButton->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        fileDialogButton->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        fileNameLabel->setText(QString());
        vLable->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        vLabelCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        eLabel->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        eLabelCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        vertex_empty->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        vertex_circle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        vertex_square->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Type vertex", nullptr));
        edg_line->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        edg_dotted->setText(QCoreApplication::translate("MainWindow", "Dotted", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Type_edg", nullptr));
        Color_B_V_E->setItemText(0, QCoreApplication::translate("MainWindow", "Backround", nullptr));
        Color_B_V_E->setItemText(1, QCoreApplication::translate("MainWindow", "Vertex", nullptr));
        Color_B_V_E->setItemText(2, QCoreApplication::translate("MainWindow", "Edg", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Size_vertex_or_edg", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        scaleAx->setItemText(0, QCoreApplication::translate("MainWindow", "X", nullptr));
        scaleAx->setItemText(1, QCoreApplication::translate("MainWindow", "Y", nullptr));
        scaleAx->setItemText(2, QCoreApplication::translate("MainWindow", "Z", nullptr));

        scaleAx->setCurrentText(QCoreApplication::translate("MainWindow", "X", nullptr));
        button_screenshot->setText(QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
        format_screenshot->setItemText(0, QCoreApplication::translate("MainWindow", "jpeg", nullptr));
        format_screenshot->setItemText(1, QCoreApplication::translate("MainWindow", "bmp", nullptr));

        format_screenshot->setCurrentText(QCoreApplication::translate("MainWindow", "jpeg", nullptr));
        type_projection->setItemText(0, QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        type_projection->setItemText(1, QCoreApplication::translate("MainWindow", "Central", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
