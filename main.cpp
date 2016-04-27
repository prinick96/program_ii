#include "core/core.cpp"

int main() {

  Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
  Lista *Materias_I = CreateEntity((char *) "data/materias_inscritas.txt",2,Materias_I);
  Lista *Materias = CreateEntity((char *) "data/materias.txt",3,Materias);
  Lista *Secciones = CreateEntity((char *) "data/secciones.txt",4,Secciones);
  Lista *Semestres = CreateEntity((char *) "data/semestres.txt",5,Semestres);
  Lista *Planillas = CreateEntity((char *) "data/planillas.txt",6,Planillas);

  Menu();

  return true;
}
