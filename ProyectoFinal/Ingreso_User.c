#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga_datos.h"
#include "gestion_arbol.h" 
#include "Ingreso_User.h"
#include "Registro_User.h"  
#include "Menu_Usuario.h"
#define Max_Caracteres 20
int login(struct nodo *raiz,const char* path){
	
	
	
	
	char* user = (char*)malloc(27 * sizeof(char));
	//char* pass = (char*)malloc(27 * sizeof(char));
	char pass[Max_Caracteres + 1];
	int i = 0;
	char ch;
	char op;
	raiz = precarga(raiz,path);
	
	
	//const struct nodo* user_actual;
	
	system("cls");
	fflush(stdin);
	printf("\n\n");
	printf("\t\t\t\t\t         F.I.O\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\t\t\t\t\t    Ingreso al sistema\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\n");
	
	
	printf("Ingrese el usuario: ");   scanf("%26s",user);
	printf("Ingrese su contraseña: ");
	
	while ((ch = getch()) != '\r') {  // Obtener caracteres sin mostrarlos en pantalla
		if (ch == '\b') {  // Si se presiona la tecla de retroceso (backspace)
			if (i > 0) {
				i--;
				printf("\b \b");  // Borrar el último caracter mostrado en pantalla
			}
		} else if (i < Max_Caracteres) {
			pass[i++] = ch;
			printf("*");  // Mostrar un asterisco en lugar del caracter
		}
	}
	printf("\n");
	pass[i] = '\0';  // Agregar el carácter nulo al final de la cadena de contraseña
	

	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
		system("cls");
		printf("Inicio exitoso...\n");
		
		Menu_Usuario(raiz,nodoEncontrado);
		
		return 1;
	} else {
		printf("El usuario no existe...Desea Crear Usuario?\t\n1-Si\n2-No\n\n");
		fflush(stdin);
		do{
			printf("\nOpcion Ingresada: ");scanf("%c",&op);
		}while(op != '1' && op != '2');
		
		
		if(op == '1'){
			Sign_in(raiz,path);
		}else{
			printf("\nError...Credenciales incorrectas.\n");
		}
		return 0;
		
	}
}
	
