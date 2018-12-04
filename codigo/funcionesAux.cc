#include <iostream>
#include "funcionesAux.h"

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
	else{
		aux = "No Lider";
	}
	return aux;
}

bool convertirStringLider(char *lider){
	bool aux;
	
	if(lider=="Lider"){
		aux=true;
	}else{
		aux=false;
	}
	return aux;
}


void modificarDatos(struct RegistroAlumno *alumno){
	string auxStr;
	char dni[10];
	int op,auxNum;
	cout<<"Escoger opcion a modificar: "<<endl;
	cout<<"1. DNI"<<endl;
	cout<<"2. Nombre"<<endl;
	cout<<"3. Apellidos"<<endl;
	cout<<"4. Telefono"<<endl;
	cout<<"5. Direccion"<<endl;
	cout<<"6. Email"<<endl;
	cout<<"7. Fecha de Nacimiento"<<endl;
	cout<<"8. Curso"<<endl;
	cout<<"9. Equipo"<<endl;
	cout<<"10. Lider"<<endl;
	cin>>op;
	switch(op){
		case 1:
			cout<<"Introduce DNI: "<<endl;
			cin>>auxStr;
			strcpy(alumno->dni,auxStr.c_str());
		break;
		case 2:
			cout<<"Introduce Nombre: "<<endl;
			cin.getline(auxStr,100);
			strcpy(alumno->nombre,auxStr.c_str());
		break;
		case 3:
			cout<<"Introduce Apellidos: "<<endl;
			cin.getline(auxStr,100);
			strcpy(alumno->apellidos,auxStr.c_str());
		break;
		case 4:
			cout<<"Introduce Telefono: "<<endl;
			cin>>auxNum;
			alumno->telefono = auxNum;
		break;
		case 5:
			cout<<"Introduce Direccion: "<<endl;
			cin.getline(auxStr,100);
			strcpy(alumno->direccion,auxStr.c_str());
		break;
		case 6:
			cout<<"Introduce Email: "<<endl;
			cin>>auxStr;
			strcpy(alumno->email,auxStr.c_str());
		break;
		case 7:
			cout<<"Introduce Fecha de nacimiento: "<<endl;
			cin>>auxStr;
			strcpy(alumno->fechaNacimiento,auxStr.c_str());
		break;
		case 8:
			cout<<"Introduce Curso: "<<endl;
			cin>>auxNum;
			(*alumno).curso = auxNum;
		break;
		case 9:
			cout<<"Introduce Equipo: "<<endl;
			cin>>auxNum;
			(*alumno).equipo = auxNum;
		break;
		case 10:
			cout<<"¿Lider o No Lider?: "<<endl;
			cin>>auxStr;
			strcpy(alumno->lider,auxStr.c_str());
		break;	
		default:
			cout<<"Opcion no valida."<<endl;
	}
}