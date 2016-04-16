#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;

typedef struct {
    string str;
    int integer;
    double flotante;
    char character;
} multi_array;

//Incluimos todas las clases
#include "classes/Node.cpp"
#include "classes/Lista.cpp"

/*
  #Hace lo mismo que el explode() de PHP
  #Recibe *str que es el string
  #Recibe el delimitador, por ejemplo
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
