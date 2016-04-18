class Lista {
private:
  Node *primero;
  Node *ultimo;
  Node *new_node;

  /*
    Crea un Nodo, a corde con lo que debería llevar el Nodo de cada una de las seis entidades.
    const short int type, definido como const porque nunca cambiará a lo largo del código.
      type define que entidad se está creando:
        1: alumnos, 2: materias inscritas, 3: materias, 4: secciones, 5: semestres, 6: planillas
    char *elements: "string" debe seguir la estructura de cada línea correspondiente al archivo en data/
    de la entidad, de aquí se extraen los elementos a ingresar.
  */
  void CreateNode(const short int type, char *elements) {
    this->new_node = new Node();

    vector<string> array = explode("_", (string) elements); //un vector dinámico

    switch (type) {
      case 1: //Alumnos
        stringstream(array[0]) >> this->new_node->cedula; //Esto convierte array[0] de string a int
        this->new_node->expediente = array[1];
        this->new_node->nombre = array[2];
        this->new_node->nacimiento = array[3];
        stringstream(array[4]) >> this->new_node->indice;
        stringstream(array[5]) >> this->new_node->creditos_extras;
        stringstream(array[6]) >> this->new_node->semestre;
      break;
      case 2: //Materias Inscritas
        this->new_node->cod_materia = array[0];
        this->new_node->cod_seccion = array[1];
        stringstream(array[2]) >> this->new_node->cedula;
      break;
      case 3: //Materias
        this->new_node->cod_materia = array[0];
        this->new_node->nombre = array[1];
        stringstream(array[2]) >> this->new_node->creditos;
        stringstream(array[3]) >> this->new_node->semestre;
      break;
      case 4: //Secciones
        this->new_node->cod_seccion = array[0];
        stringstream(array[1]) >> this->new_node->numero_seccion;
        stringstream(array[2]) >> this->new_node->cedula_profesor;
        this->new_node->profesor = array[3];
        stringstream(array[4]) >> this->new_node->max_alumnos;
        this->new_node->turno = array[5];
        stringstream(array[6]) >> this->new_node->hora_entrada;
        stringstream(array[7]) >> this->new_node->hora_salida;
        stringstream(array[8]) >> this->new_node->alumnos_inscritos;
      break;
      case 5: //Semestres
        stringstream(array[0]) >> this->new_node->semestre;
        stringstream(array[1]) >> this->new_node->creditos;
      break;
      case 6: //Planillas
        this->new_node->cod_materia = array[0];
        this->new_node->cod_seccion = array[1];
        stringstream(array[2]) >> this->new_node->cedula;
      break;
    }
  }
public:
  /*
    __construct()
    Constructor, crea la lista "vacía", haciendo que sus dos nodos pricipales "primero" y "ultimo"
    apunten a NULL porque está vacía y no tiene nodos.
  */
  Lista() {
    this->primero = NULL;
    this->ultimo = NULL;
  }
  /*
    Agrega un elemento a una lista, es decir crea un nuevo nodo y lo conecta con el anterior.
    ##Cada Nodo nuevo, se colocará de último en la lista##
    Si la lista está vacía, el primer nodo == ultimo nodo
  */
  void Add(const short int type, char *elements) {
    this->CreateNode(type,elements);
    if(this->primero == NULL) {
      this->primero = new_node;
    } else {
      this->new_node->ant = this->ultimo;
      this->ultimo->sig = this->new_node;
    }
    this->ultimo = this->new_node;
  }
  /*
    Agrega un elemento a una lista, es decir crea un nuevo nodo y lo conecta con el anterior y el siguiente.
    #La forma de inserción de nodos es tal que, la lista queda ordenada de
    menor (primer nodo) a mayor (ultimo nodo), dependiendo de un parámetro#
    Si la lista está vacía, el primer nodo == ultimo nodo
  */
  void AddSort() {

  }
  void DelLast() {
    cout << "pronto" << endl;
  }
  void DelFirst() {
    cout << "pronto" << endl;
  }
  void DelElement() {
    cout << "pronto" << endl;
  }
  void DebugPrint() {
    if(this->primero != NULL) {
      Node *temp = this->primero;
      while (temp != NULL) {
        cout << temp->ant << " <- (" << temp << ") -> " << temp->sig << endl;
        temp = temp->sig;
      }
    } else {
      cout << "DEBUG: Lista vacia" << endl;
    }
  }

};
