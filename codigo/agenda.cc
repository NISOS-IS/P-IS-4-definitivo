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

bool Agenda::insertarAlumno(Alumno alumno){
	ofstream file("agenda.bin", ios::out | ios::binary);
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
	int i=0,op,auxNum,j,cont=0,resp=0;
	list<Alumno> al;
	RegistroAlumno alumno,auxReg;
	fstream file;
	al = buscarAlumno(dni,apellidos,0);
	string auxStr;
	bool found=false;

	if(al.empty()){
		return false;
	}else{
		file.open("agenda.bin", ios::in | ios::out | ios::binary);

		if(file.is_open()){

			file.seekg(0,ios::end);
			j = file.tellg()/sizeof(RegistroAlumno);
			file.seekg(0*sizeof(RegistroAlumno));

			file.read((char*)&alumno,sizeof(RegistroAlumno));
			while(!found && (cont < j)){
				
				string aux1(alumno.dni),aux2(alumno.apellidos);
				if((dni == aux1) || (apellidos == aux2)){
					/*PEDIR LOS DATOS A MODIFICAR*/
					while(resp != 2){
						modificarDatos(&alumno);
						cout<<"Desea continuar modificando datos: "<<endl;
						cout<<"1. Si\n2. No"<<endl;
						cin>>resp;
					}
					/**/
					file.seekp(i*sizeof(RegistroAlumno));
					/*APLICA EL PROCESO DE MODIFICACION*/
					file.write((char*)&alumno,sizeof(RegistroAlumno));
					found = true;
				}
				i++;
				cont++;
				file.read((char*)&alumno,sizeof(RegistroAlumno));
			}
		}
		file.close();
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
	buscarAlumno(dni,apellidos,equipo);
}
