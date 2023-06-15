#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "estructuras.h"
#include "menu.h"
#include "archivo.h"

int main(int argc, char *argv[]){
	
	struct nodo* raiz = NULL;
	char user[26];
	char pass[26];
	const char *path ="../login.txt";
	int op;
	
	
	do{
		op = mostrarMenu();
		//Precarga(raiz,path);
		switch (op){
		case 1:
			printf("Bienvenido: ");
			printf("Ingrese el usuario: ");
			do{
				scanf("%25s", user);
				
				if(!(validarUsuario(user))){
					puts("Usuario Invalido");
				}
				
			}while(!(validarUsuario(user)));
			
			printf("Ingrese la contraseña: ");
			do{
				scanf("%25s", pass);
				if(!(validarPass(pass))){
					puts("Pass Invalido");
				}
			}while(!(validarPass(pass)));
			
			
			
			//Busqueda(user, pass);
			printf("Inicio exitoso.\n");
			//system("cls");
			MenuUsuario(raiz,Usuario);
			break;
			
		case 2:
			printf("Crear usuario:\n");
			printf("Ingrese el usuario: ");
			do{
				scanf("%25s", user);
				
				if(!(validarUsuario(user))){
					puts("Usuario Invalido");
				}
				
			}while(!(validarUsuario(user)));
			
			printf("Ingrese la contraseña: ");
			do{
				scanf("%25s", pass);
				if(!(validarPass(pass))){
					puts("Pass Invalido");
				}
			}while(!(validarPass(pass)));
			//if()Busqueda(user, pass);
			InsertarNuevo(path, user, pass);
			//LeerFile(path);
			break;
			
		case 3:
			printf("Saliendo del programa...\n");
			break;
		}
		printf("\n");
		
		
	} while (op != 6);
	
	return 0;
}

