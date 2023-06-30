#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H
#include <stdbool.h>


char menuOpciones(const char* user,const char *ruta);
char menuAmigo(const char *user,const char *amigo, bool band,char* ruta);
char menuEliminar(struct nodo* raiz,struct nodo* nodoEncontrado,const char *user);
char menuCambioPass(struct nodo* raiz,struct nodo* nodoEncontrado,char *user);
void menuBuscar(struct nodo* raiz, const char* user, char* ruta);
void Menu_Usuario(struct nodo* raiz,struct nodo* nodoEncontrado);
#endif
