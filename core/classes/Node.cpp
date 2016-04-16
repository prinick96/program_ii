class Node {
private:
  //Alumnos
  int indice;
  int creditos_extras;
  string expediente;
  string nacimiento;

  //Secciones
  int numero_seccion;
  int max_alumnos;
  int alumnos_inscritos;
  int cedula_profesor;
  double hora_entrada;
  double hora_salida;
  string profesor;
  string turno;

  //Compartidos
  int cedula;//alumnos, materias_inscritas, planillas
  int creditos; //materias, semestres
  int semestre;//alumnos, materias, semestres
  string cod_seccion;//materias_inscritas, secciones, planillas
  string cod_materia;//materias_inscritas, materias, planillas
  string nombre;//alumnos, materias,
  Node *sig;//todos
  Node *ant;//todos

public:
  Node(Node *s = NULL, Node *a = NULL) {
    this->sig = s;
    this->ant = a;
  }
  /*
    Cómo todas las propiedades de la class son private, debo darle permisos a Lista,
    para que acceda a esta clase Node y pueda modificarlas.
  */
friend class Lista;
};
