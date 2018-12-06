#include <iostream>
#include<limits>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	string cadena;
	cadena= lider;

	if(cadena=="Lider"){
		aux=true;
	}else{
		aux=false;
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

char letraDNI(int dni){
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

  return letra[dni%23];
}

short verificaDNI(char *dni){
	dni[8]=  toupper(dni[8]);
	if (strlen(dni)!=9)
      	return 0;
	else
    	return (letraDNI(atoi(dni))==dni[8]);
}

bool compruebaFecha(string fecha){
	char linea[10];
	strcpy(linea, fecha.c_str());
	unsigned d;
	unsigned m;
	unsigned a;
	bool correcto=true, correctoM=false, correctoD=false;
   
   strcpy(linea, fecha.c_str());
   if (linea == NULL)
      return EXIT_FAILURE;
   
   if (sscanf(linea, "%2u/%2u/%4u", &d, &m, &a) == 3){
	   if(d>=1 && d<=31){
		   correctoD=true;
	   }else{
		   correctoD=false;
	   }
	   if(m>=1 && m<=12){
		   correctoM=true;
	   }else{
		   correctoM=false;
	   }
	   
   }else{
	   correcto=false;
   }
   
   if(correcto==true && correctoD==true && correctoM==true){
	   correcto=true;
   }else{
		correcto=false;
   }
   return correcto;
}

bool validarEmail(string email){
	bool correcto=true;
	size_t at = email.find('@');
    if (at == string::npos){
        correcto=false;
    }
    size_t dot = email.find('.', at + 1);
    if (dot == string::npos){
        correcto=false;
    }
    return correcto;
}

void escribirDatos(){
	Alumno alumno("","","",0,"","","",0,0,false);
	Agenda agenda;
	list<Alumno> aux;
	char auxDNI[9], auxCad[100], nombreC[100], apellidosC[100], direccionC[100], vTelefono;
	string DNI, nombre, apellidos, direccion, email, fechaNacimiento, vCurso, vEquipo;
	int telefono, curso, equipo, esLider=1;
	bool lider, variableCorrecta=false,encontrado=false, funcionCorrecta=false;
	
	while(variableCorrecta==false || encontrado==true){
		cout<<"Introduce DNI"<<endl;
		cin>>DNI;
		strcpy(auxDNI, DNI.c_str());
		auxDNI[8]=  toupper(auxDNI[8]);
		DNI= auxDNI;
		encontrado= agenda.comprobarExistenciaDNI(DNI);
		if(encontrado==false){
			variableCorrecta= alumno.setDNI(DNI);
		}else{
			cout<<"DNI existente. Introduzca uno distinto"<<endl;
		}
	}
	variableCorrecta= false;
	
	cout<<"Introduce Nombre"<<endl;
	getchar();
	leerlinea(auxCad,100);
	nombre=auxCad;
	alumno.setNombre(nombre);
	
	cout<<"Introduce Apellido"<<endl;
	leerlinea(auxCad,100);
	apellidos=auxCad;
	alumno.setApellidos(apellidos);

	while(variableCorrecta==false){
		cout<<"Introduce Telefono"<<endl;
		cin>>telefono;
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Numero de telefono incorrecto"<<endl;
				cin>>telefono;
			}
			if(!cin.fail()){
				variableCorrecta= alumno.setTelefono(telefono);
			}
			break;
		}
	}
	getchar();
	cout<<"Introduce Direccion"<<endl;
	leerlinea(direccionC,100);
	direccion = direccionC;
	alumno.setDireccion(direccion);

	variableCorrecta= false;

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
		cout<<"Introduce Fecha de Nacimiento en formato dd/mm/aaaa"<<endl;											
		cin>>fechaNacimiento;
		variableCorrecta= alumno.setFechaNacimiento(fechaNacimiento);
	}
	variableCorrecta= false;

	while(variableCorrecta==false){		
		cout<<"Introduce el Curso"<<endl;
		cin>>curso;
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Debe introducir el numero del Curso"<<endl;
				cin>>curso;
			}
			if(!cin.fail()){
				variableCorrecta= alumno.setCurso(curso);
			}
			break;
		}
		
	}
	variableCorrecta= false;

	while(variableCorrecta==false){
		cout<<"Introduce el equipo"<<endl;
		cin>>equipo;
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Debe introducir un numero del equipo"<<endl;
				cin>>equipo;
			}
			if(!cin.fail()){
				variableCorrecta= alumno.setEquipo(equipo);
			}
			break;
		}
	}
	variableCorrecta=false;

	do{
		cout<<"¿El alumno es lider de grupo?"<<endl;
		cout<<"1. Si"<<endl;
		cout<<"2. No"<<endl;
		cin>>esLider;
			while(1){
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Debe introducir el numero 1 o 2"<<endl;
					cin>>esLider;
				}
				if(!cin.fail()){
									
					if(esLider==1){
						lider=true;
						aux=agenda.buscarAlumno("","",equipo);
						encontrado= agenda.comprobarLider(aux, lider);
					
						if(encontrado==false){
							lider=true;
						}else{
							lider=false;
						}
					}else if(esLider==2){
						lider=false;
					}else{
						cout<<"Debe introducir 1 o 2"<<endl;
					}
					alumno.setLider(lider);	
				}
				break;
			}
	}while(esLider!=1 && esLider!=2);
		funcionCorrecta= agenda.insertarAlumno(alumno);
		if(funcionCorrecta=true){
			cout<<"Alumno Guardado"<<endl;
		}else{
			cout<<"Fallo al Guardar Alumno"<<endl;
		}
}

void modificarDatos(struct RegistroAlumno *alumno,bool lider){
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
			if(((lider==true) && (strcmp(alumno->lider,"Lider")==0)) || (lider == false)){
				cout<<"¿Lider o No Lider?: "<<endl;
				cout<<"1. Lider\n2. No lider"<<endl;
				cin>>auxNum;
				if(auxNum == 1){
					strcpy(alumno->lider,"Lider");
				}else if(auxNum == 2){
					strcpy(alumno->lider,"No Lider");
					cout<<"Lider==="<<alumno->lider<<endl;
				}
				getchar();
			}else
				cout<<"Ya existe un lider en este equipo."<<endl;

		break;
		case 9:
			cout<<"Saliendo...\n"<<endl;
		break;
		default:
			cout<<"Opcion no valida."<<endl;
	}
}

void mostrarListado(){
	Agenda agenda;
	list<Alumno>aux = agenda.mostrarLista();
	for (list<Alumno>::iterator it = aux.begin();it != aux.end(); it++){
		cout<<"DNI: \t\t\t"<<it->getDNI()<<endl;
		cout<<"Nombre: \t\t"<<it->getNombre()<<endl;
		cout<<"Apellidos:\t\t"<<it->getApellidos()<<endl;
		cout<<"Telefono: \t\t"<<it->getTelefono()<<endl;
		cout<<"Direccion: \t\t"<<it->getDireccion()<<endl;
		cout<<"Email: \t\t\t"<<it->getEmail()<<endl;
		cout<<"Fecha de nacimiento: \t"<<it->getFechaNacimiento()<<endl;
		cout<<"Curso: \t\t\t"<<it->getCurso()<<endl;
		cout<<"Equipo: \t\t"<<it->getEquipo()<<endl;
		cout<<"Lider: \t\t\t"<<convertirBoolLider(it->getLider())<<endl;		
		cout<<endl;
	}
	aux.clear();
}

bool liderPorEquipo(int equipo){
	int j,cont=0;
	RegistroAlumno alumno;
	ifstream in;
	in.open("agenda.bin", ios::in | ios::binary);
	
	if(in.is_open()){
		in.seekg(0,ios::end);
		j = in.tellg()/sizeof(RegistroAlumno);
		in.seekg(0*sizeof(RegistroAlumno));

		in.read((char *)&alumno,sizeof(RegistroAlumno));
		while(cont < j){
			if(alumno.equipo == equipo){
				if(strcmp(alumno.lider,"Lider") == 0){
					return true;
				}
			}
			in.read((char *)&alumno,sizeof(RegistroAlumno));
			cont++;
		}
		in.close();
	}else{
		cout<<"No se pudo abrir el fichero para comprobar si el equipo tiene lider."<<endl;
	}
	return false;
}