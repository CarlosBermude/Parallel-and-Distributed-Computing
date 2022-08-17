/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>


/* 4.- Escribe un programa en C para mostrar los 10 primeros números naturales. */
void numerosNaturales(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 4: \n");
	/* Se declaran las variables */
	int contador, limite;
	
	/* Se inicializan dependiendo del requerimiento */
	limite = 10;
	contador = 1;
	
	/*Se imprime toda la informacion solicitada */
	printf("\n-------------------------------------------------------------\n");
	printf("A continuacion se mostraran los 10 primeros numeros naturales ");
	printf("\n-------------------------------------------------------------\n\t\t");
	while(contador <= limite){
		printf("%i  ",contador);
		contador++;
	}
	printf("\n-------------------------------------------------------------\n");
	

}

int main(){
	/* Ejecución Punto 4: */
	numerosNaturales();
	
	return 0;
}


