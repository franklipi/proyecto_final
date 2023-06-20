
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *validarUser() {
	
	static char users[26];

	bool band;
	do{
		band=true;
		printf("Ingrese el usuario: "); 
		scanf("%26s",users);
		
		// Eliminar el car�cter de nueva l�nea ('\n') al final del string
		size_t longitud = strlen(users);
		if (longitud > 0 && users[longitud - 1] == '\n') {
			users[longitud - 1] = '\0';
		}
		
		// Verificar la longitud del nombre de usuario
		longitud = strlen(users);
		if (longitud < 4 || longitud > 26) {
			band = false;
		}
		
		// Verificar caracteres permitidos
		for (int i = 0; i < longitud; i++) {
			char caracter = users[i];
			if (!(caracter >= 'a' && caracter <= 'z') &&
				!(caracter >= 'A' && caracter <= 'Z') &&
				!(caracter >= '0' && caracter <= '9') &&
				!(caracter == '_' || caracter == '-' || caracter == '.')) {
				band = false;
			}
		}
		
		
		if ((!band)) {
			puts("Usuario invalido... Reingrese...");\
		}else{
			band=true;
			//printf("Datos ingresados correctamente\n ");
		}
		
	}while(!band); // Usuario valido si cumple las condiciones de caracteres permitidos
	
	return users;
}


char *validarPass() {
	
	bool band;
	int i;
	static char passw[26];
	
	do {
	
		printf("Ingrese la contrase�a: ");
		scanf("%26s",passw);
		
		size_t len = strlen(passw);
		if (len < 6 || len > 26) {
			band = false; // Longitud incorrecta
		}else{
			// Verificar si la contrase�a contiene al menos un d�gito y un car�cter especial
			for ( i = 0; i < len; i++) {
				if (isdigit(passw[i])) {
					band = true;
				} else if (!isalnum(passw[i])) {
					band = true;
				}
			}
		}
		
		if ((!band)) {
			puts("Password invalido... Reingrese...");\
			
		}else{
		band=true;
		printf("Datos ingresados correctamente\n ");
	}
		
	}while(!band); // Contrase�a v�lida si cumple ambas�condiciones
	
	return passw;
}


























