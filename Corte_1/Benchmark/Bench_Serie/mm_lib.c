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
#include <errno.h>
#include <unistd.h>

/*	Se implementa  MM con iguales dimensiones
* 	Se inicializa las matrices con números aleatorios
*/

struct timespec inicioCuenta, finCuenta;





/*** Función para crear aleatorios DOUBLE ***/
double random_double(){
	double min = 0.001, max = 0.9999999999999999;
	static int flag = -1;
	if((flag = (flag<0)))
		srand(time(NULL) + getpid());
	if (min > max)
		return errno = EDOM, NAN;
	return min + (double) rand()/((double) RAND_MAX/(max-min));
}

/* Función inicialización Aleatoria DOUBLE*/
void inicializacion_double_rnd(double *matrizA, double *matrizB, double *matrizC, int N){
	int j, i;
	srand(time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrizA[i+j*N] = random_double();
			matrizB[i+j*N] = random_double();	
			matrizC[i+j*N] = 0;
		}
	}
}

/* Función inicialización */
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int N){
	int j, i;
	srand(time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrizA[i+j*N] = 2*(i+j);
			matrizB[i+j*N] = 2*i + 3*j;	
			matrizC[i+j*N] = 0;
		}
	}
}

/* Función Multiplicación DOUBLE */
void mm_c_double(double *matrizA, double *matrizB, double  *matrizC, int N){
	int i, j, k;
	double suma=0.0;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			suma = 0;
			/** Punteros aruxiliares **/
			double *pA, *pB;
			pA = matrizA + (i*N);
			pB = matrizB + j;
			for(k = 0; k < N; k++, pA++, pB += N){
				suma += (*pA * *pB);
			}
			matrizC[j+i*N] = suma;
		}
	}
}

// Impresion matrix double
void printMatrix(int N, double *M){
	int i,j;
    for(i=0;i<N;++i){
        for(j=0;j<N;++j){
            printf("%f  ", M[j+i*N]);
        }
        printf("\n");
    }
}

/*** Función para crear aleatorios INT ***/
int random_int(){
	int min = 0, max = 9;
	static int flag = -1;
	if((flag = (flag<0)))
		srand(time(NULL) + getpid());
	if (min > max)
		return errno = EDOM, NAN;
	return min + (int) rand()/((int) RAND_MAX/(max-min));
}

/* Función inicialización Aleatoria INT*/
void inicializacion_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N){
	int j, i;
	srand(time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrizA[i+j*N] = random_int();
			matrizB[i+j*N] = random_int();	
			matrizC[i+j*N] = 0;
		}
	}
}



/* Función inicialización */
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int N){
	int j, i;
	srand(time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matrizA[i+j*N] = 2*(i+j);
			matrizB[i+j*N] = 2*i + 3*j;	
			matrizC[i+j*N] = 0;
		}
	}
}


/* Función Impresión */
void impresion_int(int *matriz, int N){
	int i, j;
	if( N < 5){ 
		printf("\n	");
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				printf(" %d",matriz[j+i*N]);
			}
			printf("\n	");
		}
		printf("\n---------------------------\n");
	}
}
/* Benchmark NO PUNTEROS */
/* Función Multiplicación */
void mm_clasica_int(int *matrizA, int *matrizB, int  *matrizC, int N){
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

/* Benchmark 01 - PUNTEROS */
/* Función Multiplicación */
void mm_c_int(int *matrizA, int *matrizB, int  *matrizC, int N){
	int i, j, k, suma;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			suma = 0;
			/** Punteros aruxiliares **/
			int *pA, *pB;
			pA = matrizA + (i*N);
			pB = matrizB + j;
			for(k = 0; k < N; k++, pA++, pB += N){
				suma += (*pA * *pB);
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
	printf("%f\n",total_time);
}

