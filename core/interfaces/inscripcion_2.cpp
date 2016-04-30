/*
  Etapa 2 de proceso de inscripción, selección de materias y de secciones.
  Recibe los creditos totales del alumnos a inscrbirse, el semestre al que aplica y la cedula de quien aplica.
  Los recibe de Inscripcion();
  Listas usadas aqui:
  Materias
  Planillas
*/
void InscripcionFase2(int creditos, int semestre, string cedula) {
  extern Lista *Materias;
  extern Lista *Planillas;
  string codigos_materias;

  cout << "FASE 2: A partir de ahora no podra regresar hasta completar el proceso." << endl;
  VerSemestres(true,semestre,creditos);
  cout << "\nSepara con comas los CODIGOS de las materias a inscribir. Ejemplo: 0001,0002: " << endl;
  cin >> codigos_materias;

  vector<string> nrc = explode(",",codigos_materias);
  short int x, creditos_necesarios = 0;
  Node *temp_m = Materias->primero;
  for(x = 0; x < nrc.size(); x++) {
    while (temp_m != NULL) {
      if(temp_m->cod_materia == nrc[x]) {
        creditos_necesarios += temp_m->creditos;
        break;
      }
      temp_m = temp_m->sig;
    }
  }

  if(creditos >= creditos_necesarios) {
    vector <string> codigos_secciones;
    string c_seccion;
    for(x = 0; x < nrc.size(); x++) {
      system(clear);
      cout << "Elige una seccion para inscribir tu materia." << endl;
      VerSeccionesConCupo(true,nrc[x]);
      cout << "\nEscribe el codigo de la seccion que quieres: ";
      cin >> c_seccion;
      nrc[x] = nrc[x] + '_' + c_seccion + '_' + cedula;

      char *str = new char[nrc[x].length() + 1]; //Como Add recibe es un (char *) y no puedo castear, uso memoria dinamica
      strcpy(str, nrc[x].c_str()); //Convierto en (char *) a data con el metodo c_str() y con strcpy() lo copio a str
      Planillas->AddSort(6,str);
      delete[] str;//Libero de memoria el char * temporal

    }
  } else {
    cout << "Te faltan " << creditos_necesarios - creditos << " creditos para inscribir todas las materias solicitadas." << endl;
    short int y;
    cout << "Para intentar de nuevo introduce 0, para salir al menu introduce 1: ";
    cin >> y;
    if(y == 0) {
      system(clear);
      InscripcionFase2(creditos,semestre,cedula);
    } else {
      Menu();
    }
  }

}
