#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
struct nodo* crearnodo(int valor) {
	struct nodo* nodo = (struct nodo*)malloc(sizeof(struct nodo));
	nodo->dato = valor;
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	return nodo;
}
struct nodo* insertarnodo(struct nodo* raiz, int valor) {
	if (raiz== NULL) {
		struct nodo* nuevo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
		return nuevo_nodo;
	} else {
		if (valor < raiz->dato) {
			raiz->izquierdo = insertarnodo(raiz->izquierdo, valor);
		} else {
			raiz->derecho = insertarnodo(raiz->derecho, valor);
		}
		return raiz;
	}
}

	
	struct nodo* buscarnodo(struct nodo* raiz, int valor) {
	if (raiz == NULL || raiz->dato == valor) {
		return raiz;
	}
	
	if (valor < raiz->dato) {
		return buscarnodo(raiz->izquierdo, valor);
	} else {
		return buscarnodo(raiz->derecho, valor);
	}
}
	
		
	struct nodo* buscarmin(struct nodo* raiz) {
		while (nodo->izquierdo != NULL) {
			nodo = nodo->izquierdo;
		}
		return nodo;
	}
	struct nodo* eliminarnodo(struct nodo* raiz, int valor) {
		if (raiz == NULL) {
			return raiz;
		}
		
		if (valor < raiz->dato) {
			raiz->izquierdo = eliminarnodo(raiz->izquierdo, valor);
		} else if (valor > raiz->dato) {
			raiz->derecho = eliminarnodo(raiz->derecho, valor);
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
		
		
		void imprimirarbol(struct nodo* raiz) {
			if (raiz != NULL) {
				imprimirarbol(raiz->izquierdo);
				printf("%d ", raiz->dato);
				imprimirarbol(raiz->derecho);
			}
		}
		
