#include <iostream>
#include <string>
#include <cstdio>
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

void Persona::setDNI(string dni){
	bool correcto = true;//comprobarDNI(dni);
	if(correcto){
		dni_ = dni;
	}
	else{
		cout<<"El DNI no es correcto"<<endl;
	}
}

void Persona::setNombre(string nombre){
	nombre_ = nombre;
}

void Persona::setApellidos(string apellidos){
	apellidos_ = apellidos;
}

void Persona::setTelefono(int telefono){
    string s = to_string(telefono);
	if(s.size()==9){
		telefono_ = atoi(s.c_str());
	}
	else{
		cout<<"El telefono no es correcto"<<endl;
	}
}

void Persona::setDireccion(string direccion){
	direccion_ = direccion;
}

void Persona::setEmail(string email){
	
}

void Persona::setFechaNacimiento(string fecha_nacimiento){
	
}
