#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar un nombre de usuario en la pila
struct NodoPila {
	char nombre[50];
	struct NodoPila* siguiente;
};

// Estructura para almacenar las solicitudes de amistad
struct NodoSolicitud {
	char nombre[50];
	struct NodoPila* pilaAmigos;
	struct NodoSolicitud* siguiente;
};

// Función para agregar una solicitud de amistad
void agregarSolicitud(struct NodoSolicitud** solicitudes, const char* nombreUsuario, const char* nombreAmigo) {
	// Buscar el nodo de la solicitud correspondiente al nombre de usuario
	struct NodoSolicitud* nodoUsuario = *solicitudes;
	while (nodoUsuario != NULL && strcmp(nodoUsuario->nombre, nombreUsuario) != 0) {
		nodoUsuario = nodoUsuario->siguiente;
	}
	
	if (nodoUsuario == NULL) {
		// El nodo de solicitud para el nombre de usuario no existe, crear uno nuevo
		nodoUsuario = (struct NodoSolicitud*)malloc(sizeof(struct NodoSolicitud));
		strcpy(nodoUsuario->nombre, nombreUsuario);
		nodoUsuario->pilaAmigos = NULL;
		nodoUsuario->siguiente = *solicitudes;
		*solicitudes = nodoUsuario;
	}
	
	// Crear un nuevo nodo para el nombre del amigo y agregarlo a la pila
	struct NodoPila* nuevoAmigo = (struct NodoPila*)malloc(sizeof(struct NodoPila));
	strcpy(nuevoAmigo->nombre, nombreAmigo);
	nuevoAmigo->siguiente = nodoUsuario->pilaAmigos;
	nodoUsuario->pilaAmigos = nuevoAmigo;
}

// Función para mostrar las solicitudes de amistad
void mostrarSolicitudes(struct NodoSolicitud* solicitudes) {
	struct NodoSolicitud* nodoUsuario = solicitudes;
	
	while (nodoUsuario != NULL) {
		printf("Usuario: %s\n", nodoUsuario->nombre);
		
		struct NodoPila* nodoAmigo = nodoUsuario->pilaAmigos;
		printf("Amigos solicitantes:\n");
		while (nodoAmigo != NULL) {
			printf("- %s\n", nodoAmigo->nombre);
			nodoAmigo = nodoAmigo->siguiente;
		}
		
		nodoUsuario = nodoUsuario->siguiente;
		printf("\n");
	}
}

// Función para liberar la memoria de las solicitudes de amistad
void liberarSolicitudes(struct NodoSolicitud* solicitudes) {
	struct NodoSolicitud* nodoUsuario = solicitudes;
	
	while (nodoUsuario != NULL) {
		struct NodoPila* nodoAmigo = nodoUsuario->pilaAmigos;
		
		while (nodoAmigo != NULL) {
			struct NodoPila* nodoActual = nodoAmigo;
			nodoAmigo = nodoAmigo->siguiente;
			free(nodoActual);
		}
		
		struct NodoSolicitud* nodoActual = nodoUsuario;
		nodoUsuario = nodoUsuario->siguiente;
		free(nodoActual);
	}
}

// Ejemplo de uso
int main() {
	struct NodoSolicitud* solicitudes = NULL;
	
	agregarSolicitud(&solicitudes, "Usuario1", "Amigo1");
	agregarSolicitud(&solicitudes, "Usuario1", "Amigo2");
	agregarSolicitud(&solicitudes, "Usuario2", "Amigo3");
	agregarSolicitud(&solicitudes, "Usuario3", "Amigo4");
	agregarSolicitud(&solicitudes, "Usuario3", "Amigo5");
	
	mostrarSolicitudes(solicitudes);
	
	liberarSolicitudes(solicitudes);
	
	return 0;
}


