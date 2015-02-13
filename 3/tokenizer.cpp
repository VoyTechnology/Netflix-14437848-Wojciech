#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    string fileName;

    if(argc != 2){
        cout << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    } else {
        fileName = argv[1];
    }

    ifstream file;
    file.open(fileName);

    int _max = pow(2, 16);

    string word_store[_max];
    int number_store[_max];

    string rawInput;

    while(file >> rawInput){

        string buffer;

        for(int i = 0; i < rawInput.length(); i++){
            if(rawInput[i] != '.' && rawInput[i] != ',' && rawInput[i] != '-'){
                buffer += tolower( rawInput[i] );
            }
        }

        string input = buffer;

        for(int i = 0; i<_max; i++){
            if(word_store[i] == input){
                number_store[i]++;
                break;
            } else if( word_store[i] == ""){
                word_store[i] = input;
                number_store[i]++;
                break;
            }
        }
    }



    for(int i = 0; i< _max; i++){
        if(word_store[i] != ""){
            cout << word_store[i] << "\t" << number_store[i] << endl;
        }
    }

	file.close();
    return 0;
}
