#include <algorithm> //para el find() del vector
typedef struct {
  int nota;
  int time;
  int estado;
  string semestral;
  string cod_materia;
} jaja;

typedef struct {
  int cedula;
  int semestre;
  int indice;
  string nacimiento;
  string nombre;
} xd;

typedef struct {
  string nombre;
  int veces;
} fracasados;

class Record {
private:
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

  //iDirecta
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

  //Busca fracasos
  void search_materia(Node *raiz,string cod_materia, int &veces) {
    if(raiz == NULL) {
      return;
    } else {
      this->search_materia(raiz->derecho,cod_materia,veces);
      //que la materia del arbol sea igual al buscado y que su estado sea raspado
      if(raiz->cod_materia == cod_materia && raiz->estado == 2) {
        veces++;
      }
      this->search_materia(raiz->izquierdo,cod_materia,veces);
    }
  }

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

  /*
    Dado un alumno, mostrar el record académico en orden cronológico.
  */
  void mostrar_por_anio(Node *raiz, string nombre_alumno) {
    int e_notas, aprobadas;
    this->klk(raiz,this->lol);
    this->lol = this->wasabi(this->lol,(this->lol).size());
    cout << "Records academicos de " << nombre_alumno << " ordenados por anio " << endl;
    for (int i = 0; i < (this->lol).size(); i++) {
      cout << "-Nota: " << this->lol[i].nota << endl;
      cout << "-Período Académico: " << this->lol[i].time << " -> " << this->lol[i].semestral << endl;
      cout << "-Estado: " << this->estado[this->lol[i].estado] << endl;
      cout << "-Código Materia: " << this->lol[i].cod_materia << "\n" << endl;
    }
  }

  /**
  Mostrar todos los índices académicos de cada alumno e
  imprimir los datos del alumno con mejor índice y los datos del
  alumno con el peor índice de la Escuela.
  */
  void mostrar_indices() {
    extern Lista *Alumnos;
    extern Lista *Materias_I;
    int e_notas = 0, aprobadas = 0, min = 20, max = 0, indice;
    map<int, xd> kha;
    vector<int> repetidas;

    Node *temp_a = NULL;
    Node *temp_mi = Materias_I->primero;

    cout << "Indices académicos ordenados por alumnos: \n\n" << endl;
    while (temp_mi != NULL) {
      temp_a = Alumnos->primero;

      while (temp_a != NULL) {

        if(temp_a->cedula == temp_mi->cedula && find(repetidas.begin(), repetidas.end(), temp_a->cedula) == repetidas.end()) {

          repetidas.push_back(temp_a->cedula);

          e_notas = aprobadas = 0;
          //cout << temp_a->record_academico << endl;
          if(temp_a->record_academico == NULL) {
            indice = 0;
          } else {
            this->indice_academico(temp_a->record_academico,e_notas,aprobadas);
            //cout << temp_a->record_academico << endl;
            indice = (e_notas/aprobadas);
          }
          cout << "Indice de " << temp_a->nombre << " : " << indice << "\n" << endl;

          //menor indice alum
          if(indice <= min) {
            min = indice;
            kha[min].nombre = temp_a->nombre;
            kha[min].cedula = temp_a->cedula;
            kha[min].semestre = temp_a->semestre;
            kha[min].nacimiento = temp_a->nacimiento;
            kha[min].indice = indice;
          }

          //mayor indice alum
          if(indice > max) {
            max = indice;
            kha[max].nombre = temp_a->nombre;
            kha[max].cedula = temp_a->cedula;
            kha[max].semestre = temp_a->semestre;
            kha[max].nacimiento = temp_a->nacimiento;
            kha[max].indice = indice;
          }

        }

        temp_a = temp_a->sig;
      }
      temp_mi = temp_mi->sig;
    }

    cout << " MEJOR Y PEOR ESTUDIANTE \n" << endl;
    cout << "Mejor estudiante: " <<  kha[max].nombre <<endl;
    cout << "- Cedula: " << kha[max].cedula << endl;
    cout << "- Indice: " << kha[max].indice << endl;
    cout << "- Nacimiento: " << kha[max].nacimiento << endl;
    cout << "- Semestre actual: " << kha[max].semestre << "\n\n" << endl;

    cout << "Peor estudiante: " <<  kha[min].nombre <<endl;
    cout << "- Cedula: " << kha[min].cedula << endl;
    cout << "- Indice: " << kha[min].indice << endl;
    cout << "- Nacimiento: " << kha[min].nacimiento << endl;
    cout << "- Semestre actual: " << kha[min].semestre << "\n\n" << endl;

  }


  /**
    Dada una materia, mostrar quienes son los alumnos que la
    están viendo por cuarta vez y la han reprobado ya tres veces,
    para evaluar cuáles son los alumnos con alto riesgo.
  */
  void repitientes(string cod_materia) {
    extern Lista *Alumnos;
    vector<fracasados> alumnos;
    fracasados tmp;
    Node *temp_a = Alumnos->primero;
    int veces;

    while (temp_a != NULL) {
      veces = 0;
      this->search_materia(temp_a->record_academico,cod_materia,veces);
      tmp.nombre = temp_a->nombre;
      tmp.veces = veces;
      alumnos.push_back(tmp);
      temp_a = temp_a->sig;
    }

    cout << "Alumnos que han reprobado tres o mas veces: \n\n" << endl;
    int final = 0;
    for (int i = 0; i < alumnos.size(); i++) {
      //cout << alumnos[i].nombre << " ha reprobado " << alumnos[i].veces << " veces" << endl;
      if(alumnos[i].veces >= 3) {
        cout << alumnos[i].nombre << " ha reprobado " << alumnos[i].veces << " veces" << endl;
        final++;
      }
    }

    if(final == 0) {
      cout << "Ningun alumno ha reprobado 3 o mas veces" << endl;
    }

  }

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
