#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string inputFile, outputFile;
    if(argc != 3){
        cout << "Usage: " << argv[0] << " <input> <output>" << endl;
        return 1;
    } else {
        inputFile = argv[1];
        outputFile = argv[2];
    }

	// Storage for array
    vector <int> v;

    ifstream input_file;
    input_file.open(inputFile);

    ofstream output_file;
    output_file.open(outputFile);

    int input;

    while(input_file >> input){
		v.push_back(input);
    }

    // Convert vector into an array
    int a[v.size()];
    std::copy(v.begin(), v.end(), a);

    for(unsigned int i = 1; i < v.size(); i++){
        int t1, t2;

		while( a[i-1] < a[i]){
			t1 = a[i - 1];
			t2 = a[i];

			a[i - 1] = t2;
			a[i] = t1;
			i--;
		}
    }

	for(int i = (v.size() - 1); i > 0; i--){
		output_file << a[i] << " ";
	}

	input_file.close();
	output_file.close();

    return 0;
}
