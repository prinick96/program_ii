#include "core.c"
#include "entities.c"

int main() {

  //Creación de todas las listas doblemente enlazadas para las entidades
  node_alumno *Alumnos = NULL; //Lista con alumnos
  node_materia_inscrita *Materias_I = NULL; //Lista con las materias inscritas
  node_materia *Materias = NULL; //Lista con las materias
  node_seccion *Secciones = NULL; //Lista con las secciones
  node_semestre *Semestres = NULL; //Lista con los semestres
  node_planilla *Planillas = NULL; //Lista con las planillas de solicitud de inscripción
  //Fin de creación de listas

  //Carga de datos para todas las listas
  Alumnos = CreateAlumnos(Alumnos,"data/alumnos.txt");
  Materias_I = CreateMaterias_I(Materias_I,"data/materias_inscritas.txt");
  //Fin de carga de datos para todas las listas


  //Solo para ver como se agrega alumnos por ejemplo...
  while (Alumnos != NULL) {
    printf("%p ant<- %p ->sig %p nombre %s\n",Alumnos->ant,Alumnos,Alumnos->sig,Alumnos->nombre);
    Alumnos = Alumnos->sig;
  }

  return true;
}
