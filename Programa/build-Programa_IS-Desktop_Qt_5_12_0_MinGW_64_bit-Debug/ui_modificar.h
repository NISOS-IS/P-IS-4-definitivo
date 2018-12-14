/********************************************************************************
** Form generated from reading UI file 'modificar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICAR_H
#define UI_MODIFICAR_H

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

class Ui_Modificar
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButtonAceptar;
    QPushButton *pushButtonCancelar;
    QWidget *layoutWidget_2;
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
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *lineEditCurso;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEditEquipo;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QComboBox *comboBoxLider;

    void setupUi(QDialog *Modificar)
    {
        if (Modificar->objectName().isEmpty())
            Modificar->setObjectName(QString::fromUtf8("Modificar"));
        Modificar->resize(325, 457);
        layoutWidget = new QWidget(Modificar);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 390, 179, 30));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButtonAceptar = new QPushButton(layoutWidget);
        pushButtonAceptar->setObjectName(QString::fromUtf8("pushButtonAceptar"));

        horizontalLayout_11->addWidget(pushButtonAceptar);

        pushButtonCancelar = new QPushButton(layoutWidget);
        pushButtonCancelar->setObjectName(QString::fromUtf8("pushButtonCancelar"));

        horizontalLayout_11->addWidget(pushButtonCancelar);

        layoutWidget_2 = new QWidget(Modificar);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 274, 370));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditDNI = new QLineEdit(layoutWidget_2);
        lineEditDNI->setObjectName(QString::fromUtf8("lineEditDNI"));

        horizontalLayout->addWidget(lineEditDNI);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditNombre = new QLineEdit(layoutWidget_2);
        lineEditNombre->setObjectName(QString::fromUtf8("lineEditNombre"));

        horizontalLayout_2->addWidget(lineEditNombre);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditApellidos = new QLineEdit(layoutWidget_2);
        lineEditApellidos->setObjectName(QString::fromUtf8("lineEditApellidos"));

        horizontalLayout_3->addWidget(lineEditApellidos);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditTelefono = new QLineEdit(layoutWidget_2);
        lineEditTelefono->setObjectName(QString::fromUtf8("lineEditTelefono"));

        horizontalLayout_4->addWidget(lineEditTelefono);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEditDireccion = new QLineEdit(layoutWidget_2);
        lineEditDireccion->setObjectName(QString::fromUtf8("lineEditDireccion"));

        horizontalLayout_6->addWidget(lineEditDireccion);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEditEmail = new QLineEdit(layoutWidget_2);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        horizontalLayout_5->addWidget(lineEditEmail);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        dateEditFecha = new QDateEdit(layoutWidget_2);
        dateEditFecha->setObjectName(QString::fromUtf8("dateEditFecha"));

        horizontalLayout_7->addWidget(dateEditFecha);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        lineEditCurso = new QLineEdit(layoutWidget_2);
        lineEditCurso->setObjectName(QString::fromUtf8("lineEditCurso"));

        horizontalLayout_9->addWidget(lineEditCurso);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEditEquipo = new QLineEdit(layoutWidget_2);
        lineEditEquipo->setObjectName(QString::fromUtf8("lineEditEquipo"));

        horizontalLayout_10->addWidget(lineEditEquipo);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        comboBoxLider = new QComboBox(layoutWidget_2);
        comboBoxLider->addItem(QString());
        comboBoxLider->addItem(QString());
        comboBoxLider->addItem(QString());
        comboBoxLider->setObjectName(QString::fromUtf8("comboBoxLider"));

        horizontalLayout_8->addWidget(comboBoxLider);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(Modificar);

        QMetaObject::connectSlotsByName(Modificar);
    } // setupUi

    void retranslateUi(QDialog *Modificar)
    {
        Modificar->setWindowTitle(QApplication::translate("Modificar", "Dialog", nullptr));
        pushButtonAceptar->setText(QApplication::translate("Modificar", "Aceptar", nullptr));
        pushButtonCancelar->setText(QApplication::translate("Modificar", "Cancelar", nullptr));
        label->setText(QApplication::translate("Modificar", "DNI:", nullptr));
        label_2->setText(QApplication::translate("Modificar", "Nombre:", nullptr));
        label_3->setText(QApplication::translate("Modificar", "Apellidos:", nullptr));
        label_4->setText(QApplication::translate("Modificar", "Tel\303\251fono:", nullptr));
        label_5->setText(QApplication::translate("Modificar", "Direcci\303\263n:", nullptr));
        label_6->setText(QApplication::translate("Modificar", "E-mail:", nullptr));
        label_7->setText(QApplication::translate("Modificar", "Fecha de Nacimiento:", nullptr));
        label_8->setText(QApplication::translate("Modificar", "Curso:", nullptr));
        label_9->setText(QApplication::translate("Modificar", "Equipo:", nullptr));
        label_10->setText(QApplication::translate("Modificar", "Rol:", nullptr));
        comboBoxLider->setItemText(0, QString());
        comboBoxLider->setItemText(1, QApplication::translate("Modificar", "Lider", nullptr));
        comboBoxLider->setItemText(2, QApplication::translate("Modificar", "No Lider", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Modificar: public Ui_Modificar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICAR_H
