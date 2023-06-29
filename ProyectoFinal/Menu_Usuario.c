#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "gestion_arbol.h"
#include "Registro_User.h" 
#include "Menu_Usuario.h"
#include "menu_principal.h"

void Menu_Usuario(struct nodo* raiz, struct nodo* nodoEncontrado) {
	char opx;
	char opc;
	const char* directorio = "./Users/";
	char* user = nodoEncontrado->user;
	const char* formato = ".txt";
	char nombre_us[26];
	char amigos[200];
	struct nodo* buscar = NULL;
	int encontrado=0;
	char opc_elim;
	char ruta[256];
	FILE* archivo;
	
	snprintf(ruta, sizeof(ruta), "%s/%s%s", directorio, user, formato);
	
	if (access(directorio, F_OK) == -1) {
		if (mkdir(directorio) == -1) {
			perror("Error al crear el directorio");
			exit(EXIT_FAILURE);
		}
	}
	
	archivo = fopen(ruta, "a+");// abro en modo lectura y escritura
	
	if (archivo == NULL) {
		printf("Error al crear o abrir el archivo.\n");
		return;
	}
	
	do {
		opx = menuOpciones(user);
		switch (opx) {
		case '1':
			menuBuscar(user);
			scanf("%s", nombre_us);
			
			buscar = buscarnodo(raiz, nombre_us);
			if (buscar != NULL) {
				//system("cls");
				printf("%s esta en linea!!!\n", nombre_us);
				rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
				
				
				while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
					encontrado = 0; // Reiniciar la variable encontrado a 0
					amigos[strcspn(amigos, "\n")] = '\0'; // Eliminar el carácter de nueva línea al final de la línea
					char* token = strtok(amigos, "\n");//dividir la linea en tokens separados por salto de linea
					while (token != NULL) {
						if (strcmp(token, nombre_us) == 0) {
							encontrado = 1;
							/*
							printf("Usted tiene '%s' agregado como amigo.\n", nombre_us);
							printf("Desea eliminarlo de su lista?\n1. Si\n2. No\n");
							*/
							
							opc_elim = menuAmigo(user,nombre_us,encontrado);
							//scanf("%d", &opc_elim);
							if (opc_elim == '1') {
								rewind(archivo); // Vuelve al inicio del archivo para escribir desde el principio
								FILE* archivoTemporal = fopen("temp.txt", "w"); // Abre un archivo temporal para escribir los datos actualizados
								
								if (archivoTemporal == NULL) {
									printf("Error al abrir el archivo temporal.\n");
									fclose(archivo);
									return;
								}
								
								while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
									if (strlen(amigos) > 1 && strstr(amigos, nombre_us) == NULL) {
										fprintf(archivoTemporal, "%s\n", amigos);
									}
								}
								
								fclose(archivo);
								fclose(archivoTemporal);
								remove(ruta); // Elimina el archivo original
								rename("temp.txt", ruta); // Renombra el archivo temporal al nombre original
								
								archivo = fopen(ruta, "a+"); // Reabre el archivo en modo lectura y escritura
								if (archivo == NULL) {
									printf("Error al abrir el archivo.\n");
									return;
								}
								
								printf("El %s ha sido eliminado de su lista de amigos.\n",nombre_us);
								fflush(archivo);
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
					/*
					printf("Usted no tiene agregado '%s' como amigo.\n", nombre_us);
					printf("Desea AGREGARLO a su lista?\n1. Si\n2. No\n");
					int opc;
					scanf("%d", &opc);
					*/
					opc = menuAmigo(user,nombre_us,encontrado);
					switch (opc) {
					case '1':
						fseek(archivo, 0, SEEK_END); // Mueve el puntero al final del archivo
						fprintf(archivo,"%s\n", nombre_us);
						system("cls");
						printf("El usuario ha sido agregado a sus amigos.\n");
						fflush(archivo);
						break;
					case '2':
						break;
					default:
						printf("Opción no válida.\n");
						break;
					}
				}
			} else {
				system("cls");
				printf("%s no esta en linea.\n",nombre_us);
			}
			rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
			break;
		case '9':
			opx = menuEliminar(user);
			
			if(opx == '1'){
				char *pass;
				printf("Ingrese la contraseña: "); scanf("%s",pass);
				
				if ((strcmp(nodoEncontrado->pass, pass) == 0)){
					eliminarUs("login.txt",user);
					eliminarnodo(raiz,user,nodoEncontrado->pass);
				}else{
					puts("Credenciales incorrectas...");
				}
			
			}
			
			return;
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


char menuOpciones(char* user){
	char opx;
	fflush(stdin);
	//system("cls");
	printf("\n\n");
	printf(" ------------------------\n",2,20);
	printf("|      Usuario:%s     |\n",user,2,20);
	printf(" ------------------------\n",2,20);
	
	imprimirCentrado("------------------------\n",2,20);
	imprimirCentrado("    1-Buscar amigos\n",2,20);
	imprimirCentrado("    9-Eliminar Usuario\n",2,20);
	imprimirCentrado("         S-Salir\n",2,20);
	imprimirCentrado("------------------------\n",2,20);
	printf("\n");
	
	
	
	do {

		printf("Opcion Ingresada: ");scanf("%c", &opx);
		if(opx != '1'&& opx != '9' && opx != 's' && opx != 'S'){
			puts("Opcion invalida...Reingrese...");
		}
	}while(opx != '1'&& opx != '9' && opx != 's' && opx != 'S');
	
	return opx;
}

void menuBuscar(char *user){
	
	fflush(stdin);
	//system("cls");
	printf("\n\n");
	printf("\tUsuario:%s\n",user);
	printf("\t\t\t\t\t=========================\n");
	printf("\t\t\t\t\t          Amigos\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("Ingrese el usuario a buscar: ");

	}

char menuAmigo(char *user,const char *amigo, int band){
	
	fflush(stdin);
	char opx;
	if(band == 1){
		//system("cls");
		printf("\n\n");
		printf("=========================\n");
		printf("USUARIO:%s\n",user);
		printf("=========================\n");
		printf("\t\t\t\t\t------------------------\n");
		printf("\t\t\t\t\t          Amigos\n");
		printf("\t\t\t\t\t------------------------\n");
		printf("[%s]\n",amigo);
		printf("Estado: amigo\n");
		printf("Desea eliminarlo?\n1-Si\n2-No\n");
		do {
			printf("Opcion Ingresada: ");scanf("%c", &opx);
			if(opx != '1' && opx != '2'){
				puts("Opcion invalida...Reingrese...");
			}
		}while(opx != '1' && opx != '2');
		
	}else if(band == 0){
		//system("cls");
		fflush(stdin);
		printf("\n\n");
		printf("\tUsuario:%s\n",user);
		printf("\t\t\t\t\t------------------------\n");
		printf("\t\t\t\t\t          Amigos\n");
		printf("\t\t\t\t\t------------------------\n");
		printf("[%s]\n",amigo);
		printf("Estado: Sin relacion\n");
		printf("Desea Agregarlo?\n1-Si\n2-No\n");
		do {
			printf("Opcion Ingresada: ");scanf("%c", &opx);
			if(opx != '1' && opx != '2'){
				puts("Opcion invalida...Reingrese...");
			}
		}while(opx != '1' && opx != '2');
	}
	return opx;	
}
	
char menuEliminar(char *user){
	char opx;
	fflush(stdin);
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t      Usuario:%s\n",user);
	printf("\t\t\t\t\t------------------------\n");
	printf("\t\t\t\t\t    ELIMINACION DE USUARIO\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\n");
	printf("Esta a punto de eliminar su cuenta...");
	printf("Desea continuar?\n1-Si\n2-No");
	do {
		printf("Opcion Ingresada: ");scanf("%c", &opx);
		if(opx != '1' && opx != '2'){
			puts("Opcion invalida...Reingrese...");
		}
	}while(opx != '1' && opx != '2');
	
	return opx;
}
