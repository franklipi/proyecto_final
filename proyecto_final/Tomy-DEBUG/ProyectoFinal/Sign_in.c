#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "verificar_datos.h"
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#include "login.h"
#include "Sign_in.h" 


int Sign_in(struct nodo *raiz, const char* path){
	
	fflush(stdin);
	char* user = (char*)malloc(27 * sizeof(char));
	char* pass = (char*)malloc(27 * sizeof(char));
	int op;
	
	printf("\t\tCreacion de usuario\n\n"); 
	
	//const struct nodo* user_actual;
	printf("Ingrese el nuevo usuario: "); user = validarUser();
	printf("Ingrese su contraseña: ");    pass = validarPass();
	
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		
		printf("El usuario ya existe Desea iniciar sesion?\t\n1-si\n2-no\n");
		do{
			scanf("%i",&op);
		}while(op != 1 && op != 2);
		
		if(op == 1){
			login(raiz,path);
		}
		
		return 1;
	}else{
		InsertarNuevo(path,user,pass);
		return 0;
	}
	
}
	
