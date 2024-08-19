#include <stdio.h>

int main() {
    int Casos;
    scanf("%d", &Casos);

    while (Casos--) {
        int Fila, Columna, Punto ;
        scanf("%d %d %d", &Fila, &Columna, &Punto);

        printf("%d %d %d\n", Fila, Columna, Punto);

        char mat[101][101];

        for (int i = 0; i < Fila; i++) {
            scanf("%s", mat[i]);
        }

        for (int q = 0; q < Punto; q++) {
            int fil, col;
            scanf("%d %d", &fil, &col);

            int maxLado = 1, lado = 1;

            for (lado = 1; lado <= Fila && lado <= Columna; lado++) {
                int mitadLado = lado / 2;
                char centro = mat[fil][col];
                int bandera = 1;
                int i, j;

                for (i = fil - mitadLado; i <= fil + mitadLado && bandera; i++) {
                    for (j = col - mitadLado; j <= col + mitadLado && bandera; j++) {
                        if (i < 0 || i >= Fila || j < 0 || j >= Columna || mat[i][j] != centro) {
                            bandera = 0;
                        }
                    }
                }

                if (bandera) {
                    maxLado = lado;
                }
            }

            printf("%d\n", maxLado);
        }
    }

    return 0;
}
