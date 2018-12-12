/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButtonSalir;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonIniciarSesion;
    QPushButton *pushButtonRegistrarse;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        pushButtonSalir = new QPushButton(Widget);
        pushButtonSalir->setObjectName(QString::fromUtf8("pushButtonSalir"));
        pushButtonSalir->setGeometry(QRect(250, 190, 105, 28));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 50, 201, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonIniciarSesion = new QPushButton(widget);
        pushButtonIniciarSesion->setObjectName(QString::fromUtf8("pushButtonIniciarSesion"));

        verticalLayout->addWidget(pushButtonIniciarSesion);

        pushButtonRegistrarse = new QPushButton(widget);
        pushButtonRegistrarse->setObjectName(QString::fromUtf8("pushButtonRegistrarse"));

        verticalLayout->addWidget(pushButtonRegistrarse);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButtonSalir->setText(QApplication::translate("Widget", "Salir", nullptr));
        pushButtonIniciarSesion->setText(QApplication::translate("Widget", "Iniciar Sesi\303\263n", nullptr));
        pushButtonRegistrarse->setText(QApplication::translate("Widget", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
