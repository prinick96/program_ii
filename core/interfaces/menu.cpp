#include <stdlib.h>
void Menu();
void ShowError(string error_s, bool error);

//Incluyo todas las demás interfaces utilizadas.
#include "ver_semestres.cpp"
#include "ver_materias.cpp"

/*
  Recibe el string con el error a mostrar, el estado de verdad del error.
  Según el estado de error muestra un error en pantalla.
*/
void ShowError(string error_s, bool error) {
  if(error) {
    system(clear);
    cout << "\n\n" << error_s << "\n" << endl;
  }
}

void Menu() {
  system(clear);
  int opcion;
  bool error = false;

  do {

    ShowError("ERROR: Debes introducir un valor entre 0 y 9",error);
    cout << "Menu\n" << endl;

    //Preguntar semestre (int), listar sus materias y la info del semestre
    cout << "1- Obtener informacion de Semestre" << endl;
    //Preguntar materia (codigo), detallar todo y el semestre en que esta
    cout << "2- Obtener informacion de Materia" << endl;
    //Preguntar materia (codigo), mostrar todas las secciones de esa materia
    cout << "3- Obtener informacion de Secciones" << endl;
    //Preguntar alumno (cedula), Consultar mi planilla de inscripcion
    cout << "4- Consultar mi planilla de inscripcion" << endl;
    //Mostrar todas las planillas de inscrpción y poder aceptar alumnos (ordenada por cedula)
    cout << "5- Consultar todas las planillas de inscripcion" << endl;
    //Preguntar materia (codigo), desplegar SOLO las secciones con cupo
    cout << "6- Ver secciones con cupo" << endl;
    //Preguntar alumno (cedula), Mostrar las materias inscriptas por mi (como alumno)
    cout << "7- Mis materias" << endl;
    //Preguntar seccion (codigo), mostrar todos sus alumnos
    cout << "8- Alumnos en una seccion" << endl;
    //Proceso de inscripcion (solicitar datos), (meter en planilla)
    cout << "9- Inscribirme" << endl;
    //Modificar/agregar/eliminar secciones,materias,alumnos
    cout << "10- Modificacion de registros" << endl;
    cout << "0- SALIR" << endl;

    cout << "Teclear una opcion: "; cin >> opcion;

    if(opcion < 0 || opcion > 10) {
      error = true;
    } else {
      error = false;
    }

  } while(error);

  system(clear);
  switch (opcion) {
    case 1:
      //"ver_semestres.cpp"
      VerSemestres();
    break;
    case 2:
      //"ver_materias.cpp"
      VerMaterias();
    break;
    case 3:
      cout << "interfaz 3" << endl;
    break;
    case 4:
      cout << "interfaz 4" << endl;
    break;
    case 5:
      cout << "interfaz 5" << endl;
    break;
    case 6:
      cout << "interfaz 6" << endl;
    break;
    case 7:
      cout << "interfaz 7" << endl;
    break;
    case 8:
      cout << "interfaz 8" << endl;
    break;
    case 9:
      cout << "interfaz 9" << endl;
    break;
    case 10:
      cout << "interfaz 10" << endl;
    break;
    default:
      cout << "Adios." << endl;
    break;
  }
}
