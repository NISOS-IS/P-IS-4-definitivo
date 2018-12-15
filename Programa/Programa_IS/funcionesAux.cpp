/*Archivo funcionesAux.cc que contiene funciones auxiliares usadas por el programa*/
#include <iostream>
#include<limits>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcionesAux.h"
#include "agenda.h"
#include "profesor.h"

using namespace std;

/*
Funcion comprobarExistenciaDNI que comprueba si un dni ya esta guardado en agenda
@param dni
@return bool
*/
bool comprobarExistenciaDNI(string dni){
    bool correcto = false;
    ifstream file("alumnos.bin", ios::in | ios::binary);
    RegistroAlumno aux;
    bool encontrado = false;
    if(file.is_open()){
        while(!file.eof()){
            file.read(reinterpret_cast <char*>(&aux), sizeof(RegistroAlumno));
            if(aux.dni == dni){
                encontrado = true;
            }
        }
        if(encontrado){
            correcto = true;
        }
        else{
            correcto = false;
        }
    }
    return correcto;
}


/*
Funcion comprobarLider que comprueba si un equipo ya tiene lider asignado
@param list<Alumno>, lider
@return bool
*/
bool comprobarLider(list<Alumno> &aux, bool lider){
    list<Alumno>::iterator i;
    bool encontrado = false;
    for(i = aux.begin(); i != aux.end(); i++){
        if(i->getLider() == lider){
            encontrado = true;
        }
    }
    if(encontrado){
        return true;
    }
    else{
        return false;
    }
}

bool compruebaEmailProfesor(string email){
    bool correcto = false;
       ifstream file("profesores.bin", ios::in | ios::binary);
       Registro aux;
       bool encontrado = false;
       if(file.is_open()){
           while(!file.eof()){
               file.read(reinterpret_cast <char*>(&aux), sizeof(Registro));
               if(aux.email == email){
                   encontrado = true;
               }
           }
           if(encontrado==true){
               correcto = true;
           }
           else{
               correcto = false;
           }
       }
       return correcto;
}

bool compruebaUsuario(string usuario){
    bool correcto = false;
       ifstream file("profesores.bin", ios::in | ios::binary);
       Registro aux;
       bool encontrado = false;
       if(file.is_open()){
           while(!file.eof()){
               file.read(reinterpret_cast <char*>(&aux), sizeof(Registro));
               if(aux.usuario == usuario){
                   encontrado = true;
               }
           }
           if(encontrado==true){
               correcto = true;
           }
           else{
               correcto = false;
           }
       }
       return correcto;
}


/*
Funcion comprobarEmail que comprueba si un email ya esta guardado en la agenda
@param list<Alumno>, email
@return bool
*/
bool comprobarEmail(list<Alumno> &aux, string email){
    list<Alumno>::iterator i;
    bool encontrado = false;

    for(i = aux.begin() ; i != aux.end() ; i++){
        if(i->getEmail() == email){
            encontrado = true;
        }
    }
    if(encontrado){
        return true;
    }
    else{
        return false;
    }
}


/*
Funcion convertirBool que convierte un bool en un string
@param a
@return string
*/
string convertirBool(bool a){
    string aux;
    if(a){
        aux = "Coordinador";
    }
    else{
        aux = "Ayudante";
    }
    return aux;
}


/*
Funcion convertirBool que convierte un bool en un string
@param a
@return string
*/
string convertirBoolLider(bool a){
    string aux;
    if(a==true){
        aux = "Lider";
    }
    else{
        aux = "No lider";
    }
    return aux;
}

/*
Funcion convertirBool que convierte un bool en un string
@param a
@return string
*/
bool convertirStringLider(char *a){
    bool aux=false;
    string cadena;
    cadena= a;

    if(cadena=="Lider"){
        aux=true;
    }else{
        aux=false;
    }
    return aux;
}


/*
Funcion leerlinea que permite la introduccion de cadenas de caracteres con espacios
@param *cad, max
@return int
*/
int leerlinea(char *cad, int max){
    int i=0, c;
    while((i<max-1) && (c = getchar()) != '\n'){
        cad[i] = '\0';
        i++;
    }
    cad[i] = '\0';
    return i;
}

/*
Funcion mayusculas que convierte en mayusculas una cadena
@param cadena
@return string
*/
string mayusculas(string cadena){
    for(int i=0; i<cadena.length(); i++){
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}


/*
Funcion escribeDatos que pide los datos de un alumno
@return void
*/
bool escribirDatos(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, int curso, int equipo, bool lider){
    Alumno alumno;
    Agenda agenda;
    list<Alumno> aux;
    char auxDNI[9];
    QWidget *parent= new QWidget;
    bool funcionCorrecta=false, devuelve=false, encontrado=false, guardar=true;;

    strcpy(auxDNI, dni.c_str());
    auxDNI[8]= toupper(auxDNI[8]);
    dni= auxDNI;
    encontrado= comprobarExistenciaDNI(dni);
    if(encontrado==false){
        if((alumno.setDNI(dni))==false){
            guardar=false;
        }
    }else{
        QMessageBox::critical(parent, "Title", "DNI existente. Introduzca uno distinto");
        guardar=false;
    }

    nombre= mayusculas(nombre);
    alumno.setNombre(nombre);

    apellidos= mayusculas(apellidos);
    alumno.setApellidos(apellidos);

   // variableCorrecta=alumno.setTelefono(telefono);
    if(alumno.setTelefono(telefono)==false){
        guardar=false;
    }

    direccion= mayusculas(direccion);
    alumno.setDireccion(direccion);

    aux= agenda.mostrarLista();
    if(aux.empty()){
        if((alumno.setEmail(email))==false){
            guardar=false;
        }
    }else{
        encontrado= comprobarEmail(aux, email);
        if(encontrado==false){
            if((alumno.setEmail(email))==false){
                guardar=false;
            }
        }else{
            guardar=false;
            QMessageBox::critical(parent, "Title", "Ese email ya esta registrado. Introduzca uno distinto");
        }
    }

    if((alumno.setFechaNacimiento(fecha_nacimiento))==false){
        guardar=false;
    }

    if((alumno.setCurso(curso))==false){
        guardar=false;
    }

    if((alumno.setEquipo(equipo))==false){
        guardar=false;
    }

    if(lider==true){
        aux=agenda.buscarAlumno("","",equipo);
        encontrado= comprobarLider(aux, lider);
        if(encontrado==false){
            lider=true;
        }else{
            lider=false;
        }
    }
    alumno.setLider(lider);

    if(guardar==true){
        funcionCorrecta= agenda.insertarAlumno(alumno);
            if(funcionCorrecta==true){
                devuelve= true;
            }else{
                devuelve= false;
            }
    }
    return devuelve;
}

bool modificarDatos(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fechaNacimiento, int curso, int equipo, bool lider){
    Alumno alumno;
    Agenda agenda;
    list<Alumno> aux;
    bool devuelve=false, funcionCorrecta=false, guardar=true, variableCorrecta=false, encontrado;

    alumno.setDNI(dni);
    nombre= mayusculas(nombre);
    alumno.setNombre(nombre);

    apellidos= mayusculas(apellidos);
    alumno.setApellidos(apellidos);

    variableCorrecta=alumno.setTelefono(telefono);
    if(variableCorrecta==false){
        guardar=false;
    }

    direccion= mayusculas(direccion);
    alumno.setDireccion(direccion);

    alumno.setEmail(email);

    if((variableCorrecta= alumno.setFechaNacimiento(fechaNacimiento))==false){
        guardar=false;
    }

    if((variableCorrecta=alumno.setCurso(curso))==false){
        guardar=false;
    }

    if((variableCorrecta=alumno.setEquipo(equipo))==false){
        guardar=false;
    }

    if(lider==true){
        aux=agenda.buscarAlumno("","",equipo);
        encontrado= comprobarLider(aux, lider);
        if(encontrado==false){
            lider=true;
        }else{
            lider=false;
        }
    }
    alumno.setLider(lider);

    if(guardar==true){
        funcionCorrecta= agenda.insertarAlumno(alumno);
            if(funcionCorrecta==true){
                devuelve= true;
            }else{
                devuelve= false;
            }
    }
    return devuelve;
}

/*
Funcion mostrarListado que muestra el listado de todos los alumnos en el registro
@return void
*/
void mostrarListado(){
    Agenda agenda;
    list<Alumno> aux = agenda.mostrarLista();
    aux.clear();
}


/*
Funcion ActualizaFicheroInicio que crea un fichero con el usuario y contraseña de los profesores
@param RegUsu (struct)
return bool
*/
bool ActualizarFicheroInicio(RegUsu reg){
    ofstream file("iniciosesion.bin", ios::out | ios::binary | ios::app);

    if(file.is_open()){
        file.write((char*)&reg, sizeof(RegUsu));
        file.close();
        return true;
    }
    else{
        return false;
    }
}
