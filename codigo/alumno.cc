/*Archivo alumno.cc que contiene la funciones de la clase Alumno*/

#include <iostream>
#include <string>
#include "alumno.h"
#include "funcionesAux.h"

using namespace std;

<<<<<<< HEAD

/*
Constructor de la clase Alumno que hereda de Persona
@param dni, nombre, apellidos, telefono, email, fecha_nacimiento, curso, equipo, lider
=======
/*
Constructor de la clase Alumno que hereda de Persona
@param dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento, curso, equipo, lider
>>>>>>> 1bd83ba798adb5cb224ac44e67779dc0f46764ae
*/
Alumno::Alumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo, bool lider):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){

}

<<<<<<< HEAD

/*
Método setCurso que comprueba que el curso se introduzca de forma correcta
@param curso(int)
@return bool
=======
/*
Metodo setCurso que comprueba que el curso se introduzca de forma correcta
@param curso
@return devuelve true si el curso es correcto o false si no lo es
>>>>>>> 1bd83ba798adb5cb224ac44e67779dc0f46764ae
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

<<<<<<< HEAD

/*
Método setEquipo que comprueba que el equipo se introduzca de forma correcta
@param equipo (int)
@return bool
=======
/*
Metodo setEquipo que comprueba que el equipo se introduzca de forma correcta
@param curso
@return devuelve true si el equipo es correcto o false si no lo es
>>>>>>> 1bd83ba798adb5cb224ac44e67779dc0f46764ae
*/
bool Alumno::setEquipo(int equipo){
	if(equipo > 0){
		equipo_ = equipo;
		return true;
	}
	else{
<<<<<<< HEAD
		cout<<"El equipo es inválido"<<endl;
=======
		cout<<"El equipo no es válido"<<endl;
>>>>>>> 1bd83ba798adb5cb224ac44e67779dc0f46764ae
		return false;
	}
}

<<<<<<< HEAD

/*
Método setLider que asigna un lider al equipo
@param lider(bool)
@return void
*/
void Alumno::setLider(bool lider){
	lider_=lider;
=======
/*
Metodo setLider
@param lider
*/
void Alumno::setLider(bool lider){
	lider_=lider;
	
>>>>>>> 1bd83ba798adb5cb224ac44e67779dc0f46764ae
}
