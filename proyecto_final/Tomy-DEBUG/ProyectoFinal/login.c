
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_arbol.h" 
#include "verificar_datos.h"



int login(struct nodo *raiz, char *user, char *pass){
	
	
	printf("Ingrese el usuario: "); user = validarUser();
	printf("Ingrese su contraseña: "); pass = validarPass();
	
	struct nodo* nodoEncontrado = buscarnodo(raiz, user);
	
	if (nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0) {
		printf("Inicio exitoso.\n");
		return 1;
	} else {
		printf("Error...Credenciales incorrectas.\n");
		return 0;
		
	}
	

}
