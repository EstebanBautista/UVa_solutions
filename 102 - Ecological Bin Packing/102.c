/* Esteban David Muñoz Bautista - 8982338 - Bin */
/* O(1) */
#include <stdio.h>


void conte(int contenedores[3][3]) {
  int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &contenedores[i][j]);
        }
    }
}

int cantidadMoves(int contenedores[3][3], char orden[3]) {
    char combinaciones[6][3] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int MoveMin = -1;
    int i, j;
    for (i = 0; i < 6; i++) {
        int move = 0;
        for (j = 0; j < 3; j++) {
            if (combinaciones[i][j] == 'B') {
                move += contenedores[j][1] + contenedores[j][2];
            } else if (combinaciones[i][j] == 'G') {
                move += contenedores[j][0] + contenedores[j][2];
            } else if (combinaciones[i][j] == 'C') {
                move += contenedores[j][0] + contenedores[j][1];
            }
        }

        if (MoveMin == -1 || move < MoveMin) {
            MoveMin = move;
            for (j = 0; j < 3; j++) {
                orden[j] = combinaciones[i][j];
            }
        }
    }

    return MoveMin;
}

void botellas() {
    int contenedores[3][3];
    char orden[3];
    int bandera = 0;

    while (!bandera) {
        conte(contenedores);
        if (feof(stdin)) {
            bandera = 1; 
        } else {
            int minMovimientos = cantidadMoves(contenedores, orden);
            printf("%c%c%c %d\n", orden[0], orden[1], orden[2], minMovimientos);
        }
    }

}

int main(){
  botellas();
  return 0;
}
