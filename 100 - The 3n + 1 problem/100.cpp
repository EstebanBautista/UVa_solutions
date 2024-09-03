// Esteban David Muñoz Bautista

#include <stdio.h>

int operaciones(int num) {
  int resultado = num, cont = 1;
  while (resultado != 1) {
    cont += 1;
    if (resultado % 2 != 0) {
      resultado = 3 * resultado + 1;

    } else if (resultado % 2 == 0) {

      resultado = resultado / 2;
    }
  }
  return cont;
}

void ciclos() {
  int i, j, num, num2, resultado = 0, longitud = 0, ganador;

  while (scanf("%d %d", &i, &j) != EOF) {
    num = i;
    num2 = j;
    resultado = 0;
    ganador = (i < j) ? i : j;
    if (ganador == i) {
      while (i <= j) {
        longitud = operaciones(i);
        if (resultado < longitud) {
          resultado = longitud;
        }
        i++;
      }
    } else {
      while (j <= i) {
        longitud = operaciones(j);
        if (resultado < longitud) {
          resultado = longitud;
        }
        j++;
      }
    }

    printf("%d %d %d\n", num, num2, resultado);
  }
}

int main() {
  ciclos();
  return 0;
}