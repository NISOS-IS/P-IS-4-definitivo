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
			if(apel=="" && equipo==0){
				if(alumnoAux.dni == dni){
					encontrado = true;
				}
			}else if(dni=="" && equipo==0){
				if(alumnoAux.apellidos==apel){
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

bool Agenda::comprobarExistenciaDNI(string dni){
	bool correcto=false;
	ifstream file("agenda.bin", ios::in | ios::binary);
	RegistroAlumno aux;
	bool encontrado = false;
	if(file.is_open()){
		
		while(!file.eof()){
			file.read(reinterpret_cast <char *> (&aux), sizeof(RegistroAlumno));
			if(aux.dni == dni){
				encontrado = true;
			}
		}
		if(encontrado){
			correcto= true;
		}
		else{
			correcto= false;
		}
	}
	return correcto;
}

bool Agenda::comprobarLider(list<Alumno> &aux, bool lider){
	list<Alumno>::iterator i;
	bool encontrado=false;
	for(i=aux.begin();i!=aux.end();i++){
		if(i->getLider()==lider){
			encontrado=true;
		}
	}
	if(encontrado==true){
		return true;
	}else{
		return false;
	}
}

bool Agenda::comprobarEmail(list<Alumno> &aux, string email){
	list<Alumno>::iterator i;
	bool encontrado=false;
	
	for(i=aux.begin();i!=aux.end();i++){
		if(i->getEmail()==email){
			encontrado=true;
		}
	}
	if(encontrado){
		return true;
	}else{
		return false;
	}
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

bool Agenda::borrarAlumno(string dni, string apellidos){
	int j,cont=0;
	list<Alumno> al;
	RegistroAlumno alumno;
	ifstream in;
	ofstream out;
	al = buscarAlumno(dni,apellidos,0);

	if(al.empty()){
		return false;
	}else{
		in.open("agenda.bin", ios::in | ios::binary);
		out.open("temporal.bin", ios::out | ios::binary);

		if(in.is_open()){
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

		}else{
			return false;
		}
		in.close();
		out.close();
		remove("agenda.bin");
		rename("temporal.bin","agenda.bin");
		return true;
	}
}

bool Agenda::modificarAlumno(string dni, string apellidos){
	listaAlumnos_.clear();
	int i=0,j=0,cont=0,resp=0,esp=0;
	char auxStr[100];
	ifstream in;
	ofstream out;
	list<Alumno> alumno;
	RegistroAlumno reg;
	bool encontrado = false;

	alumno = buscarAlumno(dni,apellidos,0);
	//Para saber si en el parametro apellidos estan ambos apellidos o uno solo
	if(apellidos != ""){
		for (int i = 0; i < apellidos.size(); ++i){
			if(apellidos[i] == ' ')esp = 1;
		}
	}

	if(alumno.empty()){
		return false;
	}else{
		in.open("agenda.bin", ios::in | ios::binary);
		out.open("temporal.bin", ios::out | ios::binary | ios::app);

		if(in.is_open() && out.is_open()){
			for (list<Alumno>::iterator it = alumno.begin(); it != alumno.end(); it++){
				if((dni == it->getDNI()) || (apellidos == it->getApellidos())){
					cout<<"Nombre: \t\t"<<it->getNombre()<<endl;
					cout<<"Apellidos:\t\t"<<it->getApellidos()<<endl;
					cout<<"Telefono: \t\t"<<it->getTelefono()<<endl;
					cout<<"Direccion: \t\t"<<it->getDireccion()<<endl;
					cout<<"Fecha de nacimiento: \t"<<it->getFechaNacimiento()<<endl;
					cout<<"Curso: \t\t\t"<<it->getCurso()<<endl;
					cout<<"Equipo: \t\t"<<it->getEquipo()<<endl;
					cout<<"Lider: \t\t"<<convertirBoolLider(it->getLider())<<"\n"<<endl;
				}
			}

			if((apellidos != "") && (esp == 0)){
				cout<<"Introduzca los apellidos del alumno: "<<endl;
				leerlinea(auxStr,100);
				apellidos = auxStr;
			}

			in.seekg(0,ios::end);
			j = in.tellg()/sizeof(RegistroAlumno);
			in.seekg(0*sizeof(RegistroAlumno));

			in.read((char*)&reg,sizeof(RegistroAlumno));
			while(!encontrado && (cont < j)){
				string aux1(reg.dni),aux2(reg.apellidos);
				if((dni == aux1) || (apellidos == aux2)){
					while(resp != 2){
						modificarDatos(&reg);
						cout<<"¿Desea continuar modificando datos: ?"<<endl;
						cout<<"1. Si\n2. No"<<endl;
						cin>>resp;
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

list<Alumno> Agenda::mostrarLista(){
	int j,cont=0;
	ifstream in;
	in.open("agenda.bin",ios::in | ios::binary);
	RegistroAlumno al;
	list<Alumno> alumno;
	Alumno aux("","","",0,"","","",0,0,false);

	if(in.is_open()){
		in.seekg(0,ios::end);
		j = in.tellg()/sizeof(RegistroAlumno);
		in.seekg(0*sizeof(RegistroAlumno));

		in.read((char *)&al,sizeof(RegistroAlumno));
		while(cont < j){
			/*cout<<"DNI: "<<al.dni<<endl;
			cout<<"Nombre: "<<al.nombre<<endl;
			cout<<"Apellidos: "<<al.apellidos<<endl;
			cout<<"Telefono: "<<al.telefono<<endl;
			cout<<"Direccion: "<<al.direccion<<endl;
			cout<<"Email: "<<al.email<<endl;
			cout<<"Fecha de nacimiento: "<<al.fechaNacimiento<<endl;
			cout<<"Curso: "<<al.curso<<endl;
			cout<<"Equipo: "<<al.equipo<<endl;
			cout<<"Lider: "<<al.lider<<endl;
			cout<<endl;
			in.read((char *)&al,sizeof(RegistroAlumno));
			*/
			
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
