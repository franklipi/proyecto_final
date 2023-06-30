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
	char ruta[180];
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
	printf("\n\n");
	printf("INICIO EXITOSO...\n\n");
	system("pause");
	do {
		opx = menuOpciones(user,ruta);
		switch (opx) {
		case '1':
			menuBuscar(user,ruta);
			scanf("%s", nombre_us);system("color 0e");
			
			buscar = buscarnodo(raiz, nombre_us);
			if (buscar != NULL) {
				//system("cls");
				//printf("%s esta en linea!!!\n", nombre_us);system("color 0e");
				rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
				
				
				while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
					encontrado = 0; // Reiniciar la variable encontrado a 0
					amigos[strcspn(amigos, "\n")] = '\0'; // Eliminar el carácter de nueva línea al final de la línea
					char* token = strtok(amigos, "\n");//dividir la linea en tokens separados por salto de linea
					while (token != NULL) {
						if (strcmp(token, nombre_us) == 0) {
							encontrado = 1;
							
							
							opc_elim = menuAmigo(user,nombre_us,encontrado);
							//scanf("%d", &opc_elim);
							if (opc_elim == '1') {
								rewind(archivo); // Vuelve al inicio del archivo para escribir desde el principio
								FILE* archivoTemporal = fopen("temp.txt", "w"); // Abre un archivo temporal para escribir los datos actualizados
								
								if (archivoTemporal == NULL) {
									printf("Error al abrir el archivo temporal.\n");system("color 0e");
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
									printf("Error al abrir el archivo.\n");system("color 0e");
									return;
								}
								
								printf("El %s ha sido eliminado de su lista de amigos.\n",nombre_us);system("color 0e");
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
				
					opc = menuAmigo(user,nombre_us,encontrado);
					switch (opc) {
					case '1':
						fseek(archivo, 0, SEEK_END); // Mueve el puntero al final del archivo
						fprintf(archivo,"%s\n", nombre_us);
						system("cls");
						printf("El usuario ha sido agregado a sus amigos.\n");system("color 0e");
						fflush(archivo);
						break;
					case '2':
						break;
					default:
						printf("Opción no válida.\n");system("color 0e");
						break;
					}
				}
			} else {
				system("cls");
				printf("%s no esta en linea.\n",nombre_us);system("color 0e");
			}
			rewind(archivo); // Vuelve al inicio del archivo para leer desde el principio
			break;
			
			
		case '2':
			opx = menuCambioPass(user);
			
			if(opx == '1'){
				char* pass = (char*)malloc(27 * sizeof(char));
				char* newpass = (char*)malloc(27 * sizeof(char));
				char* newpass1 = (char*)malloc(27 * sizeof(char));
				printf("Ingrese la contraseña: "); scanf("%s",pass);system("color 0e");
				
				
				if ((strcmp(nodoEncontrado->pass, pass) == 0)){
					
					printf("Ingrese la nueva contrasena"); scanf("%s", newpass);
					printf("Vuelva a confirmar la contrasena");scanf("%s", newpass1);
					if ((strcmp(newpass, newpass1) == 0)){
						eliminarUs("login.txt",user);
						InsertarNuevo("login.txt",user,newpass1);
						eliminarnodo(raiz,user,nodoEncontrado->pass);
						return 0;
					}else{
						puts("Las contrasenas no coinciden...\n");
					}
				}else{
					puts("Credenciales incorrectas...");system("color 0e");
				}
				
				free(pass);
				free(newpass);
				free(newpass1);
			}
			
			break;
		
		case '9':
			opx = menuEliminar(user);
			
			if(opx == '1'){
				char* pass = (char*)malloc(27 * sizeof(char));
				printf("Ingrese la contraseña: "); scanf("%s",pass);system("color 0e");
				
				if ((strcmp(nodoEncontrado->pass, pass) == 0)){
					eliminarUs("login.txt",user);
					eliminarnodo(raiz,user,nodoEncontrado->pass);
				}else{
					puts("Credenciales incorrectas...");system("color 0e");
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

char menuOpciones(char* user, char ruta[]){
	char opx;
	fflush(stdin);
	//int *cant;
	//(*cant)=0;
	
	
	//leerAmigos(ruta,&cant);
	system("cls");
	
	
	imprimirCentrado("=========================\n",6,50);
	imprimirCentrado("PERFIL  \n",6,50);
	imprimirCentrado("=========================\n",6,50);
	
	
	
	printf("============================\n");
	printf("        @%s \n",user);
	printf("============================\n");
	
	//(*cant)=0;
	//leerAmigos(ruta,&cant);
	imprimirCentrado("=========================\n",6,1);
	imprimirCentrado("    AMIGOS:   \n",6,10);
	imprimirCentrado("=========================\n",6,1);
	
	
	printf("=========================\n");
	printf("       1-Buscar amigos\n");
	printf("    2-Cambio de contrasena.\n");
	printf("    9-Eliminar Usuario\n");
	printf("         S-Salir\n");
	printf("=========================\n");
	printf("\n");
	
	system("color 0e");
	do {
		printf("Opcion Ingresada: ");scanf("%c", &opx);system("color 0e");
		if(opx != '1' && opx != '2' && opx != '9' && opx != 's' && opx != 'S'){
			puts("Opcion invalida...Reingrese...");system("color 0e");
		}
	}while(opx != '1' && opx != '2' && opx != '9' && opx != 's' && opx != 'S');
	
	return opx;
}

void menuBuscar(char *user,char ruta[]){
	
	fflush(stdin);
	system("cls");
	
	printf("\n\n");
	printf("============================\n");
	printf("        @%s \n",user);
	printf("============================\n");
	/*
	int * cant; (*cant)=0;
	leerAmigos(ruta,&cant);
	*/
	imprimirCentrado("=========================\n",6,1);
	imprimirCentrado("     AMIGOS:   \n",6,10);
	imprimirCentrado("=========================\n",6,1);
	printf("Ingrese el usuario a buscar: ");
	system("color 0e");
	}

	
char menuAmigo(char *user,const char *amigo, int band){
	
	fflush(stdin);
	char opx;
	if(band == 1){
		system("cls");
		printf("\n\n");
		printf("============================\n");
		printf("        @%s \n",user);
		printf("============================\n");
		imprimirCentrado("=========================\n",6,1);
		imprimirCentrado("AMIGOS:\n",6,12);
		imprimirCentrado("=========================\n\n\n",6,1);
		
		
		
		
		printf("============================\n");
		printf("        En linea!!!\n");
		printf("       @%s\n",amigo);
		//printf("      En linea!!!\n");
		printf("      Estado: Amigo\n");
		printf("============================\n");system("color 0e");
		
		
		printf("Desea eliminarlo?\n1-Si\n2-No\n");
		do {
			printf("Opcion Ingresada: ");scanf("%c", &opx);system("color 0e");
			if(opx != '1' && opx != '2'){
				puts("Opcion invalida...Reingrese...");system("color 0e");
			}
		}while(opx != '1' && opx != '2');
		
	}else if(band == 0){
		system("cls");
		fflush(stdin);
		printf("\n\n");

		imprimirCentrado("=========================\n",6,1);
		imprimirCentrado("AMIGOS:\n",6,15);
		imprimirCentrado("=========================\n\n\n",6,1);
		printf("============================\n");
		printf("         En linea\n");
		printf("        @%s\n",amigo);
		printf("       Estado: Sin relacion\n");
		printf("============================\n");
		
		
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
	printf("============================\n");
	printf("        @%s \n",user);
	printf("============================\n");
	
	imprimirCentrado("=========================\n",6,40);
	imprimirCentrado("   Eliminacion de usuario   \n",6,10);
	imprimirCentrado("=========================\n",6,40);
	printf("\n");
	printf("Esta a punto de eliminar su cuenta...\n");
	printf("Desea continuar?\n1-Si\n2-No\n");system("color 0e");
	do {
		printf("Opcion Ingresada: ");scanf("%c", &opx);
		if(opx != '1' && opx != '2'){
			puts("Opcion invalida...Reingrese...\n");
		}
	}while(opx != '1' && opx != '2');
	
	return opx;
}
	
char menuCambioPass(char *user){
	
	char opx;
	fflush(stdin);
	system("cls");
	printf("\n\n");
	printf("============================\n");
	printf("        @%s \n",user);
	printf("============================\n");
	
	imprimirCentrado("=========================\n",6,40);
	imprimirCentrado("   CAMBIO DE CONTRASENA   \n",6,10);
	imprimirCentrado("=========================\n",6,40);
	printf("\n");
	printf("Desea continuar?\n1-Si\n2-No\n");system("color 0e");
	do {
		printf("Opcion Ingresada: ");scanf("%c", &opx);
		if(opx != '1' && opx != '2'){
			puts("Opcion invalida...Reingrese...\n");system("color 0e");
		}
	}while(opx != '1' && opx != '2');
	
	return opx;	
}
