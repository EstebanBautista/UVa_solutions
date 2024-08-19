#include <queue>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>

using namespace std;

void cola(){
    int casos, cantidad, MiPosicion, numeros, encontro, tiempo, impreso;
    pair <int,int> compara;
    cin >> casos;
    
    while(casos--){
        cin >> cantidad >> MiPosicion;
        queue <pair<int,int>> ColaDeImpresion;
        vector <int> tabla(10, 0);
        for (int j = 0; j < cantidad; j++){
            cin >> numeros;
            tabla[numeros]++;
            ColaDeImpresion.push(make_pair(numeros, j));
        }
        tiempo = 0;
        impreso = 0;
        for (int i = 9; i > 0 && impreso == 0; i--){
            encontro = 0;
            
            if ( tabla[i] != 0){
                while (!ColaDeImpresion.empty() && encontro == 0){
                    compara = ColaDeImpresion.front();
                    ColaDeImpresion.pop();
                    if(compara.first == i){
                        tiempo += 1;

                        if(compara.second == MiPosicion ){
                            encontro = 1;
                            impreso = 1;
                        }
                        tabla[i]--;
                        if(tabla[i] == 0){
                            encontro =1;
                        }                        
                    }
                    else{
                        ColaDeImpresion.push(compara);
                    }
                    
                }
            }
        }
        cout << tiempo << endl;
    } 
}

int main(){
    cola();
    return 0;
}