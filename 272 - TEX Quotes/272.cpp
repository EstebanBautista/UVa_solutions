#include <iostream>
#include <string>

using namespace std;


int main(){
    string line, word;
    bool hay = true;

    while ( getline(cin, line) ){
        word = "";
        for (int i = 0; i < line.length(); i++){
            
            if (line[i] == '"' && hay == true){

                word += "``";
                hay = false;
            }
            else if( line[i] == '"' && hay == false ){

                word += "''";
                hay = true;
            }
            else{
                word += line[i];
            }
        }

        cout << word << endl;
    }

    return 0;
}