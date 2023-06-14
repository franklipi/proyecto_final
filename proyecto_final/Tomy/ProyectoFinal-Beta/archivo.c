#include <stdio.h>



void LeerFile(const char* path){
	
	FILE* arch = fopen(path, "r");
	
	char *text;
	
	
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

void InsertarNuevo(const char* path, const char * user, const char *pass){
	
	FILE* arch = fopen(path, "a");
	
	// Escribir el texto en el archivo
	fprintf(arch, "%s,%s\n", user,pass);
	
	fclose(arch);

}
	
int main(int argc, char *argv[]) {
	
	
	char *path = "../login.txt";
	
	//LeerFile(path);
	
	InsertarNuevo(path,"tomas", "1234");
	
	LeerFile(path);
	return 0;
}
	
