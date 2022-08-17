/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>
#include<math.h>


/* 3.- Escribe un programa en C para calcular la distancia entre los dos puntos. */
void distanciaEntreDosPuntos(){
printf("----------------------------------------------");
	printf("\n                PUNTO 3: \n");
	
	/*Se declaran las variables necesarias */
	float x1, y1, x2, y2, distancia;
	
	/* Se piden los datos requeridos para la prueba */
	printf("----------------------------------------------\n");
	printf("Ingrese x1: ");
	scanf("%f", &x1);
	printf("Ingrese y1: ");
	scanf("%f", &y1);
	printf("Ingrese x2: ");
	scanf("%f", &x2);
	printf("Ingrese y2: ");
	scanf("%f", &y2);
	
	/* Se realiza el calculo basado en la fórmula de distancia entre dos puntos */
	distancia = sqrt( pow((x2-x1),2) + pow((y2-y1),2));
	
	
	
	printf("\n----------------------------------------------\n");
	printf(" Datos de Prueba \n");
	printf("x1: %f", x1);
	printf("y1: %f", y1);
	printf("x2: %f", x2);
	printf("y2: %f", y2);
	printf("\n----------------------------------------------\n");
	printf(" Distancia entre dichos puntos : %f", distancia);
	printf("\n----------------------------------------------\n");
}


int main(){
	/* Ejecución Punto 3: */
	distanciaEntreDosPuntos();
	
	return 0;
}


