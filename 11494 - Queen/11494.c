/* Esteban David Muñoz Bautista - 8982338 - Queen */
/* mejor caso : O(1) - Peor caso O(n) */
#include <stdio.h>

int absoluto(int num) {
    int nuevoNum;
    nuevoNum = num < 0 ? -num : num;
    return nuevoNum;
}

void moves() {
  int x1, y1, x2, y2;
  int flag = 0; 
  
  while (flag == 0) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        flag = 1;
    else {
      int move = 0;
      
      if (x1 != x2 && y1 != y2)
          move = (absoluto(x1 - x2) == absoluto(y1 - y2)) ? 1 : 2;
      else if (x1 == x2 || y1 == y2)
          move = (x1 == x2 && y1 == y2) ? 0 : 1;
          
      printf("%d\n", move);
    }
  }
}

int main(){
  moves();
  return 0;
}