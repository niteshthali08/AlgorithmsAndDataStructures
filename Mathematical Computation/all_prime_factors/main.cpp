//
//  main.cpp
//  all_prime_factors
//
//  Created by Nitesh Thali on 7/13/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Ref: http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
 Important Property:
 
 "Every composite number has at least one prime factor less than or equal to square root of itself.
 This property can be proved using counter statement. Let a and b be two factors of n such that a*b = n. If both are greater than √n, then a.b > √n, * √n, which contradicts the expression “a * b = n”."
 This impleies that remaining one after division till √n will be a prime number.
 */

#include <iostream>
#include <cmath>
using namespace std;

void printAllPrimeFactors(long n){
    while(n%2 == 0){
        cout << 2 << " ";
        n /= 2;
    }
    for(int i=3; i<= sqrt(n); i++){
        while(n%i ==0){
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 2) // this is important, take for example 45, 34 and try.
        // > 2 becuase we have already printed for 2. This number can be either 1 or greater than 1
        cout << n << "\n";
        
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //long n = 13195;
    long n = 600851475143;
    printAllPrimeFactors(n);
    return 0;
}
