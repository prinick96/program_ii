#include "core.h"

array_s *OpFile(char *route) {
  FILE * f = fopen(route,"r");
  array_s *vector = (array_s *) malloc(1);
  if(f != NULL ) {
    char *tmp = (char *) malloc(sizeof(char) * 180);
    unsigned int bytes = 0, x = 0;
    while (0 == feof(f)) {
      bytes = bytes + sizeof(array_s);
      vector = (array_s *) realloc(vector,bytes);
      fgets(tmp,180,f);
      vector[x].str = tmp;
      x++;
    }
    vector[x - 1].str = "END";
  } else {
    free(vector);
    printf("ERROR: Abriendo archivo %s\n",route);
    exit(false);
  }
  fclose(f);

  return vector;
}

void *CreateEntity(array_s *entity,char *lista) {
  int *x = (int *) malloc(sizeof(int));
  void *list_dir = NULL;
  *x = 0;
  while (entity[*x].str != "END") {
    /*switch (lista) {
      case "alumnos":
        //crea con nodos para alumnos
      break;
      case "materias_inscritas":
        //crea nodos para materias inscritas
      break;
      case "materias":
        //lo mismo con materias
      break;
      case "secciones":
        //lo mismo con secciones
      break;
      case "semestres":
        //lo mismo con semestres
      break;
    }*/
    printf("%s",entity[*x].str);
    (*x)++;
  }
  free(x);

  return list_dir;
}
