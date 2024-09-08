#include <iostream>
using namespace std;

int main() {
    long long num1, num2;
    int sum, carry, totalCarry;
    
    
    while (cin >> num1 >> num2 && (num1 != 0 || num2 != 0)) {

        carry = 0;
        totalCarry = 0; 

        
        while (num1 > 0 || num2 > 0) {

            // Sumar el último dígito de ambos números junto con el carry
             sum = (num1 % 10) + (num2 % 10) + carry;

            if (sum > 9) {
                totalCarry++;  
                carry = 1;     
            } 
            else {
                carry = 0;  
            }

            // Remover el último dígito de ambos números
            num1 /= 10;
            num2 /= 10;
        }

        
        if (totalCarry == 0) {
            cout << "No carry operation." << endl; 
        } else if (totalCarry == 1) {
            cout << "1 carry operation." << endl;   
        } else {
            cout << totalCarry << " carry operations." << endl; 
        }
    }

    return 0;
}
