/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>


/* 2.- Escribe un programa en C para convertir los días especificados en años, semanas y días.
Nota: Ignore el año bisiesto.*/
void convertirDias(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 2: \n");
	
	/*Se declaran las variables necesarias */
	int diasIngresados, anios, semanas, dias;
	
	/* Se piden los datos requeridos para la prueba */
	printf("----------------------------------------------\n");
	printf("Ingrese la cantidad de dias: ");
	scanf("%i", &diasIngresados);
	
	/* Se hacen las respectivas operaciones para el calculo solicitado */
	anios = diasIngresados / 365;
	semanas = (diasIngresados - (anios*365))/7;
	dias = diasIngresados - (semanas*7) - (anios*365);
	
	printf("\n----------------------------------------------\n");
	printf(" Datos de Prueba \n");
	printf("Numero de dias: %i", diasIngresados);
	printf("\n----------------------------------------------\n");
	printf(" Anios : %i", anios);
	printf("\n Semanas: %i", semanas);
	printf("\n Dias: %i\n", dias);
	printf("----------------------------------------------\n");
	
}


int main(){
	/* Ejecución Punto 2: */
	convertirDias();
	
	return 0;
}
