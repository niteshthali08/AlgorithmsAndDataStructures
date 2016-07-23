//
//  main.cpp
//  largest_prime_factor
//
//  Created by Nitesh Thali on 7/13/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 The prime factors of 13195 are 5, 7, 13 and 29.
 What is the largest prime factor of the number 600851475143 ?
 
 NOTE: Any numeber can be broken down into product of its prime factors.
 
 Ref: http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
 Important Property:
 
 "Every composite number has at least one prime factor less than or equal to square root of itself.
 This property can be proved using counter statement. Let a and b be two factors of n such that a*b = n. If both are greater than √n, then a.b > √n, * √n, which contradicts the expression “a * b = n”."
 This impleies that remaining one after division till √n will be a prime number.
 */

#include <iostream>
#include <cmath>
using namespace std;

long getLargestlPrimeFactor(long n){
    long largest = 0;
    while(n%2 == 0){
        largest = 2;
        n /= 2;
    }
    for(int i=3; i<= sqrt(n); i++){
        while(n%i ==0){
            largest = i;
            n /= i;
        }
    }
    if (n > largest) // this is important, take for example 45, 34 and try.
        // > 2 becuase we have already printed for 2. This number can be either 1 or greater than 1
        largest = n;
    return largest;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    long n = 600851475143;
    cout << "Largest prime factor: " << getLargestlPrimeFactor(n) << endl;
    return 0;
}