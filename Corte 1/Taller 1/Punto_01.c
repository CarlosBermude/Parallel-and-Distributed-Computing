/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>


/* 1.- Escribe un programa en C que acepte dos enteros del 			
	usuario y calcule el producto de los dos enteros. */
void productoInt(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 1: \n");
	
	/* Declaro el tipo de variable con su respectivo nombre */
	int a, b, producto;
	printf("----------------------------------------------");
	printf("\n Introduzca el primer entero: ");
	scanf("%i",&a);
	
	printf("\n Introduzca el segundo entero: ");
	scanf("%i",&b);
	
	producto = a * b;
	
	printf("----------------------------------------------\n"
	"Producto de los dos enteros anteriores: %i \n\n", producto);
	
}

int main(){
	/* Ejecución Punto 1 */
	productoInt();
	
	return 0;
}


