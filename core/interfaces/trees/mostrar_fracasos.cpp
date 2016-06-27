void MostrarFracasos() {
  string cod_materia;
  cout << "Escribir 0 para regresar al MENU" << endl;
  cout << "Introduce el codigo de una materia: ";
  cin >> cod_materia;
  if(cod_materia != "0") {

    Record *rec = new Record();
    rec->repitientes(cod_materia);

    short int x;
    cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      MostrarFracasos();
    }
  } else {
    Menu();
  }
}
