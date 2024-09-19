// C++ Program to Check if a Number is Prime using Brute
// Force Method
#include <iostream>
using namespace std;

bool isPrime(int n) {
  
    // If the number is less than or equal to 1, it is not
    // prime
    if (n <= 1) {
        return false;
    }

    // Check for divisors from 2 to n-1
    for (int i = 2; i < n; i++) {
      
        // If n is divisible by any number in this range, it
        // is not prime
        if (n % i == 0) {
            return false;
        }
    }

    // If no divisors are found, it is prime
    return true;
}

int main() {
    int n = 10;

    if (isPrime(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}


//Optimized approach

                                
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function to check if a
// given number is prime.
bool checkPrime(int n){ 

    // Initialize a counter variable to
    // count the number of factors.
    int cnt = 0;

    // Loop through numbers from 1
    // to the square root of n.
    for(int i = 1; i <= sqrt(n); i++){ 

        // If n is divisible by i
        // without any remainder.
        if(n % i == 0){ 

            // Increment the counter.
            cnt = cnt + 1;

            // If n is not a perfect square,
            // count its reciprocal factor.
            if(n / i != i){
                cnt = cnt + 1;
            }
        }
    }

    // If the number of
    // factors is exactly 2.
    if(cnt == 2){
         // Return true, indicating
         // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else{ 
        // Return false, indicating
        // that the number is not prime.
        return false; 
    }
}


int main() {
    int n = 1483;
    bool isPrime = checkPrime(n);
    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
                                
                            
