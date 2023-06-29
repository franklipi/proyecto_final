#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Menu_Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

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

void imprimirCentrado(const char* mensaje, int color) {
	int ancho_pantalla = obtenerAnchoPantalla();
	int mensaje_longitud = strlen(mensaje);
	int margen_izquierdo = (ancho_pantalla - mensaje_longitud) / 2;
	
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
//	clearScreen();
	// Mensaje a imprimir
	//char mensaje;
	// Imprime el mensaje centrado en la pantalla
	
	printf("\n\n");
	/*
	for(int i=0; i<120; i++){
		
		mensaje[i]="-";
	}
	*/
	//imprimirCentrado(mensaje);
	//const char* mensaje = "Este es un mensaje centrado";
	//imprimirCentrado(mensaje);
	clearScreen();
	
	imprimirCentrado("|---------------------------------------------------------------------------------------------|\n",11);
	imprimirCentrado("            _/_/_/_/            _/_/_/             _/_/ ", 9); // Imprimir en rojo
	imprimirCentrado("            _/                    _/             _/    _/", 9); // Imprimir en verde
	imprimirCentrado("           _/_/_/                _/             _/    _/", 9); // Imprimir en amarillo
	imprimirCentrado("          _/                    _/             _/    _/", 9); // Imprimir en azul
	imprimirCentrado("        _/             _/   _/_/_/       _/    _/_/", 9); // Imprimir en cyan
	imprimirCentrado("|---------------------------------------------------------------------------------------------\n",11);
	/*
	for(int i=0; i<120; i++){
		printf("-");
	}
	*/
	
	//printf("---------------------------------------------------------------------------------------------\n");
	//printf("\t\t\t\t\t   Bienvenido a F.I.O\n");
	imprimirCentrado("------------------------\n",12);
	//system("color e0");
	imprimirCentrado("1.Iniciar sesion\n",12);
	imprimirCentrado("2.Crear Usuario Nuevo\n",12);
	//printf("\t\t\t\t\t  99.Modo Administrador\n");
	imprimirCentrado("------------------------\n",12);
	printf("\n");
	//clearScreen();
	
	do{
		printf("Opcion Ingresada: ");scanf("%c",&op);
		if(op != '1' && op != '2' && op != '3' && op != '9' && op != 's'  && op != 'S'){
			puts("Opcion Invalida...Reingrese");
		}
	}while(op != '1' && op != '2' && op != '3' && op != '9' && op != 's'  && op != 'S');
	
	
	
	
	
	return op;
	
}

	
