//
//  main.cpp
//  find_all_factors
//
//  Created by Nitesh Thali on 7/14/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    find all factors of a given number!
 Soln: Efficient way
    For example factors of 24 are 1,2,3,4,6,8,12,24
    Factors are paired. 1 and 24, 2 and 12, 3 and 8, 4 and 6.
    
    Therefore we can iterate to the square root of given number and then calculate the paired factors. Most importantly will have to iterate till i < sqrt(n) and till i <= sqrt(n) because if its a perfect square will count it twice.
 
    Also remember important property:
    "Every composite number has at least one prime factor less than or equal to square root of itself."
 */

#include <iostream>
#include <cmath>
using namespace std;

int findFactors(int n){
    int factors = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0)
            factors += 2; // count the pairs since iterating till sqrt(n)
    }
    if (sqrt(n) * sqrt(n) == n)
        factors++; // count once
    return factors;
}
int main(int argc, const char * argv[]) {
    int n = 24;
    cout << "Number of factors of " << n << ": "<< findFactors(n) << endl;
    return 0;
}
