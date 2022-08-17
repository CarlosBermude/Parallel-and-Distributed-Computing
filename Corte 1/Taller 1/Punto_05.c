/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>


/* 5.- Escribe un programa en C para mostrar el patrón como triángulo rectángulo usando un
asterisco. La cantidad de líneas del triangulo es ingresada por consola por el usuario, y el valor
máximo de líneas es de 14. */
void trianguloRectangulo(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 5: \n");
	
	/* Se declaran las variables */
	int lineas, maximo, i, j;
	
	/*Se inicializan las variables */
	maximo = 14;
	lineas = 15;
	
	/* Se realiza el algoritmo de impresión requerido*/
	while (lineas > maximo){
		printf("Ingrese la cantidad de lineas: ");
		scanf("%i", &lineas);
		if(lineas > maximo){
			printf("\nERROR Ingrese un numero menor o igual a 14\n");
		}
	}
	
	for (i = 0; i < lineas; i++){
		for (j = 0; j < (i+1); j++){
			printf("*");
		}
		printf("\n");
	}
	
}


int main(){
	/* Ejecución Punto 5 */
	trianguloRectangulo();
	
	return 0;
}


