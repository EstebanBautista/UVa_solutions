#include <iostream>

using namespace std;

int main(){
    int casos, cEntrada, velocidad, cont = 1;

    cin >> casos;

    while( casos-- ){
        int mayor = 0;

        cin >> cEntrada;

        for ( int i = 0; i < cEntrada; i++){
            
            cin >> velocidad;
            if( velocidad > mayor) {
                mayor = velocidad;
            }
        }
        cout << "Case " << cont << ": " << mayor << endl;
        cont++;
    }

    return 0;
}