#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

string lower(string word){
	string buffer;
	char l;

	for(int i = 0; i<word.size(); i++){
		l = tolower(word[i]);
		if( l >= 'a' && l <= 'z'){
			buffer += l;
		}
	}

	return buffer;
}

int main(int argc, char *argv[]){

	string corpus_path;

	if( (argc <=1 ) || (argc > 2) ){
		corpus_path = "corpus.txt";
	} else {
		corpus_path = argv[1];
	}

	// Storage for the words and their count
	map < string, int > words;
	map < string, int >::iterator it;

	// Load the sample that makes the count
	ifstream file;
	file.open(corpus_path);

	// Current word;
	string word;

	// Load the sample input 1 at a time
	while(file >> word){
		// Put the word to lower case
		word = lower(word);

		// If the word is found, add one, else insert the word
		if(words.count(word)){
			words.find(word)->second++;
		} else {
			words.insert({word, 1 });
		}
	}

	file.close();

	// Total numbers of words;
	int sum = 0;

	// Calculate the total
	for(auto x: words){
		sum += x.second;
	}

	// Ask user to enter his sentence:
	string input_raw, input;
	double probability = 1.0;
	cout << "Please enter your sentence:\n";

	getline(cin, input_raw);

	stringstream full_input(input_raw);



	// Do a loop and get the user input
	while(full_input >> input){
		input = lower(input);

		if(words.count(input) != 0 ){
			probability *= (double)words.find(input)->second/(double)sum;
		} else {
			probability *= (double)1/(double)sum;
		}
	}

	cout << "\nProbability: ";
	cout << setprecision(10) << probability << endl;

	return 0;

}
