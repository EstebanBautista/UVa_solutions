
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string toLowercase(string cad){
  string res = "";
  for(int i = 0; i < cad.size(); i++)
    res.push_back(tolower(cad[i]));
  return res;
}

class Jugador{
  private:
    string nombre;
    int puntos;

  public:
    Jugador(string &s, int p){
      nombre = s;
      puntos = p;
    }

    bool operator<(Jugador& jug){
      bool ans;
      if(puntos != jug.puntos)
	ans = puntos > jug.puntos;
      else
	ans = toLowercase(nombre) < toLowercase(jug.nombre);
      return ans;
    }

    void print(){
       cout << nombre << " " << puntos << endl;
    }
};

int main(){
  int n, i, j, k, pos, aux, caso = 1;
  string nombre, resto;
  string linea;
  vector<Jugador> vec;

  while(cin >> n){
    vec.clear();
    cin.ignore();
    for(i = 0; i < n; i++){
       getline(cin, linea);

       pos = linea.find(";");
       nombre = linea.substr(0, pos);
       resto = linea.substr(pos);
       aux = 0;
       for(j = 0, k = 0; j < resto.size(); j++){
	  if(resto[j] != ' ' && resto[j] != ';'){
	     aux += (resto[j] - 48);
	     k++;
	     if(k == 5){
	       aux += (resto[j] - 48);
	       k = 0;
	     }
	  }
       }

       Jugador jug(nombre, aux);
       vec.push_back(jug);
    }

    sort(vec.begin(), vec.begin() + n);
    cout << "Case " << caso++ << ":" << endl;
    for(i = 0; i < n; i++)
      vec[i].print();
  }

  return 0;
}
