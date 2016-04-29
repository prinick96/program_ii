/*
  Se encarga de mostrar toda la interfaz para ver información del semestre seleccionado.
  Listas usadas aquí:
    -Materias
    -Semestres
*/
void VerSemestres() {

  //Son variables externas (globales) definidas antes del int main() de main.cpp
  extern Lista *Semestres;
  extern Lista *Materias;

  short int semestre;
  bool error = false;
  do {
    ShowError("ERROR: Debes introducir un valor entre 1 y 10.",error);
    cout << "Escribir 0 para regresar al MENU" << endl;
    cout << "Introducir semestre: ";
    cin >> semestre;

    if(semestre < 0 || semestre > 10) {
      error = true;
    } else {
      error = false;
    }
  } while (error);

  if(semestre != 0) {
    Node *temp_s = Semestres->primero;
    while (temp_s != NULL) {
      if(temp_s->semestre == semestre) {
        break;
      }
      temp_s = temp_s->sig;
    }

    if(temp_s != NULL) {
      cout << "\nSemestre: " << semestre << endl;
      cout << "Creditos para los alumnos: " << temp_s->creditos << endl;
      cout << "Materias en el semestre:" << endl;

      //Si existe el semestre, pues tiene materias dentro
      Node *temp_m = Materias->primero;
      while (temp_m != NULL) {
        if(temp_m->semestre == semestre) {
          cout << "*" << temp_m->nombre << endl;
          cout << " -CODIGO: " << temp_m->cod_materia << endl;
          cout << " -CREDITOS: " << temp_m->creditos << endl;
        }
        temp_m = temp_m->sig;
      }

    } else {
      cout << "Semestre no encontrado." << endl;
    }

    short int x;
    cout << "\n\nPara seleccionar otro semestre escriba 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();//Recursividad
    } else {
      system(clear);
      VerSemestres();//Recursividad
    }

  } else {
    Menu(); //Recursividad, recuerda que estoy dentro de Menu()
  }

}
