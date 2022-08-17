#*************************************************
#Fecha: 09-agosto-2022
#Autor: Carlos Mario Bermudez Galvan
#Materia: Parallel and Distribuited Computing
#Tema: Construcción Benchmark Multiplicación de matrices
#Tòpico: Script Automatizacion Compilacion
#*************************************************/

GCC = gcc
FLAGS = -ansi -std=c99 -pedantic -Wall -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm

PROGS = mm_main

all: $(PROGS)

mm_main: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)
	
clean:
	$(RM) *.o $(PROGS)
