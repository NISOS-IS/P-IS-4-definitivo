#include <iostream>
#include <string>
#include "alumno.h"
#include"profesor.h"
#include"agenda.h"

using namespace std;

void menuprincipal();
void menusecundario();
void menuBuscar(int);

int main(){
	Alumno alumno("","","",0,"","","",0,0,false);
	Profesor profesor("pepe","ariza","t",0,"w","t","s",false,"w");
	Agenda agenda;
	string usuario, contrasena, dni,op;
	string DNI, nombre, apellidos, direccion, email, fechaNacimiento;
	int telefono, curso, equipo, esLider=1;
	bool lider, variableCorrecta=false, correcto=false;
	int m1, opcion;
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
								menuBuscar(1);
								cout<<"¿Por que campo desea mostrar el/los alumno/os?"<<endl;
								cin>>opcion;
								if(opcion==1){
									cout<<"Indique el DNI"<<endl;
									cin>>dni;
									agenda.mostrarAlumno(dni, "", 0);
								}else if(opcion==2){
									cout<<"Indique el Apellido"<<endl;
									cin>>apellidos;
									agenda.mostrarAlumno("", apellidos, 0);
								}else if(opcion==3){
									cout<<"Indique el Equipo"<<endl;
									cin>>equipo;
									agenda.mostrarAlumno("", "", equipo);
								}
								break;

							case 3:
								while(variableCorrecta==false){
									cout<<"Introduce DNI"<<endl;
									cin>>DNI;
									variableCorrecta= alumno.setDNI(DNI);
								}
								variableCorrecta= false;
								
								cout<<"Introduce Nombre"<<endl;
								cin>>nombre;						
								alumno.setNombre(nombre);
								
								cout<<"Introduce Apellido"<<endl;
								cin>>apellidos;
								alumno.setApellidos(apellidos);
								
								while(variableCorrecta==false){
									cout<<"Introduce Telefono"<<endl;
									cin>>telefono;
									variableCorrecta= alumno.setTelefono(telefono);
								}
								variableCorrecta= false;
								
								cout<<"Introduce Direccion"<<endl;
								cin>>direccion;
								alumno.setDireccion(direccion);
								
								while(variableCorrecta==false){
									cout<<"Introduce Email"<<endl;
									cin>>email;
									variableCorrecta= alumno.setEmail(email);
								}
								variableCorrecta= false;
								
								while(variableCorrecta==false){
									cout<<"Introduce Fecha de Nacimiento"<<endl;
									cin>>fechaNacimiento;
									variableCorrecta= alumno.setFechaNacimiento(fechaNacimiento);
								}
								variableCorrecta= false;
								
								while(variableCorrecta==false){
									cout<<"Introduce el Curso"<<endl;
									cin>>curso;
									variableCorrecta= alumno.setCurso(curso);
								}
								variableCorrecta= false;
								
								while(variableCorrecta==false){
									cout<<"Introduce el equipo"<<endl;
									cin>>equipo;
									variableCorrecta= alumno.setEquipo(equipo);
								}
								
								//while(esLider!=1 && esLider!=2){
									cout<<"¿El alumno es lider de grupo?"<<endl;
									cout<<"1. Si"<<endl;
									cout<<"2. No"<<endl;
									cin>>esLider;
									
									if(esLider==1){
										lider=true;
									}else if(esLider==2){
										lider=false;
									}
								alumno.setLider(lider);
								//}
								agenda.insertarAlumno(alumno);
								break;

							case 4:
								menuBuscar(0);
								cout<<"¿Por que campo desea mostrar el/los alumno/os?"<<endl;
								cin>>opcion;
								if(opcion==1){
									cout<<"Indique el DNI"<<endl;
									cin>>dni;
									agenda.modificarAlumno(dni, "");
								}else if(opcion==2){
									cout<<"Indique el DNI"<<endl;
									cin>>apellidos;
									agenda.modificarAlumno(apellidos, "");
								}
								break;

							case 5:
								menuBuscar(0);
								cout<<"¿Por que campo desea mostrar el/los alumno/os?"<<endl;
								cin>>opcion;
								if(opcion==1){
									cout<<"Indique el DNI"<<endl;
									cin>>dni;
									agenda.borrarAlumno(dni, "");
								}else if(opcion==2){
									cout<<"Indique el DNI"<<endl;
									cin>>apellidos;
									agenda.borrarAlumno(apellidos, "");
								}
								break;

							case 6:
								correcto= profesor.guardarCopia();
								if(correcto==true){
									cout<<"Copia de Seguridad Guardada Correctamente"<<endl;
								}else{
									cout<<"Error al guardar Copia de Seguridad"<<endl;
								}
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

void menuBuscar(int opcion){
	cout<<"----------Elija Criterio----------"<<endl;
	cout<<"\n\t1. DNI"<<endl;
	cout<<"\t2. Apellidos"<<endl;
	if(opcion!=0){
		cout<<"\t3. Equipo"<<endl;
	}
		
}