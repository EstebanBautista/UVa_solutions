/*
Esteban David Muñoz Bautista
Ferry
codigo:8982338
*/
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


/*O(n) siendo n la cantidad de carros que hay en la izquierda  y la derecha*/
int movimiento(queue<int> izq, queue<int> der, int longBarco) {
    int repe1 = 0, carga = 0, veri = 0, flag = 0;
    while (!izq.empty() || !der.empty()) {
        if (carga <= longBarco && flag == 0) {
            if (!izq.empty()) {
                veri = izq.front();
                carga += izq.front();

                if (carga > longBarco) {
                    repe1 += 1;
                    flag = 1;
                    carga = 0;
                } else {
                    izq.pop();
                }
            }
            if (izq.empty()) {
                repe1 += 1;
                flag = 1;
                carga = 0;
            }
        }
        if (carga <= longBarco && flag == 1 && !izq.empty()) {
            if (!der.empty()) {
                veri = der.front();
                carga += der.front();

                if (carga > longBarco) {
                    repe1 += 1;
                    carga = 0;
                    flag = 0;
                } else {
                    der.pop();
                }
            }
            if (der.empty()) {
                repe1 += 1;
                flag = 0;
                carga = 0;
            }
        }
        if (izq.empty() && !der.empty()) {
            if (carga <= longBarco) {
                carga += der.front();

                if (carga > longBarco) {
                    repe1 += 1;
                    carga = 0;
                    flag = 0;

                } else {
                    der.pop();
                }
                if (der.empty()) {
                    repe1 += 1;
                    carga = 0;
                    flag = 0;
                }
            }
        }
    }

    return repe1;
}

/*O(n^2) siendo n la cantidad de casos introducidos y este se multiplica por la funcion movimiento
que tiene un costo O(n), lo que en total es O(n^2).*/ 

void info() {
    int casos, longBarco, longCarro, numCarros, ans;
    string lado;
    queue<int> Left;
    queue<int> Right;

    cin >> casos;
    while (casos--) {
        cin >> longBarco >> numCarros;
        queue<int> Left;
        queue<int> Right;
        while (numCarros--) {
            cin >> longCarro >> lado;
            if (lado == "left") {
                Left.push(longCarro);
            } else {
                Right.push(longCarro);
            }
        }
        ans = movimiento(Left, Right, longBarco * 100);
        printf("%d\n", ans);
    }
}

int main() { 
    info(); 
}