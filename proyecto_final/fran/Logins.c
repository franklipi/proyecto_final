#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  login_menu(){
	int opc;

do{
	fflush (stdin);
	system ("cls");
	printf ("Bienvenido a FIO \n");
	printf ("1 \n");
	printf ("2_Mostrar el arbol.\n");
	printf ("3_Buscar un nodo en el arbol.\n");
	printf ("4_Borrar un nodo del arbol\n");
	printf ("5_Salir\n");
	scanf("%d",&opc);
	system ("cls");
}while((opc!=1&&opc!=2&&opc!=3&&opc!=4));
return opc;
}
