#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga_datos.h"
#include "gestion_arbol.h" 
#include "Ingreso_User.h"
#include "Registro_User.h"  
#include "Menu_Usuario.h"
int login(struct nodo *raiz,const char* path){
	
	
	
	
	char* user = (char*)malloc(27 * sizeof(char));
	char* pass = (char*)malloc(27 * sizeof(char));
	char op;
	raiz = precarga(raiz,path);
	
	
	//const struct nodo* user_actual;
	
	system("cls");
	fflush(stdin);
	printf("\n\n");
	printf("\t\t\t          F.I.O\n");
	printf("\t\t\t------------------------\n");
	printf("\t\t\t    Ingreso al sistema\n");
	printf("\t\t\t------------------------\n");
	printf("\n");
	
	
	printf("Ingrese el usuario: ");   scanf("%26s",user);
	printf("Ingrese su contraseña: ");scanf("%26s",pass);
	

	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		
		printf("Inicio exitoso.\n");
		
		raiz = precarga(raiz,path);
		nodoEncontrado = buscarnodo(raiz, user);
		Menu_Usuario(raiz,nodoEncontrado);
		
		return 1;
	} else {
		printf("El usuario no existe...Desea Crear Usuario?\t\n1-si\n2-no\n\n");
		fflush(stdin);
		do{
			printf("Opcion Ingresada: ");scanf("%c",&op);
		}while(op != '1' && op != '2');
		
		
		if(op == '1'){
			Sign_in(raiz,path);
		}else{
			printf("Error...Credenciales incorrectas.\n");
		}
		return 0;
		
	}
}
	
