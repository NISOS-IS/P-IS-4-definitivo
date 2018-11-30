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
	buscarAlumno(dni,apellidos,0);
}

bool Agenda::modificarAlumno(string dni, string apellidos){
	buscarAlumno(dni,apellidos,0);

}

list<Alumno> Agenda::mostrarLista(){
	/*ifstream f("agenda.bin", ios::in | ios::binary);
	f.read((char *) &reg, sizeof(RegistroAlumno));
	while(!f.eof()){
		cout<<reg.dni<<endl;
		cout<<reg.nombre<<endl;
		cout<<reg.apellidos<<endl;
		cout<<reg.telefono<<endl;
		cout<<reg.direccion<<endl;
		cout<<reg.email<<endl;
		cout<<reg.fechaNacimiento<<endl;
		cout<<reg.curso<<endl;
		cout<<reg.equipo<<endl;
		cout<<reg.lider<<endl;
		f.close();
		f.read((char *) &reg, sizeof(RegistroAlumno));
	}*/
}

list<Alumno> Agenda::mostrarAlumno(string dni, string apellidos, int equipo){
	buscarAlumno(dni,apellidos,equipo);
}
