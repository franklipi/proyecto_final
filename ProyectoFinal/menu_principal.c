#include <stdio.h>
#include <stdlib.h>
#include "Menu_Usuario.h"


char mostrarMenu(){
	fflush(stdin);
	char op;	
	printf("\n\n");
	printf("      				_/_/_/_/            _/_/_/             _/_/\n");
	printf("     				_/                    _/             _/    _/\n");
	printf("     				_/_/_/                _/             _/    _/\n");
	printf("    				_/                    _/             _/    _/\n");
	printf("    				_/             _/   _/_/_/       _/    _/_/\n");
	//printf("\t\t\t\t\t   Bienvenido a F.I.O\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\t\t\t\t\t    1.Iniciar sesion\n");
	printf("\t\t\t\t\t  2.Crear Usuario Nuevo\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\n");
	
	do{
		printf("Opcion Ingresada: ");scanf("%c",&op);
		if(op != '1' && op != '2' && op != '3'){
			puts("Opcion Invalida...Reingrese");
		}
	}while(op != '1' && op != '2' && op != '3');
	
	return op;
	
}
