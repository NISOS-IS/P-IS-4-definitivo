/********************************************************************************
** Form generated from reading UI file 'registrarse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRARSE_H
#define UI_REGISTRARSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registrarse
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDNI;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditNombre;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditApellidos;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditTelefono;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEditDireccion;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEditEmail;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDateEdit *dateEditFecha;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QComboBox *comboBoxRol;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEditUsuario;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *lineEditContrasena;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonAceptar;
    QPushButton *pushButtonCancelar;

    void setupUi(QDialog *Registrarse)
    {
        if (Registrarse->objectName().isEmpty())
            Registrarse->setObjectName(QString::fromUtf8("Registrarse"));
        Registrarse->resize(400, 526);
        layoutWidget = new QWidget(Registrarse);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 381, 371));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditDNI = new QLineEdit(layoutWidget);
        lineEditDNI->setObjectName(QString::fromUtf8("lineEditDNI"));

        horizontalLayout->addWidget(lineEditDNI);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditNombre = new QLineEdit(layoutWidget);
        lineEditNombre->setObjectName(QString::fromUtf8("lineEditNombre"));

        horizontalLayout_2->addWidget(lineEditNombre);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditApellidos = new QLineEdit(layoutWidget);
        lineEditApellidos->setObjectName(QString::fromUtf8("lineEditApellidos"));

        horizontalLayout_3->addWidget(lineEditApellidos);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditTelefono = new QLineEdit(layoutWidget);
        lineEditTelefono->setObjectName(QString::fromUtf8("lineEditTelefono"));

        horizontalLayout_4->addWidget(lineEditTelefono);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEditDireccion = new QLineEdit(layoutWidget);
        lineEditDireccion->setObjectName(QString::fromUtf8("lineEditDireccion"));

        horizontalLayout_6->addWidget(lineEditDireccion);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEditEmail = new QLineEdit(layoutWidget);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        horizontalLayout_5->addWidget(lineEditEmail);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        dateEditFecha = new QDateEdit(layoutWidget);
        dateEditFecha->setObjectName(QString::fromUtf8("dateEditFecha"));

        horizontalLayout_7->addWidget(dateEditFecha);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        comboBoxRol = new QComboBox(layoutWidget);
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->setObjectName(QString::fromUtf8("comboBoxRol"));

        horizontalLayout_8->addWidget(comboBoxRol);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lineEditUsuario = new QLineEdit(layoutWidget);
        lineEditUsuario->setObjectName(QString::fromUtf8("lineEditUsuario"));

        horizontalLayout_10->addWidget(lineEditUsuario);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_11->addWidget(label_9);

        lineEditContrasena = new QLineEdit(layoutWidget);
        lineEditContrasena->setObjectName(QString::fromUtf8("lineEditContrasena"));
        lineEditContrasena->setEchoMode(QLineEdit::Password);

        horizontalLayout_11->addWidget(lineEditContrasena);


        verticalLayout->addLayout(horizontalLayout_11);

        layoutWidget1 = new QWidget(Registrarse);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 430, 179, 30));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButtonAceptar = new QPushButton(layoutWidget1);
        pushButtonAceptar->setObjectName(QString::fromUtf8("pushButtonAceptar"));

        horizontalLayout_9->addWidget(pushButtonAceptar);

        pushButtonCancelar = new QPushButton(layoutWidget1);
        pushButtonCancelar->setObjectName(QString::fromUtf8("pushButtonCancelar"));

        horizontalLayout_9->addWidget(pushButtonCancelar);


        retranslateUi(Registrarse);

        QMetaObject::connectSlotsByName(Registrarse);
    } // setupUi

    void retranslateUi(QDialog *Registrarse)
    {
        Registrarse->setWindowTitle(QApplication::translate("Registrarse", "Dialog", nullptr));
        label->setText(QApplication::translate("Registrarse", "DNI:", nullptr));
        label_2->setText(QApplication::translate("Registrarse", "Nombre:", nullptr));
        label_3->setText(QApplication::translate("Registrarse", "Apellidos:", nullptr));
        label_4->setText(QApplication::translate("Registrarse", "Tel\303\251fono:", nullptr));
        label_5->setText(QApplication::translate("Registrarse", "Direcci\303\263n:", nullptr));
        label_6->setText(QApplication::translate("Registrarse", "E-mail:", nullptr));
        label_7->setText(QApplication::translate("Registrarse", "Fecha de Nacimiento:", nullptr));
        label_10->setText(QApplication::translate("Registrarse", "Rol:", nullptr));
        comboBoxRol->setItemText(0, QString());
        comboBoxRol->setItemText(1, QApplication::translate("Registrarse", "Ayudante", nullptr));
        comboBoxRol->setItemText(2, QApplication::translate("Registrarse", "Coordinador", nullptr));

        label_8->setText(QApplication::translate("Registrarse", "Usuario:", nullptr));
        label_9->setText(QApplication::translate("Registrarse", "Contrase\303\261a:", nullptr));
        pushButtonAceptar->setText(QApplication::translate("Registrarse", "Aceptar", nullptr));
        pushButtonCancelar->setText(QApplication::translate("Registrarse", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrarse: public Ui_Registrarse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRARSE_H
