#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    int cases = 1;
    while (cin >> word && word != "*" ){

        if ( word == "Hajj" ){
            cout << "Case "<< cases << ": Hajj-e-Akbar" << endl;
        }
        else{
           cout << "Case "<< cases << ": Hajj-e-Asghar" << endl; 
        }
        cases += 1;
    }
    return 0;
}