#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#include "carga_datos.h"
#include "menu_principal.h"
#include "login.h"
#include "verificar_datos.h"
#include <windows.h>

int main(int argc, char *argv[]){
	
	//        Definicion de Varibles      //
	//------------------------------------//
	
	
	struct nodo* raiz = NULL;
	char* user;
	char* pass;
	const char *path = "login.txt";
	char op;
	
	
	
	//        Funcion Principal			//						
	//----------------------------------//
	
	do{
		fflush(stdin);
		op = mostrarMenu();
		
		switch (op){
			
		case '1':
			system("cls");
			raiz = precarga(raiz,path);
			
			if(login(raiz,user,pass)){
				printf("Bienvenido");
				//Menuusuario(raiz,path,user);
			}
			
			
			break;
			
		case '2':
			printf("Crear usuario:\n");
			user = validarUser();
			//printf("%s",user);
			pass = validarPass();
			//printf("%s",pass);
			InsertarNuevo(path,user,pass);
			break;
			
		case '3':
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
	} while (op != '3');
	
	return 0;
}


