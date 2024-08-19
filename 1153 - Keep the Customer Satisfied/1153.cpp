/*
Esteban David Muñoz Bautista
customer
codigo:8982338
*/
#include <iostream>
#include <queue>

using namespace std;

class Comparator {
public:
    Comparator() {};
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

/*
O(n*m + n*j) siendo n la cantidad de casos, m la cantidad de pedidos y j el tamaño de Acero_Fecha
*/
void customer() {
    int casos, pedidos, acero, fecha, almacena = 0, cont = 0;
    scanf("%d", &casos);

    while (casos--) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> Acero_Fecha;
        priority_queue<pair<int, int>> guarda;
        scanf("%d", &pedidos);
        cont = 0;
        almacena = 0;

        while (pedidos--) {
            scanf("%d %d", &acero, &fecha);
            Acero_Fecha.push(make_pair(acero, fecha));
        }

        while (!Acero_Fecha.empty()) {
            pair<int, int> paquete = Acero_Fecha.top();

            if (almacena + paquete.first <= paquete.second) {
                almacena += paquete.first;
                guarda.push(paquete);
            } 
            else if (!guarda.empty() && guarda.top().first > paquete.first) {
                almacena += paquete.first - guarda.top().first;
                guarda.pop();
                guarda.push(paquete);
            }

            Acero_Fecha.pop();
        }

        printf("%d\n", guarda.size());
        if(casos != 0) {printf("\n"); }
    }
}

int main() {
    customer();
    return 0;
}
