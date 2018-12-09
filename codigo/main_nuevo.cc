#ifdef __MINGW32__
    #include <windows.h>
    #include <tchar.h>
    #define LIMPIAR "cls"
#endif

#ifdef __linux__
    #include <unistd.h>
    #include <iostream>
    #include <stdlib.h>
    #include <string.h>
    #define LIMPIAR "clear"
#endif

#include <stdio.h>
#include "alumno.h"
#include"profesor.h"
#include"agenda.h"

using namespace std;


void menuprincipal();
void menusecundario();
void criterioBusqueda(int criterio);

int main(){

    Profesor profesor;
    Agenda agenda;
    Alumno alumno("","","",0,"","","",0);
    int op_principal, op_secundario, op_buscar;
    int inicio, iniciar;
    int equipo, telefono, curso, comp_lider, comp_rol;
    bool correcto, lider, rol, ocupado = false;
    string dni, nombre, apellido, direccion, email, fecha_nacimiento, usuario, contrasena;
    list<Alumno> lista;

    do{
        menuprincipal();
        cout<<"\nSeleccione una opción: "<<endl;
        cin>>op_principal;
        system(LIMPIAR);
        switch(op_principal){
            case 1:
                do{
                    cout<<"Usuario:"<<endl;
                    cin>>usuario;
                    cout<<"Contraseña:"<<endl;
                    cin>>contrasena;
                    //Comprobar si el usuario y/o la contraseña son correctas
                    inicio = profesor.login(usuario, contrasena);//Comprobar dentro de login si coinciden el usuario y la contreña con los datos ya almacenados
                    if(!inicio){
                        system(LIMPIAR);
                        cout<<"Usuario o contraseña inválidos."<<endl;
                        cout<<"¿Desea intentarlo otra vez?"<<endl;
                        cout<<"1. Si"<<endl;
                        cout<<"2. No"<<endl;
                        cin>>iniciar;
                    }
                    else{
                        do{
                            system(LIMPIAR);
                            menusecundario();
                            cout<<"\nSeleccione una opción:"<<endl;
                            cin>>op_secundario;
                            system(LIMPIAR);
                            switch(op_secundario){
                                case 1:
                                    lista = agenda.mostrarLista();
                                    break;

                                case 2:
                                    criterioBusqueda(1);
                                    cout<<"Elija un criterio de busqueda: "<<endl;
                                    cin>>op_buscar;
                                    system(LIMPIAR);
                                    switch(op_buscar){
                                        case 1:
                                            cout<<"Indique el DNI:"<<endl;
                                            cin>>dni;
                                            lista = agenda.mostrarAlumno(dni,"",0);
                                            break;
                                        
                                        case 2:
                                            cout<<"Indique el apellido:"<<endl;
                                            cin>>apellido;
                                            lista = agenda.mostrarAlumno("",apellido,0);
                                            break;

                                        case 3:
                                            cout<<"Indique el equipo:"<<endl;
                                            cin>>equipo;
                                            lista = agenda.mostrarAlumno("","",equipo);
                                            break;
                                    }
                                    break;
                                    
                                case 3:
                                    do{
                                        cout<<"Introduce el DNI: "<<endl;
                                        cin>>dni;
                                        correcto = alumno.setDNI(dni);
                                    }while(correcto == false);
                                    
                                    cout<<"Introduce el nombre: "<<endl;
                                    cin>>nombre;
                                    
                                    cout<<"Introduce el apellido: "<<endl;
                                    cin>>apellido;
                                    
                                    do{
                                        cout<<"Introduce el telefono: "<<endl;
                                        cin>>telefono;
                                        correcto = alumno.setTelefono(telefono);
                                    }while(correcto == false);
                                    
                                    cout<<"Introduce la direccion: "<<endl;
                                    cin>>direccion;
                                    
                                    do{
                                        cout<<"Introduce el email: "<<endl;
                                        cin>>email;
                                        correcto = alumno.setEmail(email);
                                    }while(correcto == false);
                                    
                                    do{
                                        cout<<"Introduce la fecha de nacimiento: "<<endl;
                                        cin>>fecha_nacimiento;
                                        correcto = alumno.setFechaNacimiento(fecha_nacimiento);
                                    }while(correcto == false);
                                    
                                    do{
                                        cout<<"Introduce el curso: "<<endl;
                                        cin>>curso;
                                        correcto = alumno.setCurso(curso);
                                    }while(correcto == false);
                                    
                                    do{
                                        cout<<"Introduce el numero del equipo: "<<endl;
                                        cin>>equipo;
                                        correcto = alumno.setEquipo(equipo);
                                    }while(correcto == false);
                                    
                                    cout<<"¿El alumno es lider del grupo?"<<endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl;
                                    cin>>comp_lider;
                                    
                                    if(comp_lider == 1){
                                        lider = true;
                                    }
                                    else if(comp_lider == 2){
                                        lider = false;
                                    }
                                    //comprobarLider();
                                    if(!ocupado){
                                        alumno.setLider(lider);
                                    }
                                    correcto = agenda.insertarAlumno(alumno);
                                    break;
                                    
                                case 4:
                                    criterioBusqueda(0);
                                    cout<<"Elija un criterio de busqueda: "<<endl;
                                    cin>>op_buscar;
                                    system(LIMPIAR);
                                    switch(op_buscar){
                                        case 1:
                                            cout<<"Indique el DNI: "<<endl;
                                            cin>>dni;
                                            correcto = agenda.modificarAlumno(dni,"");
                                            break;
                                            
                                        case 2:
                                            cout<<"Indique el apellido: "<<endl;
                                            cin>>apellido;
                                            correcto = agenda.modificarAlumno("",apellido);
                                            break;
                                    }
                                    break;
                                    
                                case 5:
                                    criterioBusqueda(0);
                                    cout<<"Elija un criterio de busqueda: "<<endl;
                                    cin>>op_buscar;
                                    system(LIMPIAR);
                                    switch(op_buscar){
                                        case 1:
                                            cout<<"Indique el DNI: "<<endl;
                                            cin>>dni;
                                            correcto = agenda.borrarAlumno(dni,"");
                                            break;
                                            
                                        case 2:
                                            cout<<"Indique el apellido: "<<endl;
                                            cin>>apellido;
                                            correcto = agenda.borrarAlumno("",apellido);
                                            break;
                                    }
                                    break;
                                    
                                case 6:
                                    correcto = profesor.guardarCopia();
                                    if(correcto){
                                        cout<<"Copia de Seguridad guardada correctamente"<<endl;
                                    }
                                    else{
                                        cout<<"Error al guardar la copia de seguridad"<<endl;
                                    }
                                    break;
                                    
                                case 7:
                                    correcto = profesor.cargarCopia();
                                    if(correcto){
                                        cout<<"Copia de Seguridad cargada correctamente"<<endl;
                                    }
                                    else{
                                        cout<<"Error al cargar la copia de seguridad"<<endl;
                                    }
                                    break;
                                    
                                case 8:
                                    exit(0);
                                    break;
                                    
                                default:
                                    cout<<"Debe introducir un numero del 1 al 8"<<endl;
                                
                            }
                        }while(op_secundario != 8);
                    }
                }while(iniciar==1 || inicio == true);
                break;
                
            case 2:
                do{
                    cout<<"Introduzca su DNI: "<<endl;
                    cin>>dni;
                    correcto = profesor.setDNI(dni);
                }while(correcto == false);
                
                cout<<"Introduzca su nombre: "<<endl;
                cin>>nombre;
                
                cout<<"Introduzca su apellido: "<<endl;
                cin>>apellido;
                
                do{
                    cout<<"Introduzca su telefono: "<<endl;
                    cin>>telefono;
                    correcto = profesor.setTelefono(telefono);
                }while(correcto == false);
                
                cout<<"Introduzca su direccion: "<<endl;
                cin>>direccion;
                
                do{
                    cout<<"Introduzca su email: "<<endl;
                    cin>>email;
                    correcto = profesor.setEmail(email);
                }while(correcto == false);
                
                do{
                    cout<<"Introduzca su fecha de nacimiento: "<<endl;
                    cin>>fecha_nacimiento;
                    correcto = profesor.setFechaNacimiento(fecha_nacimiento);
                }while(correcto == false);
                
                cout<<"¿Que rol tiene?"<<endl;
                cout<<"1. Coordinador"<<endl;
                cout<<"2. Ayudante"<<endl;
                cin>>comp_rol;
                
                if(comp_rol == 1){
                    rol = true;
                }
                else if(comp_rol == 2){
                    rol = false;
                }
                profesor.setRol(rol);
                
                cout<<"Introduzca su usuario: "<<endl;
                cin>>usuario;
                profesor.setUsuario(usuario);
                
                cout<<"Introduzca su contraseña: "<<endl;
                cin>>contrasena;
                profesor.setContrasena(contrasena);
                
                correcto = profesor.registrarProfesor(profesor);
                system(LIMPIAR);
                cout<<"¿Desea iniciar sesión?"<<endl;
                cout<<"1. Si"<<endl;
                cout<<"2. No"<<endl;
                cin>>iniciar;
                break;
                
            case 3:
                exit(0);
                break;
                
            default:
                cout<<"Debe introducir un numero del 1 al 3"<<endl;
        }
    }while(op_principal != 3);

    return 0;
}

void menuprincipal(){
	cout<<"----------MENU PRINCIPAL----------"<<endl;
	cout<<"\n\t1. Iniciar sesion"<<endl;
	cout<<"\t2. Registrar profesor"<<endl;
	cout<<"\t3. Salir"<<endl;
}

void menusecundario(){
	cout<<"----------MENU----------"<<endl;
	cout<<"\n\t1. Ver el listado de alumnos"<<endl;
	cout<<"\t2. Buscar uno o varios alumnos"<<endl;
	cout<<"\t3. Insertar un alumno"<<endl;
	cout<<"\t4. Modificar a un alumno"<<endl;
	cout<<"\t5. Borrar un alumno"<<endl;
	cout<<"\t6. Guardar copia del listado de alumnos"<<endl;
	cout<<"\t7. Cargar copia del listado de alumnos"<<endl;
	cout<<"\t8. Salir"<<endl;
}

void criterioBusqueda(int criterio){
	cout<<"----------Elija Criterio----------"<<endl;
	cout<<"\n\t1. DNI"<<endl;
	cout<<"\t2. Apellidos"<<endl;
	if(criterio!=0){
		cout<<"\t3. Equipo"<<endl;
	}
		
}
