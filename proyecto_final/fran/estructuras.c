#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
struct nodo* crearnodo() {
	struct nodo* nodo = (struct nodo*)malloc(sizeof(struct nodo));
	nodo->user = user;
	nodo->pass=pass;
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	return nodo;
}
struct nodo* insertarnodo(struct nodo* raiz,const char* user,const char* pass) {
	if (raiz== NULL) {
		struct nodoarbol* nuevo_nodo = (struct nodoarbol*)malloc(sizeof(struct nodoarbol));
		return nuevo_nodo;
	} else {
		if (valor < arbol->) {
			raiz->izquierdo = insertar(raiz->izquierdo, valor);
		} else {
			raiz->derecho = insertar(raiz->derecho, valor);
		}
		return raiz;
	}
}

	
	struct nodo* buscarnodo(struct nodo* raiz) {
	if (raiz == NULL || raiz->dato == valor) {
		return raiz;
	}
	
	if (valor < raiz->dato) {
		return busqueda(raiz->izquierdo, valor);
	} else {
		return busqueda(raiz->derecho, valor);
	}
}
	
		struct nodo* eliminarnodo(struct nodo* root) {
		if (raiz == NULL) {
			return raiz;
		}
		
		if (valor < raiz->dato) {
			raiz->izquierda = eliminar(raiz->izquierdo, valor);
		} else if (valor > raiz->dato) {
			raiz->derecho = eliminar(raiz->derecho, valor);
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
			
			struct nodo* nodomin = buscarmin(raiz->derecha);
			raiz->dato = nodomin->dato;
			raiz->derecho = eliminarnodo(raiz->derecho, nodomin->dato);
		}
		
		return raiz;
	}
		
		struct nodo* buscarmin(struct nodo* nodo) {
			while (nodo->izquierdo != NULL) {
				nodo = nodo->left;
			}
			return nodo;
		}
		void imprimirarbol(struct nodo* raiz) {
			if (raiz != NULL) {
				imprimirarbol(raiz->izquierdo);
				printf("%d ", raiz->dato);
				imprimirarbol(raiz->derecho);
			}
		}
		
