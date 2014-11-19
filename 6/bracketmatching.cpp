#include <iostream>
#include <fstream>

using namespace std;

bool is_wellbracketed(string input){
    int leftb = 0;
    int rightb = 0;

    for(int i = 0; i<input.length(); i++){
        if(input[i] == '('){
            leftb++;
        }

        if(input[i] == ')'){
            rightb++;
        }
    }

    if(leftb == rightb){
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]){
    if((argc <= 1) || (argc > 2) ){
      cout << "USAGE: " << argv[0] << " <input file>" << endl;
      return 0;
    }


    ifstream file;
    file.open(argv[1]);

    string input;

    file >> input;

    if(is_wellbracketed(input)){
        cout << "\"" << input << "\" is well bracketed" << endl << endl;
    } else {
        cout << "\"" << input << "\" is not well bracketed" << endl << endl;
    }

    return 0;
}
