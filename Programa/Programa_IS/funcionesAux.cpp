/*Archivo funcionesAux.cc que contiene funciones auxiliares usadas por el programa*/
#include <iostream>
#include<limits>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcionesAux.h"
#include "agenda.h"

using namespace std;

/*
Funcion comprobarExistenciaDNI que comprueba si un dni ya esta guardado en agenda
@param dni
@return bool
*/
bool comprobarExistenciaDNI(string dni){
    bool correcto = false;
    ifstream file("agenda.bin", ios::in | ios::binary);
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
    if(a){
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
    bool aux;
    if(a == "Lider"){
        aux = true;
    }
    else{
        aux = false;
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
Funcion letraDNI que calcula la letra correpondiente del dni
@param dni
@return char
*/
/*char letraDNI(int dni){
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letra[dni%23];
}



Funcion verificaDNI que comprueba que un dni es correcto
@param dni
@return short

short verificaDNI(char *dni){
    dni[8] = toupper(dni[8]);
    if(strlen(dni) != 9){
        return 0;
    }
    else{
        return (letraDNI(atoi(dni)) == dni [8]);
    }
}*/

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



/*
Funcion modificarDatos muestra al profesor las opciones que habra para modificar los datos del alumno
@param *alumno, lider
@return void
*/
void modificarDatos(struct RegistroAlumno *alumno, bool lider){
    string auxStr;
    char auxCad[100];
    char dni[10];
    int op, auxNum;

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
            leerlinea(auxCad, 100);
            auxStr = auxCad;
            auxStr = mayusculas(auxStr);
            strcpy(auxCad, auxStr.c_str());
            strcpy(alumno->nombre, auxCad);
            break;

        case 2:
            cout<<"Introduce Apellidos: "<<endl;
            leerlinea(auxCad, 100);
            auxStr = auxCad;
            auxStr = mayusculas(auxStr);
            strcpy(auxCad, auxStr.c_str());
            strcpy(alumno->apellidos, auxCad);
            break;

        case 3:
            cout<<"Introduce Telefono: "<<endl;
            cin>>auxNum;
            alumno->telefono = auxNum;
            break;

        case 4:
            cout<<"Introduce Direccion: "<<endl;
            leerlinea(auxCad, 100);
            auxStr = auxCad;
            auxStr = mayusculas(auxStr);
            strcpy(auxCad, auxStr.c_str());
            strcpy(alumno->direccion, auxCad);
            break;

        case 5:
            cout<<"Introduce Fecha Nacimiento: "<<endl;
            cin>>auxStr;
            strcpy(alumno->fechaNacimiento, auxStr.c_str());
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
            if(((lider == true) && (strcmp(alumno->lider, "Lider")==0)) || (lider == false)){
                cout<<"¿Lider o No Lider?"<<endl;
                cout<<"1. Si"<<endl;
                cout<<"2. No"<<endl;
                cin>>auxNum;

                if(auxNum == 1){
                    strcpy(alumno->lider, "Lider");
                }
                else if(auxNum == 2){
                    strcpy(alumno->lider, "No Lider");
                }
                getchar();
            }
            else{
                cout<<"Ya existe un lider en este equipo"<<endl;
            }
            break;

        case 9:
            cout<<"Saliendo..."<<endl;
            break;

        default:
            cout<<"Opcion no valida"<<endl;

    }
}

/*
Funcion mostrarListado que muestra el listado de todos los alumnos en el registro
@return void
*/
void mostrarListado(){
    Agenda agenda;
    list<Alumno> aux = agenda.mostrarLista();
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
    aux.clear();
}


/*

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


/*

*/
bool comprobarUsuario(RegUsu reg){
    ifstream file("iniciosesion.bin", ios::in | ios::binary);
    RegUsu aux;
    bool encontrado=false;

    if(file.is_open()){
        file.read((char*)&aux, sizeof(RegUsu));
        if(aux.usuario == reg.usuario){
            if(aux.contrasena == reg.contrasena){
                encontrado = true;
            }
        }
        file.close();
    }
    return encontrado;
}
