#include <iostream>

using namespace std;

void invertir(unsigned long long int numero) {
    unsigned long long int inve = 0, n = numero;
    bool flag = true;

    if (numero <= 4){
        inve =  numero * 2;
        cout << "1" << " " << inve << endl;
    }
    else{
        for (int i = 1; i > 0 && flag == true; i++ ){
            n = numero;
            inve = 0; 
            while (numero != 0) {
                inve = inve * 10 + numero % 10;
                numero=numero/10;
            }
            
            if (inve == n && i != 1){
                flag = false;
                cout << i-1 << " " << inve << endl;
            }
            else{
                inve += n;
                numero = inve;
            }
        }
        
    }

}

int main(){
    unsigned long long int casos, numero;

    scanf("%d", &casos);

    while (casos--){
        cin >> numero;
        invertir(numero);
        
    }
    return 0;
}