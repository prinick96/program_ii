void MostrarTop() {
  int cedula;
  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introduce tu cedula: ";
  cin >> cedula;
  if(cedula != 0) {

    Record *rec = new Record();
    rec->get_top_materias(cedula);

    short int x;
    cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      MostrarTop();
    }
  } else {
    Menu();
  }
}
