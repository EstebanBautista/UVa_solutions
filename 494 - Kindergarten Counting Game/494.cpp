#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[1000];
    int ans, flag, i;

    // Leer cada línea de entrada
    while (cin.getline(str, 1000)) {
        ans = 0, flag = 0;

        for (i = 0; i < strlen(str); i++) {
            if ((str[i] >= 'a' && str[i] <= 'z') || 
                (str[i] >= 'A' && str[i] <= 'Z')) {
                if (!flag) {
                    flag = 1;
                    ans++;
                }
            } else {
                flag = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
