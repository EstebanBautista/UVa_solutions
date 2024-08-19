/*
Esteban Muñoz
didit
Septiembre 30 de 2023

Analisis de complejidad:
N =  numero de casos

asumiendo que los 3 vectores seran del mismo tamanio, tambien asumiendo n como ese tamanio maximo de vectores y como el maximo entre los 3, seria n cuadrado 
como al ejecutarte el primer ciclo for este entraria al primer ciclo while y se ejecutaria n y al finalizar este iria con el siguiente, una vez terminado de ejecutar
los ciclos for internos iria al ciclo for externo y volveria a repetir el mismo procesos, hasta que el ciclo externo llegue a n-1


entonces n*n = n^2

*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void imprimir(vector<int> Vnombre) {
    for (int i = 0; i < Vnombre.size(); i++) {
        if (i != Vnombre.size() - 1) {
            printf("%d ", Vnombre[i]);
        } else if (i == Vnombre.size() - 1) {
            printf("%d", Vnombre[i]);
        }
    }
}

void comparador(vector<int> &Vnombre1, vector<int> &Vnombre2,
                vector<int> &Vnombre3, int casos) {
    int cont1 = 0, cont2 = 0, cont3 = 0;
    int flag1 = 0, flag2 = 0;
    int v2 = 0;
    int v3 = 0;
    int v1 = 0;
    vector<int> solucion1;
    vector<int> solucion2;
    vector<int> solucion3;
    for (v1 = 0; v1 < Vnombre1.size(); v1++) {
        flag1 = 0;
        flag2 = 0;
        v3 = 0;
        v2 = 0;
        while (v2 < Vnombre2.size() && flag1 != 1) {
            if (Vnombre1[v1] == Vnombre2[v2]) {
                flag1 = 1;
            }
            ++v2;
        }
        if (flag1 == 0) {
            while (v3 < Vnombre3.size() && flag2 != 1) {
                if (Vnombre1[v1] == Vnombre3[v3]) {
                    flag2 = 1;
                }
                ++v3;
            }
        }

        if (flag1 == 0 && flag2 == 0) {
          if (solucion1.size() == 0){solucion1.push_back(Vnombre1[v1]);}
          else if (Vnombre1[v1] != solucion1[solucion1.size() - 1]) {
                solucion1.push_back(Vnombre1[v1]);
            }
          
        }
    }
    
    flag1 = 0;
    flag2 = 0;
    v2 = 0;
    v3 = 0;
    v1 = 0;
    for (v2 = 0; v2 < Vnombre2.size(); v2++) {
        flag1 = 0;
        flag2 = 0;
        v3 = 0;
        v1 = 0;
        while (v1 < Vnombre1.size() && flag1 != 1) {
            if (Vnombre2[v2] == Vnombre1[v1]) {
                flag1 = 1;
            }
            ++v1;
        }
        if (flag1 == 0) {
            while (v3 < Vnombre3.size() && flag2 != 1) {
                if (Vnombre2[v2] == Vnombre3[v3]) {
                    flag2 = 1;
                }
                ++v3;
            }
        }

        if (flag1 == 0 && flag2 == 0) {
          if (solucion2.size() == 0){solucion2.push_back(Vnombre2[v2]);}
          else if (Vnombre2[v2] != solucion2[solucion2.size() - 1]) {
                solucion2.push_back(Vnombre2[v2]);
            }
          
        }
    }

    flag1 = 0;
    flag2 = 0;
    v2 = 0;
    v3 = 0;
    v1 = 0;

    for (v3 = 0; v3 < Vnombre3.size(); v3++) {
        flag1 = 0;
        flag2 = 0;
        v2 = 0;
        v1 = 0;
        while (v1 < Vnombre1.size() && flag1 != 1) {
            if (Vnombre3[v3] == Vnombre1[v1]) {
                flag1 = 1;
            }
            ++v1;
        }
        if (flag1 == 0) {
            while (v2 < Vnombre2.size() && flag2 != 1) {
                if (Vnombre3[v3] == Vnombre2[v2]) {
                    flag2 = 1;
                }
                ++v2;
            }
        }

        if (flag1 == 0 && flag2 == 0) {
            if (solucion3.size() == 0){solucion3.push_back(Vnombre3[v3]);}
            else if (Vnombre3[v3] != solucion3[solucion3.size() - 1]) {
                solucion3.push_back(Vnombre3[v3]);
            }
          
        }
    }

    if (solucion1.size() > solucion2.size() &&
        solucion1.size() > solucion3.size()) {
        printf("Case #%d:\n1 %li ", casos, solucion1.size());
        imprimir(solucion1);
        printf("\n");
    }

    else if (solucion2.size() > solucion1.size() &&
             solucion2.size() > solucion3.size()) {
        printf("Case #%d:\n2 %li ", casos, solucion2.size());
        imprimir(solucion2);
        printf("\n");
    }

    else if (solucion3.size() > solucion1.size() &&
             solucion3.size() > solucion2.size()) {
        printf("Case #%d:\n3 %li ", casos, solucion3.size());
        imprimir(solucion3);
        printf("\n");
      
    } else if (solucion1.size() == solucion2.size() &&
               solucion1.size() == solucion3.size() && solucion1.size() == 0) {
        printf("Case #%d:\n1 %li", casos, solucion1.size());
        printf("\n2 0\n3 0\n");
      
    } else if (solucion1.size() == solucion2.size() &&
               solucion1.size() == solucion3.size()) {
        printf("Case #%d:\n1 %li ", casos, solucion1.size());
        imprimir(solucion1);
        printf("\n2 %li ", solucion2.size());
        imprimir(solucion2);
        printf("\n3 %li ", solucion3.size());
        imprimir(solucion3);
        printf("\n");
    }

    else if (solucion1.size() == solucion2.size() &&
             solucion1.size() != solucion3.size()) {
        printf("Case #%d:\n1 %li ", casos, solucion1.size());
        imprimir(solucion1);
        printf("\n2 %li ", solucion2.size());
        imprimir(solucion2);
        printf("\n");
      
    } else if (solucion1.size() != solucion2.size() &&
               solucion1.size() == solucion3.size() && solucion1.size() != 0) {
        printf("Case #%d:\n1 %li ", casos, solucion1.size());
        imprimir(solucion1);
        printf("\n3 %li ", solucion3.size());
        imprimir(solucion3);
        printf("\n");
      
    } else if (solucion1.size() != solucion2.size() &&
               solucion2.size() == solucion3.size()) {
        printf("Case #%d:\n2 %li ", casos, solucion2.size());
        imprimir(solucion2);
        printf("\n3 %li ", solucion3.size());
        imprimir(solucion3);
        printf("\n");
    }
    solucion1.clear();
    solucion2.clear();
    solucion3.clear();
}

void armador(vector<int> &Vnombre) {
    Vnombre.clear();
    int cont = 0, num;
    scanf("%d", &cont);
    for (int i = 0; i < cont; i++) {
        scanf("%d", &num);
        Vnombre.push_back(num);
    }
    sort(Vnombre.begin(), Vnombre.end());
}

void didit() {
    int casos = 0, cont = 0, v1, v2, v3;
    int *ganador, *caso;
    vector<int> solucion;
    vector<int> Amigo1;
    vector<int> Amigo2;
    vector<int> Amigo3;
    scanf("%d", &casos);
    while (cont < casos) {
        armador(Amigo1);
        armador(Amigo2);
        armador(Amigo3);
        comparador(Amigo1, Amigo2, Amigo3, cont + 1);
        cont++;
    }
}

int main() {
    didit();
    return 0;
}