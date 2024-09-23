// Nombre: Esteban David Muñoz Bautista
// Codigo: 8982338

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {-1, 0, 1, 0};

void dfsaux(int posFil, int posCol, vector<vector<bool>> &vis, vector<vector<char>> &matriz, int &gemas) {
    bool flag = false;

    vis[posFil][posCol] = true;
    if (matriz[posFil][posCol] == 'G'){
        gemas += 1;
    }
    
    for (int i = 0; i < 4; i++) {
        int posx = posFil + dx[i];
        int posy = posCol + dy[i];
        
        if (matriz[posx][posy] == 'T' ){
            flag = true;
        }
    }

    for (int i = 0; i < 4 && flag == false; i++) {
        int posx = posFil + dx[i];
        int posy = posCol + dy[i];
        
        if (!vis[posx][posy] && matriz[posx][posy] != '#' && matriz[posx][posy] != 'T' ){
            dfsaux(posx, posy, vis, matriz, gemas);
        }
    }
}

void dfs(vector<vector<char>> &matriz, int filas, int columnas, int posx, int posy){
    vector<vector<bool>> vis(filas, vector<bool>(columnas, false));
    int gemas = 0;

    dfsaux(posx, posy, vis, matriz, gemas);

    cout << gemas << endl;
}


int main() {
    int  filas, columnas;

    
    while ( cin >> columnas >> filas ){
        vector<vector<char>> matriz(filas, vector<char>(columnas));
        int posx, posy;


        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {

                cin >> matriz[i][j];

                if ( matriz[i][j] == 'P' ){
                    posx = i;
                    posy = j;
                }
            }
        }

        dfs(matriz, filas, columnas, posx, posy);

    }    

    return 0;
}
