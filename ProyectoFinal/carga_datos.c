#include <stdio.h>
#include <string.h>
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#include "carga_datos.h"

struct nodo *precarga(struct nodo* raiz, const char *path){
	
	
	FILE* arch = fopen(path, "r");
	
	if(arch == NULL){
		crearArch(path);
	}else {
		ordenarUsers(path);
	}
	
	
	char user[26];
	char pass[26];
	char line[54];
	
	

	// Leer y mostrar el contenido del archivo
	while (fgets(line, sizeof(line), arch)) {
		
		// Dividir la línea en usuario y contraseña usando coma como delimitador
		char* token = strtok(line, ",");
		if (token) {
			strncpy(user, token, sizeof(user));
			user[sizeof(user) - 1] = '\0';
		}
		
		token = strtok(NULL, ",");
		if (token) {
			strncpy(pass, token, sizeof(pass));
			pass[sizeof(pass) - 1] = '\0';
		}
		
		// Eliminar el salto de línea del final de la contraseña, si existe
		if (pass[strlen(pass) - 1] == '\n') {
			pass[strlen(pass) - 1] = '\0';
		}
		
		// Insertar el nodo en el árbol binario
		raiz = insertarnodo(raiz, user, pass);
	}
	
	fclose(arch);
	
	//imprimirarbol(raiz);
	
	return raiz;
}
