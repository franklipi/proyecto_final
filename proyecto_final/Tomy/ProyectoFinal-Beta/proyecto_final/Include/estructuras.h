#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct nodo {
	char user[26];
	char pass[26];
	struct nodo* izquierdo;
	struct nodo* derecho;
};

struct nodo* crearnodo(const char *user, const char *pass);
struct nodo* insertarnodo(struct nodo* raiz, const char *user, const char *pass);
struct nodo* buscarnodo(struct nodo* raiz, const char *user);
struct nodo* buscarmin(struct nodo* nodo);
struct nodo* eliminarnodo(struct nodo* raiz, const char *user, const char *pass)
void imprimirarbol(struct nodo* raiz);

#endif
