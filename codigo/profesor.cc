/*Archivo profesor.cc que contiene las funciones de la clase Profesor*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "profesor.h"
#include "funcionesAux.h"

using namespace std;

Profesor::Profesor(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, bool rol, string contrasena):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){
	rol_ = rol;
	contrasena_ =contrasena;
}

void Profesor::setContrasena(string contrasena){
	if(contrasena.size()>=4){
		contrasena_ = contrasena;
	}
	else{
		cout<<"La contraseña debe tener 4 carácteres o más"<<endl;
	}
}

void Profesor::setUsuario(string usuario){
    usuario_ = usuario;
}

void Profesor::setRol(bool rol){
    rol_ = rol;
}

bool Profesor::buscaProfesor(string dni){
	ifstream file("profesores.bin", ios::in | ios::binary);
	Profesor aux("","","",0,"","","",false,"");
	bool encontrado = false;
	if(file.is_open()){
		while(!file.eof()){
			file.read(reinterpret_cast<char *> (&aux), sizeof(Profesor));
			if(aux.getDNI() == dni){
				encontrado = true;
			}
		}
		if(encontrado){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		cout<<"El profesor con DNI <"<<dni<<"> no está registrado."<<endl;
		return false;
	}
}

bool Profesor::registrarProfesor(Profesor profesor){
	ofstream file("profesores.bin", ios::out | ios::binary);
	Registro reg;
	strcpy(reg.dni,profesor.getDNI().c_str());
	strcpy(reg.nombre,profesor.getNombre().c_str());
    strcpy(reg.apellidos,profesor.getApellidos().c_str());
    reg.telefono=profesor.getTelefono();
    strcpy(reg.direccion,profesor.getDireccion().c_str());
    strcpy(reg.email,profesor.getEmail().c_str());
    strcpy(reg.fechaNacimiento,profesor.getFechaNacimiento().c_str());
    strcpy(reg.rol,convertirBool(profesor.getRol()).c_str());
    strcpy(reg.usuario,profesor.getUsuario().c_str());
    strcpy(reg.contrasena,profesor.getContrasena().c_str());
	file.write((char *) &reg, sizeof(Registro));
	file.close();

	/*ifstream f("profesores.bin", ios::in | ios::binary);
	f.read((char *) &reg, sizeof(Registro));
	cout<<reg.dni<<endl;
	cout<<reg.nombre<<endl;
	cout<<reg.apellidos<<endl;
	cout<<reg.telefono<<endl;
	cout<<reg.direccion<<endl;
	cout<<reg.email<<endl;
	cout<<reg.fechaNacimiento<<endl;
	cout<<reg.rol<<endl;
	cout<<reg.usuario<<endl;
	cout<<reg.contrasena<<endl;
	f.close();*/
}

bool Profesor::login(string usuario, string constrasena){

}

bool Profesor::cargarCopia(){

}

bool Profesor::guardarCopia(){
	// Creamos el archivo y lo abrimos en binario
	int lon;
	ifstream fe("agenda.bin",ios::binary); // h es el string donde se encuentra el archivo
	// Miramos cual es el tamaño del archivo
	fe.seekg (0, ios::end);
	lon = fe.tellg();
	fe.seekg (0, ios::beg);
	//Creamos una cadena de caracteres con el tamaño del archivo
	char* cadena = new char [lon];
	memset( cadena , 0 , lon );
	//Leemos el archivo y se guarda en la cadena
	fe.read(cadena,lon); 
	//Creamos otro archivo donde se copiara
	ofstream fs("copiaSeguridad.bin");
	if(fs.eof()){
		return false;
	}
	fs.write(cadena,lon);
	fs.close();
	fe.close();
	return true;
}
