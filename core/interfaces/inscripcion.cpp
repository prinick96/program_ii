#include <string.h>
#include "inscripcion_2.cpp"
/*
  Proceso de Pre-Inscripción, se solicitan datos al alumno, el semestre a inscribir y las materias segun el semestre.
  Luego las secciones segun la materia elegida, una vez realizado todo se meten los datos en la lista Planillas.
  Listas utilizadas aqui:
  Alumnos
  Semestres
*/
void Inscripcion() {
  extern Lista *Alumnos;
  extern Lista *Semestres;

  int cedula;
  string input;
  cout << "Bienvenido al proceso de inscripcion" << endl;
  cout << "Indique su cedula, o escriba 0 para regresar al menu: ";
  cin >> input;
  string cedula_s = input;
  stringstream(input) >> cedula;

  if(cedula != 0) {
    Node *temp_a = Alumnos->primero;
    while (temp_a != NULL) {
      if(temp_a->cedula == cedula) {
        break;
      }
      temp_a = temp_a->sig;
    }

    if(temp_a == NULL) {
      short int semestre, creditos_extras;
      string data = cedula_s;
      cout << "\nREGISTRO DE USUARIO:\n" << endl;

      cout << "Expediente: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      cout << "Nombre: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      cout << "Apellido: "; cin >> input; cout << "\n";
      data = data + " " + input;
      cout << "Nacimiento: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      cout << "Indice Academico: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      cout << "Creditos Extras: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      stringstream(input) >> creditos_extras;
      cout << "Semestre: "; cin >> input; cout << "\n";
      data = data + "_" + input;
      stringstream(input) >> semestre;

      Node *temp_s = Semestres->primero;
      while (temp_s != NULL) {
        if(temp_s->semestre == semestre) {
          break;
        }
        temp_s = temp_s->sig;
      }

      /*
      Si entra aqui, es porque el semestre existe.
      Por tanto agregamos al alumno, ademas necesitamos sacar la cantidad de creditos maxima segun el semestre.
      */
      if(temp_s != NULL) {
        char *str = new char[data.length() + 1]; //Como Add recibe es un (char *) y no puedo castear, uso memoria dinamica
        strcpy(str, data.c_str()); //Convierto en (char *) a data con el metodo c_str() y con strcpy() lo copio a str
        Alumnos->Add(1,str);
        delete[] str;//Libero de memoria el char * temporal

        //A partir de aqui, pasamos a una nueva etapa de la inscripcion
        system(clear);
        InscripcionFase2(temp_s->creditos + creditos_extras, semestre, cedula_s);

      } else {
        cout << "ERROR: El semestre debe estar entre 1 y 10";
      }

    } else {
      cout << "Ya existe un usuario con el numero de cedula ingresado en el sistema." << endl;
    }

    short int x;
    cout << "\n\nPara inscribir otro usuario, introducir 0 u otro numero" << endl;
    cout << "Para regresar al menu principal escriba 1" << endl;
    cout << "Opcion: "; cin >> x;

    if(x == 1) {
      Menu();
    } else {
      system(clear);
      Inscripcion();
    }
  } else {
    Menu();
  }
}
