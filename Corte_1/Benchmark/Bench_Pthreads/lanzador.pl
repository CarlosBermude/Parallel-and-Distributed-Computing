#!/usr/bin/perl


=begin comment

Fecha: 23 Agosto 2022
Autor: Carlos Bermudez
Tema: Ejecución automatizada de Benchmarks

Perl lenguaje interpretado
Fichero que quiero que interprete pasarlo a ejecutable
$ es para definir una variable 
=end comment
=cut

#Vector para los benchmarks
@Benchmarks = ("mm_main_double");

#Vector para las cargas
@Cargas = ("300","1600","4700");
#Número de repeticiones 
$n = 2;
#Se almacena la ubicacion
$Path ="/home/alejandro/Computacion_Paralela/Benchmarks_Entregable/Bench_Pthreads/";

#Se itera sobre 
#la cantidad de ejecutable 
#sobre la cantidad de cargas
#la cantidad de repeticiones

foreach $exes(@Benchmarks){
	foreach $carga (@Cargas){
	#Se crea un fichero para almacenar los datos
	#Con . se concatena
	$file = "Soluciones/".$exes."-size-".$carga.".txt";
		#printf("$Path$file\n");
		for ($i=0;$i<$n;$i++){
		system("$Path$exes $carga >>$file");
		#printf("$Path$exes $carga \n");
   	}
   	close($file);
   }
}

