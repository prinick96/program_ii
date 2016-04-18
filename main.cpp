#include "core/core.cpp"

int main() {

  Lista *Alumnos = CreateEntity((char *) "data/alumnos.txt",1,Alumnos);
  Lista *Materias_I = CreateEntity((char *) "data/materias_inscritas.txt",2,Materias_I);
  Lista *Materias = CreateEntity((char *) "data/materias.txt",3,Materias);
  Lista *Secciones = CreateEntity((char *) "data/secciones.txt",4,Secciones);
  Lista *Semestres = CreateEntity((char *) "data/semestres.txt",5,Semestres);
  Lista *Planillas = CreateEntity((char *) "data/planillas.txt",6,Planillas);

  cout << "Alumnos:" << endl;
  Alumnos->DebugPrint();
  cout << "\n\nMaterias Inscritas:" << endl;
  Materias_I->DebugPrint();
  cout << "\n\nMaterias:\n" << endl;
  Materias->DebugPrint();
  cout << "\n\nSecciones:\n" << endl;
  Secciones->DebugPrint();
  cout << "\n\nSemestres:\n" << endl;
  Semestres->DebugPrint();
  cout << "\n\nPlanillas:\n" << endl;
  Planillas->DebugPrint();

  return true;
}
