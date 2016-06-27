#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <fstream>
#include <stdlib.h>
#include <map> //Libreria para crear arrays asociativos de la forma arreglo["index"] = "valor";


//Si es Windows, usar cls, si es Linux usar clear
//#define clear "cls"
#define clear "clear"
using namespace std;

//Incluyo el prototipo para que esté disponible en Node.cpp y en Lista.cpp.
vector<string> explode( const string &delimiter, const string &str);

//Incluimos todas las clases
#include "classes/Node.cpp"
#include "classes/Lista.cpp"
#include "classes/AVL.cpp"
#include "classes/Record.cpp"

//Estructura que define la informacion de una seccion
typedef struct {
  string cod_materia;
  short int dia;
  float entrada;
  float salida;
  int max_alumnos;
  int alumnos_inscritos;
  Node *nodo;
} array_asociativo;

//La interfaz mayor
#include "interfaces/menu.cpp"

/*
  #Hace lo mismo que el explode() de PHP
  #Recibe str por referencia que es el string
  #Recibe el delimitador por referencia, por ejemplo
  vector<string> v = explode("_","hola_dos");
  v[0] -> hola
  v[1] -> dos
  Con el fin de separar elementos de los archivos .txt
*/
vector<string> explode( const string &delimiter, const string &str)
{
    vector<string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0) {
        return arr;
    }

    int i=0;
    int k=0;
    while( i < strleng )
    {
        int j=0;
        while (i+j < strleng && j < delleng && str[i+j] == delimiter[j])
            j++;
        if (j==delleng) { //aqui ya encontre el delimitador
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        } else {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}

/*
   #Crea una entidad y devuelve la Lista con sus datos cargados desde un .txt
   #char *route: La ruta del archivo .txt de la entidad
   #short int type: El tipo de entidad, se utilizará en el método Add() de la class Lista
      Es "const" porque jamás se va a modificar su valor en lo largo del código.
   #Lista* element: Un puntero (objeto) de la clase Lista
*/
Lista *CreateEntity(char *route,const short int type, Lista *element) {
   ifstream archivo;
   ifstream lerecords;
   int nota, time, estado;
   vector<string> learbolito, leuser;
   char str[180], lerecords_str[180];
   archivo.open(route);
   element = new Lista();

   if(!archivo.fail()) {
      int i = 0;
      while(!archivo.eof()) {
         archivo.getline(str,180);
         if(archivo.eof()) {
            break;
         }

         //Creamos una lista común para todas las entidades
         if(type != 4) {

           if(type == 1) {
             AVL Arbol;

             //pss....
             lerecords.open((char *) "data/record.txt");
             while (!lerecords.eof()) {
               lerecords.getline(lerecords_str,180);
               if(lerecords.eof()) {
                  break;
               }

               learbolito = explode("_", (string) lerecords_str);
               leuser = explode("_", (string) str);

               stringstream(learbolito[2]) >> nota;
               stringstream(learbolito[3]) >> time;
               stringstream(learbolito[5]) >> estado;

               //Si la cedula del usuario es igual a la cedula asociada en el record pss..
               if(leuser[0] == learbolito[0]) {
                 Arbol.Insertar(nota,time,learbolito[4],estado,learbolito[1]);
                 //cout << "insert in " << Arbol.raiz << " note " << nota << endl;
               }
             }
             lerecords.close();
             //end pss...

             element->Add(type,str,Arbol.raiz);
           } else {
             element->Add(type,str);
           }

         //Cuando sea (4) es porque es la lista de Secciones o (6) Planillas, que será ordenada
         } else {
            element->AddSort(type,str);
         }

      }
   } else {
      cout << "ERROR: Intentando abrir el archivo <" << route << ">\n" << endl;
   }

   archivo.close();

   return element;
}
