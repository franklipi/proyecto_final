#include "../Include/estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


struct nodo* crearnodo(char user, char pass) {
	struct nodo* nodo = (struct nodo*)malloc(sizeof(struct nodo));
	nodo->user = user;
	nodo->pass = pass;
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	return nodo;
}

struct nodo* insertarnodo(struct nodo* raiz, char user, char pass) {
	if (raiz== NULL) {
		struct nodo* nuevo_nodo = crearnodo(user, pass);
		return nuevo_nodo;
	} else {
		if (strcmp(user, raiz->user) < 0) {
			raiz->izquierdo = insertarnodo(raiz->izquierdo, user, pass);
		} else if (strcmp(user, raiz->user) < 0) {
			raiz->derecho = insertarnodo(raiz->derecho, user, pass);
			
		}
		//return raiz;
	}
	return raiz;
}

	
	struct nodo* buscarnodo(struct nodo* raiz, char user) {
	if (raiz == NULL || raiz->user == user) {
		return raiz;
	}
	
	if (user < raiz->user) {
		return buscarnodo(raiz->izquierdo, user);
	} else {
		return buscarnodo(raiz->derecho, user);
	}
}
	
		
	struct nodo* buscarmin(struct nodo* nodo) {
		while (nodo->izquierdo != NULL) {
			nodo = nodo->izquierdo;
		}
		return nodo;
	}
	
	struct nodo* eliminarnodo(struct nodo* raiz, char user, char pass) {
		if (raiz == NULL) {
			return raiz;
		}
		
		if (user < raiz->user) {
			raiz->izquierdo = eliminarnodo(raiz->izquierdo, user,pass);
		} else if (user > raiz->user) {
			raiz->derecho = eliminarnodo(raiz->derecho, user,pass);
		} else {
			if (raiz->izquierdo == NULL) {
				struct nodo* temp = raiz->derecho;
				free(raiz);
				return temp;
			} else if (raiz->derecho == NULL) {
				struct nodo* temp = raiz->izquierdo;
				free(raiz);
				return temp;
			}
			
			struct nodo* nodomin = buscarmin(raiz->derecho);
			raiz->dato = nodomin->user;
			raiz->derecho = eliminarnodo(raiz->derecho, nodomin->user);
		}
		
		return raiz;
	}
		
		
		void imprimirarbol(struct nodo* raiz) {
			if (raiz != NULL) {
				imprimirarbol(raiz->izquierdo);
				printf("%s", raiz->user);
				printf("%s", raiz->pass);
				
				imprimirarbol(raiz->derecho);
			}
		}
		
