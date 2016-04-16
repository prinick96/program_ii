#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

/*
  #Hace lo mismo que el explode() de PHP
  #Recibe un *** que viene a ser el vector resultante
  #Recibe *str que es el string
  #Recibe el delimitador, por ejemplo
  explode(char ***vector, "Hola_Dos",'_')

  vector[0] -> Hola
  vector[1] -> Dos

  Con el fin de separar elementos de los archivos .txt
*/
void explode(char ***arr_ptr, char *str, char delimiter);
