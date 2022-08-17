/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>


/* 6.- Escribe un programa que imprima una matriz de “1”, de tamaño NxN. El tamaño es
indicado por el usuario y debe ser siempre menor que 8. */

void generarImprimirMatriz(){
	/* Declaración de variables */
	int n, limite, i, j;
	limite = 8;
	n = 9;
	
	/* Control de requisitos (tamanio maximo debe ser 7) */
	while (n >= limite){
		printf("Ingrese el tamanio de la matriz: ");
		scanf("%i", &n);
		if(n >= limite){
			printf("\nERROR Ingrese un numero menor a 8\n");
		}
	}
	
	/* Declaración y relleno de la matriz */
	int matriz[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			matriz[i][j] = 1;
		}
	}
	/* Impresión de la matriz */
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %i ",matriz[i][j]);
		}
		printf("\n");
	}
	
}


int main(){
	/* Ejecución Punto 5: */
	generarImprimirMatriz();
	
	return 0;
}


