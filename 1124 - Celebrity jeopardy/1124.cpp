#include <iostream>
#include <string>
#include <istream>

using namespace std;

int main(){
    string cadena;
    while ( getline(cin, cadena)){
        cout << cadena << endl;
    }
    return 0;
}