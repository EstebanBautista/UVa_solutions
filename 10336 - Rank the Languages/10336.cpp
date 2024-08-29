// Nombre: Esteban David Muñoz Bautista
// Codigo: 8982338

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {-1, 0, 1, 0};

void dfsaux(int posFil, int posCol, vector<vector<bool>> &vis, vector<vector<char>> &matriz, char valor) {
    vis[posFil][posCol] = true;

    for (int i = 0; i < 4; i++) {
        int posx = posFil + dx[i];
        int posy = posCol + dy[i];

        if (posx >= 0 && posx < matriz.size() && posy >= 0 && posy < matriz[0].size() && !vis[posx][posy] && matriz[posx][posy] == valor) {
            dfsaux(posx, posy, vis, matriz, valor);
        }
    }
}

void dfs(vector<vector<char>> &matriz, map<char, int> &result) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<bool>> vis(filas, vector<bool>(columnas, false));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (vis[i][j] == false) {
                result[matriz[i][j]]++;
                dfsaux(i, j, vis, matriz, matriz[i][j]);
            }
        }
    }
}

bool comparador(const pair<int, char> &a, const pair<int, char> &b) {
    bool resultado;
    if (a.first == b.first) {
        resultado = a.second < b.second;  
    } else {
        resultado = a.first > b.first; 
    }
    return resultado;
}

int main() {
    int casos, filas, columnas;
    cin >> casos;

    for (int v = 0; v < casos; v++) {
        cin >> filas >> columnas;
        vector<vector<char>> matriz(filas, vector<char>(columnas));
        map<char, int> result;


        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> matriz[i][j];
            }
        }

        dfs(matriz, result);

        vector<pair<int, char>> rank;
        map<char, int>::iterator it = result.begin();
        for (it = result.begin(); it != result.end(); ++it) {
            if (it->second  != 0){
                rank.push_back(make_pair(it->second, it->first ));
            }
        }

        sort(rank.begin(), rank.end(), comparador);

        cout << "World #" << v + 1 << endl;
        for (size_t i = 0; i < rank.size(); i++) {
            cout << rank[i].second << ": " << rank[i].first << endl;
        }
    }

    return 0;
}
