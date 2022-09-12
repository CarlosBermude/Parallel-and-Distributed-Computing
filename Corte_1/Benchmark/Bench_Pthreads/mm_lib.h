/********************************************************************************************
* Fecha: 30 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Carlos Bermudez
* Tema: Construcción Benchmark Multiplicacion de matrices
* Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
* Topico: Modulo para Doubles
*********************************************************************************************/
#ifndef MM_LIB_H_INCLUDED /*Si no esta definido */
#define MM_LIB_H_INCLUDED /*definalo */




/*** Función para crear aleatorios double***/
double random_double();

/**************** Función Inicialización double ****************/
void inicializar_double(double *matrizA,double *matrizB, double *matrizC,int n);

/**************** Función Inicialización double Aleatoria ****************/
void inicializar_double_rnd(double *matrizA,double *matrizB, double *matrizC,int n);

/**************** Función Impresión de tipo double****************/
void impresion_double(double *matriz, int n);


/**** Benchmark 05 ****/
/***** Multiplicación de Matrices: Por punteros double*****/
void mm_c_double(double *matrizA,double *matrizB,double *matrizC,int n);

/****Funcion evaluacion inicio del tiempo *****/
void punto_prueba_inicial();

/****Funcion evaluacion final del tiempo, impresión de resultados *****/
void punto_prueba_final();

#endif
