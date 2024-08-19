#include <iostream>

using namespace std;

int main(){
    int casos, largo, ancho, alto, cont = 1;
    cin >> casos;
    while( casos--){
        cin >> largo >> ancho >> alto;
        
        if ( largo > 20 || ancho > 20 || alto > 20){
            cout << "Case " << cont << ": bad" << endl;
        }
        else { cout << "Case " << cont << ": good" << endl; }
        cont++;
    }
    return 0;
}