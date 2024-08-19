#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map <string, string> m;
    m[".-"] = "A";
    m["-..."] = "B";
    m["-.-."] = "C";
    m["-.."] = "D";
    m["."] = "E";
    m["..-."] = "F";
    m["--."] = "G";
    m["...."] = "H";
    m[".."] = "I";
    m[".---"] = "J";
    m["-.-"] = "K";
    m[".-.."] = "L";
    m["--"] = "M";
    m["-."] = "N"; 
    m["---"] = "O";
    m[".--."] = "P";
    m["--.-"] = "Q";
    m[".-."] = "R";
    m["..."] = "S";
    m["-"] = "T";
    m["..-"] = "U";
    m["...-"] = "V";
    m[".--"] = "W";
    m["-..-"] = "X";
    m["-.--"] = "Y";
    m["--.."] = "Z";

    m["-----"] = "0";
    m[".----"] = "1";
    m["..---"] = "2";
    m["...--"] = "3";
    m["....-"] = "4";
    m["....."] = "5";
    m["-...."] = "6";
    m["--..."] = "7";
    m["---.."] = "8";
    m["----."] = "9";

    m[".-.-.-"] = ".";
    m["--..--"] = ",";
    m["..--.."] = "?";
    m[".----."] = "\'";
    m["-.-.--"] = "!";
    m["-..-."] = "/";
    m["-.--."] = "(";
    m["-.--.-"] = ")";
	m[".-..."] = "&";
    m["---..."] = ":";
    m["-.-.-."] = ";";
    m["-...-"] = "=";
    m[".-.-."] = "+";
    m["-....-"] = "-";
    m["..--.-"] = "_";
    m[".-..-."] = "\"";
    m[".--.-."] = "@";


    int casos, cont = 1;
    string word, create = "";

    cin >> casos;
    cin.ignore();

    while ( casos--){
        //para evitar un salto de linea doble al final
        if ( cont > 1){
            cout << endl;
        } 

        getline(cin, word);
        cout << "Message #" << cont << endl;
        create = "";
        for (int i = 0; i < word.length(); i++){
            
            if (word[i] != ' '){
                create += word[i];
            }
            else {
                cout << m[create];
                create = "";
                if ( word[i+1] == ' '){
                cout << " ";
                }
            }
        }
        cout << m[create] << endl;
        cont++;
        
    }
    return 0;
}