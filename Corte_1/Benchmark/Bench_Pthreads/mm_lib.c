/********************************************************************************************
* Fecha: 30 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Carlos Bermudez
* Tema: Construcción Benchmark Multiplicacion de matrices
* Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
* Topico: Modulo para Doubles
*********************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>



/*** Función para crear aleatorios double***/
double random_double(){
	double min = 0.001, max = 9.999;
	static int flag = -1; /*Valor imposible*/
	if((flag = (flag<0)))
		srand(time(NULL)+getpid()); /*Semilla*/
		/*getpid() identificador del proceso*/
	if(min>max)
		return errno= EDOM,NAN; /*Indica cual es el error*/
	return min+ (double)rand()/((double)RAND_MAX/(max-min));	
}



/**************** Función Inicialización double ****************/
void inicializar_double(double *matrizA,double *matrizB, double *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= 2.0*(i+j);
		  matrizB[i+j*n] = 2.0*i+3.0*j;
		  matrizC[i+j*n]= 0;
		}
	}
}

/**************** Función Inicialización double Aleatoria ****************/
void inicializar_double_rnd(double *matrizA,double *matrizB, double *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= random_double();
		  matrizB[i+j*n] = random_double();
		  matrizC[i+j*n]= 0;
		}
	}
}

/**************** Función Impresión de tipo double****************/
void impresion_double(double *matriz, int n){
	int i,j;
	if(n<5){
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  printf(" %f ",matriz[j+i*n]);	  
		}
		printf("\n");
	}
	printf("\n-------------------\n");
	}
}


/**** Benchmark 05 ****/
/***** Multiplicación de Matrices: Por punteros double*****/
void mm_c_double(double *matrizA,double *matrizB,double *matrizC,int n){
	int i,j,k;
	double suma;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  suma=0;
		  /**Punteros Auxiliares **/
		  /*int *pA,*pB;*/
		  double *pA,*pB;
		  pA = matrizA + (i*n);
		  pB = matrizB + j;
		  /*Puntero A aumenta por la misma fila*/
		  /*Puntero B aumenta por la misma columna, lo hace por saltos*/
			for(k=0;k<n;k++,pA++,pB+=n){
				suma+=(*pA * *pB);
			}
			matrizC[j+i*n]=suma;
		}
	}
}


/*Estructura de datos, metodos que representan una estructura de tipo main*/
struct timespec inicioCuenta,  finCuenta;

/****Funcion evaluacion inicio del tiempo *****/
void punto_prueba_inicial(){
	/*Clock principal del kernell*/
	/*Balanceo de cargas multicores*/
	/*Tiempo global Lo ve desde arriba la ejecucion de procesos*/
	/*Planificador poder identificador de proceso, pedir en que momento pedir el tiempo, y segun que hace el proceso
	  			
	*/
 	clock_gettime(CLOCK_MONOTONIC,&inicioCuenta);
}

/****Funcion evaluacion final del tiempo, impresión de resultados *****/
void punto_prueba_final(){
	double total_time;
 	clock_gettime(CLOCK_MONOTONIC,&finCuenta);
 	total_time = (finCuenta.tv_sec - inicioCuenta.tv_sec)*1e9;
 	total_time = (total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec)*1e-9;
 	/*De segundos a nanosegundos y luego a segundos*/
 	printf("\nTotal time: %f\n",total_time); 	
}

