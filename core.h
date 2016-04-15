#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

//Define la cantidad de registros iniciales para cada entidad
#define ini_alumnos 1
#define ini_materias 4
#define ini_materias_inscritas 1
#define ini_secciones 1
#define ini_semestres 1

typedef struct {
  char *str;
} array_s;

/*
  #Recibe la ruta de un archivo como parámetro.
  #Devuelve un vector de tipo array_s, donde cada posición del vector es
  un string con cada linea del archivo pasado por "route".
*/
array_s *OpFile(char *route);

/*
  #array_s *entity: el vector con toda la información proveniente del archivo
  #char *lista: servirá para definir que lista quiero crear
  #Devuelve un puntero void de la direccion de memoria de la lista creada
*/
void *CreateEntity(array_s *entity,char *lista);
