#ifndef ARCHIVO_H
#define ARCHIVO_H

int crearArch(const char *path);
//void leerAdmin(const char *path,int *cant_users);
void eliminarUs(const char* path, char* usuario);
void ordenarUsers(const char* path);
void InsertarNuevo (const char *path,const char user[], const char pass[]);
#endif
