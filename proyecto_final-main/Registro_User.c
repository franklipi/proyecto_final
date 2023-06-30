#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "carga_datos.h"
#include "verificar_datos.h"
#include "gestion_arbol.h"
#include "gestion_archivo.h"
#include "Ingreso_User.h"
#include "Registro_User.h" 
#include <time.h>
#define CAPTCHA_LONG 6
#define I 100
	
int Sign_in(struct nodo *raiz, const char *path){
		
		char* user = (char*)malloc(27 * sizeof(char));
		char* pass = (char*)malloc(27 * sizeof(char));
		char op; 
		raiz = precarga(raiz,path);
		
		
		
		fflush(stdin);
		system("cls");
		printf("\n\n");
		printf("\t\t\t          F.I.O\n");
		printf("\t\t\t------------------------\n");
		printf("\t\t\t    Creacion de usuario\n");
		printf("\t\t\t------------------------\n");
		printf("\n");
		
		
		//const struct nodo* user_actual;
		printf("Ingrese el nuevo usuario: "); user = validarUser();
		printf("Ingrese su contraseña: ");    pass = validarPass();
		
		
		struct nodo* nodoEncontrado = buscarnodo(raiz, user);
		
		if(((nodoEncontrado != NULL && strcmp(nodoEncontrado->pass, pass) == 0))&&((strcmp(nodoEncontrado->user, user)==0))) {
			fflush(stdin);
			printf("El usuario ya existe Desea iniciar sesion?\t\n1-si\n2-no\n");
			do{
				printf("Opcion Ingresada: ");scanf("%c",&op);
			}while(op != '1' && op != '2');
			
			if(op == '1'){
				login(raiz,path);
			}else if(op == '2'){
				return 0;
			}
			
			return 1;
		}else{
		
				
			srand(time(NULL));
			
			char captcha[CAPTCHA_LONG + 1];
			int i;
			
			// Generar el CAPTCHA
			for (i = 0; i < CAPTCHA_LONG; i++) {
				captcha[i] = rand() % 26 + 'A'; // Generar una letra mayúscula aleatoria
				
			}
			captcha[i] = '\n';  // Agregar el carácter nulo al final de la cadena
			captcha[i+1] = '\0';
			// Mostrar el CAPTCHA al usuario
			printf("CAPTCHA: %s\n", captcha);
			
			
			// Verificación del CAPTCHA ingresado por el usuario
			char input[I];
			printf("Ingrese el CAPTCHA: ");
			
			fgets(input,sizeof(input),stdin);
			//printf("[%s]\n",input);
			
			//system("pause");
			// Comparar el CAPTCHA ingresado con el generado
			//
			while(strcmp(input, captcha) != 0){
				int j;
				printf("CAPTCHA incorrecto.\n Ingrese correctamente el CAPTCHA\n");
				// Generar el CAPTCHA
				for (j = 0; j < CAPTCHA_LONG; j++) {
					captcha[j] = rand() % 26 + 'A'; // Generar una letra mayúscula aleatoria
					
				}
				captcha[j] = '\n';  // Agregar el carácter nulo al final de la cadena
				captcha[j+1] = '\0';
				// Mostrar el CAPTCHA al usuario
				printf("CAPTCHA: %s\n", captcha);
	
				fgets(input,sizeof(input),stdin);
				system("cls");
			}
			printf("¡CAPTCHA correcto!\n");
			InsertarNuevo(path,user,pass);
			system("pause");
			return 0;
		}
		
	}
