//
//  main.cpp
//  multiple_3_and_5
//
//  Created by Nitesh Thali on 7/13/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below 1000.
 
 */

#include <iostream>

using namespace std;

long getSumBruteForce(int n){
    long sum = 0;
    for (int i=3; i<=n; i++){
        if (i%3 == 0 || i%5 == 0)
            sum+= i;
    }
    
    return sum;
    
}


long getSumClever(int n){
    long sum = 0;
    
    int count = n/3;
    sum += 3 * (count * (count + 1)/2);
    
    count = n/5;
    sum += 5*(count * (count + 1)/2);
    
    count = n/15;
    sum -= 15*(count * (count + 1)/2);
    
    return sum;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 1000;
    long sum = getSumBruteForce(n);
    cout << "Brute Force sum: " << getSumBruteForce(n) << endl;
    sum  = getSumClever(n);
    cout << "Optimized sum: " << getSumClever(n) <<endl;
    return 0;
}
