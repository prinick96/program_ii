class Lista {
private:
  Node *primero;
  Node *actual;
  Node *new_node;
public:
  Lista() {
    this->primero = NULL;
    this->actual = NULL; // el ultimo
  }
  void Add(const short int type, char *elements) {
    this->new_node = new Node();

    vector<string> array = explode("_", (string) elements);

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
        cout << array[0] << endl;
      break;
      case 3: //Materias
        cout << array[0] << endl;
      break;
      case 4: //Planillas
        cout << array[0] << endl;
      break;
      case 5: //Secciones
        cout << array[0] << endl;
      break;
      case 6: //Semestres
        cout << array[0] << endl;
      break;
    }

    if(this->primero == NULL) {
      this->primero = new_node;
    } else {
      this->new_node->ant = this->actual;
      this->actual->sig = this->new_node;
    }
    this->actual = this->new_node;
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
  void Print() {
    
  }

};
