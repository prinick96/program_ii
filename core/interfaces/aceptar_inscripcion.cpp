#include <algorithm>
/*
  Acepta la solicitud de inscripción que estará en "planillas de inscripción".
  Para aceptar una solicitud se coloca la cedula de quien solicita, se elimina de planillas
  se pasa a materias inscritas y se incrementa la cantidad de alumnos para cada seccion donde este el aceptado.
  Listas usadas aqui:
  Planillas
  Materias_I
  Secciones
  Alumnos
  Materias
*/
void AceptarInscripcion() {
  extern Lista *Planillas;
  extern Lista *Materias_I;
  extern Lista *Secciones;
  extern Lista *Alumnos;
  vector<int> cedulas; //control de alumnos
  int cedula;

  cout << "Lista de planillas de inscripción de aspirantes\n" << endl;

  Node *temp_p = Planillas->primero, *temp_a = NULL, *temp_s = NULL, *temp_m;
  while (temp_p != NULL) {
    /*
      Almacenamos las cedulas de los alumnos que solicitan SIN REPETIR ninguna.
      Mostrando nombre-cedula del aspirante
    */
    if(find(cedulas.begin(), cedulas.end(), temp_p->cedula) == cedulas.end()) {
      cedulas.push_back(temp_p->cedula);
      temp_a = Alumnos->primero;
      while (temp_a != NULL) {
        if(temp_a->cedula == temp_p->cedula) {
          break;
        }
        temp_a = temp_a->sig;
      }
      cout << temp_a->nombre << " v" << temp_p->cedula << endl;
    }
    temp_p = temp_p->sig;
  }

  //Obtengo toda la información de las secciones en UN Solo ciclo, porque más adelante la voy a necesitar
  map<string, array_asociativo> i_sec;
  map<string, array_asociativo>::iterator iter; //Iterador para i_sec
  map<string, array_asociativo>::iterator iter2; //Iterador para secciones_planilla
  temp_s = Secciones->primero;
  while (temp_s != NULL) {
      i_sec[temp_s->cod_seccion].cod_materia = temp_s->cod_materia;
      i_sec[temp_s->cod_seccion].dia = temp_s->dia;
      i_sec[temp_s->cod_seccion].entrada = temp_s->hora_entrada;
      i_sec[temp_s->cod_seccion].salida = temp_s->hora_salida;
      i_sec[temp_s->cod_seccion].max_alumnos = temp_s->max_alumnos;
      i_sec[temp_s->cod_seccion].alumnos_inscritos = temp_s->alumnos_inscritos;
      i_sec[temp_s->cod_seccion].nodo = temp_s;
      temp_s = temp_s->sig;
  }

  cout << "\nEscribir 0 para regresar al MENU" << endl;
  cout << "Introducir numero de cedula para ver planilla correspondiente: "; cin >> cedula;
  system(clear);
  if(cedula != 0) {
    short int x, z;
    string seccion_elegida = "Sin Seccion";
    //La cedula SI existe
    if(find(cedulas.begin(), cedulas.end(), cedula) != cedulas.end()) {

      //Muestro la planilla del alumno y encima recibo la informacion de toda la planilla del alumno
      map<string, array_asociativo> secciones_planilla = VerPlanilla(true,cedula);

      cout << "Introduce 0 para regresar a ver todas las planillas" << endl;
      cout << "Introduce 1 para aceptar esta planilla" << endl;
      cout << "Valor: "; cin >> x;
      if(x == 1) {
        temp_p = Planillas->primero;
        while (temp_p != NULL) { //while(1)
          //Me detengo en TODOS los registros que coincidan con la cedula para meterlos en la materia inscrita
          if(temp_p->cedula == cedula) { //if(1)

            //Si esta condicion se da, la materia no choca y tiene cupo
            if(i_sec[temp_p->cod_seccion].alumnos_inscritos < i_sec[temp_p->cod_seccion].max_alumnos) { //if(2)

              cout << "Entramos en IF con " << temp_p->cod_seccion << endl;

              //en el campo "nodo", tengo el valor de la dirección de memoria de esa sección
              (i_sec[temp_p->cod_seccion].nodo)->alumnos_inscritos++;
              seccion_elegida = temp_p->cod_seccion;

            } else { //if(2)

              cout << "Entramos en el ELSE con " << temp_p->cod_seccion << endl;

              //En este punto, tengo que buscar reasignar a otra sección al alumno que si tenga cupo.
              for(iter = i_sec.begin(); iter != i_sec.end(); iter++) { //for(1)
                z = 0;
                if(i_sec[iter->first].cod_materia == i_sec[temp_p->cod_seccion].cod_materia
                && i_sec[iter->first].alumnos_inscritos < i_sec[iter->first].max_alumnos) { //if(3)

                  //En este punto conseguí otra sección de la materia que tiene cupos.
                  //Por tanto tengo que ver si no choca con ninguna sección de las otras materias
                  //en la planilla del user
                  //En secciones_planilla tengo un map con las secciones de las otras materias y su información.
                  //Así que tengo que recorrerlas todas y si ninguna choca, elijo esta nueva seccion.

                  iter2 = secciones_planilla.begin();
                  while(iter2 != secciones_planilla.end()) {//while(1)
                    //Si el dia es igual y la hora de entrada es la misma, choca o esta entre la hora de entrada y salida choca!
                    if(secciones_planilla[iter2->first].dia == i_sec[iter->first].dia
                    && (secciones_planilla[iter2->first].entrada == i_sec[iter->first].entrada
                        || (secciones_planilla[iter2->first].entrada > i_sec[iter->first].entrada
                            && secciones_planilla[iter2->first].entrada < i_sec[iter->first].salida
                            )
                        )
                      )
                    {
                      z++; //Incremento z, porque si z al final es distinto de 0 se que al menos con alguna SI choca
                      break; //No tendria sentido seguir buscando en el bucle porque ya al menos una si choca
                    }

                    iter2++;
                  }//end while(1)

                  //Si Z es 0, el codigo de la seccion que es iter->first, no choca con ninguna materia de su planilla
                  if(z == 0) {
                    (i_sec[iter->first].nodo)->alumnos_inscritos++;
                    seccion_elegida = iter->first;
                    break;//Detenemos el for de las secciones de la planilla, porque hemos conseguido una seccion!
                  }

                }//end if(3)
              }//end for(1)
            }//end if(2)

            //Convertimos cedula de int a un string para poder concatenarlo en el formato
            string cedula_str;
            ostringstream convert; //este es el intermediario para hacer la conversión
            convert << cedula;
            cedula_str = convert.str();

            string materia_inscrita_formato = i_sec[seccion_elegida].cod_materia + "_" + seccion_elegida + "_" + cedula_str;

            char *str = new char[materia_inscrita_formato.length() + 1]; //Como Add recibe es un (char *) y no puedo castear, uso memoria dinamica
            strcpy(str, materia_inscrita_formato.c_str()); //Convierto en (char *) a data con el metodo c_str() y con strcpy() lo copio a str
            Materias_I->Add(2,str);
            delete[] str;//Libero de memoria el char * temporal
          }//end if(1)
          temp_p = temp_p->sig;
        }//end while(1)

        cout << "El alumno fue inscrito correctamente!" << endl;
        cout << "\n\nPara volver a la lista de planillas, introducir 0 u otro numero" << endl;
        cout << "Para regresar al menu principal escriba 1" << endl;
        cout << "Opcion: "; cin >> x;

        if(x == 1) {
          Menu();
        } else {
          system(clear);
          AceptarInscripcion();
        }

      } else {
        system(clear);
        AceptarInscripcion();
      }
    } else {
      cout << "\nLa cedula ingresada no existe en sistema." << endl;
      cout << "\n\nPara volver a consultar, introducir 0 u otro numero" << endl;
      cout << "Para regresar al menu principal escriba 1" << endl;
      cout << "Opcion: "; cin >> x;

      if(x == 1) {
        Menu();
      } else {
        system(clear);
        AceptarInscripcion();
      }
    }
  } else {
    Menu();
  }

}
