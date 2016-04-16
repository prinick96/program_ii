//Nodo de alumno
typedef struct Nodo_1 {
  char *expediente;
  char *nombre;
  char *nacimiento;
  int cedula;
  int indice;
  int creditos_extra;
  int semestre;
  struct Nodo_1 *ant;
  struct Nodo_1 *sig;
} node_alumno;

//Nodo para materia inscrita
typedef struct Nodo_2 {
  char *code_materia;
  char *code_seccion;
  int cedula_inscrito;
  struct Nodo_2 *ant;
  struct Nodo_2 *sig;
} node_materia_inscrita;

//Nodo para materia
typedef struct Nodo_3 {
  char *code_materia;
  char *code_seccion;
  int creditos;
  int semestre;
  struct Nodo_3 *ant;
  struct Nodo_3 *sig;
} node_materia;

//Nodo para seccion
typedef struct Nodo_4 {
  char *code_seccion;
  char *profesor;
  char *turno;
  int seccion_numero;
  int max_alumnos;
  int hora_entrada;
  int hora_salida;
  int alumnos_inscritos;
  struct Nodo_4 *ant;
  struct Nodo_4 *sig;
} node_seccion;

//Nodo para semetre
typedef struct Nodo_5 {
  int creditos;
  int semestre;
  struct Nodo_5 *ant;
  struct Nodo_5 *sig;
} node_semestre;

//Nodo para planillas de inscripción
typedef struct Nodo_6 {
  char *code_materia;
  char *code_seccion;
  int cedula_solicitante;
  struct Nodo_6 *ant;
  struct Nodo_6 *sig;
} node_planilla;

node_alumno *AddAlumno(node_alumno *Lista,char *elements);
node_alumno *CreateAlumnos(node_alumno *Lista,char *route);

node_materia_inscrita *AddMateria_I(node_materia_inscrita *Lista,char *elements);
node_materia_inscrita *CreateMaterias_I(node_materia_inscrita *Lista,char *route);
