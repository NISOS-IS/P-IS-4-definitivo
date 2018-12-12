#include <iostream>
#include <string>
#include "alumno.h"
#include "funcionesAux.h"

using namespace std;

Alumno::Alumno()
{

}

/*
Metodo setCurso que comprueba que el curso se introduzca de forma correcta
@param curso
@return devuelve true si el curso es correcto o false si no lo es
*/
bool Alumno::setCurso(int curso){
    QWidget *parent= new QWidget;
    if(curso>0 && curso<5){
        curso_ = curso;
        return true;
    }
    else{
        QMessageBox::critical(parent, "Title", "El numero de curso debe estar entre 1 y 4");
        return false;
    }
}

/*
Metodo setEquipo que comprueba que el equipo se introduzca de forma correcta
@param curso
@return devuelve true si el equipo es correcto o false si no lo es
*/
bool Alumno::setEquipo(int equipo){
    QWidget *parent= new QWidget;
    if(equipo > 0){
        equipo_ = equipo;
        return true;
    }
    else{
        QMessageBox::critical(parent, "Title", "El numero de equipo debe ser positivo");
        return false;
    }
}

/*
Metodo setLider
@param lider
*/
void Alumno::setLider(bool lider){
    lider_=lider;

}
