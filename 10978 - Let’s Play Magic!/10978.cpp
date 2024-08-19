/*
Esteban Muñoz
magic
Septiembre 30 de 2023

Analisis de complejidad:
n = cantidad cartas, es decir cantidad de casos
El primer while va hasta n casos y el while interno tambien recorre n casos, por ende se puede
inferir que la complejidad es O(n^2)

while de lectura y for : se hace n iteraciones ambos van hasta casos
segundo while: se hace n iteraciones

entonces n*n = n^2

*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void imprimir(vector<string> Vnombre) {
    for (int i = 0; i < Vnombre.size(); i++) {
        if (i != Vnombre.size() - 1) {
            cout << Vnombre[i] << " ";
        } else if (i == Vnombre.size() - 1) {
            cout << Vnombre[i] <<"\n";
        }
    }
}

void magico(){
    int casos, tam, Numcart;
    string siglas, palabra;
    
    while( scanf("%d", &casos) && casos != 0){
        vector<string>cartas(casos,"");
        Numcart = -1;

        for(int jul = 0; jul < casos; jul++){
            cin.ignore();
            cin >> siglas >> palabra;
            tam = palabra.size();

            while(tam != 0){
                Numcart = (Numcart+1) % casos;
                if (cartas[Numcart] == ""){tam-=1;}
            }
            cartas[Numcart] = siglas;
        }
        imprimir(cartas); 
    }    
}


int main(){
    magico();
    return 0;
}