/********************************************************************************
** Form generated from reading UI file 'iniciarsesion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIARSESION_H
#define UI_INICIARSESION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IniciarSesion
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUsuario;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditContrasena;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAceptar;
    QPushButton *pushButtonCancelar;

    void setupUi(QDialog *IniciarSesion)
    {
        if (IniciarSesion->objectName().isEmpty())
            IniciarSesion->setObjectName(QString::fromUtf8("IniciarSesion"));
        IniciarSesion->resize(400, 300);
        widget = new QWidget(IniciarSesion);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 341, 211));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditUsuario = new QLineEdit(widget);
        lineEditUsuario->setObjectName(QString::fromUtf8("lineEditUsuario"));

        horizontalLayout->addWidget(lineEditUsuario);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditContrasena = new QLineEdit(widget);
        lineEditContrasena->setObjectName(QString::fromUtf8("lineEditContrasena"));
        lineEditContrasena->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditContrasena);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonAceptar = new QPushButton(widget);
        pushButtonAceptar->setObjectName(QString::fromUtf8("pushButtonAceptar"));

        horizontalLayout_3->addWidget(pushButtonAceptar);

        pushButtonCancelar = new QPushButton(widget);
        pushButtonCancelar->setObjectName(QString::fromUtf8("pushButtonCancelar"));

        horizontalLayout_3->addWidget(pushButtonCancelar);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(IniciarSesion);

        QMetaObject::connectSlotsByName(IniciarSesion);
    } // setupUi

    void retranslateUi(QDialog *IniciarSesion)
    {
        IniciarSesion->setWindowTitle(QApplication::translate("IniciarSesion", "Dialog", nullptr));
        label->setText(QApplication::translate("IniciarSesion", "Usuario:", nullptr));
        label_2->setText(QApplication::translate("IniciarSesion", "Contrase\303\261a:", nullptr));
        pushButtonAceptar->setText(QApplication::translate("IniciarSesion", "Aceptar", nullptr));
        pushButtonCancelar->setText(QApplication::translate("IniciarSesion", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IniciarSesion: public Ui_IniciarSesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIARSESION_H
