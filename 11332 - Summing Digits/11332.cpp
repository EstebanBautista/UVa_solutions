#include <iostream>
#include <string>

using namespace std;

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    string caso;
    while (getline(cin, caso) && caso != "0") {
        int num = stoi(caso);
        while (num >= 10) {
            num = sumDigits(num);
        }
        cout << num << endl;
    }
    return 0;
}
