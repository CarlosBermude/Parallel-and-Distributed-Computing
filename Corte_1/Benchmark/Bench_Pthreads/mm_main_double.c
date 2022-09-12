/********************************************************************************************
* Fecha: 1 Septiembre 2022 
* Profesor: John Corredor, PhD
* Autor: Carlos Bermudez
* Tema: Construcción Benchmark Multiplicacion de matrices
*Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
*********************************************************************************************/


//Validar multiplicacion de matrices
//Revisar warning
//Revisar que los procesos si se estan realizando correctamente
//malloc y free de matrices
#include <stdlib.h> /*Para el atof*/
#include "mm_lib.h"
#include <pthread.h>
#include <stdio.h>
#include <omp.h>



/** Funcion puntero para envio de PROBLEMA **/
/* La idea principal es dividir la Matriz A en porciones, 
* tal que cada porcion vaya a un hilo. Cada hilo se podrá
* identificar, pasando como argumento a la función. La
* solución pñanteada envia toda la matriz B para cada hilo.
*/


/*Se declaran las variables globales, en una estructura de datos */
typedef struct arguments_hilos{
	double *Arg_matA;
	double *Arg_matB;
	double *Arg_matC;
	int Arg_Num_Hilos;
	int Arg_Dimension;
	int Arg_ID_Hilo;	
}  arg_hilos;




void *mm_clasica(void *argHILO_mm){
	//Identificador inicia en (0)
	//500*(0) apunta al inicio
	//500*(0+1) apunta al final

	//500*(1) Inicio 
	//500*(1+1) Final
	
	/* Se castea argHILO como arg_hilos */
	double *a = ((arg_hilos *) argHILO_mm)->Arg_matA;
	double *b = ((arg_hilos *) argHILO_mm)->Arg_matB;
	double *c = ((arg_hilos *) argHILO_mm)->Arg_matB;
	int ID_Hilo = ((arg_hilos *) argHILO_mm)->Arg_ID_Hilo; 
	int N_mm = ((arg_hilos *) argHILO_mm)->Arg_Dimension;
	int Num_Hilos_mm = ((arg_hilos *) argHILO_mm)->Arg_Num_Hilos;
	
	
	int porcion = N_mm/Num_Hilos_mm;//Porcion de la matriz
	int ini_porcion, fin_porcion;//Inicio y fin de la porcion

	ini_porcion = ID_Hilo*porcion;//Inicio de la porcion
	fin_porcion = (ID_Hilo+1)*porcion;//Fin de la porcion
	for(int i=ini_porcion;i<fin_porcion;i++){
		for(int j=0;j<N_mm;j++){
			double suma= 0;
			/**Punteros Auxiliares **/
			 double *pA,*pB;
		  	pA = a + (i*N_mm);
		  	pB = b + j;
			for(int k=0;k<N_mm;k++,pA++,pB+=N_mm){
				suma+=(*pA * *pB);
			}
			c[j+i*N_mm] = suma;
		}
	}
	return 0;
}

int main(int argc, char **argv){
	double *matA, *matB, *matC;
        int N=(int)atof(argv[1]); // Cantidad de Fila(Columnas
	int Num_Hilos = (int)atof(argv[2]); 
	
        int MAX_NUM_HILOS = omp_get_max_threads();
        printf("%d \n",MAX_NUM_HILOS);
        

	
	if((Num_Hilos < 0 || Num_Hilos > MAX_NUM_HILOS || !(N % Num_Hilos == 0))){
		printf("Revise datos de entrada");
		exit(0);
	}
	
	
	
	
	
	/****Declaración de matrices con apuntadores a memoria de tipo int****/
	pthread_t *hilos; //Vector de hilos
	
	arg_hilos arg_threads[Num_Hilos];
	
	
	// Reserva memoria con MALLOC
	
	matA = (double *) malloc(N*N*sizeof(double));
	matB = (double *) malloc(N*N*sizeof(double));
	matC = (double *) malloc(N*N*sizeof(double));
	
	
	//a=MEM_CHUNK;
	//a = (double *)malloc(N*N*sizeof(double));
	//b=a+(N*N);
	//c=b+(N*N);
	
	inicializar_double(matA,matB,matC,N);
	impresion_double(matA,N);
	impresion_double(matB,N);
	punto_prueba_inicial();

	//Se reserva la memoria para cada hilo 
	//Ubica un tamaño de memoria y luego la libera.
	//m memoria alloc ubicacion
	hilos = (pthread_t *)malloc(Num_Hilos*sizeof(pthread_t)); //Memoria 4bytes por hilo

	/**Se ha de repartir cada problema con su correspondiente carga, 
	 * en funcion de la cantidad de hilo**/
	for(int i=0; i<Num_Hilos; i++){
	
		// Se asigna vector de estructura por tipo para cada hilo
		arg_threads[i].Arg_matA = matA;
		arg_threads[i].Arg_matB = matB;
		arg_threads[i].Arg_matC = matC;
		arg_threads[i].Arg_Num_Hilos = Num_Hilos;
		arg_threads[i].Arg_Dimension = N;
		arg_threads[i].Arg_ID_Hilo = i;
		
		pthread_create(&hilos[i],NULL,mm_clasica, &arg_threads[i]);//Repartir el hilo
	}
	
	/** Se cierra o se unen los hilos **/
	for (int j=0; j<Num_Hilos; j++){
		pthread_join(hilos[j],NULL);
	}

	//mm_c_double(a,b,c,N);
	punto_prueba_final();
	impresion_double(matC,N);

	/* Liberación memoria */
	free(hilos);
	free(matA);
	free(matB);
	free(matC);
	
return 0;
}
