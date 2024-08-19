#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int casos, comando, valor;

    while( cin >> casos ){
        bool s = true, q = true, pQ = true;
        stack<int> pilaPilota;
        queue<int> colaColota;
        priority_queue<int>  priorityPrioridad;

        while( casos--){

            cin >> comando >> valor;

            if ( comando == 1 ){
                if ( s ) { pilaPilota.push(valor); }
                if ( q ) { colaColota.push(valor); }
                if ( pQ ) { priorityPrioridad.push(valor);}
            }
            else{
                if ( s ){
                    if ( pilaPilota.empty() || pilaPilota.top() != valor ) {
                        s = false;
                    }
                    else{
                        pilaPilota.pop();
                    }
                }
                if ( q ){
                    if ( colaColota.empty() || colaColota.front() != valor ) {
                        q = false;
                    }
                    else{
                        colaColota.pop();
                    }
                }
                if ( pQ ){
                    if ( priorityPrioridad.empty() || priorityPrioridad.top() != valor ){
                        pQ = false;
                    }
                    else{
                        priorityPrioridad.pop();
                    }
                }
            }

        }
        if (!s && !q && !pQ ) { cout << "impossible" << endl; }
            else if ( s && !q && !pQ ) { cout << "stack" << endl; }
            else if ( q && !s && !pQ ) { cout << "queue" << endl; }
            else if ( pQ && !s && !q ) { cout << "priority queue" << endl; }
            else    { cout << "not sure" << endl; }

    }
    

    return 0;
}