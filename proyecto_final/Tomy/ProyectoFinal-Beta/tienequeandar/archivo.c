#include <stdio.h>


FILE* archApertura(const char* path){
	
	FILE* arch = fopen(path, "r");
	
	if(arch != NULL){
		puts("[Apetura_Archivo] Exito");
	}else{
		puts("[Apetura_Archivo] Error : No Encontrado");
	}
	
	return arch;
}


void *archLectura(const char *path){
	
	char *text;
	
	FILE *arch = archApertura(path);
	
	// Leer y mostrar el contenido del archivo
	if(arch != NULL){
		while (fgets(text, sizeof(text), arch) != NULL) {
			printf("%s", text);
		}
	}else{
		puts("[Apetura_Archivo] Error : No Encontrado");
		return 0;
	}
	
	// Cerrar el archivo
	fclose(arch);
	
	return arch;
}
	
	
int main(int argc, char *argv[]) {
	
	
	char *path = "../login.txt";
	
	archLectura(path);
	return 0;
}
	
