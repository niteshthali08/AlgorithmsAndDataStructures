//
//  main.cpp
//  check_relative_prime
//
//  Created by Nitesh Thali on 7/15/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to check if two numbers are relatively prime. (Relative primes are those which does not have common divisors)
    Solution: We can do this quickly by using Euclid's algorithm to find GCD of two numbers. If GCD==1 then numbers are relatively prime.
 */

#include <iostream>
using namespace std;
int findGCDIterative(int a, int b){
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int findGCD(int a, int b) {
    if (b == 0)
        return a;
    
    return findGCD(b, a % b);
}

bool isRealtivelyPrime(int a, int b){
    return findGCD(a,b) == 1 ? true : false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 3, b=8;
    cout << "Relatively Prime ?: " << isRealtivelyPrime(a, b) << endl;
    return 0;
}
