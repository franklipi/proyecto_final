#include <stdio.h>
#include <stdlib.h>
//#include "Menu_Usuario.h"

void menuUsuario(struct nodo* raiz,const char* path){
	char opx;
	const char nombre_us[26];
	char amigos[200];
	struct nodo* buscar=NULL;
	int encontrado=0;
	int opc_elim;
	int contador_amigos=0;
	char text;
//abro mi archivo al principio , para leer
	FILE *archivo = fopen("path.txt", "r"); // Reemplaza "archivo.txt" con la ruta de tu archivo
	
	if (archivo == NULL) {
		printf("Error en el archivo.\n");
		return 1;
	}
	
	//FILE *archivo;//
	
	do{
		printf("\n BIENVENIDO %s!\n",raiz->user);
	
	printf("CANTIDAD DE AMIGOS:\n %d",cantidad); 
	//abrir el archivo correspondiente//FILE *archivo;
	printf("SI DESEA BUSCAR ALGUIEN EN LA RED PRESIONE 1\n SI DESEA SALIR PRESIONE S");
	scanf("%c",opx);
	switch (opx){
		
	case 1:
		printf("\t BUSCAR USUARIOS \n Ingrese el usuario a buscar en la red....\n");
		scanf("%s",nombre_us);
		struct nodo* buscar=buscarnodo(raiz,nombre_us);
		if(buscar!=NULL){
			printf("\n Usuario encontrado.\n %s\n",buscar->nombre_us);
		
	
			//bucle obtiene lo que hay en el archivo en una cadena y verifica la existencia//
			while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
				if (strstr(amigos, nombre_us) != NULL) {
					printf("Usted tiene '%s' agregado como amigo.\n", nombre_us);
					encontrado = 1;
					printf("\n Desea eliminarlo de su lista?\n 1.Si\n2.No\n",&opc_elim);
						if(opc_elim==1){
						archivo = fopen("archivo.txt", "r+"); // Reemplaza "archivo.txt" con el nombre y ruta del archivo original
						
						if (archivo == NULL) {
							printf("No se pudo abrir el archivo.\n");
							return ;
						}
						
						FILE *archivoTemporal = fopen(nombreTemporal, "w"); // Abre el archivo temporal en modo escritura
						
						if (archivoTemporal == NULL) {
							printf("No se pudo abrir el archivo temporal.\n");
							fclose(archivo);
							return ;
						}
						
						while (fscanf(archivo, "%s", nombre_us) != EOF) {
							if (strcmp(palabra, nombre_us) != 0) {
								fprintf(archivoTemporal, "%s ", palabra);
							}
						}
						
						fclose(archivo);
						fclose(archivoTemporal);
						
						remove("archivo.txt");
						rename(nombreTemporal, "archivo.txt");
						
						printf("El usuario  ha sido Eliminado de su lista de amigos.\n");
						
						return 0;
					}
						
					}
					
				}
			}
			
			if (!encontrado) {
				printf("Usted no tiene agregado '%s' como amigo.\n %a", nombre_us);
				printf("\t Desea AGREGARLO a su lista?\n 1. Si.\n 2. no");
				scanf("%c", );
					switch(opc){
					case 1:
						//abro el archivo al final//
						//copio lo que hay en mi cadena en mi archivo
						archivo = fopen("archivo.txt", "a");
						if (archivo == NULL) {
							printf("No se pudo abrir el archivo.\n");
							return 1;
						}
						fprintf(archivo, "%s", nombre_us);
						
						printf("El usuario ha sido agregado a sus amigos .\n")
						
						break;
					case 2:
						
						
						break;
						
						
				}
			}
			
			
		}else{
			printf(" El usuario no ha sido encontrado en la red..\n");
			
		}
		fclose(archivo);
		break;
		//switch//
} while(opx!='s'||opx!='S');
	printf("\n Saliendo\n");
	

}


