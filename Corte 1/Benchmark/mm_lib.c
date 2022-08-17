/*************************************************
*Fecha: 09-agosto-2022
*Autor: Carlos Mario Bermudez Galvan
*Materia: Parallel and Distribuited Computing
*Tema: Biblioteca de funciones para  Multiplicación de matrices
**************************************************/

#include "mm_lib.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

/*	Se implementa  MM con iguales dimensiones
* 	Se inicializa las matrices con números aleatorios
*/

struct timespec inicioCuenta, finCuenta;

/* Función inicialización */
void inicializacion(int *matrizA, int *matrizB, int *matrizC, int N){
	int j, i;
	srand(time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrizA[i+j*N] = 3*(i+1);
			matrizB[i+j*N] = 2*(i+j);	
			matrizC[i+j*N] = 0;
		}
	}
}


/* Función Impresión */
void impresionMM(int matriz[], int N){
	int i, j;
	printf("\n	");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf(" %d",matriz[i+j*N]);
		}
		printf("\n	");
	}
}

/* Función Multiplicación */
void mm_clasica(int matrizA[], int matrizB[], int  matrizC[], int N){
	int i, j, k, suma;
	for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				suma = 0;
				for(k = 0; k < N; k++){
					suma += matrizA[j+k*N] * matrizB[k+i*N];
			}
			  matrizC[j+i*N] = suma;
		}
	}
}

/* Función evaluación inicio de tiempo */
void punto_prueba_inicial(){
	clock_gettime(CLOCK_MONOTONIC, &inicioCuenta);
}

/* Función evaluación final de tiempo, impresión de resultado */
void punto_prueba_final(){
	double total_time;
	clock_gettime(CLOCK_MONOTONIC, &finCuenta);
	total_time = (finCuenta.tv_sec - inicioCuenta.tv_sec)*1e9;
	total_time = (total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec)*1e-9;
	printf("\n\tTotal time ----> |%f| <----\n",total_time);
}

