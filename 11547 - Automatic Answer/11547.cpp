#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int casos, n, p;
    cin >> casos;
    while (casos--){
        cin >> n;
        p = (((((n*567)/9)+7492)*235)/47)-498;
        p = abs(p % 100);
        
        cout << p / 10 <<endl;
    }
    return 0;
}