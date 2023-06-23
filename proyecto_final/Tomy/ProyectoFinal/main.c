#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "login.h"
#include "gestion_arbol.h"
#include "menu_principal.h"
#include "gestion_archivo.h"
#include "carga_datos.h"
#include <windows.h>


int main(int argc, char *argv[]){
	
	//        Definicion de Varibles      //
	//------------------------------------//
	
	
	struct nodo* raiz = NULL;
	char * user;
	char * pass;
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
				puts("inicio exitoso");
			}
			
			break;
			
		case '2':
			printf("Crear usuario:\n");
			user = validarUser();
			pass = validarPass();
			
			InsertarNuevo(path, user, pass);
			break;
			
		case '3':
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
	} while (op != '3');
	
	return 0;
}


