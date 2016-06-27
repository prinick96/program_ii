void Menu();
void ShowError(string error_s, bool error);

//Incluyo todas las demás interfaces utilizadas.
#include "ver_semestres.cpp"
#include "ver_materias.cpp"
#include "ver_planilla.cpp"
#include "ver_secciones_cupo.cpp"
#include "ver_mis_materias.cpp"
#include "ver_alumnos_en_seccion.cpp"
#include "inscripcion.cpp"
#include "aceptar_inscripcion.cpp"
#include "modificar_alumno.cpp"
#include "trees/mostrar_record_crono.cpp"
#include "trees/mostrar_indice_alumno.cpp"
#include "trees/mostrar_indices.cpp"
#include "trees/mostrar_fracasos.cpp"
#include "trees/mostrar_top.cpp"
#include "trees/mostrar_sufrimiento.cpp"

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
    cout << "4- Todas las planillas de inscripcion y aceptar solicitudes" << endl;
    cout << "5- Ver secciones con cupo" << endl;
    cout << "6- Mis materias" << endl;
    cout << "7- Alumnos en una seccion" << endl;
    cout << "8- Inscribirme" << endl;
    cout << "9- Modificar mis datos de alumno" << endl;
    cout << "10- Mostrar record academico de alumno" << endl;
    cout << "11- Mostrar indice academico de alumno" << endl;
    cout << "12- Mostrar indice academico de todos los alumnos inscritos" << endl;
    cout << "13- Mostrar raspados de una materia" << endl;
    cout << "14- Mostrar mejores materias de un alumno" << endl;
    cout << "15- Mostrar la peor materia de un alumno" << endl;
    cout << "0- SALIR" << endl;

    cout << "Teclear una opcion: "; cin >> opcion;

    if(opcion < 0 || opcion > 15) {
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
      AceptarInscripcion();
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
      Inscripcion();
    break;
    case 9:
      ModificarAlumno();
    break;
    case 10:
      MostrarRecordCrono();
    break;
    case 11:
      MostrarIndiceAlumno();
    break;
    case 12:
      MostrarIndices();
    break;
    case 13:
      MostrarFracasos();
    break;
    case 14:
      MostrarTop();
    break;
    case 15:
      MostrarSufrimiento();
    break;
    default:
      cout << "Adios." << endl;
    break;
  }
}
