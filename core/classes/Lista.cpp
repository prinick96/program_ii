class Lista {
private:
  //new_node es un nodo que solo estará involucrado en un proceso interno, no me interesa desde fuera.
  Node *new_node;
  /*
    Crea un Nodo, a corde con lo que debería llevar el Nodo de cada una de las seis entidades.
    const short int type, definido como const porque nunca cambiará a lo largo del código.
      type define que entidad se está creando:
        1: alumnos, 2: materias inscritas, 3: materias, 4: secciones, 5: semestres, 6: planillas
    char *elements: "string" debe seguir la estructura de cada línea correspondiente al archivo en data/
    de la entidad, de aquí se extraen los elementos a ingresar.
  */
  void CreateNode(const short int type, char *elements, Node *Arbol = NULL) {
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
        this->new_node->record_academico = Arbol;
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
        this->new_node->cod_materia = array[1];
        stringstream(array[2]) >> this->new_node->numero_seccion;
        stringstream(array[3]) >> this->new_node->cedula_profesor;
        this->new_node->profesor = array[4];
        stringstream(array[5]) >> this->new_node->max_alumnos;
        this->new_node->turno = array[6];
        stringstream(array[7]) >> this->new_node->dia;

        //Transforma en FLOAT
        this->new_node->hora_entrada = atof(array[8].c_str());
        this->new_node->hora_salida = atof(array[9].c_str());

        stringstream(array[10]) >> this->new_node->alumnos_inscritos;
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
  //Me interesa acceder a los nodos primero y ultimo desde FUERA de la lista
  Node *primero;
  Node *ultimo;
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
 void Add(const short int type, char *elements, Node *Arbol = NULL) {
   this->CreateNode(type,elements);
   if(this->primero == NULL) {
     this->primero = this->new_node;
   } else {
     this->new_node->ant = this->ultimo;
     /*Cuando por SEGUNDA VEZ se llama a Add(), this->primero tiene la MISMA Dirección que this->ultimo, por lo que
     al yo modificar this->ultimo->sig también estoy modificando this->primero->sig
     */
     this->ultimo->sig = this->new_node;
   }
   this->ultimo = this->new_node;
 }
 /*
   Agrega un elemento a una lista, es decir crea un nuevo nodo y lo conecta con el anterior y el siguiente.
   #La forma de inserción de nodos es tal que, la lista queda ordenada de menor (primer nodo) a mayor (ultimo nodo)#
   Si la lista está vacía, el primer nodo == ultimo nodo
 */
 void AddSort(const short int type, char *elements) {
   this->CreateNode(type,elements);
   //Primero vemos si la lista está vacía, al ser así ultimo == primero, es decir al nuevo nodo ambos
   if(this->primero == NULL) {
     this->primero = this->new_node;
     this->ultimo = this->new_node;
   } else {
     //Luego, hay que ver si existe UN SOLO elemento en la lista para llenar con un "->sig" al primer elemento
     if(this->primero->sig == NULL) {

       //Si el único elemento que existe en ella es mayor el nuevo nodo, pues metemos nuevo nodo de primero
       if((this->new_node->alumnos_inscritos <= this->primero->alumnos_inscritos && type == 4)
       || (this->new_node->cedula <= this->primero->cedula && type == 6)) {
         this->new_node->sig = this->primero;
         this->primero = this->new_node;
       //Si no, lo metemos de último
      } else {
         this->new_node->ant = this->ultimo;
         this->ultimo->sig = this->new_node;
         this->ultimo = this->new_node;
       }

     } else {
       //Ahora viene el caso "complejo", cuando hay más de un elemento en la lista
       Node *temp = this->primero, *selected = NULL; //Es importante fijarse en selected = NULL
       short int x = 1; //Este contador me servirá para saber si debo agregar de PRIMERO el elemento
       while (temp != NULL) {
         if((this->new_node->alumnos_inscritos <= temp->alumnos_inscritos && type == 4)
         || (this->new_node->cedula <= temp->cedula && type == 6)) { //if(1)
           selected = temp; //Aquí capturo el elemento que es mayor o igual a el nuevo nodo
           break;
         }
         temp = temp->sig;
         x++; //Esto me sirve para saber si ya NO estoy en el primer nodo
       }

       //selected será NULL cuando NUNCA entre en el if(1), por lo que el nodo se agrega de último
       if(selected == NULL) {
         this->new_node->ant = this->ultimo;
         this->ultimo->sig = this->new_node;
         this->ultimo = this->new_node;
       //x será igual a 1 cuando selected NO sea NULL y el elemento que estoy metiendo es el MENOR de todos en la lista
       } else if(x == 1) {
         this->new_node->sig = this->primero;
         this->primero = this->new_node;
       //Se irá al else cuando x NO sea 1 (es decir no debo agregar de primero) y selected NO sea NULL
       } else {
         //Pues solo conecto nodo anterior con nodo nuevo y nodo nuevo con nodo seleccionado
         this->new_node->sig = selected;
         this->new_node->ant = selected->ant;
         (selected->ant)->sig = this->new_node;
         selected->ant = this->new_node;
       }
     }
   }
 }
 /*
   Borra el último nodo de una lista
 */
 void DelLast() {
   Node *temp = this->ultimo;
   if(this->ultimo->ant != NULL) {
     (this->ultimo->ant)->sig = NULL;
   } else {
     this->primero = NULL;
   }
   this->ultimo = this->ultimo->ant;
   delete temp;
 }
 /*
   Borra el primer nodo de una lista
 */
 void DelFirst() {
   Node *temp = this->primero;
   this->primero = this->primero->sig;
   if(this->primero == NULL) {
     this->ultimo = this->primero;
   } else {
     this->primero->ant = NULL;
   }
   delete temp;
 }
 /*
  Borra un elemento por cedula como parametro a identificar
 */
 void DelByCedula(int cedula) {
   Node *temp = this->primero, *temp_del;
   while (temp != NULL) {
     if(temp->cedula == cedula) {
       if(temp->ant == NULL && temp->sig == NULL) { //Es el unico elemento
         delete temp;
         this->primero = NULL;
         this->ultimo = NULL;
         break; //Como es el unico, detenemos el bucle
       } else if(temp->ant == NULL && temp->sig != NULL) { //Es el primero y NO el unico
         temp = temp->sig; //Avanzamos en la lista
         this->DelFirst(); //Ese elemento de arriba como era el primero, esta en this->primero y lo borramos
       } else if(temp->ant != NULL && temp->sig == NULL) { //Es el ultimo y NO el unico
         this->DelLast(); //Y como es el ultimo, temp esta en this->ultimo, este se borra y se libera
         break;
       } else { //No es el unico, no es el primero y tampoco es el ultimo
         (temp->ant)->sig = temp->sig; //Conecto el anterior con el que viene despues del que quiero borrar
         (temp->sig)->ant = temp->ant; //Conecto el siguiente con el que viene antes del que quiero borrar
         temp_del = temp;
         temp = temp->sig;//Avanzamos en la lista
         delete temp_del;
       }
     } else {
       temp = temp->sig;
     }
   }
 }
 /*
   Muestra gráficamente los nodos anidados
 */
 void DebugPrint(const int type = 0) {
   if(this->primero != NULL) {
     Node *temp = this->primero;
     while (temp != NULL) {
       if(type == 4) {
         cout << temp->ant << " <- (" << temp << "): " << temp->alumnos_inscritos << " -> " << temp->sig << endl;
       } else if(type == 6) {
         cout << temp->ant << " <- (" << temp << "): " << temp->cedula << " -> " << temp->sig << endl;
       } else {
         cout << temp->ant << " <- (" << temp << ") -> " << temp->sig << endl;
       }
       temp = temp->sig;
     }
   } else {
     cout << "DEBUG: Lista vacia" << endl;
   }
 }

};
