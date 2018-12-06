/*Archivo agenda.h que contiene la clase Agenda*/

#ifndef AGENDA_H_
#define AGENDA_H_

#include <list>
#include <string>
#include "alumno.h"

using namespace std;

/*
Clase Agenda
@param list<Alumno>
*/
class Agenda{
	private:
		list<Alumno> listaAlumnos_;
	public:
		//constructor de la clase Agenda
		Agenda();

		//Busca uno o varios alumnos en el fichero binario
		list<Alumno> buscarAlumno(string dni, string apellidos, int equipo);
		
		//Inserta un alumno en el fichero binario
		bool insertarAlumno(Alumno alumno);

		//Borra un alumno del fichero binario
		bool borrarAlumno(string dni, string apellidos);

		//Modifica algunos de los datos de un alumno del fichero binario
		bool modificarAlumno(string dni, string apellidos);

		//Muestra por pantalla el listado de alumnos del fichero binario
		list<Alumno> mostrarLista();

		//Muestra por pantalla los datos de un alumno en concreto
		list<Alumno> mostrarAlumno(string dni, string apellidos, int equipo);
};

#endif
