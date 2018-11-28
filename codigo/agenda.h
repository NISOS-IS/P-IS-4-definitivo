/*Archivo agenda.h que contiene la clase Agenda*/

#ifndef AGENDA_H_
#define AGENDA_H_

class Agenda{
	private:
		list<Alumno> listaALumnos_;
	public:
		//Busca uno o varios alumnos en el fichero binario
		list<Alumno> buscarAlumno(string dni, string apellidos, int equipo);

		//Inserta un alumno en el fichero binario
		bool insertarAlumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, sting fecha_nacimiento);

		//Borra un alumno del fichero binario
		bool borrarAlumno(string dni, string apellidos);

		//Modifica algunos de los datos de un alumno del fichero binario
		bool modificarAlumno(string dni, string apellidos);

		//Muestra por pantalla el listado de alumnos del fichero binario
		list<Alumno> mostrarLista();

		//Muestra por pantalla los datos de un alumno en concreto
		list<Alumno> mostrarAlumno(string dni, string apellidos);
};

#endif
