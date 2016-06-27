#include "core/core.cpp"

Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
Lista *Materias_I = CreateEntity((char *) "data/materias_inscritas.txt",2,Materias_I);
Lista *Materias = CreateEntity((char *) "data/materias.txt",3,Materias);
Lista *Secciones = CreateEntity((char *) "data/secciones.txt",4,Secciones);
Lista *Semestres = CreateEntity((char *) "data/semestres.txt",5,Semestres);
Lista *Planillas = CreateEntity((char *) "data/planillas.txt",6,Planillas);

int main() {

  /*AVL Arbol;
  //const int nota, const int time, const string semestral, const int estado, const string cod_materia
  for(int i = 1; i < 20; i++) {
    Arbol.Insertar(20 + i,10 + i,"Mayo-Junio",1,"021545");
  }*/

  //verArbol(Arbol.raiz);

  Record *rec = new Record();

  //load
  //Menu();

  //rec->mostrar_por_notas(Arbol.raiz);

  return true;
}
