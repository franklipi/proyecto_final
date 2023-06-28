
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
	unsigned short int i=0;
	char ch;
	//const struct nodo* user_actual;
	
	
	printf("Ingrese el usuario: ");   
	scanf("%26s",user);
	
	
	printf("Ingrese su contraseña: ");
	while (getchar() != '\n');
	while((ch=getch())!='\r'){
		if (ch == '\b') {  // Si se presiona la tecla de retroceso (backspace)
			if (i > 0) {
				i--;
				printf("\b \b");  // Borrar el último caracter mostrado en pantalla
			}
		} else if (i < 27) {
			pass[i++] = ch;
			printf("*");  // Mostrar un asterisco en lugar del caracter
		}
	}
	
	pass[i] = '\0';
	
	//scanf("%26s",pass);
	
	
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		
		printf("\nInicio exitoso.\n");
		
		//user_actual=nodoEncontrado;
		//Menu_Usuario(raiz,user,path);
		Menu_Usuario(raiz,nodoEncontrado);
		
		return 1;
	} else {
		printf("\nEl usuario no existe...Desea Crear Usuario?\t\n1-si\n2-no");
		
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
	
