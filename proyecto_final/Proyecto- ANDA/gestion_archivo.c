#include "gestion_arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

//ESTE ESSSS

void LeerFile(const char* path){
	
	FILE* arch = fopen(path, "r");
	
	char text[100]={" "};
	
	
	// Leer y mostrar el contenido del archivo
	if(arch != NULL){
		while (fgets(text, sizeof(text), arch) != NULL) {
			printf("%s", text);
			
		
			
		}
	}else{
		puts("[Apetura_Archivo] Error : No Encontrado");
		
	}
	
	// Cerrar el archivo
	fclose(arch);
}

void InsertarNuevo(const char* path, const char user[], const char pass[]){
	
	FILE* arch = fopen(path, "a");
	
	// Escribir el texto en el archivo
	fprintf(arch, "%s,%s\n", user,pass);
	
	fclose(arch);

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
