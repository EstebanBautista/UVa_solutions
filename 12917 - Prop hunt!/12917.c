#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int hunt, prop, objects, posibilidades;

    while (scanf("%d %d %d", &hunt, &prop, &objects) != EOF){
        posibilidades = labs(prop - objects);
        if ((posibilidades < hunt) || (hunt == objects) || (prop > objects)){
            printf("Hunters win!\n");
        }
        else{
            printf("Props win!\n");
        }
    }
    return 0;
}