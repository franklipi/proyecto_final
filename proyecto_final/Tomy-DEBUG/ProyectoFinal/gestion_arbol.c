#include "gestion_arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "login.h"

struct nodo* crearnodo(const char* user, const char* pass) {
	struct nodo* nodo = (struct nodo*)malloc(sizeof(struct nodo));
	strcpy(nodo->user, user);
	strcpy(nodo->pass, pass);
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	return nodo;
}

struct nodo* insertarnodo(struct nodo* raiz, const char* user, const char* pass) {
	if (raiz == NULL) {
		struct nodo* nuevo_nodo = crearnodo(user, pass);
		return nuevo_nodo;
	} else {
		if (strcmp(user, raiz->user) < 0) {
			raiz->izquierdo = insertarnodo(raiz->izquierdo, user, pass);
		} else if (strcmp(user, raiz->user) > 0) {
			raiz->derecho = insertarnodo(raiz->derecho, user, pass);
		}
	}
	return raiz;
}

struct nodo* buscarnodo(struct nodo* raiz, const char* user) {
	if (raiz == NULL || strcmp(raiz->user, user) == 0) {
		return raiz;
	}
	
	if (strcmp(user, raiz->user) < 0) {
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

struct nodo* eliminarnodo(struct nodo* raiz, const char* user, const char* pass) {
	if (raiz == NULL) {
		return raiz;
	}
	
	if (strcmp(user, raiz->user) < 0) {
		raiz->izquierdo = eliminarnodo(raiz->izquierdo, user, pass);
	} else if (strcmp(user, raiz->user) > 0) {
		raiz->derecho = eliminarnodo(raiz->derecho, user, pass);
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
		strcpy(nodomin->user, raiz->user);
		strcpy(nodomin->pass, raiz->pass);
		raiz->derecho = eliminarnodo(raiz->derecho, nodomin->user, nodomin->pass);
	}
	
	return raiz;
}

void imprimirarbol(struct nodo* raiz) {
	if (raiz != NULL) {
		imprimirarbol(raiz->izquierdo);
		printf("%s\n", raiz->user);
		printf("%s\n", raiz->pass);
		imprimirarbol(raiz->derecho);
	}
}

