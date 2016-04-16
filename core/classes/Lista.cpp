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
  void Add(vector<multi_array> v, short int type) {
    this->new_node = new Node();

    switch (type) {
      case 1: //Alumnos
        cout << "pronto" << endl;
      break;
      case 2: //Materias Inscritas
        cout << "pronto" << endl;
      break;
      case 3: //Materias
        cout << "pronto" << endl;
      break;
      case 4: //Planillas
        cout << "pronto" << endl;
      break;
      case 5: //Secciones
        cout << "pronto" << endl;
      break;
      case 6: //Semestres
        cout << "pronto" << endl;
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

};
