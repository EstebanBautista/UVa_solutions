#include <iostream>
#include <cmath>

using namespace std;



int main(){
    int casos;
    cin >> casos;
    while ( casos-- ){
        long long warriors, rows;
        cin >> warriors;
        rows = (-1+sqrt(8*warriors+1))/2;
        cout << rows << endl;
            
    }
    return 0;
}