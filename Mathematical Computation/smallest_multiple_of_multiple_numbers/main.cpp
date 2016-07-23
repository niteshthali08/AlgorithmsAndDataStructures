//
//  main.cpp
//  smallest_multiple_of_multiple_numbers
//
//  Created by Nitesh Thali on 7/13/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 
 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 
 */

#include <iostream>
using namespace std;
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    
    return findGCD(b, a % b);
}

int findLCM(int a, int b){
    int gcd = findGCD(a, b);
    return (a*b)/gcd;
}

int findSmallestMultiple (int n){
    int lcm = 1;
    for(int i=2; i<n; i++){
        lcm = findLCM(lcm, i);
    }
    return lcm;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n =10; // find smallest multiple from 1 to n.
    cout << "Smallest Multiple: " << findSmallestMultiple(n) << endl;
}
