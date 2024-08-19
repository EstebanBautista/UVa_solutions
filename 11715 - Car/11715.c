/* Esteban David Muñoz Bautista - 8982338 - Car */
/* O(n) */
#include <stdio.h>
#include <math.h>



void formulas(int caso, double valor1, double valor2, double valor3, int cont) {
  double aceleracion, desplazamiento, tiempo, velocidadF, velocidadI;

  if (caso == 1) {
    aceleracion = (valor2 - valor1) / valor3;
    desplazamiento = valor1 * valor3 + 0.5 * aceleracion * (valor3 * valor3);
    printf("Case %d: %.3lf %.3lf\n", cont, desplazamiento, aceleracion);
  } else if (caso == 2) {
    tiempo = (valor2 - valor1) / valor3;
    desplazamiento = valor1 * tiempo + 0.5 * valor3 * (tiempo * tiempo);
    printf("Case %d: %.3lf %.3lf\n", cont, desplazamiento, tiempo);
  } else if (caso == 3) {
    velocidadF = sqrt(valor1 * valor1 + 2 * valor2 * valor3);
    tiempo = (velocidadF - valor1) / valor2;
    printf("Case %d: %.3lf %.3lf\n", cont, velocidadF, tiempo);
  } else if (caso == 4) {
    velocidadI = sqrt(valor1 * valor1 - 2 * valor2 * valor3);
    tiempo = (valor1 - velocidadI) / valor2;
    printf("Case %d: %.3lf %.3lf\n", cont, velocidadI, tiempo);
  }
}


void car() {
  int caso = 1, cont = 0;
  double valor1 = 0, valor2 = 0, valor3 = 0;
  scanf("%d", &caso);
  while (caso != 0) {
    scanf("%lf %lf %lf", &valor1, &valor2, &valor3);
    cont += 1;
    formulas(caso, valor1, valor2, valor3, cont);
    
    scanf("%d", &caso);
  }
}






int main() {
  car();
  return 0;
}