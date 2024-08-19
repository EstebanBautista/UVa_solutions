#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long int mios, suyos, resultado;
    while ( cin >> mios >> suyos ){
    
    if (suyos < mios){
            resultado = mios - suyos;
            cout << resultado << endl; 
        }
        else { 
            resultado = suyos - mios;
            cout << resultado << endl;  
        }
        
    }
    return 0;
}