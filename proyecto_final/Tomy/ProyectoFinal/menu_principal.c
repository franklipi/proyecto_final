#include <stdio.h>
#include <stdlib.h>
#include "Menu_Usuario.h"


char mostrarMenu(){
	
	char op;
	
	printf("Bienvenido\n\t1.Iniciar sesion\n\t2.Crear Usuario Nuevo\n\t");
	
	do{
		printf("Opcion Ingresada: ");scanf("%c",&op);
		if(op != '1' && op != '2' && op != '3'){
			puts("Opcion Invalida...Reingrese");
		}
	}while(op != '1' && op != '2' && op != '3');
	
	
	return op;
	
}
