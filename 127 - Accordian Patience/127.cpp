// Esteban David Muñoz Bautista
//  Codigo: 8982338
// La complejidad es O(1) dado que siempre itera sobre el mismo valor que es 52, siendo este siempre la cantidad de cartas


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool judge(string cardA, string cardB){
    bool ans = false;
    if (cardA[0] == cardB[0] || cardA[1] == cardB[1]){
        ans = true;
    }

    return ans;
}

void solucion(){
    string card;
    bool stop = false;
    string piles;
    while ( cin >> card && stop == false){
        if ( card != "#"){
            vector<stack<string>> deck(52);
            
            deck[0].push(card);
            for (int pos = 1; pos < 52; pos++) {
                cin >> card;
                deck[pos].push(card);
            }
    
        
            for (int pos = 1; pos < deck.size(); pos++){
                if ( pos >= 3 && judge(deck[pos].top(), deck[pos-3].top()) ){
                    deck[pos-3].push(deck[pos].top());
                    deck[pos].pop();
                    if (deck[pos].empty()){
                        deck.erase(deck.begin() + pos);
                    }
                    if ( pos >= 4){
                        pos-=4;
                    }
                    else{
                        pos-=3;
                    }
                }
                else if ( judge(deck[pos].top(), deck[pos-1].top()) ){
                    deck[pos-1].push(deck[pos].top());
                    deck[pos].pop();
                    if ( deck[pos].empty() ){
                        deck.erase(deck.begin() + pos);
                    }
                    if ( pos >= 2){
                        pos-=2;
                    }
                    else{
                        pos--;
                    }
                
                }
            }
            

            if (deck.size() > 1 ){
                piles = " piles remaining:";
            }else{
                piles = " pile remaining:";
            }

            cout << deck.size() << piles;
            
            for (int i = 0; i < deck.size(); i++) {
                cout << " " << deck[i].size();
            }
            cout << endl;
        }
        else{
            stop = false;
        }
    }         
            
}   

int main(){
    solucion();
    return 0;
}