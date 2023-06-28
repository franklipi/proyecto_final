#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "carga_datos.h"
#include "verificar_datos.h"
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#include "Ingreso_User.h"
#include "Registro_User.h" 


int Sign_in(struct nodo *raiz, const char* path){
	

	char* user = (char*)malloc(27 * sizeof(char));
	char* pass = (char*)malloc(27 * sizeof(char));
	char op; 
	raiz = precarga(raiz,path);
	
	
	
	fflush(stdin);
	system("cls");
	printf("\n\n");
	printf("\t\t\t          F.I.O\n");
	printf("\t\t\t------------------------\n");
	printf("\t\t\t    Creacion de usuario\n");
	printf("\t\t\t------------------------\n");
	printf("\n");
	//const struct nodo* user_actual;
	printf("Ingrese el nuevo usuario: "); user = validarUser();
	printf("Ingrese su contraseña: ");    pass = validarPass();
	
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		fflush(stdin);
		printf("El usuario ya existe Desea iniciar sesion?\t\n1-si\n2-no\n");
		do{
			printf("Opcion Ingresada: ");scanf("%c",&op);
		}while(op != '1' && op != '2');
		
		if(op == '1'){
			login(raiz,path);
		}else if(op == '2'){
			return 0;
		}
		
		return 1;
	}else{
		if((strcmp(nodoEncontrado->user, user)!=0)){
			InsertarNuevo(path,user,pass);
		}
		
		return 0;
	}
	
}
	
