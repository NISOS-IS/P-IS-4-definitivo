#include <iostream>
#include "funcionesAux.h"

using namespace std;

string convertirBool(bool a){
	string aux;
	if(a==true){
		aux = "Coordinador";
	}
	else{
		aux = "Ayudante";
	}
	return aux;
}

string convertirBoolLider(bool a){
	string aux;
	if(a==true){
		aux = "Lider";
	}
	else{
		aux = "No Lider";
	}
	return aux;
}

bool convertirStringLider(char *lider){
	bool aux;
	
	if(lider=="Lider"){
		aux=true;
	}else{
		aux=false;
	}
	return aux;
}