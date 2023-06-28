#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "gestion_arbol.h"
#include "Sign_in.h"
#include "Menu_Usuario.h"

void Menu_Usuario(struct nodo* raiz, struct nodo* nodoEncontrado) {
	char opx;
	const char* directorio = "./Users";
	char* user = nodoEncontrado->user;
	const char* formato = ".txt";
	char nombre_us[26];
	char amigos[200];
	struct nodo* buscar = NULL;
	int encontrado = 0;
	int opc_elim;
	char ruta[256];
	FILE* archivo;
	
	snprintf(ruta, sizeof(ruta), "%s/%s%s", directorio, user, formato);
	
	if (access(directorio, F_OK) == -1) {
		if (mkdir(directorio) == -1) {
			perror("Error al crear el directorio");
			exit(EXIT_FAILURE);
		}
	}
	
	archivo = fopen(ruta, "r+");// abro en modo lectura y escritura
	if (archivo == NULL) {
		printf("Error al crear o abrir el archivo.\n");
		return;
	}
	
	do {
		printf("\nBIENVENIDO %s!\n", user);
		printf("SI DESEA BUSCAR ALGUIEN EN LA RED PRESIONE 1\nSI DESEA SALIR PRESIONE S\n");
		scanf(" %c", &opx);
		
		switch (opx) {
		case '1':
			printf("\nBUSCAR USUARIOS\nIngrese el usuario a buscar en la red: ");
			scanf("%s", nombre_us);
			
			buscar = buscarnodo(raiz, nombre_us);
			if (buscar != NULL) {
				printf("Usuario encontrado: %s\n", nombre_us);
				rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
				
				encontrado = 0; // Reiniciar la variable encontrado a 0
				
				while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
					char* token = strtok(amigos, " ");//dividir la linea en tokens separados por espacios
					while (token != NULL) {
						if (strcmp(token, nombre_us) == 0) {
							printf("Usted tiene '%s' agregado como amigo.\n", nombre_us);
							encontrado = 1;
							printf("Desea eliminarlo de su lista?\n1. Si\n2. No\n");
							scanf("%d", &opc_elim);
							if (opc_elim == 1) {
								rewind(archivo); // Vuelve al inicio del archivo para escribir desde el principio
								FILE* archivoTemporal = fopen("temp.txt", "w"); // Abre un archivo temporal para escribir los datos actualizados
								
								if (archivoTemporal == NULL) {
									printf("Error al abrir el archivo temporal.\n");
									fclose(archivo);
									return;
								}
								
								while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
									if (strstr(amigos, nombre_us) == NULL) {
										fprintf(archivoTemporal, "%s", amigos);
									}
								}
								
								fclose(archivo);
								fclose(archivoTemporal);
								remove(ruta); // Elimina el archivo original
								rename("temp.txt", ruta); // Renombra el archivo temporal al nombre original
								
								archivo = fopen(ruta, "r+"); // Reabre el archivo en modo lectura y escritura
								if (archivo == NULL) {
									printf("Error al abrir el archivo.\n");
									return;
								}
								
								printf("El usuario ha sido eliminado de su lista de amigos.\n");
								fflush(archivo);
								encontrado = 0; // Reiniciar el indicador encontrado a 0 después de eliminar el usuario
							}
							break; // Salir del bucle interno
						}
						token = strtok(NULL, " ");
					}
					if (encontrado) {
						break; // Salir del bucle externo si se encontró y eliminó al usuario
					}
				}
				
				if (!encontrado) {
					printf("Usted no tiene agregado '%s' como amigo.\n", nombre_us);
					printf("Desea AGREGARLO a su lista?\n1. Si\n2. No\n");
					int opc;
					scanf("%d", &opc);
					switch (opc) {
					case 1:
						fseek(archivo, 0, SEEK_END); // Mueve el puntero al final del archivo
						fprintf(archivo, "%s ", nombre_us);
						printf("El usuario ha sido agregado a sus amigos.\n");
						fflush(archivo);
						break;
					case 2:
						break;
					default:
						printf("Opción no válida.\n");
						break;
					}
				}
			} else {
				printf("El usuario no ha sido encontrado en la red.\n");
			}
			rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
			break;
			
		case 's':
		case 'S':
			break;
			
		default:
			printf("Opción no válida.\n");
			break;
		}
		
		fflush(archivo); // Guarda los cambios en el archivo
		
	} while (opx != 's' && opx != 'S');
	
	fclose(archivo);
	printf("\nSaliendo.\n");
}
