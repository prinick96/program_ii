class AVL {
  private:
   enum {IZQUIERDO, DERECHO};

  public:
    // Punteros de la lista, para cabeza y nodo actual:
    Node *raiz;
    Node *actual;
    int contador;
    int altura;
   // Constructor y destructor básicos:
   AVL() : raiz(NULL), actual(NULL) {}
   ~AVL() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const int nota, const int time, const string semestral, const int estado, const string cod_materia);
   // Borrar un elemento del árbol:
   void Borrar(const int nota);
   // Función de búsqueda:
   bool Buscar(const int nota);
   // Comprobar si el árbol está vacío:
   bool Vacio(Node *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Node *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un nota:
   int Altura(const int nota);
   // Devolver referencia al nota del nodo actual:
   int &ValorActual() { return actual->nota; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&, int) , Node *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&, int) , Node *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&, int) , Node *nodo=NULL, bool r=true);
   void verArbol(Node *arbol, int n);

  private:
   // Funciones de equilibrado:
   void Equilibrar(Node *nodo, int, bool);
   void RSI(Node* nodo);
   void RSD(Node* nodo);
   void RDI(Node* nodo);
   void RDD(Node* nodo);
   // Funciones auxiliares
   void Podar(Node* &);
   void auxContador(Node*);
   void auxAltura(Node*, int);
};

// Poda: borrar todos los nodos a partir de uno, incluido
void AVL::Podar(Node* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un nota en el árbol AVL
void AVL::Insertar(const int nota, const int time, const string semestral, const int estado, const string cod_materia)
{
   Node *padre = NULL;

   actual = raiz;
   // Buscar el nota en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && nota != actual->nota) {
      padre = actual;
      if(nota > actual->nota) actual = actual->derecho;
      else if(nota < actual->nota) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) {
     raiz = new Node();
     raiz->nota = nota;
     raiz->time = time;
     raiz->semestral = semestral;
     raiz->estado = estado;
     raiz->cod_materia = cod_materia;
   }
   // Si el nota es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(nota < padre->nota) {
      padre->izquierdo = new Node();
      padre->izquierdo->nota = nota;
      padre->izquierdo->padre = padre;
      padre->izquierdo->time = time;
      padre->izquierdo->semestral = semestral;
      padre->izquierdo->estado = estado;
      padre->izquierdo->cod_materia = cod_materia;
      Equilibrar(padre, IZQUIERDO, true);
   }
   // Si el nota es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(nota > padre->nota) {
      padre->derecho = new Node();
      padre->derecho->nota = nota;
      padre->derecho->padre = padre;
      padre->derecho->time = time;
      padre->derecho->semestral = semestral;
      padre->derecho->estado = estado;
      padre->derecho->cod_materia = cod_materia;
      Equilibrar(padre, DERECHO, true);
   }
}

// Equilibrar árbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(Node *nodo, int rama, bool nuevo)
{
   bool salir = false;

   // Recorrer camino inverso actualizando valores de FE:
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; // Depende de si añadimos ...
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = true; // La altura de las rama que
                                      // empieza en nodo no ha variado,
                                      // salir de Equilibrar
      else if(nodo->FE == -2) { // Rotar a derechas y salir:
         if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotación doble
         else RSD(nodo);                         // Rotación simple
         salir = true;
      }
      else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
         if(nodo->derecho->FE == -1) RDI(nodo); // Rotación doble
         else RSI(nodo);                        // Rotación simple
         salir = true;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
   }
}

// Rotación doble a derechas
void AVL::RDD(Node* nodo)
{
   Node *Padre = nodo->padre;
   Node *P = nodo;
   Node *Q = P->izquierdo;
   Node *R = Q->derecho;
   Node *B = R->izquierdo;
   Node *C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación doble a izquierdas
void AVL::RDI(Node* nodo)
{
   Node *Padre = nodo->padre;
   Node *P = nodo;
   Node *Q = P->derecho;
   Node *R = Q->izquierdo;
   Node *B = R->izquierdo;
   Node *C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;

   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación simple a derechas
void AVL::RSD(Node* nodo)
{
   Node *Padre = nodo->padre;
   Node *P = nodo;
   Node *Q = P->izquierdo;
   Node *B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->izquierdo = B;
   Q->derecho = P;

   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Rotación simple a izquierdas
void AVL::RSI(Node* nodo)
{

   Node *Padre = nodo->padre;
   Node *P = nodo;
   Node *Q = P->derecho;
   Node *B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = P;

   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Eliminar un elemento de un árbol AVL
void AVL::Borrar(const int nota)
{
   Node *padre = NULL;
   Node *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(nota == actual->nota) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
            // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
               else                         Equilibrar(padre, IZQUIERDO, false);
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->nota;
            actual->nota = nodo->nota;
            nodo->nota = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(nota > actual->nota) actual = actual->derecho;
         else if(nota < actual->nota) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::InOrden(void (*func)(int&, int) , Node *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->nota, nodo->FE);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void (*func)(int&, int), Node *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->nota, nodo->FE);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void (*func)(int&, int), Node *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->nota, nodo->FE);
}

// Buscar un valor en el árbol
bool AVL::Buscar(const int nota)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(nota == actual->nota) return true; // nota encontrado
      else if(nota > actual->nota) actual = actual->derecho; // Seguir
      else if(nota < actual->nota) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el nota nota
int AVL::Altura(const int nota)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(nota == actual->nota) return altura; // nota encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(nota > actual->nota) actual = actual->derecho;
         else if(nota < actual->nota) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int AVL::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(Node *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void AVL::auxAltura(Node *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d, int FE)
{
   cout << d << "(" << FE << "),";
}

void verArbol(Node *arbol, int n = 1)
{
  if(arbol==NULL) return;

  verArbol(arbol->derecho, n+1);

  cout<< arbol->nota <<endl;
  verArbol(arbol->izquierdo, n+1);
}
