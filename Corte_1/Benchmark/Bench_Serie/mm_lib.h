/*************************************************
*Fecha: 09-agosto-2022
*Autor: Carlos Mario Bermudez Galvan
*Materia: Parallel and Distribuited Computing
*Tema: Biblioteca de funciones para  Multiplicación de matrices
**************************************************/

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

double random_double();
void inicializacion_double_rnd(double *matrizA, double *matrizB, double *matrizC, int N);
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int N);
void mm_c_double(double *matrizA, double *matrizB, double  *matrizC, int N);
void printMatrix(int SZ, double *M);

int random_int(); 
void inicializacion_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N);
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int N);
void impresion_int(int matriz[], int N);
void mm_clasica_int(int *matrizA, int *matrizB, int  *matrizC, int N);
void mm_c_int(int *matrizA, int *matrizB, int  *matrizC, int N);
void punto_prueba_inicial();
void punto_prueba_final();

#endif
