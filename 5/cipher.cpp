#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

string cipher_key(string file){

	// Define the storage map
	vector< pair<char, int > > freq;

	freq.push_back( make_pair('a', 0) );
	freq.push_back( make_pair('b', 0) );
	freq.push_back( make_pair('c', 0) );
	freq.push_back( make_pair('d', 0) );
	freq.push_back( make_pair('e', 0) );
	freq.push_back( make_pair('f', 0) );
	freq.push_back( make_pair('g', 0) );
	freq.push_back( make_pair('h', 0) );
	freq.push_back( make_pair('i', 0) );
	freq.push_back( make_pair('j', 0) );
	freq.push_back( make_pair('k', 0) );
	freq.push_back( make_pair('l', 0) );
	freq.push_back( make_pair('m', 0) );
	freq.push_back( make_pair('n', 0) );
	freq.push_back( make_pair('o', 0) );
	freq.push_back( make_pair('p', 0) );
	freq.push_back( make_pair('q', 0) );
	freq.push_back( make_pair('r', 0) );
	freq.push_back( make_pair('s', 0) );
	freq.push_back( make_pair('t', 0) );
	freq.push_back( make_pair('u', 0) );
	freq.push_back( make_pair('v', 0) );
	freq.push_back( make_pair('w', 0) );
	freq.push_back( make_pair('x', 0) );
	freq.push_back( make_pair('y', 0) );
	freq.push_back( make_pair('z', 0) );

	char n;

	for(long i = 0; i < file.length(); i++){
		n = tolower(file[i]);
		if( n >= 'a' && n <= 'z' ){

			for( unsigned int k=0; k < freq.size(); k++){
                if(freq[k].first == n){
					freq[k].second++;
                }
			}

		}
	}

	sort(freq.begin(), freq.end(),  [](const pair<char, int>& lhs, const pair<char, int>& rhs) {
             return lhs.second > rhs.second; } );

	string output;

	for( unsigned int i = 0; i < freq.size(); i++){
		output += freq[i].first;
	}

	cout << "Using cipher key: " << output << endl;

	return output;


}

string cipher_generator( string c, string input){
	string a = "abcdefghijklmnopqrstuvwxyz";

	string buffer;

	char n;

	for(long i = 0; i < input.length(); i++){

		n = tolower(input[i]);

		if( n >= 'a' && n <= 'z' ){
			for(int k=0; k<26; k++){
				if(n == a[k]){
					buffer += c[k];
					break;
				}
			}
		} else {
			buffer += input[i];
		}
	}

	return buffer;
}

string cipher_decoder( string c, string input){
	string a = "abcdefghijklmnopqrstuvwxyz";

	string buffer;

	char n;

	for(long i = 0; i < input.length(); i++){

		n = tolower(input[i]);

		if( n >= 'a' && n <= 'z' ){
			for(int k=0; k<26; k++){
				if(n == c[k]){
					buffer += a[k];
					break;
				}
			}
		} else {
			buffer += input[i];
		}
	}

	return buffer;
}

int main(int argc, char *argv[]){
    string sampleFile, inputFile, outputFile;

    if(argc != 4){
        cout << "Usage: " << argv[0] << " <sample> <input> <output>" << endl;
        return 1;
    } else {
        sampleFile = argv[1];
        inputFile = argv[2];
        outputFile = argv[3];
    }

	// Load the book to use as cipher key
	ifstream sample_raw;
	sample_raw.open(sampleFile);
	string sample, cipher, sample_buffer;

	while(sample_raw >> sample_buffer){
		sample += sample_buffer;
	}

	// Generate the cipher based on sample
	cipher = cipher_key(sample);

	// Load the text to cipher
	ifstream input;
	input.open(inputFile);

	string input_buffer;

	//Define the file to save to
	ofstream output;
	output.open(outputFile);

	// Cipher the text, a word at a time
	while(input >> input_buffer){
		output << cipher_generator(cipher, input_buffer+" ");
	}

	//Cipher Decryption
	ifstream ciphered_raw;
	ciphered_raw.open(outputFile);
	string ciphered;
	ofstream decyphered;
	decyphered.open(decypheredFile);

	while(ciphered_raw >> ciphered){
		decyphered << cipher_decoder(cipher, ciphered+" ");
	}

	sample_raw.close();
	input.close();
	output.close();
	ciphered_raw.close();
	decyphered.close();
    return 0;
}
