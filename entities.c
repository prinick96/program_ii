#include "headers/entities.h"

node_alumno *AddAlumno(node_alumno *Lista,char *elements) {
  node_alumno *nuevo_nodo, *tmp = NULL;
  nuevo_nodo = (node_alumno *) malloc(sizeof(node_alumno));
  if(nuevo_nodo != NULL) {

    char **elemento;
    explode(&elemento,elements, '_');
    nuevo_nodo->cedula = atoi(elemento[0]);
    nuevo_nodo->expediente = elemento[1];
    nuevo_nodo->nombre = elemento[2];
    nuevo_nodo->nacimiento = elemento[3];
    nuevo_nodo->indice = atoi(elemento[4]);
    nuevo_nodo->creditos_extra = atoi(elemento[5]);
    nuevo_nodo->semestre = atoi(elemento[6]);
    nuevo_nodo->sig = NULL;
    if(Lista == NULL) {
      nuevo_nodo->ant = NULL;
      Lista = nuevo_nodo;
    } else {
      tmp = Lista;
      while (tmp->sig != NULL) {
        tmp = tmp->sig;
      }
      nuevo_nodo->ant = tmp;
      tmp->sig = nuevo_nodo;
    }

  } else {
    puts("No hay memoria suficiente para llenar lista ALUMNOS");
    exit(false);
  }

  return Lista;
}

node_alumno *CreateAlumnos(node_alumno *Lista,char *route) {
  FILE * f = fopen(route,"r");
  if(f != NULL ) {
    char elements[200];
    while (0 == feof(f)) {
      fgets(elements,200,f);
      Lista = AddAlumno(Lista,elements);
    }
  } else {
    printf("ERROR: Abriendo archivo %s\n",route);
    exit(false);
  }
  fclose(f);

  return Lista;
}

node_materia_inscrita *AddMateria_I(node_materia_inscrita *Lista,char *elements) {
  node_materia_inscrita *nuevo_nodo, *tmp = NULL;
  nuevo_nodo = (node_materia_inscrita *) malloc(sizeof(node_alumno));
  if(nuevo_nodo != NULL) {

    char **elemento;
    explode(&elemento,elements, '_');
    nuevo_nodo->code_materia = elemento[0];
    nuevo_nodo->code_seccion = elemento[1];
    nuevo_nodo->cedula_inscrito = atoi(elemento[2]);
    nuevo_nodo->sig = NULL;
    if(Lista == NULL) {
      nuevo_nodo->ant = NULL;
      Lista = nuevo_nodo;
    } else {
      tmp = Lista;
      while (tmp->sig != NULL) {
        tmp = tmp->sig;
      }
      nuevo_nodo->ant = tmp;
      tmp->sig = nuevo_nodo;
    }

  } else {
    puts("No hay memoria suficiente para llenar lista ALUMNOS");
    exit(false);
  }

  return Lista;
}

node_materia_inscrita *CreateMaterias_I(node_materia_inscrita *Lista,char *route) {
  FILE * f = fopen(route,"r");
  if(f != NULL ) {
    char elements[200];
    while (0 == feof(f)) {
      fgets(elements,200,f);
      Lista = AddMateria_I(Lista,elements);
    }
  } else {
    printf("ERROR: Abriendo archivo %s\n",route);
    exit(false);
  }
  fclose(f);

  return Lista;
}
