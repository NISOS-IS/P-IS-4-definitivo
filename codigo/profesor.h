/*Archivo profesor.h que contiene la clase Profesor que hereda de la clase Persona*/

#ifndef PROFESOR_H_
#define PROFESOR_H_

class Profesor: public Persona{
	private:
		bool rol_;
		string usuario_;
		string contrasena_;
	public:
		Profesor(bool rol, string usuario, string contrasena);

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
		bool registrarProfesor();

		//Inicia sesión de un profesor
		void login(string usuario, string constrasena);

		//Guarda una copia de seguridad del fichero binario de alumnos
		bool guardarCopia();

		//Cargar una copia de seguridad en el fichero binario de alumnos
		bool cargarCopia();
};

#endif
