
/*Archivo profesor.cc que contiene las funciones de la clase Profesor*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "profesor.h"
#include "funcionesAux.h"

using namespace std;

Profesor::Profesor(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fecha_nacimiento, bool rol, string contrasena):Persona(dni, nombre, apellidos, telefono, direccion, email, fecha_nacimiento){
    rol_ = rol;
    contrasena_ =contrasena;
}

Profesor::Profesor():Persona(){}


/*
Método setContrasena que comprueba que una contraseña sea correcta
@param contrasena(string)
@return bool
*/
void Profesor::setContrasena(string contrasena){
    if(contrasena.size()>=4){
        contrasena_ = contrasena;
    }
    else{
        cout<<"La contraseña debe tener 4 carácteres o más"<<endl;
    }
}

void Profesor::setUsuario(string usuario){
    usuario_ = usuario;
}

void Profesor::setRol(bool rol){
    rol_ = rol;
}

bool Profesor::buscaProfesor(string dni){
    ifstream file("profesores.bin", ios::in | ios::binary);
    Profesor aux("","","",0,"","","",false,"");
    bool encontrado = false;
    if(file.is_open()){
        while(!file.eof()){
            file.read(reinterpret_cast<char *> (&aux), sizeof(Profesor));
            if(aux.getDNI() == dni){
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
    else{
        cout<<"El profesor con DNI <"<<dni<<"> no está registrado."<<endl;
        return false;
    }
}

bool Profesor::registrarProfesor(Profesor profesor){
    ofstream file("profesores.bin", ios::out | ios::binary | ios::app);
    Registro reg;

    if(file.is_open()){
        strcpy(reg.dni,profesor.getDNI().c_str());
        strcpy(reg.nombre,profesor.getNombre().c_str());
        strcpy(reg.apellidos,profesor.getApellidos().c_str());
        reg.telefono=profesor.getTelefono();
        strcpy(reg.direccion,profesor.getDireccion().c_str());
        strcpy(reg.email,profesor.getEmail().c_str());
        strcpy(reg.fechaNacimiento,profesor.getFechaNacimiento().c_str());
        strcpy(reg.rol,convertirBool(profesor.getRol()).c_str());
        strcpy(reg.usuario,profesor.getUsuario().c_str());
        strcpy(reg.contrasena,profesor.getContrasena().c_str());
        file.write((char *) &reg, sizeof(Registro));
        file.close();
        return true;
    }
    else{
        return false;
    }
}

bool Profesor::login(string usuario, string contrasena){
    ifstream file("usuarios.bin", ios::in | ios::binary);
    bool correcto = false, encontrado = false;
    RegUsu aux;
    if(file.is_open()){
        while(!file.eof()){
            file.read((char*) &aux, sizeof(RegUsu));
            if(aux.usuario == usuario){
                encontrado = true;
            }
        }
        if(encontrado){
            if(aux.contrasena == contrasena){
                cout<<"SESIÓN INICIADA"<<endl;
                correcto = true;
            }
            else{
                cout<<"Usuario o contrasena incorrectos"<<endl;
                correcto = false;
            }
        }
        file.close();
    }
    return correcto;
}


/*
Método cargarCopia carga la copia de seguridad del fichero de la agenda
@return bool
*/
bool Profesor::cargarCopia(){
    int cont = 0, asig;
    ifstream in;
    ofstream out;
    RegistroAlumno alumno;

    in.open("copiaSeguridad.bin", ios::in | ios::binary);
    out.open("temporal.bin", ios::out | ios::binary);

    if(in.is_open() && out.is_open()){
        in.seekg(0, ios::end);
        asig = in.tellg() / sizeof(RegistroAlumno);
        in.seekg(0*sizeof(RegistroAlumno));

        in.read((char*)&alumno, sizeof(RegistroAlumno));
        do{
            out.write((char*)&alumno, sizeof(RegistroAlumno));
            in.read((char*)&alumno, sizeof(RegistroAlumno));
            cont++;
        }while(cont < asig);

        in.close();
        out.close();
        remove("agenda.bin");
        rename("temporal.bin", "agenda.bin");
        return true;
    }
    else{
        cout<<"NO se pudo crear el fichero de copia"<<endl;
        return false;
    }
}


/*
Método guardarCopia que realiza una copia de seguridad de agenda
@return bool
*/
bool Profesor::guardarCopia(){
    int lon;
    ifstream fe;
    bool correcto = false;
    //Creamos otro archivo donde se copiara
    fe.open("agenda.bin");
    ofstream fs("copiaSeguridad.bin");
    // Miramos cual es el tamaño del archivo
    if(fe.fail()){
        correcto = false;
    }else{
        fe.seekg (0, ios::end);
        lon = fe.tellg();
        fe.seekg (0, ios::beg);
        //Creamos una cadena de caracteres con el tamaño del archivo
        char* cadena = new char [lon];
        memset( cadena , 0 , lon );
        //Leemos el archivo y se guarda en la cadena
        fe.read(cadena,lon);
        if(fs.eof()){
            correcto = false;
        }
        else{
            fs.write(cadena,lon);
            correcto = true;
        }
    }

    fs.close();
    fe.close();

    return correcto;
}
