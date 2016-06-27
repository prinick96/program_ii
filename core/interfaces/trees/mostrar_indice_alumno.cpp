void MostrarIndiceAlumno() {
  int cedula;
  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introduce tu cedula: ";
  cin >> cedula;
  if(cedula != 0) {
    int E_notas = 0;
    int aprobadas = 0;
    int indice;

    Record *rec = new Record();
    rec->pedir_alumno(cedula,E_notas,aprobadas,true);

    if(aprobadas > 0) {
      indice = (E_notas/aprobadas);
    } else {
      indice = 0;
    }

    cout << "El indice academico del alumno es " << indice << endl;

    short int x;
    cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      MostrarIndiceAlumno();
    }
  } else {
    Menu();
  }
}
