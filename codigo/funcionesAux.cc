/*Archivo funcionesAux.cc que contiene funciones auxiliares usadas por el programa*/

#include <iostream>
#include <limits>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include "agenda.h"
#include "funcionesAux.h"

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
char letraDNI(int dni){
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letra[dni%23];
}


/*
Funcion verificaDNI que comprueba que un dni es correcto
@param dni
@return short
*/
short verificaDNI(char *dni){
    dni[8] = toupper(dni[8]);
    if(strlen(dni) != 9){
        return 0;
    }
    else{
        return (letraDNI(atoi(dni)) == dni [8]);
    }
}


/*
Funcion compruebaFecha que comprueba si una fecha es correcta
@param fecha
@return bool
*/
bool compruebaFecha(string fecha){
    char linea[10];
    strcpy(linea, fecha.c_str());
    unsigned d, m, a;
    bool correcto = true, correctoM = false, correctoD = false;
    
    strcpy(linea, fecha.c_str());
    if(linea == NULL){
        return EXIT_FAILURE;
    }
    //Comprueba que el formato de la fecha sea correcto, es decir, dd/mm/aaaa
    if(sscanf(linea, "%2u/%2u/%4u", &d, &m, &a) == 3){
        //Comprueba que el dia no sea menor de 1 ni mayor de 31
        if(d >= 1 && d <= 31){
            correctoD = true;
        }
        else{
            correctoD = false;
        }
        
        //Comprueba que el mes no sea menor de 1 ni mayor de 12
        if(m >= 1 && m <= 12){
            correctoM = true;
        }
        else{
            correctoM = false;
        }
    }
    else{
        correcto = false;
    }
    
    if(correcto && correctoD && correctoM){
        correcto = true;
    }
    else{
        correcto = false;
    }
    return correcto;
}


/*
Funcion validarEmail que comprueba que un email tenga el formato correcto
@param email
@return bool
*/
bool validarEmail(string email){
    bool correcto = true;
    
    size_t at = email.find('@'); //Busca dentro de la cadena un "@"
    if(at == string::npos){
        correcto = false;
    }
    
    size_t dot = email.find('.', at+1); //Busca dentro de la cadena un "."
    if(dot == string::npos){
        correcto = false;
    }
    
    return correcto;
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
void escribirDatos(){
    Alumno alumno("","","",0,"","","",0,0,false);
    Agenda agenda;
    list<Alumno> aux;
    char auxDNI[9], auxCad[100], nombreC[100], apellidosC[100], direccionC[100];
    string DNI, nombre, apellidos, direccion, email, fechaNacimiento;
    int telefono, curso, equipo, esLider = 1;
    bool lider, variableCorrecta = false, encontrado = false, funcionCorrecta = false;
    
    while(variableCorrecta == false || encontrado == true){
        cout<<"Introduce DNI"<<endl;
        cin>>DNI;
        strcpy(auxDNI, DNI.c_str());
        auxDNI[8] = toupper(auxDNI[8]);
        DNI = auxDNI;
        encontrado = comprobarExistenciaDNI(DNI);
        if(!encontrado){
            variableCorrecta = alumno.setDNI(DNI);
        }
        else{
            cout<<"DNI existente. Introduzca uno distinto"<<endl;
        }
    }
    variableCorrecta = false;
    
    cout<<"Introduce Nombre: "<<endl;
    getchar();
    leerlinea(auxCad, 100);
    nombre = auxCad;
    nombre = mayusculas(nombre);
    alumno.setNombre(nombre);
    
    cout<<"Introduce Apellido: "<<endl;
    leerlinea(auxCad, 100);
    apellidos = auxCad;
    apellidos = mayusculas(apellidos);
    alumno.setApellidos(apellidos);
    
    while(variableCorrecta = false){
        cout<<"Introduce Telefono: "<<endl;
        cin>>telefono;
        while(1){
            //Comprueba que solo se introducen numeros
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Numero de telefono incorrecto"<<endl;
                cin>>telefono;
            }
            if(!cin.fail()){
                variableCorrecta = alumno.setTelefono(telefono);
            }
            break;
        }
    }
    getchar();
    cout<<"Introduce Direccion: "<<endl;
    leerlinea(direccionC, 100);
    direccion = direccionC;
    direccion = mayusculas(direccion);
    alumno.setDireccion(direccion);
    
    variableCorrecta = false;
    
    while(variableCorrecta == false || encontrado == true){
        cout<<"Introduce Email"<<endl;
        cin>>email;
        aux = agenda.mostrarLista();
        encontrado = comprobarEmail(aux, email);
        if(encontrado == false){
            variableCorrecta = alumno.setEmail(email);
        }
        else{
            cout<<"Ese email ya está registrado. Introduzca uno distinto"<<endl;
        }
    }
    variableCorrecta = false;
    
    while(variableCorrecta == false){
        cout<<"Introduce Fecha de Nacimiento en formato dd/mm/aaaa"<<endl;
        cin>>fechaNacimiento;
        variableCorrecta = alumno.setFechaNacimiento(fechaNacimiento);
    }
    variableCorrecta = false;
    
    while(variableCorrecta == false){
        cout<<"Introduce Curso: "<<endl;
        cin>>curso;
        while(1){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Debe introducir el numero del Curso: "<<endl;
                cin>>curso;
            }
            if(!cin.fail()){
                variableCorrecta = alumno.setCurso(curso);
            }
            break;
        }
    }
    variableCorrecta = false;
    
    while(variableCorrecta == false){
        cout<<"Introduce Equipo: "<<endl;
        cin>>equipo;
        while(1){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Debe introducir el numero del Equipo: "<<endl;
                cin>>curso;
            }
            if(!cin.fail()){
                variableCorrecta = alumno.setEquipo(equipo);
            }
            break;
        }
    }
    variableCorrecta = false;
    
    do{
        cout<<"¿El alumno es lider de grupo?"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. No"<<endl;
        cin>>esLider;
            while(1){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Debe introducir el numero 1 o 2"<<endl;
                    cin>>esLider;
                }
                if(!cin.fail()){
                    if(esLider == 1){
                        lider = true;
                        aux = agenda.buscarAlumno("","",equipo);
                        encontrado = comprobarLider(aux, lider);
                        
                        if(encontrado == false){
                            lider = true;
                        }
                        else{
                            lider = false;
                        }
                    }
                    else if(esLider == 2){
                        lider = false;
                    }
                    else{
                        cout<<"Debe introducir 1 o 2"<<endl;
                    }
                    alumno.setLider(lider);
                }
                break;
            }
    }while(esLider!=1 && esLider!=2);
    funcionCorrecta = agenda.insertarAlumno(alumno);
    if(funcionCorrecta = true){
        cout<<"Alumno Guardado"<<endl;
    }
    else{
        cout<<"Fallo al Guardar Alumno"<<endl;
    }
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
