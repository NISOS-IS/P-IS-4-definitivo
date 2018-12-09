#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "persona.h"
#include "funcionesAux.h"

using namespace std;

//Constructores de la clase Persona, uno recibe todos los parámetros obligatorios y otro no recibe ningún parámetro
Persona::Persona(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento){
	dni_ = dni;
	nombre_ = nombre;
	apellidos_ = apellidos;
	telefono_ = telefono;
	direccion_ = direccion;
	email_ = email;
	fechaNacimiento_ = fecha_nacimiento;
}

Persona::Persona(){}


/*
Método setDNI que comprueba que un dni sea correcto
@param dni(string)
@return bool
*/
bool Persona::setDNI(string dni){
	bool correcto = true;//comprobarDNI(dni);
	if(correcto){
		dni_ = dni;
		return true;
	}
	else{
		cout<<"El DNI no es correcto"<<endl;
		return false;
	}
}

void Persona::setNombre(string nombre){
	nombre_ = nombre;
}

void Persona::setApellidos(string apellidos){
	apellidos_ = apellidos;
}


/*
Método setTelefono que comprueba que un telefono sea correcto
@param telefono(int)
@return bool
*/
bool Persona::setTelefono(int telefono){
    string s = to_string(telefono);
	if(s.size()==9){
		telefono_ = atoi(s.c_str());
		return true;
	}
	else{
		cout<<"El telefono no es correcto"<<endl;
		return false;
	}
}

void Persona::setDireccion(string direccion){
	direccion_ = direccion;
}


/*
Método setEmail que compruebe que un email es correcto
@param email(string)
@return bool
*/
bool Persona::setEmail(string email){
	if(validarEmail(email)){
	    email_ = email;
	    return true;
	}
	else{
	    cout<<"El email no es correcto"<<endl;
	    return false;
	}
}


/*
Método setFechaNacimiento que comprueba que una fecha de Nacimiento sea correcta
@param fecha_nacimiento(string)
@return bool
*/
bool Persona::setFechaNacimiento(string fecha_nacimiento){
	if(compruebaFecha(fecha_nacimiento)){
	    fechaNacimiento_ = fecha_nacimiento;
	    return true;
	}
	else{
	    return false;
	}
}
