#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "persona.h"
#include "funcionesAux.h"

Persona::Persona(string dni, string nombre, string apellidos, int telefono, string direccion, string email, string fechaNacimiento)
{
    dni_ = dni;
    nombre_ = nombre;
    apellidos_ = apellidos;
    telefono_ = telefono;
    direccion_ = direccion;
    email_ = email;
    fechaNacimiento_ = fechaNacimiento;
}

Persona::Persona(){}

/*
Metodo setDNI que comprueba que un dni sea correcto
@param dni
@return true si el dni es correcto y false si no lo es
*/
bool Persona::setDNI(string dni){
    QWidget *parent= new QWidget;
    char cadDni[9];

    strcpy(cadDni, dni.c_str());

    dni[8] = toupper(dni[8]);
    if(strlen(cadDni) != 9){
        QMessageBox::critical(parent, "Title", "El DNI introducido no es correcto");
        return false;
    }
    else{
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        if(letra[atoi(cadDni)%23] == dni[8]){
            dni_=dni;
            return true;
        }else{
            QMessageBox::critical(parent, "Title", "El DNI introducido no es correcto");
            return false;
        }
    }
}

void Persona::setNombre(string nombre){
    nombre_ = nombre;
}

void Persona::setApellidos(string apellidos){
    apellidos_ = apellidos;
}

/*
Metodo setTelefono que comprueba que un telefono sea correcto
@param telefono
@return true si el telefono es correcto y false si no lo es
*/
bool Persona::setTelefono(int telefono){
    QWidget *parent= new QWidget;
    string s = to_string(telefono);
    if(s.size()==9){

        telefono_ = atoi(s.c_str());
        return true;
    }
    else{
        QMessageBox::critical(parent, "Title", "El Telefono introducido no es correcto");
        return false;
    }
}

void Persona::setDireccion(string direccion){
    direccion_ = direccion;
}

/*
Metodo setEmail que comprueba que un email sea correcto
@param email
@return true si el email es correcto y false si no lo es
*/
bool Persona::setEmail(string email){
    QWidget *parent= new QWidget;
    bool correcto = true;

    size_t at = email.find('@'); //Busca dentro de la cadena un "@"
    if(at == string::npos){
        correcto = false;
    }

    size_t dot = email.find('.', at+1); //Busca dentro de la cadena un "."
    if(dot == string::npos){
        correcto = false;
    }

    if(correcto==true){
        email_ = email;
        return true;
    }
    else{
         QMessageBox::critical(parent, "Title", "El Email introducido no es correcto");
        return false;
    }
}

/*
Metodo setFechaNacimiento que comprueba que un fechaNacimiento sea correcta
@param fecha_nacimiento
@return true si la fechaNacimiento es correcta y false si no lo es
*/
bool Persona::setFechaNacimiento(string fecha_nacimiento){
    bool correcto=true;
    QWidget *parent= new QWidget;
    char linea[10];
    strcpy(linea, fecha_nacimiento.c_str());
    unsigned d, m, a;
    bool correctoM = false, correctoD = false;

    strcpy(linea, fecha_nacimiento.c_str());
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

    if(correcto==true){
        fechaNacimiento_ = fecha_nacimiento;
        return true;
    }
    else{
         QMessageBox::critical(parent, "Title", "La Fecha introducida no es correcta. Debe usar el formato dd/MM/aaaa");
        return false;
    }
}
