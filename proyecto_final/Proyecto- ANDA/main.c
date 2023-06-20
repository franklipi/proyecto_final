#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "gestion_arbol.h"
#include "menu_principal.h"
#include "gestion_archivo.h"
#include "carga_datos.h"
    
int main(int argc, char *argv[]){
	
	struct nodo* raiz = NULL;
	char * user;
	char * pass;
	const char *path = "../login.txt";
	char op;
	
	do{
		fflush(stdin);
		op = mostrarMenu();
		
		switch (op){
			
		case '1':
			raiz = precarga(raiz,path);
			
			user = validarUser();
			pass = validarPass();
			
			struct nodo* nodoEncontrado = buscarnodo(raiz, user);
			if (nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0) {
				printf("Inicio exitoso.\n");
				
				// MenuUsuario(raiz, Usuario);
			} else {
				printf("Inicio fallido. Usuario o contraseña incorrectos.\n");
			}
			break;
			
		case '2':
			printf("Crear usuario:\n");
			user = validarUser();
			pass = validarPass();
	
			InsertarNuevo(path, user, pass);
			break;
			
		case '3':
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
	} while (op != '3');
	
	return 0;
}

	
	
	/*
	
	
	{
		raiz = precarga(raiz, path);
		
		user = validarUser();
		pass = validarPass();
		
		// Buscar si el usuario y la contraseña son válidos en el árbol raíz
		struct nodo* nodoEncontrado = buscarnodo(raiz, user);
		if (nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0) {
			printf("Inicio exitoso.\n");
			registrado = 1; // El usuario se ha registrado exitosamente
			// MenuUsuario(raiz, Usuario);
		} else {
			printf("Inicio fallido. Usuario o contraseña incorrectos.\n");
		}
	}
*/
