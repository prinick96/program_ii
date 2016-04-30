/*
  Se encarga de la interfaz que muestra la planilla de inscripción de un alumno, dada la cedula de este.
  Listas usadas aqui:
  Planillas
  Materias
*/
void VerPlanilla(bool only_see = false, int cedula = 0) {
  //Son variables externas (globales) definidas antes del int main() de main.cpp.
  extern Lista *Planillas;
  extern Lista *Materias;

  if(!only_see) {
    cout << "Escribir 0 para regresar al MENU" << endl;
    cout << "Introduce tu cedula: ";
    cin >> cedula;
  }

  if(cedula != 0) {
    short int y = 0;
    Node *temp_p = Planillas->primero, *temp_m = NULL;
    //Empiezo recorriendo cada nodo de la lista de planillas
    while (temp_p != NULL) {
      //Cada vez que se repita un ciclo del while de la lista de planillas, temp_m vuelve a ser el primer nodo
      temp_m = Materias->primero;
      //Si la cedula del nodo de planilla coincide con la del usuario introducido recorro la de materias
      if(temp_p->cedula == cedula) {
        //Recorro la de materias hasta que consiga la materia por su codigo
        while (temp_m != NULL) {
          //Cuando la encuentre, mostare asi el NOMBRE y no el codigo de la materia
          if(temp_m->cod_materia == temp_p->cod_materia) {
            cout << " Materia: " << temp_m->nombre << endl;
            cout << " Seccion: " << temp_p->cod_seccion << endl;
            break;
          }
          temp_m = temp_m->sig;
        }
        y++;
        cout << "\n" << endl;
      }
      temp_p = temp_p->sig;
    }

    if(0 == y) { //Si y++ no se ejecuto nunca, significa que nunca encontró la planilla para ese user & y sigue siendo 0
      cout << "No se ha encontrado informacion." << endl;
    }

    if(!only_see) {
      short int x;
      cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
      cout << "Para regresar al menu principal escriba 1" << endl;
      cout << "Opcion: "; cin >> x;

      if(x == 1) {
        Menu();
      } else {
        system(clear);
        VerPlanilla();
      }
    }
  } else {
    Menu();
  }
}
