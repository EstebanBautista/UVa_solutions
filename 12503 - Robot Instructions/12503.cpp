#include <iostream>

int test[100];

using namespace std;

int main(){
    char word[6];
    int cases, object, ans = 0, index;
    
    cin >> cases;
    while (cases--){
        cin >> object;
        ans = 0;
        for (int i = 0; i < object; i++){
            cin >> word;
            if (word[0] == 'L'){
                test[i] = -1;
                ans -= 1;
            }
            else if (word[0] == 'R'){
                test[i] = 1; 
                ans += 1;
            }
            else{
                cin.ignore(3);
                cin >> index;
                test[i] = test[index-1];
                ans += test[i];
                
            }
        }
        cout << ans << endl; 
    }

    return 0;
}