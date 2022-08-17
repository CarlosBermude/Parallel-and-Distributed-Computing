/******************************************
* Fecha: 16-agosto-2022
* Autor: Carlos Mario Bermudez Galvan
* Materia: Parallel and Distributed Computing
* Tema: Taller 1 - Programación en C
******************************************/

/* Se incluyen las bibliotecas básicas necesarias */
#include<stdio.h>
#include<math.h>


/* 1.- Escribe un programa en C que acepte dos enteros del 			
	usuario y calcule el producto de los dos enteros. */
void productoInt(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 1: \n");
	
	/* Declaro el tipo de variable con su respectivo nombre */
	int a, b, producto;
	printf("----------------------------------------------");
	printf("\n Introduzca el primer entero: ");
	scanf("%i",&a);
	
	printf("\n Introduzca el segundo entero: ");
	scanf("%i",&b);
	
	producto = a * b;
	
	printf("----------------------------------------------\n"
	"Producto de los dos enteros anteriores: %i \n\n", producto);
	
}

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

/* 3.- Escribe un programa en C para calcular la distancia entre los dos puntos. */
void distanciaEntreDosPuntos(){
printf("----------------------------------------------");
	printf("\n                PUNTO 3: \n");
	
	/*Se declaran las variables necesarias */
	float x1, y1, x2, y2, distancia;
	
	/* Se piden los datos requeridos para la prueba */
	printf("----------------------------------------------\n");
	printf("Ingrese x1: ");
	scanf("%f", &x1);
	printf("Ingrese y1: ");
	scanf("%f", &y1);
	printf("Ingrese x2: ");
	scanf("%f", &x2);
	printf("Ingrese y2: ");
	scanf("%f", &y2);
	
	/* Se realiza el calculo basado en la fórmula de distancia entre dos puntos */
	distancia = sqrt( pow((x2-x1),2) + pow((y2-y1),2));
	
	
	
	printf("\n----------------------------------------------\n");
	printf(" Datos de Prueba \n");
	printf("x1: %f", x1);
	printf("y1: %f", y1);
	printf("x2: %f", x2);
	printf("y2: %f", y2);
	printf("\n----------------------------------------------\n");
	printf(" Distancia entre dichos puntos : %f", distancia);
	printf("\n----------------------------------------------\n");
}

/* 4.- Escribe un programa en C para mostrar los 10 primeros números naturales. */
void numerosNaturales(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 4: \n");
	/* Se declaran las variables */
	int contador, limite;
	
	/* Se inicializan dependiendo del requerimiento */
	limite = 10;
	contador = 1;
	
	/*Se imprime toda la informacion solicitada */
	printf("\n-------------------------------------------------------------\n");
	printf("A continuacion se mostraran los 10 primeros numeros naturales ");
	printf("\n-------------------------------------------------------------\n\t\t");
	while(contador <= limite){
		printf("%i  ",contador);
		contador++;
	}
	printf("\n-------------------------------------------------------------\n");
	

}

/* 5.- Escribe un programa en C para mostrar el patrón como triángulo rectángulo usando un
asterisco. La cantidad de líneas del triangulo es ingresada por consola por el usuario, y el valor
máximo de líneas es de 14. */
void trianguloRectangulo(){
	printf("----------------------------------------------");
	printf("\n                PUNTO 5: \n");
	
	/* Se declaran las variables */
	int lineas, maximo, i, j;
	
	/*Se inicializan las variables */
	maximo = 14;
	lineas = 15;
	
	/* Se realiza el algoritmo de impresión requerido*/
	while (lineas > maximo){
		printf("Ingrese la cantidad de lineas: ");
		scanf("%i", &lineas);
		if(lineas > maximo){
			printf("\nERROR Ingrese un numero menor o igual a 14\n");
		}
	}
	
	for (i = 0; i < lineas; i++){
		for (j = 0; j < (i+1); j++){
			printf("*");
		}
		printf("\n");
	}
	
}


/* Función principal donde probar cada función requerida
*  en el taller 1  */
int main(){
	/* Ejecución Punto 1 */
	//productoInt();
	
	/* Ejecución Punto 2: */
	//convertirDias();
	
	/* Ejecución Punto 3: */
	//distanciaEntreDosPuntos();
	
	/* Ejecución Punto 4: */
	//numerosNaturales();
	
	/* Ejecución Punto 5: */
	//trianguloRectangulo();
	
	
	/* 6.- Escribe un programa que imprima una matriz de “1”, de tamaño NxN. El tamaño es
indicado por el usuario y debe ser siempre menor que 8. */
	
	int n, limite, i, j;
	limite = 8;
	n = 9;
	while (n >= limite){
		printf("Ingrese el tamanio de la matriz: ");
		scanf("%i", &n);
		if(n >= limite){
			printf("\nERROR Ingrese un numero menor a 8\n");
		}
	}
	int matriz[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			matriz[i][j] = 1;
		}
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %i ",matriz[i][j]);
		}
		printf("\n");
	}
	
	
		
	
	
	
	return 0;
}














