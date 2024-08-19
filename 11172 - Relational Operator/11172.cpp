#include <iostream>

using namespace std;

int main(){
    int casos, a, b;
    cin >> casos;
    while (casos--){
        cin >> a >> b;
        if ( a < b) { cout << "<" << endl; }
        else if (a > b) { cout << ">" << endl; }
        else { cout << "=" << endl; }
    }
    return 0;
}