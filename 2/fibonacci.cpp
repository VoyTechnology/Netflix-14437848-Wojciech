#include <iostream>
#include <string>
using namespace std;


// Fibonacci function
unsigned long long int fib_r(unsigned long long int n){
    if(n < 3){
        return 1;
    } else {
        return fib_r( n-1 ) + fib_r( n-2 );
    }
}

// Iterative
unsigned long long int fib_i(int n){
    unsigned long long int nums[n - 1];

    // Prime the nums array
    nums[0] = 1;
    nums[1] = 1;

    for(int i = 2; i < n; i++){
        nums[i] = nums[i-1] + nums[i-2];
    }

    return nums[n - 1];
}

int main(int argc, char *argv[]){
    unsigned long long int n;
    // Declare variables
    if(argc != 2){
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    } else {
        n = atoi(argv[1]);
    }

    // Print out the results
    cout << "The " << n << "th number: " << fib_i(n) << " (iterative)" << endl;
    cout << "The " << n << "th number: " << fib_r(n) << " (recursive)" << endl;

    return 0;
}
