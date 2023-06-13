#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/estructuras.h"	

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

int main(){
	struct nodo* raiz = NULL;
	int opcion;
	int valor;
	
	do {
		
		opcion = mostrarMenu();
		switch (opcion) {
		case 1:
			printf("Ingrese el valor del nodo: ");
			scanf("%d", &valor);
			raiz = insertarnodo(raiz, valor);
			printf("Nodo insertado exitosamente.\n");
			break;
		case 2:
			printf("Ingrese el valor a buscar: ");
			scanf("%d", &valor);
			struct nodo* nodoencontrado = buscarnodo(raiz, valor);
			if (nodoencontrado != NULL) {
				printf("Nodo encontrado: %d\n", nodoencontrado->dato);
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

