void MostrarIndices() {

  Record *rec = new Record();
  rec->mostrar_indices();

  short int x;
  cout << "Para regresar al menu principal escriba 1" << endl;
  cout << "Opcion: "; cin >> x;
  Menu();
}
