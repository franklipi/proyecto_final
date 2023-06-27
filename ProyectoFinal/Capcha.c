#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CAPTCHA_LENGTH 6

int main() {
	srand(time(NULL));
	
	char captcha[CAPTCHA_LENGTH + 1];
	int i;
	
	// Generar el CAPTCHA
	for (i = 0; i < CAPTCHA_LENGTH; i++) {
		captcha[i] = rand() % 26 + 'A';  // Generar una letra mayúscula aleatoria
	}
	captcha[i] = '\0';  // Agregar el carácter nulo al final de la cadena
	
	// Mostrar el CAPTCHA al usuario
	printf("CAPTCHA: %s\n", captcha);
	
	// Verificación del CAPTCHA ingresado por el usuario
	char input[CAPTCHA_LENGTH + 1];
	printf("Ingrese el CAPTCHA: ");
	scanf("%s", input);
	
	// Comparar el CAPTCHA ingresado con el generado
	if (strcmp(input, captcha) == 0) {
		printf("¡CAPTCHA correcto!\n");
	} else {
		printf("CAPTCHA incorrecto.\n");
	}
	
	return 0;
}


