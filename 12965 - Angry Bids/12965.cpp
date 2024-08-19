// Nombre: Esteban David Muñoz Bautista
// Codigo: 8982338


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solve(vector<int> &con, int valorPro){
    int mid ;
    int left = 0, right = con.size() - 1;
    while (left <= right) {
        mid = ((right+left)/2);
        if (con[mid] >= valorPro){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return left;
}


int main(){

    int casos, p, c, valor, enojados, enoPro, enoCon;
    

    cin >> casos;

    while (casos--){

        vector<int> prodcutores;
        vector<int> consumidores;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ans;;

        enojados = 0;

        cin >> p >> c;

        for ( int i = 0; i < p; i++){
            cin >> valor;
            prodcutores.push_back(valor);
        }
        prodcutores.push_back(0);

        for ( int i = 0; i < c; i++){
            cin >> valor;
            consumidores.push_back(valor);
        }
        sort(prodcutores.begin(), prodcutores.end());
        sort(consumidores.begin(), consumidores.end());

        
        
        for (int i = 0; i < prodcutores.size(); i++ ){
            enoPro = (prodcutores.size()-1)-i;
            enoCon = solve( consumidores, prodcutores[i]);
            enojados = enoPro + enoCon;
            ans.push(make_pair(enojados, prodcutores[i]));
            enojados = 0;
        }
        cout << ans.top().second << " " << ans.top().first << endl;
        
    }

    

    return 0;
}