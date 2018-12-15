/*Archivo funcionesAux.h que contiene struct de Registros y RegistroAlumno y las cabeceras de funciones auxiliares*/
#ifndef FUNCIONESAUX_H_
#define FUNCIONESAUX_H_

#include <fstream>
#include <string>
#include <iostream>
#include "agenda.h"
#include <QMessageBox>

using namespace std;

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

struct RegUsu{
    char usuario[100];
    char contrasena[100];
    char rol[15];
};

bool comprobarExistenciaDNI(string dni);
bool comprobarLider(list<Alumno> &aux, bool lider);
bool compruebaEmailProfesor(string email);
bool compruebaUsuario(string usuario);
bool comprobarEmail(list<Alumno> &aux, string email);
string convertirBool(bool a);
string convertirBoolLider(bool a);
bool convertirStringLider(char *lider);
string mayusculas(string cadena);
bool escribirDatos(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fechaNacimiento, int curso, int equipo, bool lider);
bool modificarDatos(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fechaNacimiento, int curso, int equipo, bool lider);
int leerlinea(char *cad, int max);
void mostrarListado();
bool ActualizarFicheroInicio(RegUsu reg);
bool comprobarUsuario(RegUsu reg);

#endif
