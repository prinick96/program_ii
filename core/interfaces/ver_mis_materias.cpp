/*
  Dada la cedula de un alumno, podra ver sus materias inscritas
  Listas usadas:
  Materias_I
  Materias
*/
void VerMisMaterias() {
  extern Lista *Materias_I;
  extern Lista *Materias;
  int cedula;

  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introduce tu cedula: ";
  cin >> cedula;
  if(cedula != 0) {

    short int y = 0;
    Node *temp_mi = Materias_I->primero, *temp_m = NULL;
    //Empiezo recorriendo cada nodo de la lista de materias inscritas
    while (temp_mi != NULL) {
      //Cada vez que se repita un ciclo del while de la lista de materias inscritas, temp_m vuelve a ser el primer nodo
      temp_m = Materias->primero;
      //Si la cedula del nodo de materias inscritas coincide con la del usuario introducido recorro la de materias
      if(temp_mi->cedula == cedula) {
        //Recorro la de materias hasta que consiga la materia por su codigo
        while (temp_m != NULL) {
          //Cuando la encuentre, mostare asi el NOMBRE y no el codigo de la materia
          if(temp_mi->cod_materia == temp_m->cod_materia) {
            cout << " Materia: " << temp_m->nombre << endl;
            cout << " Seccion: " << temp_mi->cod_seccion << endl;
            break;
          }
          temp_m = temp_m->sig;
        }
        y++;
        cout << "\n" << endl;
      }
      temp_mi = temp_mi->sig;
    }

    if(0 == y) { //Si y++ no se ejecuto nunca, significa que nunca encontró la planilla para ese user & y sigue siendo 0
      cout << "No se ha encontrado informacion para el numero de cedula "<< cedula << endl;
    }

    short int x;
    cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      VerMisMaterias();
    }
  } else {
    Menu();
  }
}
