#include "core/core.cpp"

Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
Lista *Materias_I = CreateEntity((char *) "data/materias_inscritas.txt",2,Materias_I);
Lista *Materias = CreateEntity((char *) "data/materias.txt",3,Materias);
Lista *Secciones = CreateEntity((char *) "data/secciones.txt",4,Secciones);
Lista *Semestres = CreateEntity((char *) "data/semestres.txt",5,Semestres);
Lista *Planillas = CreateEntity((char *) "data/planillas.txt",6,Planillas);

int main() {

  //load
  //Menu();

  Record *rec = new Record();

  AVL Arbol;
  for(int x = 1; x < 20; x++) {
    Arbol.Insertar(x,x*2,"semestral",1,"cod_materia");
  }

  rec->mostrar_por_anio(Arbol.raiz,"alguien");


  return true;
}
