#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H


void Menu_Usuario(struct nodo* raiz,struct nodo* nodoEncontrado);
char menuOpciones(char* user,char ruta[]);
char menuEliminar(char *user);
void menuBuscar(char* user,char ruta[]);
char menuAmigo(char *user,const char *amigo,int band);
#endif
