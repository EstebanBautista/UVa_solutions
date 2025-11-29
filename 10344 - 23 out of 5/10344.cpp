// Nombre: Esteban David Muñoz Bautista
// Código: 898233

#include <bits/stdc++.h>
using namespace std;

bool encontrado = false;

bool solveRec(vector<int> &numeros, int valor, int cont) {
    bool ans = false;

    if (cont == 0) {
        if (valor == 23) {
            encontrado = true;
            ans = true;
        }
    } 
    else {
        int sumita = 0;
        for (int x : numeros) sumita += x;

        if (!((valor * sumita < 23 && valor + sumita < 23) ||
              (valor - sumita > 23 && valor * sumita > 23))) {

            int i = 0;
            while (i < 5 && !encontrado) {
                if (numeros[i] != 0 && !encontrado) {
                    int num = numeros[i];
                    numeros[i] = 0;

                    int j = 0;
                    while (j < 3 && !encontrado) {
                        if (j == 0 && !encontrado)
                            ans = solveRec(numeros, valor + num, cont - 1);
                        else if (j == 1 && !encontrado)
                            ans = solveRec(numeros, valor - num, cont - 1);
                        else if (j == 2 && !encontrado)
                            ans = solveRec(numeros, valor * num, cont - 1);

                        j = j + 1;
                    }

                    numeros[i] = num;
                }
                i = i + 1;
            }
        }
    }

    return ans;
}

bool solveInicial(vector<int> numeros) {
    encontrado = false;
    bool ans = false;

    int i = 0;
    while (i < 5 && !encontrado) {
        int num = numeros[i];
        numeros[i] = 0;
        solveRec(numeros, num, 4);
        numeros[i] = num;
        i = i + 1;
    }

    if (encontrado) ans = true;
    return ans;
}

int main() {
    vector<int> numeros(5);
    bool seguir = true;

    while (seguir) {
        int suma = 0;
        for (int i = 0; i < 5; i++) {
            cin >> numeros[i];
            suma = suma + numeros[i];
        }

        if (suma == 0) {
            seguir = false;
        } else {
            bool posible = solveInicial(numeros);
            if (posible) cout << "Possible\n";
            else cout << "Impossible\n";
        }
    }

    return 0;
}
