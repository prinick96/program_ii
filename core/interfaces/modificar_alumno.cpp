/*
  Se encarga de modificar un alumno, pide el numero de cedula, si existe pide modificar cada cosa de el.
  Listas usadas aqui:
  Alumnos
  Materias_I : Es necesaria, porque he de modificar la cédula en todas las coincidencias de la cédula nueva si se cambió!
  Planillas : Igual que con Materias_I
*/
void ModificarAlumno() {

  extern Lista *Alumnos;
  extern Lista *Materias_I;
  extern Lista *Planillas;

  cout << "Introduce tu número de cedula: ";
  int cedula;
  cin >> cedula;

  Node *tmp_a = Alumnos->primero;
  while (tmp_a != NULL) {
    if(tmp_a->cedula == cedula) {
      break;
    }
    tmp_a = tmp_a->sig;
  }

  if(tmp_a != NULL) {
    string str;
    int integer;
    int cedula_new;

    //El semestre no se puede modificar, por razones obvias.

    cout << "Cedula (" << tmp_a->cedula << ") - Nueva: "; cin >> cedula_new;
    tmp_a->cedula = cedula_new;
    cout << "Expediente (" << tmp_a->expediente << ") - Nuevo: "; cin >> str;
    tmp_a->expediente = str;
    cout << "Nombre (" << tmp_a->nombre << ") - Nuevo: "; cin >> str;
    tmp_a->nombre = str;
    cout << "Nacimiento (" << tmp_a->nacimiento << ") - Nueva: "; cin >> str;
    tmp_a->nacimiento = str;
    cout << "Indice Academico (" << tmp_a->indice << ") - Nuevo: "; cin >> integer;
    tmp_a->indice = integer;
    cout << "Creditos Extra (" << tmp_a->creditos_extras << ") - Nuevo: "; cin >> integer;
    tmp_a->creditos_extras = integer;

    cout << "Todos los datos fueron cambiados correctamente: \n" << endl;
    cout << "Nombre: " << tmp_a->nombre << endl;
    cout << "Cedula: " << tmp_a->cedula << endl;
    cout << "Expediente: " << tmp_a->expediente << endl;
    cout << "Nacimiento: " << tmp_a->nacimiento << endl;
    cout << "Indice Academico: " << tmp_a->indice << endl;
    cout << "Creditos Extra: " << tmp_a->creditos_extras << endl;


    Node *temp_mi = Materias_I->primero;
    while (temp_mi != NULL) {
      if(temp_mi->cedula == cedula) {
        temp_mi->cedula = cedula_new;
      }
      temp_mi = temp_mi->sig;
    }

    Node *temp_p = Planillas->primero;
    while (temp_p != NULL) {
      if(temp_p->cedula == cedula) {
        temp_p->cedula = cedula_new;
      }
      temp_p = temp_p->sig;
    }

    cout << "\n";

  } else {
    cout << "\nERROR: No se ha encontrado el numero de cedula en los alumnos registrados.\n" << endl;
  }

  short int x;
  cout << "\n\nPara ingresar otra cedula escriba 0 u otro numero" << endl;
  cout << "Para regresar al menu principal escriba 1" << endl;
  cout << "Opcion: "; cin >> x;

  system(clear);
  if(x == 1) {
    Menu();
  } else {
    ModificarAlumno();
  }
}
