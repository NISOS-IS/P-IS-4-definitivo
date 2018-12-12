/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonMostrarAlumno;
    QPushButton *pushButtonBorrarAlumno;
    QPushButton *pushButtonModificarAlumno;
    QPushButton *pushButtonInsertarAlumno;
    QPushButton *pushButtonListadoAlumnos;
    QPushButton *pushButtonGuardarCopia;
    QPushButton *pushButtonCargarCopia;
    QPushButton *pushButtonSalir;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(1080, 570);
        tableWidget = new QTableWidget(Menu);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(440, 30, 551, 221));
        layoutWidget = new QWidget(Menu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 281, 411));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonMostrarAlumno = new QPushButton(layoutWidget);
        pushButtonMostrarAlumno->setObjectName(QString::fromUtf8("pushButtonMostrarAlumno"));

        verticalLayout->addWidget(pushButtonMostrarAlumno);

        pushButtonBorrarAlumno = new QPushButton(layoutWidget);
        pushButtonBorrarAlumno->setObjectName(QString::fromUtf8("pushButtonBorrarAlumno"));

        verticalLayout->addWidget(pushButtonBorrarAlumno);

        pushButtonModificarAlumno = new QPushButton(layoutWidget);
        pushButtonModificarAlumno->setObjectName(QString::fromUtf8("pushButtonModificarAlumno"));

        verticalLayout->addWidget(pushButtonModificarAlumno);

        pushButtonInsertarAlumno = new QPushButton(layoutWidget);
        pushButtonInsertarAlumno->setObjectName(QString::fromUtf8("pushButtonInsertarAlumno"));

        verticalLayout->addWidget(pushButtonInsertarAlumno);

        pushButtonListadoAlumnos = new QPushButton(layoutWidget);
        pushButtonListadoAlumnos->setObjectName(QString::fromUtf8("pushButtonListadoAlumnos"));

        verticalLayout->addWidget(pushButtonListadoAlumnos);

        pushButtonGuardarCopia = new QPushButton(layoutWidget);
        pushButtonGuardarCopia->setObjectName(QString::fromUtf8("pushButtonGuardarCopia"));

        verticalLayout->addWidget(pushButtonGuardarCopia);

        pushButtonCargarCopia = new QPushButton(layoutWidget);
        pushButtonCargarCopia->setObjectName(QString::fromUtf8("pushButtonCargarCopia"));

        verticalLayout->addWidget(pushButtonCargarCopia);


        verticalLayout_2->addLayout(verticalLayout);

        pushButtonSalir = new QPushButton(layoutWidget);
        pushButtonSalir->setObjectName(QString::fromUtf8("pushButtonSalir"));

        verticalLayout_2->addWidget(pushButtonSalir);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", nullptr));
        pushButtonMostrarAlumno->setText(QApplication::translate("Menu", "Buscar Alumno/s", nullptr));
        pushButtonBorrarAlumno->setText(QApplication::translate("Menu", "Borrar Alumno", nullptr));
        pushButtonModificarAlumno->setText(QApplication::translate("Menu", "ModificarAlumno", nullptr));
        pushButtonInsertarAlumno->setText(QApplication::translate("Menu", "Insertar Alumno", nullptr));
        pushButtonListadoAlumnos->setText(QApplication::translate("Menu", "Listado de Alumnos", nullptr));
        pushButtonGuardarCopia->setText(QApplication::translate("Menu", "Guardar copia de seguridad", nullptr));
        pushButtonCargarCopia->setText(QApplication::translate("Menu", "Cargar copia de seguridad", nullptr));
        pushButtonSalir->setText(QApplication::translate("Menu", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
