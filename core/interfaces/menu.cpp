#include <stdlib.h>

void Menu();
void ShowError(string error_s, bool error);

//Incluyo todas las demás interfaces utilizadas.
#include "ver_semestres.cpp"
#include "ver_materias.cpp"
#include "ver_planilla.cpp"
#include "ver_secciones_cupo.cpp"
#include "ver_mis_materias.cpp"
#include "ver_alumnos_en_seccion.cpp"

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

    cout << "1- Obtener informacion de Semestre" << endl;
    cout << "2- Obtener informacion de Materia" << endl;
    cout << "3- Consultar mi planilla de inscripcion" << endl;

    //Mostrar todas las planillas de inscrpción y poder aceptar alumnos (ordenada por cedula)
    cout << "4- Todas las planillas de inscripcion y aceptar solicitudes" << endl;

    cout << "5- Ver secciones con cupo" << endl;
    cout << "6- Mis materias" << endl;
    cout << "7- Alumnos en una seccion" << endl;
    
    //Proceso de inscripcion (solicitar datos), (meter en planilla)
    cout << "8- Inscribirme" << endl;
    //Modificar/agregar/eliminar secciones,materias,alumnos
    cout << "9- Modificacion de registros" << endl;
    cout << "0- SALIR" << endl;

    cout << "Teclear una opcion: "; cin >> opcion;

    if(opcion < 0 || opcion > 9) {
      error = true;
    } else {
      error = false;
    }

  } while(error);

  system(clear);
  switch (opcion) {
    case 1:
      VerSemestres();
    break;
    case 2:
      VerMaterias();
    break;
    case 3:
      VerPlanilla();
    break;
    case 4:
      //AceptarInscripcion();
    break;
    case 5:
      VerSeccionesConCupo();
    break;
    case 6:
      VerMisMaterias();
    break;
    case 7:
      VerAlumnosEnSeccion();
    break;
    case 8:
      cout << "interfaz 8" << endl;
    break;
    case 9:
      cout << "interfaz 9" << endl;
    break;
    default:
      cout << "Adios." << endl;
    break;
  }
}
