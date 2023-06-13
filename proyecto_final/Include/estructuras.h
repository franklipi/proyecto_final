#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct nodo {
	int dato;
	struct nodo* izquierdo;
	struct nodo* derecho;
};

struct nodo* crearnodo(int valor);
struct nodo* insertarnodo(struct nodo* raiz, int valor);
struct nodo* buscarnodo(struct nodo* raiz, int valor);
struct nodo* buscarmin(struct nodo* nodo);
void imprimirarbol(struct nodo* raiz);

#endif
