#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;



int main() {

    int casos, numC, numV;
    string name, party;
    map<string, string> partidos;  // Mapa para relacionar candidatos con partidos
    map<string, int> candidatos;     // Mapa para contar los votos de los candidatos

    cin >> casos;
    bool first = true;

    while (casos--) {
        if (!first) cout << endl;
        first = false;
        partidos.clear();  // Limpia el mapa de candidatos y partidos
        candidatos.clear();  // Limpia el mapa de votos

        cin >> numC;  // Número de candidatos
        while (getchar() != '\n');  // Limpiar el buffer de entrada
        for (int i = 0; i < numC; i++) {
            getline(cin, name);  // Nombre del candidato
            getline(cin, party); // Partido del candidato
            partidos[name] = party;    // Asocia el nombre con su partido
            candidatos[name] = 0;        // Inicializa los votos del candidato
        }

        cin >> numV;  // Número de votos
        while (getchar() != '\n');  // Limpiar el buffer de entrada
        for (int i = 0; i < numV; i++) {
            getline(cin, name);  // Nombre del candidato votado
            if (partidos[name] != "") {  // Si el candidato existe en el mapa
                candidatos[name]++;  // Incrementa sus votos
            }
        }

        // Proceso de encontrar al ganador
        int ganador = -1;
        bool empate = false;
        for (map<string, int>::iterator i = candidatos.begin(); i != candidatos.end(); ++i) {
            if (i->second > ganador) {  // Si el candidato tiene más votos
                ganador = i->second;
                name = i->first;  // Guarda el nombre del ganador provisional
                empate = false;   // No hay empate
            } 
            else if (i->second == ganador) {  // Si hay otro con los mismos votos
                empate = true;  // Marca que hay empate
            }
}

        if (!empate) {
            cout << partidos[name] << endl;  // Imprime el partido del ganador
        } else {
            cout << "tie" << endl;  // Imprime "tie" en caso de empate
        }
    }

    return 0;
}
