#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    int caso = 1;
    bool flag = true;

    while(cin >> word && flag == true){
        
        if ( word == "#" ){ flag = false; }
        else if ( word == "HELLO"){ cout << "Case " << caso <<": ENGLISH" <<endl; }
        else if ( word == "HOLA"){ cout << "Case " << caso <<": SPANISH" <<endl; }
        else if ( word == "HALLO"){ cout << "Case " << caso <<": GERMAN" <<endl; }
        else if ( word == "BONJOUR"){ cout << "Case " << caso <<": FRENCH" <<endl; }
        else if ( word == "CIAO"){ cout << "Case " << caso <<": ITALIAN" <<endl; }
        else if ( word == "ZDRAVSTVUJTE"){ cout << "Case " << caso <<": RUSSIAN" <<endl; }
        else { cout << "Case " << caso <<": UNKNOWN" <<endl; }
        caso++;
    }
    return 0;
}