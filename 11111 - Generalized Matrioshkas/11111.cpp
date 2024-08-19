#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
    string numeritos;
    while (getline(cin, numeritos)){

        istringstream caso(numeritos);
        stack<int> matrioshka, capacidad;
        bool siSoy = true, creado = false;
        int num;
        while (caso >> num && siSoy){

          if ( num < 0){
	    creado = true;
            num = labs(num);
            matrioshka.push(num);
            
            if ( !capacidad.empty() && capacidad.top() <= num){
                siSoy = false;
            }
            else if (!capacidad.empty() && capacidad.top() > num) {
                capacidad.top() -= num;   
            }
            capacidad.push(num);
          }
          else{
            if(!matrioshka.empty() && matrioshka.top() - num == 0){
                capacidad.pop();
                matrioshka.pop();
            }
            else if (!matrioshka.empty() && matrioshka.top() - num != 0){
                siSoy = false;
            }
          }
        }
        if (!matrioshka.empty() || !capacidad.empty()) {
            siSoy = false;
        }
	if (creado == false){
		siSoy = false;
	}
        if ( siSoy == true){
            cout << ":-) Matrioshka!" << endl;
        }
        else{
            cout << ":-( Try again." << endl;
        }
    }
    return 0;
}