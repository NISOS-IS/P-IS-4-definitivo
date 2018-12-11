/*Archivo alumno.h que contiene la clase Alumno que hereda de la clase Persona*/

#ifndef ALUMNO_H_
#define ALUMNO_H_

#include "persona.h"

/*
Clase Alumno que hereda de Persona
@param curso_, equipo_, lider_
*/
class Alumno: public Persona{
	private:
		int curso_;
		int equipo_;
		bool lider_;
	public:
		//constructor de la clase Alumno que hereda de la clase Persona
		Alumno(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo=0, bool lider=false);

		//métodos get y set de la variable curso_
		inline int getCurso(){return curso_;};
		bool setCurso(int curso);

		//métodos get y set de la variable equipo_
		inline int getEquipo(){return equipo_;};
		bool setEquipo(int equipo);

		//métodos get y set de la variable lider_
		inline bool getLider(){return lider_;};
		void setLider(bool lider);
};

#endif
