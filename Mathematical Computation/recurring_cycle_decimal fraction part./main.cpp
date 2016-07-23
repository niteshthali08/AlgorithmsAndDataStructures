//
//  main.cpp
//  recurring_cycle_decimal fraction part.
//
//  Created by Nitesh Thali on 7/14/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 
 1/2	= 	0.5
 1/3	= 	0.(3)
 1/4	= 	0.25
 1/5	= 	0.2
 1/6	= 	0.1(6)
 1/7	= 	0.(142857)
 1/8	= 	0.125
 1/9	= 	0.(1)
 1/10	= 	0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 
 
 Solution: 
    THe idea is to keep multiplying numerator with 10 and taking modulo with given number in a loop and recording numerator in a map with the length of a sequence senn so far. If the same numerator is seen in future it means that means fraction part is repeating from current position. Length of the repeating sequence will be equal to the difference between current length and time when that numerator was seen for the first time.
 
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int findCycleLength(int n){
    int numerator = 1;
    int len = 0;
    unordered_map<int, int> mp;
    // first insertion into the map tells that current numerator is seen when sequence len=0
    while(mp.find(numerator) == mp.end()){
        mp[numerator] = len;
        numerator = numerator * 10 % n;
        if(numerator == 0)
            return 0;
        len++;
    }
    return len - mp[numerator]; // mp[numerator] is the start index for that repeating length.
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cout << "Denominator: ";
    cin >>n;
    cout << "Cycle Length: " << findCycleLength(n) << endl;
    return 0;
}
