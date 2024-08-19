// Esteban Muñoz
// Complejidad O(n)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int casos, cantiMangos, capacidad, cont = 1;

    cin >> casos;
    
    while (casos--) {
        int tipoM, hambre, sumaM = 0;
        bool flag = true;
        vector<int> platos;
        vector<int> comer;

        cin >> cantiMangos >> capacidad;

        for (int i = 0; i < cantiMangos; i++){
            cin >> tipoM;
            platos.push_back(tipoM);
        }

        for (int f = 0; f < cantiMangos; f++){
            cin >> hambre;
            comer.push_back(hambre);
        }

        for (int i = 0; i < platos.size() && flag == true; i++){
            sumaM += platos[i];
            if (sumaM > capacidad || platos[i] > comer[i]){
                cout << "Case " << cont << ": No" << endl;
                flag = false;
            }
            

        }
        if (flag == true){
            cout << "Case " << cont << ": Yes" << endl;
        }
        
        
        cont++;
    }

    return 0;
}