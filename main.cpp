#include "core/core.cpp"

Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
Lista *Materias_I = CreateEntity((char *) "data/materias_inscritas.txt",2,Materias_I);
Lista *Materias = CreateEntity((char *) "data/materias.txt",3,Materias);
Lista *Secciones = CreateEntity((char *) "data/secciones.txt",4,Secciones);
Lista *Semestres = CreateEntity((char *) "data/semestres.txt",5,Semestres);
Lista *Planillas = CreateEntity((char *) "data/planillas.txt",6,Planillas);

int main() {

  // Un árbol de enteros
  AVL ArbolInt;

  // Inserción de nodos en árbol:
  ArbolInt.Insertar(6);
  ArbolInt.Insertar(77);
  ArbolInt.Insertar(8);
  ArbolInt.Insertar(84);
  ArbolInt.Insertar(9);
  ArbolInt.Insertar(11);
  ArbolInt.Insertar(11);
  ArbolInt.Insertar(16);
  ArbolInt.Insertar(15);
  ArbolInt.Insertar(121);
  ArbolInt.Insertar(112);
  ArbolInt.Insertar(0);
  ArbolInt.Insertar(45);
  ArbolInt.Insertar(3);
  ArbolInt.Insertar(4);
  ArbolInt.Insertar(5);


  verArbol(ArbolInt.raiz,1);


  cin.get();

  return true;
}
