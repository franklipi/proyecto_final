#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	const char* directorio = "./Users"; // Directorio relativo
	const char* user = "fran";
	const char* formato = ".txt";
	
	char ruta[256];
	snprintf(ruta, sizeof(ruta), "%s/%s%s", directorio, user, formato);
	
	// Verificar si el directorio existe, si no, crearlo
	if (access(directorio, F_OK) == -1) {
		if (mkdir(directorio) == -1) {
			perror("Error al crear el directorio");
			exit(EXIT_FAILURE);
		}
		printf("Directorio creado: %s\n", directorio);
	}

	
	// Crear y abrir el archivo
	FILE* archivo = fopen(ruta, "a+");
	if (archivo != NULL) {
		printf("Archivo creado: %s\n", ruta);
		// Realizar operaciones en el archivo
		fclose(archivo);
	} else {
		printf("Error al crear el archivo.\n");
	}

	return 0;
}

