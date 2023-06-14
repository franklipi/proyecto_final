#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "estructuras.h"	
#include "menu.h"
#include "archivo.h"	



int main(int argc, char *argv[]){
	struct nodo* raiz = NULL;
	char *path = "login.txt";
	carga(path);
	
	char user[26];
	char pass[26];
	int opcion;
	
	do {
		
		opcion = mostrarMenu();
		switch (opcion) {
		case 1:
			printf("Ingrese el usuario: ");
			scanf("%s", user);
			printf("Ingrese La contraseña: ");
			scanf("%s", pass);
			raiz = insertarnodo(raiz, user, pass);
			printf("Nodo insertado exitosamente.\n");
			break;
			
		case 2:
			
			printf("Ingrese el usuario: ");
			scanf("%s", user);
			struct nodo* nodoencontrado = buscarnodo(raiz, user);
			if (nodoencontrado != NULL) {
				printf("Nodo encontrado: %s\n", nodoencontrado->user);
				printf("Nodo encontrado: %s\n", nodoencontrado->pass);
			} else {
				printf("Nodo no encontrado.\n");
			}
			break;
		case 3:
			printf("Arbol binario: ");
			imprimirarbol(raiz);
			printf("\n");
			break;
		case 4:
			raiz=eliminarnodo(raiz,user,pass);
		case 5:
			printf("Registro: \n");
			printf("Ingrese el usuario: ");
			scanf("%s", user);
			printf("Ingrese La contraseña: ");
			scanf("%s", pass);
			
			
			
			break;
			
			
		case 6:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción inválida. Por favor, ingrese una opción válida.\n");
			break;
		}
		
		printf("\n");
	} while (opcion != 6);
	
	return 0;
}

