#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct nodo {
	struct nodo* izquierdo;
	struct nodo* derecho;
	char user[30];
	char pass[30];
};

struct nodo* crearnodo();
struct nodo* insertarnodo(struct nodo* raiz,const char* user,const char* pass);
struct nodo* buscarnodo(struct nodo* raiz);
void imprimirarbol(struct nodo* raiz);

#endif
