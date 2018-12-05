#ifndef FUNCIONESAUX_H_
#define FUNCIONESAUX_H_

#include <fstream>
#include <string>

struct Registro{
		char dni[10];
		char nombre[100];
		char apellidos[100];
		int telefono;
		char direccion[100];
		char email[100];
		char fechaNacimiento[100];
		char rol[20];
		char usuario[100];
		char contrasena[100];
};

struct RegistroAlumno{
		char dni[10];
		char nombre[100];
		char apellidos[100];
		int telefono;
		char direccion[100];
		char email[100];
		char fechaNacimiento[100];
		int curso;
		int equipo;
		char lider[100];
};

using namespace std;

bool comprobarDNI(string dni);
bool comprobarEmail(string email);
bool comprobarTel(int telefono);
bool comprobarFechaNacimiento(string fecha_nacimiento);
void imprimirBool(bool a);
string convertirBool(bool a);
string convertirBoolLider(bool a);
bool convertirStringLider(char *lider);
void escribirDatos();
void modificarDatos(struct RegistroAlumno *alumno);
int leerlinea(char *cad,int max);
char letraDNI(int dni);
short verificaDNI(char *dni);
bool compruebaFecha(string fecha);
bool validarEmail(string email);
#endif
