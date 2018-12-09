/*Archivo agenda.cc que contiene todas las funciones relativas a la clase Agenda*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "agenda.h"
#include "funcionesAux.h"

//Constructor de la clase Agenda vacío
Agenda::Agenda(){}

/*
Funcion buscarAlumno que busca un alumno en la agenda
@param dni, apel, equipo
@return list<Alumno>
*/
list<Alumno> Agenda::buscarAlumno(string dni, string apel, int equipo){
    ifstream file("agenda.bin", ios::in | ios::binary);
    Alumno aux("","","",0,"","","",0,0,false);
    RegistroAlumno alumnoAux;
    string apellido;
    bool encontrado = false;
    if(file.is_open()){
        while(!file.eof()){
            file.read(reinterpret_cast <char*> (&alumnoAux), sizeof(RegistroAlumno));
            apellido = alumnoAux.apellidos;
            //Si apel es una cadena vacia y equipo 0, realiza la busqueda por dni
            if(apel=="" && equipo==0){
                if(alumnoAux.dni == dni){
                    encontrado = true;
                }
            }
            //Si dni es una cadena vacia y equipo 0, realiza la busqueda por apellido
            if(dni == "" && equipo==0){
                //comprueba si apellido tiene apel
                if(apellido.find(apel) != string::npos){
                    encontrado = true;
                }
            }
            //Si dni y apel son cadenas vacias, realiza la busqueda por equipo
            if(dni=="" && apel==""){
                if(alumnoAux.equipo == equipo){
                    encontrado = true;
                }
            }
            
            if(encontrado){
                aux.setDNI(alumnoAux.dni);
                aux.setNombre(alumnoAux.nombre);
                aux.setApellidos(alumnoAux.apellidos);
                aux.setTelefono(alumnoAux.telefono);
                aux.setDireccion(alumnoAux.direccion);
                aux.setEmail(alumnoAux.email);
                aux.setFechaNacimiento(alumnoAux.fechaNacimiento);
                aux.setCurso(alumnoAux.curso);
                aux.setEquipo(alumnoAux.equipo);
                aux.setLider(convertirStringLider(alumnoAux.lider));
                listaAlumnos_.push_back(aux);
            }
        }
    }
    return listaAlumnos_;
}


/*
Funcion insertarAlumno que inserta a un nuevo alumno en la agenda
@param alumno(Alumno)
@return bool
*/
bool Agenda::insertarAlumno(Alumno alumno){
    bool correcto = false;
	ofstream file("agenda.bin", ios::out | ios::binary | ios::app);
	RegistroAlumno reg;
	
	if(file.is_open()){
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
	    correcto = true;
	}
	return correcto;
}


/*
Funcion borrarAlumno que borra a un alumno de la agenda por DNI o por apellidos
@param dni, apellidos
@return bool
*/
bool Agenda::borrarAlumno(string dni, string apellidos){
	int j, cont = 0, esp = 0, resp = 0, tam;
	char auxStr[100];
	list<Alumno> al;
	RegistroAlumno alumno;
	
	//Limpia las list creadas para no repetir la información a mostrar
	al.clear();
	listaAlumnos_.clear();
	
	ifstream in;
	ofstream out;
	bool encontrado = false;
	al = buscarAlumno(dni, apellidos, 0);
	
	//Comprueba si el parámetro apellidos tiene uno solo o los dos
	if(apellidos != " "){
	    tam = apellidos.size();
	    for(int i = 0; i < tam; i++){
	        if(apellidos[i] == ' '){
	            esp = 1;
	        }
	    }
	}
	
	if(al.empty()){
	    return false;
	}
	else{
	    in.open("agenda.bin", ios::in | ios::binary);
	    out.open("temporal.bin", ios::out | ios::binary);
	    
	    //En caso de que el parámetro apellidos tenga uno solo volverá a pedir que se introduzca los apellidos completos
	    if((esp == 0) && (apellidos != " ")){
	        cout<<"Introduce los apellidos del alumno: "<<endl;
	        leerlinea(auxStr, 100);
	        apellidos = auxStr;
	        apellidos = mayusculas(apellidos);
	    }
	    
	    //mostrarAlumno()
	    
	    //Preguntará al profesor si quiere eliminar el alumno buscado
	    if(encontrado){
	        cout<<"¿Está seguro de querer eliminar los datos del alumno?"<<endl;
	        cout<<"1. Si"<<endl;
	        cout<<"2. No"<<endl;
	        cin>>resp;
	        getchar();
	    }
	    
	    //En caso afirmativo procedera a actualizar la agenda
	    if(resp == 1){
	        if(in.is_open() && out.is_open()){
	            //Lectura y escritura de la agenda para su actualización
	            in.seekg(0, ios::end);
	            j = in.tellg() / sizeof(RegistroAlumno);
	            in.seekg(0*sizeof(RegistroAlumno));
	            
	            in.read((char*)&alumno, sizeof(RegistroAlumno));
	            do{
	                string aux1(alumno.dni), aux2(alumno.apellidos);
	                if((aux1 != dni) && (aux2 != apellidos)){
	                    out.write((char*)&alumno, sizeof(RegistroAlumno));
	                }
	                in.read((char*)&alumno, sizeof(RegistroAlumno));
	                cont++;
	            }while(cont < j);
	            in.close();
	            out.close();
	            remove("agenda.bin");
	            rename("temporal.bin", "agenda.bin");
	        }
	        else{
	            cout<<"No se pudo abrir el fichero"<<endl;
	            return false;
	        }
	    }
	    else{
	        in.close();
	        out.close();
	        remove("temporal.bin");
	        cout<<"Saliendo..."<<endl;
	    }
	    return true;
	}
}


/*
Método modificarAlumno que modifica algunos datos de un alummno
@param dni, apellidos
@return bool
*/
bool Agenda::modificarAlumno(string dni, string apellidos){
	listaAlumnos_.clear();
	int i=0, j=0, cont=0, esp=0, equipo, resp=0;
	char auxStr[100], esLider[9];
    strcpy(esLider, "Lider");
    ifstream in;
    ofstream out;
    list<Alumno> alumno;
    RegistroAlumno reg;
    bool encontrado = false, lider = false, lid = true;
    
    alumno = buscarAlumno(dni, apellidos, 0);
    //Saber si en el parámetro apellidos están ambos apellidos o uno solo
    if(apellidos != " "){
        j = apellidos.size();
        for(int i=0; i<j; i++){
            if(apellidos[i] == ' '){
                esp = 1;
            }
        }
    }
    
    if(alumno.empty()){
        return false;
    }
    else{
        in.open("agenda.bin", ios::in | ios::binary);
        out.open("temporal.bin", ios::out | ios::binary | ios::app);
        
        if(in.is_open() && out.is_open()){
            //Comprobar si el equipo tiene lider
            lider = true;
            alumno = buscarAlumno("", "", equipo);
            lider = comprobarLider(alumno, lider);
            
            //En caso de que el parámetro apellidos tenga un solo apellido volvera a pedir que se introduzca los apellidos completos
            if((apellidos != "") && (esp == 0)){
                cout<<"Introduzca los apellidos del alumno: "<<endl;
                leerlinea(auxStr, 100);
                apellidos = auxStr;
                apellidos = mayusculas(apellidos);
            }
            
            //Apertura lectura y escritura de ficheros para la modificación de registros
            in.seekg(0, ios::end);
            j = in.tellg() / sizeof(RegistroAlumno);
            in.seekg(0*sizeof(RegistroAlumno));
            
            in.read((char*)&reg, sizeof(RegistroAlumno));
            do{
                string aux1(reg.dni), aux2(reg.apellidos);
                if((dni == aux1) || (apellidos == aux2)){
                    //Se haran tantas modificaciones mientras se cumpla la condicion while, para un mismo alumno
                    do{
                        modificarDatos(&reg, lider);
                        cout<<"¿Desea continuar modificando datos?"<<endl;
                        cout<<"1. Si"<<endl;
                        cout<<"2. No"<<endl;
                        cin>>resp;
                        getchar();
                    }while(resp != 2);
                }
                out.write((char*)&reg, sizeof(RegistroAlumno));
                in.read((char*)&reg, sizeof(RegistroAlumno));
                i++;
                cont++;
            }while(cont < j);
        }
        in.close();
        out.close();
        remove("agenda.bin");
        rename("temporal.bin", "agenda.bin");
        alumno.clear();
        return true;
    }
}


/*
Método mostrarLista que introducirá en una list<Alumno> todos los alumos del registro
@return list<Alumno>
*/
list<Alumno> Agenda::mostrarLista(){
	int j, cont=0;
	ifstream in("agenda.bin", ios::in | ios::binary);
	RegistroAlumno al;
	list<Alumno> alumno;
	alumno.clear();
	Alumno aux("","","",0,"","","",0,0,false);
	
	if(in.is_open()){
	    in.seekg(0, ios::end);
	    j = in.tellg() / sizeof(RegistroAlumno);
	    in.seekg(0*sizeof(RegistroAlumno));
	    
	    //Lee todo el registro y los introduce en un objeto de clase Alumno, y el objeto estará en un list<Alumno>
	    in.read((char*)&al, sizeof(RegistroAlumno));
	    do{
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
	        in.read((char*)&al, sizeof(RegistroAlumno));
	        cont++;
	    }while(cont < j);
	    in.close();
	}
	return alumno;
}

list<Alumno> Agenda::mostrarAlumno(string dni, string apellidos, int equipo){
	list<Alumno> aux = buscarAlumno(dni, apellidos, equipo);
	for(list<Alumno>::iterator it = aux.begin(); it != aux.end(); it++){
        cout<<"DNI: "<<it->getDNI()<<endl;
        cout<<"Nombre: "<<it->getNombre()<<endl;
        cout<<"Apellidos: "<<it->getApellidos()<<endl;
        cout<<"Telefono: "<<it->getTelefono()<<endl;
        cout<<"Direccion: "<<it->getDireccion()<<endl;
        cout<<"Email: "<<it->getEmail()<<endl;
        cout<<"Fecha de Nacimiento: "<<it->getFechaNacimiento()<<endl;
        cout<<"Curso: "<<it->getCurso()<<endl;
        cout<<"Equipo: "<<it->getEquipo()<<endl;
        cout<<"Lider: "<<convertirBoolLider(it->getLider())<<"\n"<<endl;
	}
	return aux;
}
