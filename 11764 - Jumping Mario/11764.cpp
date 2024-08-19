#include <iostream>

using namespace std;

int main(){
    int casos, walls, heights, caseOne, cont = 1;

    cin >> casos;
    while ( casos-- ){
        int top = 0, down = 0;

        cin >> walls;
        
        for (int i = 0; i < walls; i++){
            cin >> heights;

            if (i == 0){ caseOne = heights; }
            else if (caseOne < heights && i != 0){
                caseOne = heights;
                top++;
            }
            else if (caseOne > heights && i != 0){
                caseOne = heights;
                down++;
            }
        }
        cout << "Case " << cont << ": " << top << " " << down << endl;
        cont++;

    }
    return 0;
}