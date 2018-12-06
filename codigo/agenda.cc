#include "funcionesAux.h"
#include "agenda.h"
#include <iostream>
#include <fstream>
#include <cstring>

Agenda::Agenda(){}

list<Alumno> Agenda::buscarAlumno(string dni, string apel, int equipo){
ifstream file("agenda.bin", ios::in | ios::binary);
	Alumno aux("","","",0,"","","",0,0,false);
	RegistroAlumno alumnoAux;
	bool encontrado = false;
	string dni1, nombre, apellido, direccion, email, fechaNacimiento;
	if(file.is_open()){
		while(!file.eof()){
			file.read(reinterpret_cast <char *> (&alumnoAux), sizeof(RegistroAlumno));
			apellido = alumnoAux.apellidos;
			if(apel=="" && equipo==0){
				if(alumnoAux.dni == dni){
					encontrado = true;
				}
			}else if(dni=="" && equipo==0){
				if(apellido.find(apel) != string::npos){
					encontrado=true;
				}
			}else if(dni=="" && apel==""){
				if(alumnoAux.equipo==equipo){
					encontrado=true;
				}
			}
			if(encontrado){
					dni1=alumnoAux.dni;
					aux.setDNI(dni1);
					nombre=alumnoAux.nombre;
					aux.setNombre(nombre);
					apellido=alumnoAux.apellidos;
					aux.setApellidos(apellido);
					aux.setTelefono(alumnoAux.telefono);
					direccion= alumnoAux.direccion;
					aux.setDireccion(direccion);
					email= alumnoAux.email;
					aux.setEmail(email);
					fechaNacimiento= alumnoAux.fechaNacimiento;
					aux.setFechaNacimiento(fechaNacimiento);
					aux.setCurso(alumnoAux.curso);
					aux.setEquipo(alumnoAux.equipo);
					aux.setLider(convertirStringLider(alumnoAux.lider));
					listaAlumnos_.push_back(aux);
			}else{
			}
			
		}
	}

	return listaAlumnos_;
}

bool Agenda::insertarAlumno(Alumno alumno){
	ofstream file("agenda.bin", ios::out | ios::binary | ios::app);
	RegistroAlumno reg;
	strcpy(reg.dni,alumno.getDNI().c_str());
	strcpy(reg.nombre,alumno.getNombre().c_str());
    strcpy(reg.apellidos,alumno.getApellidos().c_str());
    reg.telefono=alumno.getTelefono();
    strcpy(reg.direccion, alumno.getDireccion().c_str());
    strcpy(reg.email, alumno.getEmail().c_str());
    strcpy(reg.fechaNacimiento,alumno.getFechaNacimiento().c_str());
	reg.curso=alumno.getCurso();
	reg.equipo=alumno.getEquipo();
	strcpy(reg.lider,convertirBoolLider(alumno.getLider()).c_str());
	file.write((char *) &reg, sizeof(RegistroAlumno));
	file.close();
	
	return true;
}

/* borrar el alumno indicado ya sea por dni o apellidos */
bool Agenda::borrarAlumno(string dni, string apellidos){
	int j,cont=0,esp=0,resp=0,tam;
	char auxStr[100];
	list<Alumno> al;
	//limpia las list creadas para no repetir la informacion a mostrar
	al.clear();
	listaAlumnos_.clear();
	RegistroAlumno alumno;
	ifstream in;
	ofstream out;
	bool encontrado = false;
	al = buscarAlumno(dni,apellidos,0);
	
	/*Comprueba si el parametros apellidos tiene los apellidos
	o uno solo
	*/
	if(apellidos != ""){
		tam=apellidos.size();
		for (int i = 0; i < tam; i++){
			if(apellidos[i] == ' ')esp = 1;
		}
	}

	if(al.empty()){
		cout<<"No entro"<<endl;
		return false;
	}else{
		in.open("agenda.bin", ios::in | ios::binary);
		out.open("temporal.bin", ios::out | ios::binary);

		/* En caso de que el parametro apellidos tenga un solo apellido
		volvera a pedir que se introduzca los apellidos completo.
		*/
		if((esp == 0) && (apellidos != "")){
			cout<<"Introduce los apellidos del alumno: "<<endl;
			leerlinea(auxStr,100);
			apellidos = auxStr;
			apellidos= mayusculas(apellidos);
		}

		/*Muestra por pantalla los datos del alumno
		 a eliminar*/
		for (list<Alumno>::iterator it = al.begin(); it != al.end(); it++){
			if((dni == it->getDNI()) || (apellidos == it->getApellidos())){
				cout<<"Nombre: \t\t"<<it->getNombre()<<endl;
				cout<<"Apellidos:\t\t"<<it->getApellidos()<<endl;
				cout<<"Telefono: \t\t"<<it->getTelefono()<<endl;
				cout<<"Direccion: \t\t"<<it->getDireccion()<<endl;
				cout<<"Fecha de nacimiento: \t"<<it->getFechaNacimiento()<<endl;
				cout<<"Curso: \t\t\t"<<it->getCurso()<<endl;
				cout<<"Equipo: \t\t"<<it->getEquipo()<<endl;
				cout<<"Lider: \t\t\t"<<convertirBoolLider(it->getLider())<<"\n"<<endl;
				encontrado = true;
			}
		}

		/* Preguntara al profesor si quiere eliminar el registro del alumno*/
		if(encontrado){
			cout<<"¿Está seguro de querer eliminar los datos del alumno?"<<endl;
			cout<<"1. Si\n2. No"<<endl;
			cin>>resp;
			getchar();
		}
		/*En caso afirmativo procedera a actualizar la agenda */
		if(resp == 1){
			if(in.is_open() && out.is_open()){

				/*Lectura y escritura de la agenda para su actualizacion */
				in.seekg(0,ios::end);
				j = in.tellg()/sizeof(RegistroAlumno);
				in.seekg(0*sizeof(RegistroAlumno));

				in.read((char *)&alumno,sizeof(RegistroAlumno));
				while(cont < j){
					string aux1(alumno.dni),aux2(alumno.apellidos);
					if((aux1 != dni) && (aux2 != apellidos)){
						out.write((char *)&alumno,sizeof(RegistroAlumno));
					}
					in.read((char *)&alumno,sizeof(RegistroAlumno));
					cont++;
				}
				in.close();
				out.close();
				remove("agenda.bin");
				rename("temporal.bin","agenda.bin");
			}else{
				cout<<"No se pudo abrir el fichero."<<endl;
				return false;
			}
		}else{
			in.close();
			out.close();
			remove("temporal.bin");
			cout<<"Saliendo..."<<endl;
		}
		return true;
	}
}

bool Agenda::modificarAlumno(string dni, string apellidos){
	listaAlumnos_.clear();
	int i=0,j=0,cont=0,esp=0,equipo,resp=0;
	char auxStr[100],esLider[9];
	strcpy(esLider,"Lider");
	ifstream in;
	ofstream out;
	list<Alumno> alumno;
	RegistroAlumno reg;
	bool encontrado = false,lider=false,lid=true;

	alumno = buscarAlumno(dni,apellidos,0);
	//Saber si en el parametro apellidos estan ambos apellidos o uno solo
	if(apellidos != ""){
		j=apellidos.size();
		for (int i = 0; i < j; ++i){
			if(apellidos[i] == ' ')esp = 1;
		}
	}

	if(alumno.empty()){
		return false;
	}else{
		in.open("agenda.bin", ios::in | ios::binary);
		out.open("temporal.bin", ios::out | ios::binary | ios::app);

		if(in.is_open() && out.is_open()){

			/* Mostrar los alumnos que se van a modificar los datos */
			for (list<Alumno>::iterator it = alumno.begin(); it != alumno.end(); it++){
				if((dni == it->getDNI()) || (apellidos == it->getApellidos())){
					cout<<"Nombre: \t\t"<<it->getNombre()<<endl;
					cout<<"Apellidos:\t\t"<<it->getApellidos()<<endl;
					cout<<"Telefono: \t\t"<<it->getTelefono()<<endl;
					cout<<"Direccion: \t\t"<<it->getDireccion()<<endl;
					cout<<"Fecha de nacimiento: \t"<<it->getFechaNacimiento()<<endl;
					cout<<"Curso: \t\t\t"<<it->getCurso()<<endl;
					cout<<"Equipo: \t\t"<<it->getEquipo()<<endl;
					cout<<"Lider: \t\t\t"<<convertirBoolLider(it->getLider())<<"\n"<<endl;
					equipo = it->getEquipo();
					//lid=it->getLider();
				}
			}

			/* Comprobar si el equipo tiene lider */
			/*********************************************/
			//lider = liderPorEquipo(equipo);
			lider=true;
			alumno = buscarAlumno("","",equipo);
			lider = comprobarLider(alumno,lider);
			/*********************************************/

			/* 
			En caso de que el parametro apellidos tenga un solo apellido
			volvera a pedir que se introduzca los apellidos completo.
			*/
			if((apellidos != "") && (esp == 0)){
				cout<<"Introduzca los apellidos del alumno: "<<endl;
				leerlinea(auxStr,100);
				apellidos = auxStr;
				apellidos= mayusculas(apellidos);
			}

			/* Apertura lectura y escritura de ficheros para la 
			modificacion de registros */
			in.seekg(0,ios::end);
			j = in.tellg()/sizeof(RegistroAlumno);
			in.seekg(0*sizeof(RegistroAlumno));

			in.read((char*)&reg,sizeof(RegistroAlumno));
			while(cont < j){

				string aux1(reg.dni),aux2(reg.apellidos);
				if((dni == aux1) || (apellidos == aux2)){
					/* se haran tantas modificaciones mientras
					se cumpla la condicion while, para un mismo alumno
					*/
					while(resp != 2){
						modificarDatos(&reg,lider);
						cout<<"¿Desea continuar modificando datos?"<<endl;
						cout<<"1. Si\n2. No"<<endl;
						cin>>resp;
						getchar();
					}
				}

				out.write((char*)&reg,sizeof(RegistroAlumno));
				in.read((char*)&reg,sizeof(RegistroAlumno));
				i++;
				cont++;
			}
		}
		in.close();
		out.close();
		remove("agenda.bin");
		rename("temporal.bin","agenda.bin");
		alumno.clear();
		return true;
	}
}

/* Introducira en un list todos los alumnos del registro 
para su utilizacion proxima a mostrar el listado*/
list<Alumno> Agenda::mostrarLista(){
	int j,cont=0;
	ifstream in;
	in.open("agenda.bin",ios::in | ios::binary);
	RegistroAlumno al;
	list<Alumno> alumno;
	alumno.clear();
	Alumno aux("","","",0,"","","",0,0,false);

	if(in.is_open()){
		in.seekg(0,ios::end);
		j = in.tellg()/sizeof(RegistroAlumno);
		in.seekg(0*sizeof(RegistroAlumno));

		/* Lee todo el registro y los introduce en un objeto
		de clase Alumno, y el objeto estara en un list<Alumno>
		*/
		in.read((char *)&al,sizeof(RegistroAlumno));
		while(cont < j){
			aux.setDNI(al.dni);
			aux.setNombre(al.nombre);
			aux.setApellidos(al.apellidos);
			aux.setTelefono(al.telefono);
			aux.setDireccion(al.direccion);
			aux.setEmail(al.email);
			aux.setFechaNacimiento(al.fechaNacimiento);
			aux.setCurso(al.curso);
			aux.setEquipo(al.equipo);
			aux.setLider(convertirStringLider(al.lider));
			alumno.push_back(aux);
			in.read((char *)&al,sizeof(RegistroAlumno));
			cont++;
		}
		in.close();
	}
	return alumno;
}

list<Alumno> Agenda::mostrarAlumno(string dni, string apellidos, int equipo){
	list<Alumno> aux;
	aux= buscarAlumno(dni, apellidos, equipo);
	return aux;
}
