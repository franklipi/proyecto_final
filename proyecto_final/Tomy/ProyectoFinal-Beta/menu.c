#include <stdio.h>
#include "menu.h"
int mostrarMenu(){
	int opx;
	printf("1. Insertar nodo\n");
	printf("2. Buscar nodo\n");
	printf("3. Imprimir arbol\n");
	printf("4. Eliminarnodo\n");
	printf("5. Registro\n");
	printf("6. Salir\n");
	printf("Ingrese su opcion: ");scanf("%d",&opx);
	
	return opx;
}


