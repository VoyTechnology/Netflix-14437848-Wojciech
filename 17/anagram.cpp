#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

string sorted(string word){
	sort(word.begin(), word.end() );
	return word;
}

int main(int argc, char *argv[]){
	map < string, string > words;

	if( argc != 2 && argc != 3){
        cout << "Usage: " << argv[0] << " <dictionary file> [word]" << endl;
        return 0;
	}

    ifstream file;
    file.open( argv[1] );

	string word;
    while(file >> word){
		words.insert( { word, sorted(word) } );
    }

    string input;

    if(argc == 3){
        input = argv[2];
    } else {
        cout << "Please enter your word: ";
        cin >> input;
    }

	for(auto x: words){

		if(x.second == sorted(input)){
			cout << "\t" << x.first << endl;
		}
	}

	return 0;
}
