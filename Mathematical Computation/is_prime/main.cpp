//
//  main.cpp
//  is_prime
//
//  Created by Nitesh Thali on 7/14/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n == 0 || n == 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
            return false;
    
    for (int i = 3; i<= sqrt(n); i += 2) { // note property sqrt, sqrt(n) * sqrt(n) cannot be greater than n, contradiction. -> so one has to be less than sqrt(n)
            if (n % i == 0)
                return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 101;
    cout << "Is prime, " << n << "?: "<< isPrime(n) << endl;
    return 0;
}
