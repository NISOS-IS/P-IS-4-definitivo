/*Archivo persona.h que contiene la clase Persona*/

#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>

using namespace std;

class Persona{
	private:
		string dni_;
		string nombre_;
		string apellidos_;
		int telefono_;
		string direccion_;
		string email_;
		string fechaNacimiento_;
	public:
		//constructor de Persona
		Persona(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento);
		Persona();

		//métodos get y set de dni_
		inline string getDNI(){return dni_;};
		void setDNI(string dni);

		//métodos get y set de nombre_
		inline string getNombre(){return nombre_;};
		void setNombre(string nombre);

		//métodos get y set de apellidos_
		inline string getApellidos(){return apellidos_;};
		void setApellidos(string apellidos);
	
		//métodos get y set de telefono_
		inline int getTelefono(){return telefono_;};
		void setTelefono(int telefono);

		//métodos get y set de direccion_
		inline string getDireccion(){return direccion_;};
		void setDireccion(string direccion);

		//métodos get y set de email_
		inline string getEmail(){return email_;};
		void setEmail(string email);

		//métodos get y set de fechaNacimiento_
		inline string getFechaNacimiento(){return fechaNacimiento_;};
		void setFechaNacimiento(string fecha_nacimiento);
};

#endif
