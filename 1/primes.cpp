/*
    Primes
    Write a program to compute all the prime numbers less than given integer N.
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
using namespace std;

//Check is the number a prime
bool is_prime(int number){
    // Do a loop to check each number from 2 up to (excluding) end value
    for(int c = 2; c <= sqrt(number); c++){

        // Check is the number dividable. If it is, return false
        if(number % c == 0){
            return false;
        }
    }
    // If the number was not divided, return true, its a prime
    return true;
}

// Main function
int main(int argc, char *argv[]){
    // The end value. If 0 quit the program
    unsigned long long int n = 1;

    if( argc != 2 ){
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    } else {
        n = atoi( argv[1] );
    }

    ofstream file;
    file.open("output.txt");

    cout << "All primes generated can be found in output.txt" << endl;

    unsigned int counter = 0;

    cout << "Number of primes from 1 to " << n << ": " << endl;

    // Run the script to get the primes and output each number
    for(unsigned long long int i = 1; i < n; i++ ){
        if( is_prime(i) ){
            counter++;
            file << i << " ";
        }
    }

    cout << counter << endl;

    file.close();
    return 0;
}
