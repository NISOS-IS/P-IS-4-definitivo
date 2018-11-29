/*Archivo alumno.cc que contiene la funciones de la clase Alumno*/

#include <iostream>
#include <string>
#include "alumno.h"
#include "funcionesAux.h"

using namespace std;

Alumno::Alumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo, bool lider):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){

}

void Alumno::setCurso(int curso){
	if(curso>0 && curso<5){
		curso_ = curso;
	}
	else{
		cout<<"El curso introducido no es correcto"<<endl;
	}
}

void Alumno::setEquipo(int equipo){
	if(equipo > 0){
		equipo_ = equipo;
	}
	else{
		cout<<"El equipo no es válido"<<endl;
	}
}

void Alumno::setLider(bool lider){
	
}
