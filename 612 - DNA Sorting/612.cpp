// Esteban David Muñoz Bautista

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool compareitor3000( pair<string, int>& valen, pair<string, int>& tina){
    return (valen.second < tina.second);
}

int main(){
    int casos, columnas, filas, cantidad;
    string adn;

    cin >> casos;
    while( casos-- ){
        list<pair<string,int>> listillaLapilla;


        cin >> columnas >> filas;

        for (int i = 0; i < filas; i++){
            cin >> adn;
            cantidad = 0;
            for ( int j = 0; j < columnas; j++){
                for ( int v = j+1; v < columnas; v++ ){
                    if (adn[j] > adn[v]){
                        cantidad++;
                    }
                }
            }
            listillaLapilla.push_back(make_pair(adn, cantidad));
        }
        listillaLapilla.sort(compareitor3000);
        list<pair<string, int>>::iterator it;
        for (it = listillaLapilla.begin(); it != listillaLapilla.end(); it++){
            cout << it->first << endl;
        }
        if ( casos != 0){ cout << endl; }
    }

    return 0;
}