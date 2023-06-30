#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H


void Menu_Usuario(struct nodo* raiz,struct nodo* nodoEncontrado);
char menuOpciones(const char* user,const char ruta[]);
void menuBuscar(struct nodo* raiz, const char* user, const char* ruta);
char menuAmigo(char *user,const char *amigo, short int band);
char menuEliminar(struct nodo* raiz,struct nodo* nodoEncontrado,const char *user);
char menuCambioPass(struct nodo* raiz,struct nodo* nodoEncontrado,const char *user);
#endif
