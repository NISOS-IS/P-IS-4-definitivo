/*Archivo alumno.cc que contiene la funciones de la clase Alumno*/

#include <iostream>
#include <string>
#include "alumno.h"
#include "funcionesAux.h"

using namespace std;


/*
Constructor de la clase Alumno que hereda de Persona
@param dni, nombre, apellidos, telefono, email, fecha_nacimiento, curso, equipo, lider
*/
Alumno::Alumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo, bool lider):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){

}


/*
Método setCurso que comprueba que el curso se introduzca de forma correcta
@param curso(int)
@return bool
*/
bool Alumno::setCurso(int curso){
	if(curso>0 && curso<5){
		curso_ = curso;
		return true;
	}
	else{
		cout<<"El curso introducido no es correcto"<<endl;
		return false;
	}
}


/*
Método setEquipo que comprueba que el equipo se introduzca de forma correcta
@param equipo (int)
@return bool
*/
bool Alumno::setEquipo(int equipo){
	if(equipo > 0){
		equipo_ = equipo;
		return true;
	}
	else{
		cout<<"El equipo es inválido"<<endl;
		return false;
	}
}


/*
Método setLider que asigna un lider al equipo
@param lider(bool)
@return void
*/
void Alumno::setLider(bool lider){
	lider_=lider;
}
