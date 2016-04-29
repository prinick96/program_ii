/*
  Se encarga de mostrar toda la interfaz para ver información de la materia seleccionada (se pide el codigo)
  Listas usadas aquí:
    -Materias
    -Secciones
*/
void VerMaterias() {
  //Son variables externas (globales) definidas antes del int main() de main.cpp.
  extern Lista *Materias;
  extern Lista *Secciones;
  string cod_materia;

  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introducir codigo de materia: ";
  cin >> cod_materia;

  if(cod_materia != "0") {

    Node *temp_m = Materias->primero;
    while (temp_m != NULL) {
      if(cod_materia == temp_m->cod_materia) {
        break;
      }
      temp_m = temp_m->sig;
    }

    if(temp_m != NULL) {
      cout << "Codigo de materia: " << cod_materia << endl;
      cout << "Nombre: " << temp_m->nombre << endl;
      cout << "Creditos Necesarios: " << temp_m->creditos << endl;
      cout << "Se ve en Semestre: " << temp_m->semestre << endl;
      cout << "Secciones: " << endl;
      Node *temp_s = Secciones->primero;
      while (temp_s != NULL) {
        string dia_semana[5] = {"Lunes","Martes","Miercoles","Jueves","Viernes"};
        if(temp_s->cod_materia == cod_materia) {
          cout << " *" << temp_s->cod_seccion << "- Seccion " << temp_s->numero_seccion << endl;
          cout << "  - Profesor: " << temp_s->profesor << " C.I v" << temp_s->cedula_profesor << endl;
          cout << "  - Alumnos maximos: " << temp_s->max_alumnos << endl;
          cout << "  - Turno: " << temp_s->turno << endl;
          cout << "  - Dia de Semana: " << dia_semana[temp_s->dia] << endl;
          cout << "  - Hora de entrada: " << temp_s->hora_entrada << endl;
          cout << "  - Hora de salida: " << temp_s->hora_salida << endl;
          cout << "  - Alumnos Inscritos: " << temp_s->alumnos_inscritos << "\n" << endl;
        }
        temp_s = temp_s->sig;
      }
    } else {
      cout << "No se ha encontrado la materia solicitada." << endl;
    }

    short int x;
    cout << "\n\nPara seleccionar otra materia escriba 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      VerMaterias();
    }
  } else {
    Menu();
  }

}
