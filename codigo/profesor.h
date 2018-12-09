/*Archivo profesor.h que contiene la clase Profesor que hereda de la clase Persona*/

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include <string>
#include <fstream>
#include "persona.h"

using namespace std;

class Profesor: public Persona{
	private:
		bool rol_;
		string usuario_;
		string contrasena_;
	public:
		//constructor de la clase Profesor que hereda de la clase Persona
		Profesor(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, bool rol, string contrasena);
		Profesor();

		//métodos get y set de rol_
		inline bool getRol(){return rol_;};
		void setRol(bool rol);

		//métodos get y set de usuario_;
		inline string getUsuario(){return usuario_;};
		void setUsuario(string usuario);

		//métodos get y set de contrasena_
		inline string getContrasena(){return contrasena_;};
		void setContrasena(string contrasena);

		//Busca un profesor del fichero binario
		bool buscaProfesor(string dni);

		//Registra un profesor y lo añade al fichero binario
		bool registrarProfesor(Profesor profesor);

		//Inicia sesión de un profesor
		bool login(string usuario, string contrasena);

		//Guarda una copia de seguridad del fichero binario de alumnos
		bool guardarCopia();

		//Cargar una copia de seguridad en el fichero binario de alumnos
		bool cargarCopia();

};

#endif
