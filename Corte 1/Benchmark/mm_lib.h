/*************************************************
*Fecha: 09-agosto-2022
*Autor: Carlos Mario Bermudez Galvan
*Materia: Parallel and Distribuited Computing
*Tema: Biblioteca de funciones para  Multiplicación de matrices
**************************************************/

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

void inicializacion(int matrizA[], int matrizB[], int matrizC[], int N);
void impresionMM(int matriz[], int N);
void mm_clasica(int matrizA[], int matrizB[], int  matrizC[], int N);
void punto_prueba_inicial();
void punto_prueba_final();

#endif
