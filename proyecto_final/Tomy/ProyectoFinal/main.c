#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "estructuras.h"
#include "menu_principal.h"
#include "archivo.h"
#include "precarga.h"

int main(int argc, char *argv[]){
	
	struct nodo* raiz = NULL;
	char * user;
	char * pass;
	const char *path = "../login.txt";
	int op;
	
	do{
		op = mostrarMenu();
		
		
		//raiz = precarga(raiz,path);
		switch (op){
		case '1':
			user = validarUser();
			
			pass = validarPass();
			
			//buscarnodo(struct nodo* raiz, const char user[]);
			printf("Inicio exitoso.\n");
	
			//MenuUsuario(raiz,Usuario);
			break;
			
		case '2':
			printf("Crear usuario:\n");
			printf("Ingrese el usuario: ");
			user = validarUser();
			
			printf("Ingrese la contraseña: ");
			pass = validarPass();
			
			
			//if()Busqueda(user, pass);
			InsertarNuevo(path, user, pass);
			//LeerFile(path);
			break;
			
		case '3':
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
	} while (op != '3');
	
	return 0;
}

