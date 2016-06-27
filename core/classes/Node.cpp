class Node {
public:
  //Arbolito
  int nota;
  int time;
  string semestral;
  int estado;
  int FE;
  Node *izquierdo;
  Node *derecho;
  Node *padre;

  //Alumnos
  int indice;
  int creditos_extras;
  string expediente;
  string nacimiento;
  Node *record_academico;

  //Secciones
  int numero_seccion;
  int max_alumnos;
  int alumnos_inscritos;
  int cedula_profesor;
  int dia; //1 lunes .. 5 viernes
  float hora_entrada;
  float hora_salida;
  string profesor;
  string turno;

  //Compartidos
  int cedula;//alumnos, materias_inscritas, planillas
  int creditos; //materias, semestres
  int semestre;//alumnos, materias, semestres
  string cod_seccion;//materias_inscritas, secciones, planillas
  string cod_materia;//materias_inscritas, materias, planillas, secciones, Arbol
  string nombre;//alumnos, materias
  Node *sig;//todos
  Node *ant;//todos.
  /*
    __construct().
    Constructor de la clase Node, coloca el nodo "flotando" apenas se instancia,
    enlazando con null a siguiente y anterior hasta que se defina estos.
  */
  Node(Node *s = NULL, Node *a = NULL) {
    this->sig = NULL;
    this->ant = NULL;

    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
    this->FE = 0;
  }
};
