typedef struct {
  int nota;
  int time;
  int estado;
  string semestral;
  string cod_materia;
} jaja;

class Record {
public:
  vector<string> estado;
  vector<jaja> lol;
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

  //saca toda la info de un arbol a un vector dinamico de tipo 'jaja', que tiene la forma de un nodo de arbol
  void klk(Node *ah, vector<jaja> &k_ase) {
    jaja tmp;
    if(ah == NULL) {
      return;
    } else {
      this->klk(ah->derecho,k_ase);
      tmp.nota = ah->nota;
      tmp.time = ah->time;
      tmp.estado = ah->estado;
      tmp.semestral = ah->semestral;
      tmp.cod_materia = ah->cod_materia;
      k_ase.push_back(tmp);
      this->klk(ah->izquierdo,k_ase);
    }
  }

  //iDirecta por aqui?...
  vector<jaja> wasabi(vector<jaja> ah_ok, int n) {
    int x,val,y;
    jaja tmp;
    for(x = 1; x < n; x++) {
      val = tmp.time = ah_ok[x].time;
      tmp.nota = ah_ok[x].nota;
      tmp.time = ah_ok[x].time;
      tmp.estado = ah_ok[x].estado;
      tmp.semestral = ah_ok[x].semestral;
      tmp.cod_materia = ah_ok[x].cod_materia;
      y = x - 1;
      while (y >= 0 && ah_ok[y].time > val) {
        ah_ok[y + 1] = ah_ok[y];
        y--;
      }
      ah_ok[y + 1] = tmp;
    }

    return ah_ok;
  }

  //Dado un alumno, mostrar el record académico en orden cronológico.
  void mostrar_por_anio(Node *raiz, string nombre_alumno) {
    int e_notas, aprobadas;
    klk(raiz,this->lol);
    this->lol = this->wasabi(this->lol,(this->lol).size());
    cout << "Records academicos de " << nombre_alumno << " ordenados por anio " << endl;
    for (int i = 0; i < (this->lol).size(); i++) {
      cout << "-Nota: " << this->lol[i].nota << endl;
      cout << "-Período Académico: " << this->lol[i].time << " -> " << this->lol[i].semestral << endl;
      cout << "-Estado: " << this->estado[this->lol[i].estado] << endl;
      cout << "-Código Materia: " << this->lol[i].cod_materia << "\n" << endl;
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

  /**
  Mostrar todos los índices académicos de cada alumno e
  imprimir los datos del alumno con mejor índice y los datos del
  alumno con el peor índice de la Escuela.
  */
  void mostrar_indices() {
    extern Lista *Alumnos;
    int e_notas, aprobadas;

    Node *temp_a = Alumnos->primero;
    cout << "Indices académicos ordenados por alumnos: " << endl;
    while (temp_a != NULL) {
      e_notas = aprobadas = 0;
      indice_academico(temp_a->record_academico,e_notas,aprobadas);
      cout << "Indice de " << temp_a->nombre << " : " <<  (e_notas/aprobadas) << "\n" << endl;
      temp_a = temp_a->sig;
    }

    //FALTA MEJOR Y EL PEOR IMPRIMIR
  }


  /**
  Dada una materia, mostrar quienes son los alumnos que la

están viendo por cuarta vez y la han reprobado ya tres veces,

para evaluar cuáles son los alumnos con alto riesgo.
*/

/*
Obtener las primeras cinco materias en las que un alumno en

particular ha obtenido las mejores calificaciones.
*/

/*
Dado un alumno, imprimir la materia que más le ha costado en

la carrera, es decir, aquella que ha cursado en mayores

oportunidades y la ha reprobado y/o retirado.
*/

};
