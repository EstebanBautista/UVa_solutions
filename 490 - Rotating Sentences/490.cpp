#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int i = 0, n, col = 0, j;
    char arr[101][101];

    // Leer cada línea de entrada
    while (cin.getline(arr[i], 101)) {
        arr[i][strlen(arr[i])] = '\0';  // Eliminamos el salto de línea
        if (strlen(arr[i]) > col)
            col = strlen(arr[i]);  // Actualizamos la columna máxima
        ++i;
    }

    n = i;
    // Imprimir las columnas en orden invertido
    for (i = 0; i < col; ++i) {
        for (j = n - 1; j >= 0; --j) {
            if (i < strlen(arr[j]))
                cout << arr[j][i];
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
