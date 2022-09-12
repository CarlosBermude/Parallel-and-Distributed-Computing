#!/usr/bin/perl

###################################################
#Fecha : 23 Agosto 2022
#Autor: Carlos Bermudez
#Tema: Ejecución automatizada de Benchmarks
###################################################

#Vector para los Benchmarks
@Benchmarks = ("mm_main", "mm_main_int_rnd", "mm_main_double", "mm_main_double_rnd");
#Vector para las cargas
@Carga = ("280", "300", "350", "400", "450", "500", "600", "800", "1000", "1500", "2000", "2500");
#Numero de repeticiones
$n = 35;
#Se almacena la ubicación
$Path = "/home/carlos/Documents/Parallel-and-Distributed-Computing/Corte_1/Benchmark/Bench_Serie/";
#$Path = `pwd`;
#chomp($Path);
#Se itera sobre
#la cantidad de ejecutables
#la cantidad de cargas
#la cantidad de repeticiones

foreach $exes (@Benchmarks){
	foreach $carga (@Carga){
		#Se crea un fichero apara almacenar los datos
		$file = "Soluciones/".$exes."-size-".$carga.".txt";
		for($i=0;$i<$n;$i++){
			system("$Path$exes $carga >> $file");
			printf("$Path$exes $carga\n");
		}
		close($file);
	}
}

printf("Finalizado");






