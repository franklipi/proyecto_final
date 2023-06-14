#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/estructuras.h"	
#include "../Include/menu.h"

int mostrarMenu(void){
	int opx;
	printf("1. Insertar nodo\n");
	printf("2. Buscar nodo\n");
	printf("3. Imprimir arbol\n");
	printf("4. Salir\n");
	printf("Ingrese su opcion: ");
	scanf("%d",&opx);
	
	return opx;
}

int menu(){
	struct nodo* raiz = NULL;
	char user;
	char pass;
	
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
				printf("Nodo encontrado: %d\n", nodoencontrado->user);
				printf("Nodo encontrado: %d\n", nodoencontrado->pass);
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
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción inválida. Por favor, ingrese una opción válida.\n");
			break;
		}
		
		printf("\n");
	} while (opcion != 4);
	
	
	return 0;
}

