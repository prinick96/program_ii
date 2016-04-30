#include <algorithm>
/*
  Acepta la solicitud de inscripción que estará en "planillas de inscripción".
  Para aceptar una solicitud se coloca la cedula de quien solicita, se elimina de planillas
  se pasa a materias inscritas y se incrementa la cantidad de alumnos para cada seccion donde este el aceptado.
  Listas usadas aqui:
  Planillas
  Materias_I
  Secciones
  Alumnos
*/
void AceptarInscripcion() {
  extern Lista *Planillas;
  extern Lista *Materias_I;
  extern Lista *Secciones;
  extern Lista *Alumnos;
  vector<int> cedulas;
  int cedula;

  cout << "Lista de planillas de inscripción de aspirantes\n" << endl;

  Node *temp_p = Planillas->primero, *temp_a = NULL;
  while (temp_p != NULL) {
    /*
      Almacenamos las cedulas de los alumnos que solicitan SIN REPETIR ninguna.
      Mostrando nombre-cedula del aspirante
    */
    if(find(cedulas.begin(), cedulas.end(), temp_p->cedula) == cedulas.end()) {
      cedulas.push_back(temp_p->cedula);
      temp_a = Alumnos->primero;
      while (temp_a != NULL) {
        if(temp_a->cedula == temp_p->cedula) {
          break;
        }
        temp_a = temp_a->sig;
      }
      cout << temp_a->nombre << " v" << temp_p->cedula << endl;
    }
    temp_p = temp_p->sig;
  }

  cout << "\nEscribir 0 para regresar al MENU" << endl;
  cout << "Introducir numero de cedula para ver planilla correspondiente: "; cin >> cedula;
  system(clear);
  if(cedula != 0) {
    short int x;
    //La cedula SI existe
    if(find(cedulas.begin(), cedulas.end(), cedula) != cedulas.end()) {
      VerPlanilla(true,cedula);
      cout << "Introduce 0 para regresar a ver todas las planillas" << endl;
      cout << "Introduce 1 para aceptar esta planilla" << endl;
      cout << "Valor: "; cin >> x;
      if(x == 1) {
        //Necesito obtener el horario de CADA seccion por separado y mterlo en un arreglo para hacer un analisis
        //Además, para disminuir los bucles en el proceso de inscripción debo chequear que lo que el haya elegido
        //no choque con alguna seccion de otra materia (el horario) antes de dejarlo pasar a las planillas de inscripción
      } else {
        system(clear);
        AceptarInscripcion();
      }
    } else {
      cout << "\nLa cedula ingresada no existe en sistema." << endl;
      cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
      cout << "Para regresar al menu principal escriba 1" << endl;
      cout << "Opcion: "; cin >> x;

      if(x == 1) {
        Menu();
      } else {
        system(clear);
        AceptarInscripcion();
      }
    }
  } else {
    Menu();
  }

}
