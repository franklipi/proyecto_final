#include <stdio.h>
#include <stdlib.h>
#include "Menu_Usuario.h"
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int obtenerAnchoPantalla() {
	int ancho_pantalla = 0;
	#ifdef _WIN32
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		ancho_pantalla = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	#else
		ancho_pantalla = sysconf(_SC_COLUMNS);
	#endif
	return ancho_pantalla;
}

void imprimirCentrado(const char* mensaje, int color, int columna) {
	int ancho_pantalla = obtenerAnchoPantalla();
	int mensaje_longitud = strlen(mensaje);
	int margen_izquierdo = columna - mensaje_longitud / 2;
	
	// Cambiar el color del texto
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
#else
	printf("\033[0;%dm", color);
#endif
	
	for (int i = 0; i < margen_izquierdo; i++) {
		printf(" ");
	}
	printf("%s\n", mensaje);
	
	// Restaurar el color del texto
#ifdef _WIN32
	SetConsoleTextAttribute(hConsole, 7); // Color predeterminado
#else
	printf("\033[0m");
#endif
}



char mostrarMenu(){
	fflush(stdin);
	char op;	

	printf("\n\n");

	system("cls");
	
	imprimirCentrado("===============================================\n",14,40);
	imprimirCentrado(" BIENVENIDO A LA RED SOCIAL OFICIAL DE LA UNAM  \n",14,40);
	imprimirCentrado("===============================================\n",14,40);
	
	
	//imprimirCentrado("|================================================================================|\n",14,20);
	imprimirCentrado("  _/_/_/_/            _/_/_/             _/_/ ", 14,40);
	imprimirCentrado("  _/                    _/             _/    _/", 14,40);
	imprimirCentrado("  _/_/_/                _/             _/    _/", 14,40);
	imprimirCentrado("  _/                    _/             _/    _/", 14,40);
	imprimirCentrado(" _/             _/   _/_/_/       _/    _/_/", 14,40);
	imprimirCentrado("|================================================================================|\n",14,20);
	
	printf("=========================\n");
	printf("1.Iniciar sesion\n");
	printf("2.Crear Usuario Nuevo\n");
	printf("S.Salir\n");
	printf("=========================\n");
	printf("\n");
	
	do{
		fflush(stdin);
		//imprimirCentrado("=========================\n",6,30);
		printf("Opcion Ingresada: "); system("color 0e"); scanf("%c",&op);system("color 0e");
		//imprimirCentrado("==============================",6,30);
		
		
		
		if(op != '1' && op != '2' && op != '3' && op != 's'  && op != 'S'){
			puts("Opcion Invalida...Reingrese...\n");system("color 0e");
		}
		
	}while(op != '1' && op != '2' && op != '3' && op != 's'  && op != 'S');
	
	
	
	
	
	return op;
	
}

	
