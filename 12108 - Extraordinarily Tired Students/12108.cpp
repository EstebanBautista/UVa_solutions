#include <iostream>

using namespace std;

int main(){
    int casos,a ,b, c, cont = 0;

    while ((scanf("%d", &casos) && casos != 0)){
        cont++;
        int despiertos[11];
        int dormidos[11];
        int posicion[11];
        int limite[11];
        int sinSueno = 0, quintSueno = 0, fase = 1;
        bool todos = false;
        for (int j = 0; j < casos; j++){
            cin >> a >> b >> c;
            despiertos[j] = a;
            dormidos[j] = b;;
            posicion[j] = c;
            limite[j] = a+b;;
            fase *= limite[j];
        }
        int ans= -1;
        for (int i = 0; i <= fase; i++){
            sinSueno = 0, quintSueno = 0;

            for ( int pos = 0; pos < casos && todos == false; pos++){
                if (posicion[pos] <= despiertos[pos]) {sinSueno++;}
                else {quintSueno++;}
                if (sinSueno == casos) {
                    ans = i+1;
                    todos = true;
                }

            }
            for (int v = 0; v < casos; v++){
                posicion[v]++;
                if ( posicion[v] == limite[v] + 1) {posicion[v] = 1;}
                else if ( posicion[v] ==  despiertos[v]+1 && sinSueno >= quintSueno) {posicion[v] = 1;}
            }
        }
        cout << "Case " << cont << ": " << ans << endl;
    }


    return 0;
}

