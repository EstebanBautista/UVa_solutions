#include <iostream>
using namespace std;

int main() {
    int casos, premios, cont = 0; 
    bool flag = true;

    while ( flag == true) {
        int ans = 0;
        cont++;
        cin >> casos;

        if (casos == 0) {
            flag = false;
        } else {
            for (int i = 0; i < casos; i++) {
                cin >> premios;

                if (premios != 0) {
                    ans++;
                } else {
                    ans--;
                }
            }

            cout << "Case " << cont << ": " << ans << endl;
        }
    }
    return 0;
}
