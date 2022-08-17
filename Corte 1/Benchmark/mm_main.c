/*************************************************
*Fecha: 09-agosto-2022
*Autor: Carlos Mario Bermudez Galvan
*Materia: Parallel and Distribuited Computing
*Tema: Construcción Benchmark Multiplicación de matrices

# carlosbermudezgalvan132@gmail.com
**************************************************/

#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>

/***** Se requiere reservar un Espacio de Memoria ************/
#define DATA_SIZE (1024*1024*64*3)
static int  MEM_CHUNK[DATA_SIZE];

int main(int argc, char **argv){
	int N;
	N = (int) atof(argv[1]);

	
	/*Declaración de matrices con apuntadores a memoria*/
	int *a, *b, *c;
	a = MEM_CHUNK;
	b = a + *MEM_CHUNK;
	c = b + *MEM_CHUNK;
	
	inicializacion(a, b, c, N);
	
	impresionMM(a, N);
	
	/*Multiplicación de matrices: Clásica*/
	punto_prueba_inicial();
	//mm_clasica(a, b, c, N);
	punto_prueba_final();
	
	return 0;
}
