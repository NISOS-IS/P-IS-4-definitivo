#include <iostream>
#include <string>
#include "alumno.h"
#include"profesor.h"
#include"agenda.h"

using namespace std;

void menuprincipal();
void menusecundario();

int main(){
	Alumno alumno("","","",0,"","","",0,0,false);
	Profesor profesor("pepe","ariza","t",0,"w","t","s",false,"w");
	Agenda agenda;
	string usuario, contrasena, dni, apellidos, op;
	int m1;
	menuprincipal();
	cout<<"\nSeleccione una opcion:"<<endl;
	cin>>m1;
	do{
		switch(m1){
			case 1:
				//Limpiar pantalla hay que buscar como se hace
				bool correcto;
				int entrar;
				cout<<"Usuario:"<<endl;
				cin>>usuario;
				cout<<"Contraseña:"<<endl;
				cin>>contrasena;
				correcto = profesor.login(usuario, contrasena);
				while(entrar!=1){
					entrar=0;
					if(correcto){
						entrar=1;
						int m2;
						menusecundario();
						cout<<"\nSeleccione una opcion:"<<endl;
						cin>>m2;
						switch(m2){
							case 1:
								agenda.mostrarLista();
								break;

							case 2:
								agenda.mostrarAlumno(dni, apellidos);
								break;

							case 3:
								agenda.insertarAlumno(alumno);
								break;

							case 4:
								agenda.modificarAlumno(dni, apellidos);
								break;

							case 5:
								agenda.borrarAlumno(dni, apellidos);
								break;

							case 6:
								profesor.guardarCopia();
								break;

							case 7:
								profesor.cargarCopia();
								break;
						}
					}
					else{
						cout<<"Usuario o contraseña inválidos."<<endl;
						entrar=0;
					}
				}	
				break;

			case 2:
				profesor.setDNI("444");
				profesor.setNombre("Pepe");
				profesor.setApellidos("Ariza");
				profesor.setTelefono(634550104);
				profesor.setDireccion("Calle");
				profesor.setEmail("email@gmail.com");
				profesor.setFechaNacimiento("01/01/2002");
				profesor.setRol(true);
				profesor.setUsuario("i72hisan");
				profesor.setContrasena("password");
				profesor.registrarProfesor(profesor);
				profesor.setDNI("333");
				profesor.setNombre("Pepe");
				profesor.setApellidos("Ariza");
				profesor.setTelefono(634550104);
				profesor.setDireccion("Calle");
				profesor.setEmail("email@gmail.com");
				profesor.setFechaNacimiento("01/01/2002");
				profesor.setRol(true);
				profesor.setUsuario("i72hisan");
				profesor.setContrasena("password");
				profesor.registrarProfesor(profesor);
				cout<<"\n\n¿Desea iniciar sesión?"<<endl;
				cin>>op;
				break;
		}
	}while(op=="s"|| op=="S");
	return 0;
}

void menuprincipal(){
	cout<<"----------MENU PRINCIPAL----------"<<endl;
	cout<<"\n\t1. Iniciar sesion"<<endl;
	cout<<"\t2. Registrar profesor"<<endl;
}

void menusecundario(){
	cout<<"----------MENU----------"<<endl;
	cout<<"\n\t1. Ver el listado de alumnos"<<endl;
	cout<<"\t2. Buscar uno o varios alumnos"<<endl;
	cout<<"\t3. Insertar un alumno"<<endl;
	cout<<"\t4. Modificar a un alumno"<<endl;
	cout<<"\t5. Borrar un alumno"<<endl;
	cout<<"\t6. Guardar copia del listado de alumnos"<<endl;
	cout<<"\t7. Cargar copia del listado de alumnos"<<endl;
}
