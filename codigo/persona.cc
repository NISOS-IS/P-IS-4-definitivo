#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "persona.h"
#include "funcionesAux.h"

using namespace std;

Persona::Persona(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento){
	dni_ = dni;
	nombre_ = nombre;
	apellidos_ = apellidos;
	telefono_ = telefono;
	direccion_ = direccion;
	email_ = email;
	fechaNacimiento_ = fecha_nacimiento;
}

bool Persona::setDNI(string dni){
	char cadDni[9];
	strcpy(cadDni, dni.c_str());
	if (verificaDNI(cadDni)){
		dni_=dni;
		return true;
	}else{
		cout<<"EL DNI introducido no es correcto"<<endl;
		return false;
	}
}

void Persona::setNombre(string nombre){
	nombre_ = nombre;
}

void Persona::setApellidos(string apellidos){
	apellidos_ = apellidos;
}

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

bool Persona::setEmail(string email){
	bool correcto=false;
	correcto= validarEmail(email);
	if(correcto==true){
		email_=email;
		return true;
	}else{
		cout<<"El email no es correcto"<<endl;
		return false;
	}
}

bool Persona::setFechaNacimiento(string fecha_nacimiento){
	bool correcto=false;
	correcto= compruebaFecha(fecha_nacimiento);
	if(correcto==true){
		fechaNacimiento_=fecha_nacimiento;
		return true;
	}else{
		return false;
	}
}
