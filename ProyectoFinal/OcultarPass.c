#include <stdio.h>
#include <conio.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
	char password[MAX_PASSWORD_LENGTH + 1];
	int i = 0;
	char ch;
	
	printf("Ingrese la contrasena: ");
	
	while ((ch = getch()) != '\r') {  // Obtener caracteres sin mostrarlos en pantalla
		if (ch == '\b') {  // Si se presiona la tecla de retroceso (backspace)
			if (i > 0) {
				i--;
				printf("\b \b");  // Borrar el último caracter mostrado en pantalla
			}
		} else if (i < MAX_PASSWORD_LENGTH) {
			password[i++] = ch;
			printf("*");  // Mostrar un asterisco en lugar del caracter
		}
	}
	
	password[i] = '\0';  // Agregar el carácter nulo al final de la cadena de contraseña
	
	printf("\nLa contrasena ingresada es: %s\n", password);
	
	return 0;
}
