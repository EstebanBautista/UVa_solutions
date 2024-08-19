/*
Esteban David Muñoz Bautista
Rain
codigo:8982338
*/
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <cstdio>
using namespace std;

/*
O(n*m) siendo n la cantidad de casos y m la longitud de la string, por lo tanto
como el ciclo for esta anidado en el while, la complejidad pasa a ser n*m 
*/

void llueve(){
    int casos, guarda, agua = 0;
    string campo;
    scanf("%d", &casos);
    while(casos--){
        stack <int> altibajos;
        agua = 0;
        cin >> campo;
        for (int i = 0; i < campo.length(); i++){
            if (campo[i] == 92 ){
               altibajos.push(i);
            }
            else if (campo[i] == '/' && !altibajos.empty()){
                guarda = altibajos.top();
                altibajos.pop();
                agua += i - guarda;

            }
        }
        printf("%d\n", agua); 
    }   
}

int main(){
    llueve();
    return 0;
}