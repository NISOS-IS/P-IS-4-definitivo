#include <iostream>
#include <stdio.h>
#include <string.h>
#include "funcionesAux.h"
#include "agenda.h"

using namespace std;

string convertirBool(bool a){
	string aux;
	if(a==true){
		aux = "Coordinador";
	}
	else{
		aux = "Ayudante";
	}
	return aux;
}

string convertirBoolLider(bool a){
	string aux;
	if(a==true){
		aux = "Lider";
	}
	else if(a==false){
		aux = "No Lider";
	}
	return aux;
}

bool convertirStringLider(char *lider){
	bool aux=false;

	if(lider=="Lider"){
		aux=false;
	}else{
		aux=true;
	}
	return aux;
}

int leerlinea(char *cad,int max){
  int i=0,c;
  while((i<max-1) && ((c = getchar()) != '\n')){
    cad[i] = c;
    i++;
  }
  cad[i] = '\0';
  return i;
}

void escribirDatos(){
	Alumno alumno("","","",0,"","","",0,0,false);
	Agenda agenda;
	list<Alumno> aux;
	char auxCad[100];
	string DNI, nombre, apellidos, direccion, email, fechaNacimiento;
	int telefono, curso, equipo, esLider=1;
	bool lider, variableCorrecta=false,encontrado=false, funcionCorrecta=false;

	while(variableCorrecta==false || encontrado==true){
		cout<<"Introduce DNI"<<endl;
		cin>>DNI;
		encontrado= agenda.comprobarExistenciaDNI(DNI);
		if(encontrado==false){
			variableCorrecta= alumno.setDNI(DNI);
		}else{
			cout<<"DNI existente. Introduzca uno distinto"<<endl;
		}
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

	while(variableCorrecta==false || encontrado==true){
		cout<<"Introduce Email"<<endl;
		cin>>email;
		aux= agenda.mostrarLista();
		encontrado= agenda.comprobarEmail(aux, email);
		if(encontrado==false){
			variableCorrecta= alumno.setEmail(email);
			}else{
				cout<<"Ese email ya esta registrado. Introduzca uno distinto"<<endl;
			}
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
	variableCorrecta=false;

	do{
		cout<<"¿El alumno es lider de grupo?"<<endl;
		cout<<"1. Si"<<endl;
		cout<<"2. No"<<endl;
		cin>>esLider;
				
		if(esLider==1){
			lider=true;
			aux=agenda.buscarAlumno("","",equipo);
			encontrado= agenda.comprobarLider(aux, lider);
		
			if(encontrado==true){
				lider=false;
			}else{
				lider=true;
			}
		}else if(esLider==2){
			lider=false;
		}else{
			cout<<"Debe introducir 1 o 2"<<endl;
		}
		alumno.setLider(lider);	
		}while(esLider!=1 && esLider!=2 && isdigit(esLider));
		funcionCorrecta= agenda.insertarAlumno(alumno);
		if(funcionCorrecta=true){
			cout<<"Alumno Guardado"<<endl;
		}else{
			cout<<"Fallo al Guardar Alumno"<<endl;
		}
}

void modificarDatos(struct RegistroAlumno *alumno){
	string auxStr;
	char auxCad[100];
	char dni[10];
	int op,auxNum;
	cout<<"Escoger opcion a modificar: "<<endl;
	cout<<"1. Nombre"<<endl;
	cout<<"2. Apellidos"<<endl;
	cout<<"3. Telefono"<<endl;
	cout<<"4. Direccion"<<endl;
	cout<<"5. Fecha de Nacimiento"<<endl;
	cout<<"6. Curso"<<endl;
	cout<<"7. Equipo"<<endl;
	cout<<"8. Lider"<<endl;
	cout<<"9. Salir"<<endl;
	cin>>op;
	getchar();
	switch(op){
		case 1:
			cout<<"Introduce Nombre: "<<endl;
			leerlinea(auxCad,100);
			strcpy(alumno->nombre,auxCad);
		break;
		case 2:
			cout<<"Introduce Apellidos: "<<endl;
			leerlinea(auxCad,100);
			strcpy(alumno->apellidos,auxCad);
		break;
		case 3:
			cout<<"Introduce Telefono: "<<endl;
			cin>>auxNum;
			alumno->telefono = auxNum;
		break;
		case 4:
			cout<<"Introduce Direccion: "<<endl;
			leerlinea(auxCad,100);
			strcpy(alumno->direccion,auxCad);
		break;
		case 5:
			cout<<"Introduce Fecha de nacimiento: "<<endl;
			cin>>auxStr;
			strcpy(alumno->fechaNacimiento,auxStr.c_str());
		break;
		case 6:
			cout<<"Introduce Curso: "<<endl;
			cin>>auxNum;
			(*alumno).curso = auxNum;
		break;
		case 7:
			cout<<"Introduce Equipo: "<<endl;
			cin>>auxNum;
			(*alumno).equipo = auxNum;
		break;
		case 8:
			cout<<"¿Lider o No Lider?: "<<endl;
			cin>>auxStr;
			strcpy(alumno->lider,auxStr.c_str());
		break;
		case 9:
			cout<<"Saliendo...\n"<<endl;
		break;
		default:
			cout<<"Opcion no valida."<<endl;
	}
}