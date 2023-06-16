#include <stdio.h>
#include <windows.h>


#define RESET       0
#define BRIGHT      8

#define FOREGROUND_BLACK    0
#define FOREGROUND_BLUE     1
#define FOREGROUND_GREEN    2
#define FOREGROUND_CYAN     3
#define FOREGROUND_RED      4
#define FOREGROUND_MAGENTA  5
#define FOREGROUND_YELLOW   6
#define FOREGROUND_WHITE    7

#define BACKGROUND_BLACK    0
#define BACKGROUND_BLUE     16
#define BACKGROUND_GREEN    32
#define BACKGROUND_CYAN     48
#define BACKGROUND_RED      64
#define BACKGROUND_MAGENTA  80
#define BACKGROUND_YELLOW   96
#define BACKGROUND_WHITE    112

void SetColor(int foreground, int background)
{
	int color = foreground + background;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ResetColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_WHITE | BACKGROUND_BLACK);
}

void DrawMenu()
{
	SetColor(FOREGROUND_CYAN | BRIGHT, BACKGROUND_BLACK);
	printf("********** MENU *********\n");
	ResetColor();
	printf("1. Registrarse\n");
	printf("2. Logearse\n");
	printf("3. Gestionar amistades\n");
	printf("4. Salir\n");
	SetColor(FOREGROUND_CYAN | BRIGHT, BACKGROUND_BLACK);
	printf("***************************\n");
	ResetColor();
}


	
	
	bool esNombreUsuarioValido(const char* user) {
		
		int longitudMinima = 4;
		int longitudMaxima = 20;
		
		// Verificar la longitud del nombre de usuario
		int longitud = strlen(nombre);
		if (longitud < longitudMinima || longitud > longitudMaxima) {
			return false;
		}
		
		// Verificar caracteres permitidos
		for (int i = 0; i < longitud; i++) {
			char caracter = nombre[i];
			if (!(caracter >= 'a' && caracter <= 'z') &&
				!(caracter >= 'A' && caracter <= 'Z') &&
				!(caracter >= '0' && caracter <= '9') &&
				!(caracter == '_' || caracter == '-' || caracter == '.')) {
				return false;
			}
		}
		
		return true;
	}
	bool validarContrasena(const char* pass) {
	
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
		
		return tieneDigito && tieneCaracterEspecial; // Contraseña válida si cumple ambas condiciones
	}
	



void Logear()
{
	SetColor(FOREGROUND_RED | BRIGHT, BACKGROUND_BLACK);
	printf("Logearse\n");
	ResetColor();
}

/*void GestionarAmistades()
{
	int opcion;
	do {
		system("cls"); // Limpiar la pantalla
		SetColor(FOREGROUND_CYAN | BRIGHT, BACKGROUND_BLACK);
		printf("********** GESTIONAR AMISTADES **********\n");
		ResetColor();
		printf("1. Añadir amigo\n");
		printf("2. Eliminar amigo\n");
		printf("3. Buscar amigos\n");
		printf("4. Volver al menú principal\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			SetColor(FOREGROUND_YELLOW | BRIGHT, BACKGROUND_BLACK);
			printf("Añadir amigo\n");
			ResetColor();
			break;
		case 2:
			SetColor(FOREGROUND_YELLOW | BRIGHT, BACKGROUND_BLACK);
			printf("Eliminar amigo\n");
			ResetColor();
			break;
		case 3:
			SetColor(FOREGROUND_YELLOW | BRIGHT, BACKGROUND_BLACK);
			printf("Buscar amigos\n");
			ResetColor();
			break;
		case 4:
			printf("Volviendo al menú principal...\n");
			break;
		default:
			SetColor(FOREGROUND_RED | BRIGHT, BACKGROUND_BLACK);
			printf("Opción inválida. Por favor, ingrese una opción válida.\n");
			ResetColor();
			break;
		}
		
		printf("\nPresione cualquier tecla para continuar...");
		getchar();
		getchar();
		
	} while (opcion != 4);
}
*/
int main(int argc, char *argv[])
{
	int menu,val;
	
	
	struct nodo *arbol=NULL;
	char user[30];
	char pass[30];
	int opcion;
	
	do {
		system("cls"); // Limpiar la pantalla
		
		DrawMenu();
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			printf("\n Ingrese su nombre de usuario : \n");
			scanf("%s", user);
			while(!esNombreUsuarioValido(user)) {
				printf("El nombre de usuario no es válido.\n Ingrese un nombre de usuario correcto\n");
				scanf("%29s", user);
			}
			printf("Nombre registrado correctamente :\n");
			printf("Ingrese la contraseña (debe tener al menos 6 caracteres y contener al menos un dígito y un carácter especial):\n ");
			scanf("%29s", pass);
			
			// Validar la contraseña
			while(!validarContrasena(pass)) {
				printf("Contraseña inválida. Debe tener al menos 6 caracteres y contener al menos un dígito y un carácter especial\nIngrese una contraseña valida\n");
				scanf("%29s", pass);
				return 0;
			}
			
			// Las credenciales son válidas
			printf("Usuario registrado correctamente ! \n");
			arbol=insertarnodo(arbol,user,pass);
			break;
		case 2:
			Logear();
			break;
		case 3:
			GestionarAmistades();
			break;
		case 4:
			printf("Saliendo del programa...\n");
			break;
		default:
			SetColor(FOREGROUND_RED | BRIGHT, BACKGROUND_BLACK);
			printf("Opción inválida. Por favor, ingrese una opción válida.\n");
			ResetColor();
			break;
		}
		
		printf("\nPresione cualquier tecla para continuar...");
		getchar();
		getchar();
		
	} while (opcion != 4);
	
	return 0;
}
