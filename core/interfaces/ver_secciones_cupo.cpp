/*

  Esta función es reutilizada en core/interfaces/inscripcion_2.cpp
  Allí, ella pasa como parametros only_see = true,
  cod_materia = "el codigo de una de las materias seleccionadas por el usuario a inscribirse",
  Por lo que cuando es llamada desde inscripcion_2.cpp esta función SOLO muestra datos

  Se solicita el codigo de la materia, y se listan todas las secciones con cupo para esa materia.
  Listas usadas aqui:
  Secciones
  Materias
*/
void VerSeccionesConCupo(bool only_see = false, string cod_materia = "0") {
  extern Lista *Secciones;
  extern Lista *Materias;

  if(!only_see) {
    cout << "Escribir 0 para regresar al MENU" << endl;
    cout << "Introducir codigo de materia: ";
    cin >> cod_materia;
  }
  if(cod_materia != "0") {

    Node *temp_m = Materias->primero;
    while (temp_m != NULL) {
      if(cod_materia == temp_m->cod_materia) {
        break;
      }
      temp_m = temp_m->sig;
    }

    if(temp_m != NULL) {
      cout << "Nombre: " << temp_m->nombre << endl;
      if(!only_see) {
        cout << "Semestre: " << temp_m->semestre << endl;
      }
      cout << "Secciones Disponibles: " << endl;
      Node *temp_s = Secciones->primero;
      while (temp_s != NULL) {
        string dia_semana[6] = {"\0","Lunes","Martes","Miercoles","Jueves","Viernes"};
        if(temp_s->cod_materia == cod_materia && temp_s->alumnos_inscritos < temp_s->max_alumnos) {
          cout << " *" << temp_s->cod_seccion << "- Seccion " << temp_s->numero_seccion << endl;
          cout << "  - CUPOS: " << temp_s->alumnos_inscritos << " ocupados de " << temp_s->max_alumnos << " disponibles " << endl;
          cout << "  - Profesor: " << temp_s->profesor << " C.I v" << temp_s->cedula_profesor << endl;
          cout << "  - Turno: " << temp_s->turno << endl;
          cout << "  - Dia de Semana: " << dia_semana[temp_s->dia] << endl;
          cout << "  - Hora de entrada: " << temp_s->hora_entrada << endl;
          cout << "  - Hora de salida: " << temp_s->hora_salida << "\n" << endl;
        }
        temp_s = temp_s->sig;
      }
    } else {
      cout << "No se ha encontrado la materia solicitada." << endl;
    }

    if(!only_see) {
      short int x;
      cout << "\n\nPara seleccionar otra materia escriba 0 u otro numero" << endl;
      cout << "Para regresar al menu principal escriba 1" << endl;
      cout << "Opcion: "; cin >> x;

      if(x == 1) {
        Menu();
      } else {
        system(clear);
        VerSeccionesConCupo();
      }
    }

  } else {
    Menu();
  }
}
