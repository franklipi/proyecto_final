#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "gestion_archivo.h"
#include "gestion_arbol.h"
#include "Registro_User.h" 
#include "Menu_Usuario.h"
#include "menu_principal.h"


char menuOpciones(const char* user, const char *ruta){
	char opx;
	fflush(stdin);
	//int *cant;
	//(*cant)=0;
	
	
	//leerAmigos(ruta,&cant);
	//system("cls");
	
	
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

	
	
	
char menuAmigo(const char *user,const char *amigo, bool band,char* ruta){
	char opx;
	//char opc_elim;
	char amigos[200];
	//char nombre_us[26];
	fflush(stdin);
	
	FILE* archivo = fopen(ruta, "a+");// abro en modo lectura y escritura
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
		printf("      Estado: Amigo\n");
		printf("============================\n");system("color 0e");
		
		
		printf("Desea eliminarlo?\n1-Si\n2-No\n");
		do {
			printf("Opcion Ingresada: ");scanf("%c", &opx);system("color 0e");
			if(opx != '1' && opx != '2'){
				puts("Opcion invalida...Reingrese...");system("color 0e");
			}
		}while(opx != '1' && opx != '2');
		if (opx == '1'){
			rewind(archivo);
			FILE* archivoTemporal = fopen("temp.txt", "w");
			
			if (archivoTemporal == NULL) {
				printf("Error al abrir el archivo temporal.\n");
				fclose(archivo);
			}
			
			while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
				if (strlen(amigos) > 1 && strstr(amigos, amigo) == NULL) {
					fprintf(archivoTemporal, "%s\n", amigos);
				}
			}
			
			fclose(archivo);
			fclose(archivoTemporal);
			remove(ruta);
			rename("temp.txt", ruta);
			
			archivo = fopen(ruta, "a+");
			if (archivo == NULL) {
				printf("Error al abrir el archivo.\n");
				//return;
			}
			
			printf("El %s ha sido eliminado de su lista de amigos.\n", amigo);
			fflush(archivo);
		}
		
		
		
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
		switch (opx) {
		case '1':
			fseek(archivo, 0, SEEK_END);
			fprintf(archivo, "%s\n", amigo);
			system("cls");
			printf("El usuario ha sido agregado a sus amigos.\n");
			system("color 0e");
			fflush(archivo);
			break;
		case '2':
			break;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	

	return opx;	
}


	
char menuEliminar(struct nodo* raiz,struct nodo* nodoEncontrado,const char *user){
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
		printf("Opcion Ingresada: ");
		scanf("%c", &opx);
		if(opx != '1' && opx != '2'){
			puts("Opcion invalida...Reingrese...\n");
		}
	}while(opx != '1' && opx != '2');
	if(opx == '1'){
		char* pass = (char*)malloc(27 * sizeof(char));
		printf("Ingrese la contrasena: "); scanf("%s",pass);system("color 0e");
		
		if ((strcmp(nodoEncontrado->pass, pass) == 0)){
			eliminarUs("login.txt",user);
			eliminarnodo(raiz,user,nodoEncontrado->pass);
		}else{
			puts("Credenciales incorrectas...");system("color 0e");
		}
	}
	
	return opx;
}
	
char menuCambioPass(struct nodo* raiz,struct nodo* nodoEncontrado,char *user){
	
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
		printf("Opcion Ingresada: ");
		scanf("%c", &opx);
		if(opx != '1' && opx != '2'){
			puts("Opcion invalida...Reingrese...\n");system("color 0e");
		}
	}while(opx != '1' && opx != '2');

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
	
	
	return opx;	
}
void menuBuscar(struct nodo* raiz, const char* user, char* ruta) {
		
	fflush(stdin);
	char nombre_us[26];
	struct nodo* buscar = NULL;
	bool encontrado=0;
	system("cls");

	printf("\n\n");
	printf("============================\n");
	printf("        @%s \n",user);
	printf("============================\n");
	
	imprimirCentrado("=========================\n",6,1);
	imprimirCentrado("     AMIGOS:   \n",6,10);
	imprimirCentrado("=========================\n",6,1);
	system("color 0e");
	
	printf("Ingrese el nombre de usuario a buscar: ");
	
	system("color 0e");
	
	
	scanf("%s", nombre_us);

	buscar = buscarnodo(raiz, nombre_us);
	if (buscar != NULL) {
		char amigos[200];
		encontrado = 0;
			
		FILE* archivo = fopen(ruta, "a+");
			if (archivo == NULL) {
				printf("Error al abrir el archivo.\n");
				return;
			}
			
			rewind(archivo);
			
			while (fgets(amigos, sizeof(amigos), archivo) != NULL) {
				encontrado = 0;
				amigos[strcspn(amigos, "\n")] = '\0';
				char* token = strtok(amigos, "\n");
				while (token != NULL) {
					if (strcmp(token, nombre_us) == 0) {
						encontrado = 1;
						
						menuAmigo(user, nombre_us, encontrado,ruta);
						break;
					}
					token = strtok(NULL, " ");
				}
				if (encontrado) {
					break;
				}
			}
			
			if (!encontrado) {
				menuAmigo(user, nombre_us, encontrado,ruta);
				
			} else {
				system("cls");
				printf("%s no está en línea.\n", nombre_us);
				system("color 0e");
			}
		}
}



void Menu_Usuario(struct nodo* raiz, struct nodo* nodoEncontrado) {
		
	char opx;
	const char* directorio = "./Users/";
	char* user = nodoEncontrado->user;
	const char* formato = ".txt";
	char ruta[180];	
	
	
	snprintf(ruta, sizeof(ruta), "%s/%s%s", directorio, user, formato);
	
	if (access(directorio, F_OK) == -1) {
		if (mkdir(directorio) == -1) {
			perror("Error al crear el directorio");
			exit(EXIT_FAILURE);
		}
	}
	
	printf("\n\n");
	printf("INICIO EXITOSO...\n\n");
	system("pause");
	
	do {
		opx = menuOpciones(user,ruta);
		switch (opx) {
		case '1':
			menuBuscar(raiz,user,ruta);
			break;
		case '2':
			menuCambioPass(raiz,nodoEncontrado,user);
			
			break;
		case '9':
			menuEliminar(raiz,nodoEncontrado,user);
			
			break;
		case 's':
		case 'S':
			break;
		}
		
		
		
	} while (opx != 's' && opx != 'S');
	
	//fclose(archivo);
	printf("\nSaliendo.\n");
	

}
	
	
	
	
	
