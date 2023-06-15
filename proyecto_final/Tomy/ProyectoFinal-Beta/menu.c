#include <stdio.h>
#include "menu.h"
int mostrarMenu(){
	
	int opx;
	printf("1. Iniciar Sesion\n");
	printf("2. Crear un usuario\n");
	printf("3. Salir\n");
	do{
		printf("Ingrese su opcion: ");scanf("%d",&opx);
		
	}while(opx != 1 || opx !=2 || opx != 3);
	
	return opx;
}
