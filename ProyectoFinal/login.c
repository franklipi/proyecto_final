
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_arbol.h" 
#include "login.h"
#include "Menu_Usuario.h"
#include "Sign_in.h" 


int login(struct nodo *raiz,const char* path){
	
	
	system("cls");
	fflush(stdin);
	
	char* user = (char*)malloc(27 * sizeof(char));
	char* pass = (char*)malloc(27 * sizeof(char));
	int op;
	//const struct nodo* user_actual;
	
	
	printf("Ingrese el usuario: ");   scanf("%26s",user);
	printf("Ingrese su contraseña: ");scanf("%26s",pass);
	
	
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		
		printf("Inicio exitoso.\n");
		
		//user_actual=nodoEncontrado;
		//Menu_Usuario(raiz,user,path);
		Menu_Usuario(raiz,nodoEncontrado);
		
		return 1;
	} else {
		printf("El usuario no existe...Desea Crear Usuario?\t\n1-si\n2-no");
		
		do{
			scanf("%i",&op);
		}while(op != 1 && op != 2);
		
		
		if(op == 1){
			Sign_in(raiz,path);
		}else{
			printf("Error...Credenciales incorrectas.\n");
		}
		return 0;
		
	}
}
	
