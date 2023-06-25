#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include "gestion_arbol.h"
#include "menu_principal.h"
#include "login.h"
#include "Sign_in.h" 
#include "gestion_archivo.h"
#include "carga_datos.h"


int main(int argc, char *argv[]){
	
	//        Definicion de Varibles      //
	//------------------------------------//
	
	
	struct nodo* raiz = NULL;
	const char *path = "login.txt";
	char op;
	
	
	//        Funcion Principal			//						
	//----------------------------------//
	
	do{
		fflush(stdin);
		raiz = precarga(raiz,path);
		op = mostrarMenu();
		
		switch (op){
			
		case '1':
			system("cls");
			fflush(stdin);
			login(raiz,path);
			
			break;
		case '2':
			
			system("cls");
			fflush(stdin);
			
			if(!Sign_in(raiz,path)){
				printf("Creacion Exitosa...\n");
			}
			
			break;
		case '3':
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
	} while (op != '3');
	
	return 0;
	
}


