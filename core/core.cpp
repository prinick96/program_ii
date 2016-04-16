#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <fstream>
using namespace std;

typedef struct {
    string str;
    int integer;
    double flotante;
    char character;
} multi_array;

//Incluyo el prototipo para que esté disponible en Node.cpp y en Lista.cpp
vector<string> explode( const string &delimiter, const string &str);

//Incluimos todas las clases
#include "classes/Node.cpp"
#include "classes/Lista.cpp"

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

Lista *CreateEntity(char *route,const short int type, Lista *element) {
   ifstream archivo;
   char str[180];
   archivo.open(route);
   element = new Lista();

   if(!archivo.fail()) {
      int i = 0;
      while(!archivo.eof()) {
         archivo.getline(str,180);
         if(archivo.eof()) {
            break;
         }
         element->Add(type,str);
      }
   } else {
      cout << "Error al abrir el archivo" << endl;
   }

   archivo.close();

   return element;
}
