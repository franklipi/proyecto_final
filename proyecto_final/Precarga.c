#include <stdio.h>
#include <estructuras.h>
/*
struct Logins{
	
	char user[20];
	char pass[20];
	char email[30];
	
	struct nodo
	
};
*/


FILE* pre_carga(const char* path) {
	FILE* arch = fopen(path, "r");
	
	return arch;
}


void *carga(const char *path){
	
	
	char *texto;
	
	FILE *arch = pre_carga(path);
	
	if(arch != NULL){
		puts("[Apetura_Archivo] Exito");
	}
	
	printf("Contenido del archivo:\n");
	
	// Leer y mostrar el contenido del archivo
	while (fgets(texto, sizeof(texto), arch) != NULL) {
		
		
		printf("%s", texto);
	}
	
	// Cerrar el archivo
	fclose(arch);
	
	return arch;
}




int main(int argc, char *argv[]) {
	
	
	char *path = "Source/Logins.txt";
	carga(path);
	
	
	
	return 0;
}

