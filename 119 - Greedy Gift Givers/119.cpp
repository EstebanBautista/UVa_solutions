/*
Esteban Muñoz
givers
Septiembre 30 de 2023

Analisis de complejidad:
N =  Cantidad de personas

El bucle externo y el bucle interno va hasta CantidadPer por ende se puede inferir que la complejidad va hasta n^2
todos los ciclos al depender de n, el ciclo se ejecutaria esa cantidad de veces, asi hasta que el siclo externo llegue a n


entonces n*n = n^2

*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solucion()
{
	int repe = 1;
    int CantidadPer, gasto, CantiGente, regalo, ite, flag;
	string nombreP;
    while (cin >> CantidadPer){
        vector<string> nombres;
        vector<int> dinero;

        for (int i = 0; i < CantidadPer; ++i){
            cin >> nombreP;
            nombres.push_back(nombreP);
            dinero.push_back(0);
        }

        for (int la = 0; la < CantidadPer; ++la){
            cin >> nombreP;
            cin >> gasto >> CantiGente;

            if (CantiGente != 0){
                regalo = gasto / CantiGente;
                ite = -1;
                flag = 0;

                for (int jul = 0; jul < CantidadPer && !flag; ++jul){
                    if (nombres[jul] == nombreP){
                        ite = jul;
                        flag = 1;
                    }
                }

                if (flag){
                    dinero[ite] -= regalo * CantiGente;

                    for (int j = 0; j < CantiGente; ++j){
                        cin >> nombreP;
                        flag = 0;

                        for (int san = 0; san < CantidadPer && !flag; ++san){
                            if (nombres[san] == nombreP){
                                dinero[san] += regalo;
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }

        if (repe++ > 1){cout << endl;}

        for (int i = 0; i < CantidadPer; ++i){
            cout << nombres[i] << " " << dinero[i] << endl;
		}
    }
}

int main(){
    solucion();
    return 0;
}
