// Esteban David Muñoz Bautista
// Codio: 8982338
// La complejidad es O(n) donde n es la cantidad de nodos y dado que
// la funcion que recorre los niveles del nodo tiene que pasar por cada uno de estos
// y estos depende de la cantidad de caracteres de la entrada

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Nodo{
    public:
    char dato;
    Nodo* left;
    Nodo* right;

    Nodo(){}

    Nodo(char dato): 
      dato(dato), 
      left(NULL), 
      right(NULL) {}
};

Nodo* createTree(string &sentence){

    stack<Nodo*> pilapilota;
    Nodo* act;
    char value;
    for (int i = 0; i < sentence.size(); i++){

        value = sentence[i];
        act = new Nodo(value);
        if ( value < 'a' ){
            act->right = pilapilota.top();
            pilapilota.pop();
            act->left = pilapilota.top();
            pilapilota.pop();
        }

        pilapilota.push(act);
    }
    return pilapilota.top();
}

string abajoArriba(Nodo* tree){
    string ans;
    Nodo* act;
    queue<Nodo*> colaColota;
    colaColota.push(tree);

    while (!colaColota.empty()){

        act = colaColota.front();
        colaColota.pop();
        ans += act->dato;

        if (act->left != NULL){
            colaColota.push(act->left);
        }
        if ( act->right != NULL ){
            colaColota.push(act->right);
        }
    }
    return ans;
}

int main(){
    string expression, ans;
    Nodo* tree;
    int casos;
    cin >> casos;

    while (casos--){
        cin >> expression;
        tree = createTree(expression);
        ans = abajoArriba(tree);
        for(int i = ans.size() - 1; i >= 0; --i){
          cout << ans[i];
        }
        cout << endl;
    }

}