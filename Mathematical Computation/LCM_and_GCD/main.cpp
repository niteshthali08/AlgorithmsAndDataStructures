//
//  main.cpp
//  LCM_and_GCD
//
//  Created by Nitesh Thali on 7/13/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Program to find LCM and GCD of a number
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

int findLCM(int a, int b){
    int gcd = findGCD(a, b);
    return (a*b)/gcd;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //int a = 10, b= 15;
    //int a = 4, b=12;
    //int a=13, b=37;
    int a = 9, b = 2;
    cout << "GCD Recursive: " << findGCD(a, b) << endl;
    cout << "GCD Iterative: " << findGCDIterative(a, b) << endl;
    cout << "LCM: " << findLCM(a, b) << endl;
    return 0;
}
