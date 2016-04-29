/*
  Dado el codigo de una seccion, se ha de listar la informacion de todos los alumnos en ella.
  Listas usadas aqui:
  Materias_I
  Alumnos
*/
void VerAlumnosEnSeccion() {
  extern Lista *Alumnos;
  extern Lista *Materias_I;
  string cod_seccion;

  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introduce codigo de la seccion: ";
  cin >> cod_seccion;

  if(cod_seccion != "0") {
    Node *temp_a = NULL;
    Node *temp_mi = Materias_I->primero;
    short int y = 0;
    while (temp_mi != NULL) {
      if(temp_mi->cod_seccion == cod_seccion) {
        //¿que harías si quisiera colocar aqui el nombre de la materia de la seccion dada?
        temp_a = Alumnos->primero;
        while (temp_a != NULL) {
          if(temp_a->cedula == temp_mi->cedula) {
            cout << " *" << temp_a->nombre << endl;
            cout << "  -Nacimiento: " << temp_a->nacimiento << endl;
            cout << "  -Indice Academico: " << temp_a->indice << endl;
            cout << "  -C.I: v" << temp_a->cedula << endl;
          }
          temp_a = temp_a->sig;
        }
        y++;
      }
      temp_mi = temp_mi->sig;
    }

    if(0 == y) {
      cout << "No se ha encontrado la ningun alumno en la seccion solicitada." << endl;
    }

    short int x;
    cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      VerAlumnosEnSeccion();
    }
  } else {
    Menu();
  }
}
