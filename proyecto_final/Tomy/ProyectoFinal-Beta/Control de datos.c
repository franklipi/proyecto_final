#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool validarUsuario(const char* user) {
	
	int longitudMinima = 4;
	int longitudMaxima = 20;
	
	// Verificar la longitud del nombre de usuario
	int longitud = strlen(user);
	if (longitud < longitudMinima || longitud > longitudMaxima) {
		return false;
	}
	
	// Verificar caracteres permitidos
	for (int i = 0; i < longitud; i++) {
		char caracter = user[i];
		if (!(caracter >= 'a' && caracter <= 'z') &&
			!(caracter >= 'A' && caracter <= 'Z') &&
			!(caracter >= '0' && caracter <= '9') &&
			!(caracter == '_' || caracter == '-' || caracter == '.')) {
			return false;
		}
	}
	
	return true;
}
bool validarPass(const char* pass) {
	
	size_t len = strlen(pass);
	if (len < 6) {
		return false; // Longitud incorrecta
	}
	
	// Verificar si la contraseña contiene al menos un dígito y un carácter especial
	bool tieneDigito = false;
	bool tieneCaracterEspecial = false;
	
	for (size_t i = 0; i < len; i++) {
		if (isdigit(pass[i])) {
			tieneDigito = true;
		} else if (!isalnum(pass[i])) {
			tieneCaracterEspecial = true;
		}
	}
	
	return tieneDigito && tieneCaracterEspecial; // Contraseña válida si cumple ambas condiciones
}




