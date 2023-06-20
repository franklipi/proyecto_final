#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char opx;
	char nombre_us[26];
	char amigos[200];
	char name_user[26] = "fran";
	
	// Crear el nombre del archivo concatenando el usuario y la extensión
	const char* user = "fran";
	const char* txt = ".txt";
	char filename[100];
	char linea[100];
	
	// Crear el nombre del archivo concatenando el usuario y la extensión
	sprintf(filename, "C:\\Users\\fran_\\OneDrive\\Escritorio\\prueba\\%s%s", user, txt);
	
	FILE* archivo;
	
	do {
		int encontrado = 0; // Mover la declaración e inicialización aquí
		
		printf("\n BIENVENIDO %s!\n", name_user);
		printf("SI DESEA BUSCAR ALGUIEN EN LA RED PRESIONE 1\nSI DESEA SALIR PRESIONE S\n");
		scanf(" %c", &opx);
		getchar();  // Consumir el carácter de nueva línea residual
		
		switch (opx) {
		case '1':
			printf("\t BUSCAR USUARIOS \n Ingrese el usuario a buscar en la red....\n");
			scanf("%s", nombre_us);
			
			archivo = fopen(filename, "r");
			
			if (archivo == NULL) {
				printf("No se pudo abrir el archivo.\n");
				return 1;
			}
			
			while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
				if (strstr(amigos, nombre_us) != NULL) {
					printf("Usted tiene '%s' agregado como amigo.\n", nombre_us);
					encontrado = 1;
					
					printf("\n Desea eliminarlo de su lista?\n 1.Si\n2.No\n");
					int opc_elim;
					scanf("%d", &opc_elim);
					
					if (opc_elim == 1) {
						FILE* archivoTemporal = fopen("C:\\Users\\fran_\\OneDrive\\Escritorio\\prueba\\nombreTemporal.txt", "w");
						
						if (archivoTemporal == NULL) {
							printf("No se pudo abrir el archivo temporal.\n");
							fclose(archivo);
							return 1;
						}
						
						while (fgets(linea, sizeof(linea), archivo) != NULL) {
							if (strstr(linea, nombre_us) == NULL) {
								fputs(linea, archivoTemporal);
							}
						}
						
						fclose(archivo);
						fclose(archivoTemporal);
						
						archivo = fopen(filename, "w");
						if (archivo == NULL) {
							printf("No se pudo abrir el archivo original en modo de escritura.\n");
							return 1;
						}
						
						archivoTemporal = fopen("C:\\Users\\fran_\\OneDrive\\Escritorio\\prueba\\nombreTemporal.txt", "r");
						if (archivoTemporal == NULL) {
							printf("No se pudo abrir el archivo temporal en modo de lectura.\n");
							return 1;
						}
						
						while (fgets(linea, sizeof(linea), archivoTemporal) != NULL) {
							fputs(linea, archivo);
						}
						
						fclose(archivo);
						fclose(archivoTemporal);
						
						remove("C:\\Users\\fran_\\OneDrive\\Escritorio\\prueba\\nombreTemporal.txt");
						
						printf("El usuario ha sido eliminado de su lista de amigos.\n");
						
						break; // Salir del bucle while
					}
				}
			}
			
			if (!encontrado) {
				printf("Usted no tiene agregado '%s' como amigo.\n", nombre_us);
				
				printf("\t Desea AGREGARLO a su lista?\n 1. Si.\n 2. No\n");
				int opc;
				scanf("%d", &opc);
				
				switch (opc) {
				case 1:
					archivo = fopen(filename, "a");
					
					if (archivo == NULL) {
						printf("No se pudo abrir el archivo.\n");
						return 1;
					}
					
					fprintf(archivo, "%s\n", nombre_us);
					fclose(archivo);
					
					printf("El usuario ha sido agregado a su lista de amigos.\n");
					break;
				case 2:
					break;
				}
			}
			
			fclose(archivo);
			break;
		case 's':
		case 'S':
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción inválida. Por favor, ingrese una opción válida.\n");
			break;
		}
		
	} while (opx != 's' && opx != 'S');
	
	return 0;
}
