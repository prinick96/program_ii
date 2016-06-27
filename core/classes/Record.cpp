class Record {
public:
  vector<string> estado;
  Record *indices;

  Record() {
    this->estado.push_back("Aprobado normal");
    this->estado.push_back("Aprobado por Reparación");
    this->estado.push_back("Reprobado");
    this->estado.push_back("Retirado");
  }

  //Mostrar por notas
  void mostrar_por_notas(Node *raiz) {
    if(raiz == NULL) {
      return;
    } else {
      this->mostrar_por_notas(raiz->derecho);
      cout << "-Nota: " << raiz->nota << endl;
      cout << "-Período Académico: " << raiz->time << " -> " << raiz->semestral << endl;
      cout << "-Estado: " << this->estado[raiz->estado] << endl;
      cout << "-Código Materia: " << raiz->cod_materia << "\n" << endl;
      this->mostrar_por_notas(raiz->izquierdo);
    }
  }

  //Dado un alumno, calcular y mostrar el índice académico, luego E_notas / aprobadas
  void indice_academico(Node *raiz, int &E_notas, int &aprobadas) {
    if(raiz == NULL) {
      return;
    } else {
      this->indice_academico(raiz->derecho,E_notas,aprobadas);
      if(raiz->estado == 0 || raiz->estado == 1) {
        aprobadas++;
      }
      E_notas = E_notas + raiz->nota;
      this->indice_academico(raiz->izquierdo,E_notas,aprobadas);
    }
  }

  void printer() {
    cout << "kha" << endl;
  }

  /**
  Mostrar todos los índices académicos de cada alumno e
  imprimir los datos del alumno con mejor índice y los datos del
  alumno con el peor índice de la Escuela.
  */
  void mostrar_indices() {
    this->indices = new Record();
    this->indices->printer();
  }


};
