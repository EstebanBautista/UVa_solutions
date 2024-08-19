#include <iostream>

using namespace std;

int main (){
    int casos, rows, columns;
    cin >> casos;
    while ( casos-- ){
        cin >> rows >> columns;
        cout << (rows/3)*(columns/3) << endl;
    }
    return 0;
}