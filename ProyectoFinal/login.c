
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_arbol.h" 
#include "verificar_datos.h"



int login(struct nodo *raiz,const char *user,const char *pass,const char* path){
	//const struct nodo* user_actual;
	printf("Ingrese el usuario: "); 
	user = validarUser();
	printf("Ingrese su contraseña: ");
	pass = validarPass();
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		
		printf("Inicio exitoso.\n");
		//user_actual=nodoEncontrado;
		//Menu_Usuario(raiz,user,path);
		return 1;
	} else {
		printf("Error...Credenciales incorrectas.\n");
		return 0;
		
	}

}
	
