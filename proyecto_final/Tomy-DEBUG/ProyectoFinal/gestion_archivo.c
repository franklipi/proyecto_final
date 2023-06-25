
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#define Max_lines 100


int crearArch(const char *path){
	
	FILE* arch = fopen(path, "w");
	
	if (arch == NULL) {
		printf("Eror en base de datos...No hay espacio disponible.\n");
		return 0;
	}else{
		return 1;
	}
	
	fclose(arch);

}

void InsertarNuevo(const char *path, const char user[], const char pass[]){
	
	
	FILE* arch = fopen(path, "a");
	
	// Escribir el texto en el archivo
	fprintf(arch, "%s,%s\n", user,pass);
	
	
	
	fclose(arch);

}

void ordenarUsers(const char* path) {
	FILE* arch = fopen(path, "r+");
	unsigned int i = 0;
	unsigned short int numUsers = 0;
	
	if (arch == NULL) {
		printf("Eror en base de datos...No se encuentra.\n");
		return;
	}
		
	// Contar la cantidad de usuarios en el archivo

	
	char line[Max_lines];
	
	while (fgets(line, Max_lines, arch) != NULL) {
		numUsers++;
	}
		
	// Leer las líneas en un arreglo
	rewind(arch);
	char** lines = (char**)malloc(numUsers * sizeof(char*));
	if (lines == NULL) {
		printf("Error de memoria.\n");
		fclose(arch);
		return;
	}

	
	
	while (fgets(line, Max_lines, arch) != NULL) {
		size_t longg = strlen(line);
		lines[i] = (char*)malloc((longg + 1) * sizeof(char));
		strcpy(lines[i], line);
		i++;
	}

	// Ordenar las líneas utilizando el algoritmo de ordenamiento de burbuja
	for (int i = 0; i < numUsers - 1; i++) {
		for (int j = 0; j < numUsers - i - 1; j++) {
			if (strcmp(lines[j], lines[j + 1]) > 0) {
				// Intercambiar las líneas
				char* temp = lines[j];
				lines[j] = lines[j + 1];
				lines[j + 1] = temp;
			}
		}
	}
		
	// Sobrescribir el archivo ordenado
	rewind(arch);
	for (int i = 0; i < numUsers; i++) {
		fputs(lines[i], arch);
	}
		
	//printf("Archivo ordenado correctamente.\n");
		
	// Liberar memoria y cerrar el archivo
	for (int i = 0; i < numUsers; i++) {
		free(lines[i]);
	}
	free(lines);
	fclose(arch);
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
