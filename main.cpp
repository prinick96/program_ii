#include "core/core.cpp"

int main() {

  Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
  Alumnos.Print();

  return true;
}
