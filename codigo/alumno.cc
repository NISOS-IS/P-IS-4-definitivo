/*Archivo alumno.cc que contiene la funciones de la clase Alumno*/

#include <iostream>
#include <string>
#include "alumno.h"
#include "funcionesAux.h"

using namespace std;

/*
Constructor de la clase Alumno que hereda de Persona
@param dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento, curso, equipo, lider
*/
Alumno::Alumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo, bool lider):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){

}

/*
Metodo setCurso que comprueba que el curso se introduzca de forma correcta
@param curso
@return devuelve true si el curso es correcto o false si no lo es
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
Metodo setEquipo que comprueba que el equipo se introduzca de forma correcta
@param curso
@return devuelve true si el equipo es correcto o false si no lo es
*/
bool Alumno::setEquipo(int equipo){
	if(equipo > 0){
		equipo_ = equipo;
		return true;
	}
	else{
		cout<<"El equipo no es válido"<<endl;
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
