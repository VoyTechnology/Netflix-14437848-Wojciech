#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cctype>
#include <fstream>
#include <cmath>

#include <gmp.h>
#include <gmpxx.h>

using namespace std;

// Call GMP mpz_class as bigint
typedef mpz_class bigint;

struct KeyData {
    bigint m; // Modulus
    bigint e; // Exponent
};

// Turns a string into a bigint
bigint str2num(string m){
    string numstr = "1";

    for(unsigned long i = 0; i < m.length(); i++){
        string s = to_string( m[i] + 0 );
        s = (s.length() == 2) ? "0" + s : s;
        numstr += s;
    }

    bigint myint(numstr);
    return myint;
}

string num2str(string raw){
    string m;
    string buf;
    for(unsigned int i = 1; i < raw.length(); i++){
        buf += raw[i];
        if(i % 3 == 0){
            m += (char)stoi(buf, nullptr, 10);
            buf = "";
        }
    }
    return m;
}

// Encrypt message
bigint encrypt(bigint m, bigint e, bigint n){
    bigint encrypted;
    mpz_powm( encrypted.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t() );
    return encrypted;
}

bigint decrypt(bigint c, bigint d, bigint n){
    bigint decrypted;
    mpz_powm( decrypted.get_mpz_t(), c.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t() );
    return decrypted;
}

// Prime number generator. Use padding to create one number bigger
bigint primegen(unsigned int s){
    string num = to_string( (rand() % 9) + 1 );
    for( unsigned int i = 0; i < s-1; i++){
        num += to_string(rand() % 10);
    }

    bigint prime;
    bigint gen(num);
    mpz_nextprime(prime.get_mpz_t(), gen.get_mpz_t());

    return prime;
}

// Function taken from http://rosettacode.org/wiki/Modular_inverse#C.2B.2B as I do not fully understand the working of modular multiplicative inverse
bigint modinv(bigint a, bigint b){
	bigint b0 = b, t, q;
	bigint x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

KeyData readFile( ifstream& file){
    KeyData data;

    unsigned int c = 0;
    string line;
    string expStr, modStr;

    while(getline( file, line ) ) {
        if(c == 1){
            expStr = line;
        }
        if(c == 2){
            modStr = line;
        }
        c++;
    }
    bigint e(expStr);
    bigint m(modStr);

    data.e = e;
    data.m = m;

    return data;
}

void usageInstructions(char *argv[]){
    cout << "usage: " << argv[0] << endl;
    cout << "\t[generate [<output_file>] [key_size] ]" << endl;
    cout << "\t[encrypt <key.pub> <message|pipe> ]" << endl;
    cout << "\t[decrypt <key.pri> <message|pipe> ]" << endl;
}

int main(int argc, char *argv[]){
    srand( time( NULL ) );

    if(argc < 2){
        usageInstructions(argv);
        return 1;
    }

    if( strcmp( argv[1], "generate" ) == 0){

        string fileName = "key";
        if( argc == 3 ){
            fileName = argv[2];
        }


        ofstream privateFile;
        privateFile.open(fileName+".pri");

        ofstream publicFile;
        publicFile.open(fileName+".pub");

        int pSize = 308; // Default length of pPrime
        int qSize = 309; // Default lenght of pPrime

        if(argc == 4 ){
            float decSize = ( atoi(argv[3]) ) * log(2);
            pSize = floor(decSize/2); // Round down
            qSize = ceil(decSize/2); // Round up
        }

        bigint p = primegen(pSize); //Prime (308 digits)
        bigint q = primegen(qSize); // Prime (309 digits)
        bigint n = p*q; // modulus
        bigint t = (p - 1)*(q - 1); // totient
        bigint e = 65537; // Public Exponent
        bigint d = modinv(e, t); // Modular multiplicative inverse

        // Perform a test
        string testString = "abc123-/*XYZ +&";
        bigint numString1 = str2num(testString);
        bigint encrypted = encrypt(numString1, e, n);
        bigint numString2 = decrypt(encrypted, d, n);
        string decrString = num2str(numString2.get_str());

        if( testString == decrString ){
            cout << "RSA SelfTesting: Success" << endl;
        } else {
            cout << "RSA SelfTesting: Fail" << endl;
            privateFile.close();
            publicFile.close();
            exit(EXIT_FAILURE);
        }


        publicFile << "-----RSA PUBLIC KEY: NETFLIX 11-----" << endl;
        publicFile << e << endl;
        publicFile << n << endl;
        publicFile << "-----END RSA PUBLIC KEY-----" << endl;

        publicFile.close();
        cout << "Public key in " << fileName << ".pub" << endl;

        privateFile << "-----RSA PRIVATE KEY: NETFLIX 11-----" << endl;
        privateFile << d << endl;
        privateFile << n << endl;
        privateFile << "-----END RSA PRIVATE KEY-----" << endl;

        privateFile.close();
        cout << "Private key in " << fileName << ".pri" << endl;

        return 0;
    }

    if( strcmp( argv[1], "encrypt" ) == 0){
        string publicFileName = "key.pub";
        if( argc == 3 ){
            publicFileName = argv[2];
        }

        ifstream publicFile;
        publicFile.open(publicFileName);


        KeyData publicData = readFile( publicFile );

        publicFile.close();

        bigint e = publicData.e; // Exponent
        bigint n = publicData.m; // Modulus

        string message;

        if(argc == 4){
            string consoleMessage(argv[3]);
            message = consoleMessage;
        } else {
            cin >> message;
        }

        if(message.length() == 0){
            cout << "Error: Please Provide a Message" << endl;
            exit(EXIT_FAILURE);
        }

        cout << encrypt( str2num(message), e, n ) << endl;
        return 0;
    }

    if( strcmp(argv[1], "decrypt" ) == 0 ){
        string privateFileName = "key.pri";
        if( argc == 3 ){
            privateFileName = argv[2];
        }

        ifstream privateFile;
        privateFile.open(privateFileName);


        KeyData privateData = readFile( privateFile );

        privateFile.close();

        bigint d = privateData.e; // Exponent
        bigint n = privateData.m; // Modulus

        string encryptedIn;

        if(argc == 4){
            encryptedIn = argv[3];
        } else {
            cin >> encryptedIn;
        }

        if(encryptedIn.length() == 0){
            cout << "Error: Please Provide an encrypted Message" << endl;
            exit(EXIT_FAILURE);
        }

        bigint encrypted(encryptedIn);

        bigint decryptedNum = decrypt( encrypted, d, n );
        string decrypted = num2str(decryptedNum.get_str());

        cout << decrypted << endl;
        return 0;
    }

    usageInstructions(argv);
    return 0;
}
