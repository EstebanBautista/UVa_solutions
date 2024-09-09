#include <iostream>

using namespace std;

int main(){
    int casos, a, b, total;
    cin >> casos;

    for (int j = 1; j <= casos; j++){
        cin >> a;
        cin >> b;
        total = 0;

        if (a % 2 != 0){
            total += a;
        }
        else{
            a +=1;
            total += a;
        }

        for ( int i = a+2; i <= b; i+=2 ){
            total += i;
        }
        cout << "Case " << j << ": " << total << endl;
    }

    return 0;
}