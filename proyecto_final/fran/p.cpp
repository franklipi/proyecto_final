#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compararStrings(const void* a, const void* b) {
	const char** str1 = (const char**)a;
	const char** str2 = (const char**)b;
	
	return strcmp(*str1, *str2);
}

int main() {
	int numStrings;
	
	
	// Crear un arreglo dinámico de punteros a cadenas de caracteres
	char** punterosStrings = malloc(numStrings * sizeof(char*));
	if (punterosStrings == NULL) {
		printf("Error: no se pudo asignar memoria.\n");
		return 1;
	}
	
	// Leer las cadenas de caracteres desde la entrada estándar
	for (int i = 0; i < numStrings; i++) {
		char buffer[100];
		printf("Ingrese el string #%d: ", i + 1);
		scanf("%s", buffer);
		
		punterosStrings[i] = malloc((strlen(buffer) + 1) * sizeof(char));
		if (punterosStrings[i] == NULL) {
			printf("Error: no se pudo asignar memoria.\n");
			// Liberar la memoria asignada anteriormente
			for (int j = 0; j < i; j++) {
				free(punterosStrings[j]);
			}
			free(punterosStrings);
			return 1;
		}
		
		strcpy(punterosStrings[i], buffer);
	}
	
	printf("\nStrings sin ordenar:\n");
	for (int i = 0; i < numStrings; i++) {
		printf("%s\n", punterosStrings[i]);
	}
	
	qsort(punterosStrings, numStrings, sizeof(char*), compararStrings);
	
	printf("\nStrings ordenados:\n");
	for (int i = 0; i < numStrings; i++) {
		printf("%s\n", punterosStrings[i]);
	}
	
	// Liberar la memoria asignada
	for (int i = 0; i < numStrings; i++) {
		free(punterosStrings[i]);
	}
	free(punterosStrings);
	
	return 0;
}
