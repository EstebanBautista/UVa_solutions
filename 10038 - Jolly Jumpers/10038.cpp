#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int lenght, valor, nums[3001];

    while (cin >>lenght){
        for (int val  = 0; val < lenght; val++){
			cin >> valor;
			nums[val] = valor;
		}
		int intervalo[3001] = {0};
		bool flag = false;
		for ( int fei = 1; fei < lenght; fei++){
			if ( labs ( nums[fei] - nums[fei-1]) < lenght ){
				intervalo[labs(nums[fei] - nums[fei-1])]++;
			}
		}
		for (int jo = 1; jo < lenght; jo++){
			if (intervalo[jo] == 0){flag = true;} 
		}
		if ( flag == false) {cout << "Jolly" << endl;}
		else { cout << "Not jolly" << endl; }
    }
    return 0;
}


