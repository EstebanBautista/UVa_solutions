// Esteban David Muñoz Bautista
// Codigo: 8982338

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> pilasS, pilasP;
vector<int> finalizacion, visitado;
vector<vector<int>> sccNodos, lista;
int t = 0, num = 0;

void gabowaux(int nodo){
    int componente, newNodo;
    t++;
    visitado[nodo] = t;

    pilasS.push(nodo);
    pilasP.push(nodo);

    for (int i = 0; i < lista[nodo].size(); i++){
        newNodo = lista[nodo][i];
        if (visitado[newNodo] == -1){
            gabowaux(newNodo);
        }
        else if (finalizacion[newNodo] == -1){
            while (visitado[pilasP.top()] > visitado[newNodo]){
                pilasP.pop();
            }
        }
    }
    if (pilasP.top() == nodo){
        num++;
        sccNodos.push_back(vector<int>());
        while (pilasS.top() != nodo){
            componente = pilasS.top();
            pilasS.pop();
            finalizacion[componente] = num - 1;
            sccNodos[num - 1].push_back(componente);
        }

        componente = pilasS.top();
        pilasS.pop();
        finalizacion[componente] = num - 1;
        sccNodos[num - 1].push_back(componente);
        pilasP.pop();
    }
}

void gabow(int fbf){
    for (int i = 0; i < fbf; i++){
        if (visitado[i] == -1) {
            gabowaux(i);
        }
    }
}

int main() {
    int fbfs, conectores, casos, contI, contA, ans, fbfA, fbfB, apunta;
    cin >> casos;
    while (casos--){
        cin >> fbfs >> conectores;

        // Limpieza
        sccNodos.clear();
        visitado.clear();
        finalizacion.clear();
        lista.clear();
        t = 0;
        num = 0;
        ans = 0;
        contI = 0;
        contA = 0;

        // para llenar visitados y finalizacion con -1 y tambien crear la lista de adyacencia 

        for (int i = 0; i < fbfs; i++){
            visitado.push_back(-1);
            finalizacion.push_back(-1);
        }

        for (int i = 0; i < fbfs; i++) {
            lista.push_back(vector<int>());
        }

        // Crear grafo transpuesto
        for (int i = 0; i < conectores; i++){
            cin >> fbfA >> fbfB;
            lista[fbfB - 1].push_back(fbfA - 1);
        }

        gabow(fbfs);

        vector<int> senialados(sccNodos.size(), 0);
        vector<int> adyacencia(sccNodos.size(), 0); 
        
        // Crear la incidencia y adyacencia del grafo SCC
        for (int nodo = 0; nodo < fbfs; nodo++) {
            for (int val = 0; val < lista[nodo].size(); val++){
                apunta = lista[nodo][val];
                if (finalizacion[nodo] != finalizacion[apunta]){
                    senialados[finalizacion[apunta]]++;
                    adyacencia[finalizacion[nodo]]++;
                }
            }
        }

        // Contar cuántas SCCs tienen incidencia entrante 0
        for (int i = 0; i < sccNodos.size() && sccNodos.size() != 1; i++){
            if (senialados[i] == 0){
                contI++;
            }
            if (adyacencia[i] == 0){
                contA++;
            }
        }

        // decici usar max para no tener que hacer varios if para determinar cual valor era mayor
        // partiendo de esta idea y sabiendo que la funcion max() para este caso donde siempre son dos valores
        // tiene una complejidad O(1)
        if (contI != 0 && contA != 0 ){
            ans = max(contI, contA); 
        }
        else if (conectores == 0 && fbfs != 1) {
            ans = fbfs;
        }

        // Imprimir el resultado
        cout << ans << endl;
    }

    return 0;
}
