//
//  main.cpp
//  Dynamic_Programming
//
//  Created by Nitesh Thali on 6/28/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  Question  Ref:https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
/*
 Problem Introduction
 You are given a primitive calculator that can perform the following three operations with the current number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a positive integer n, and the minimum number of operations needed to obtain the number n starting from the number 1.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using namespace std;

vector<int> optimal_sequence(int n) {
    /* Greedy approach wont give the correct solution*/
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
vector<int> min_sequence(int n) {
    /* Dynamic program solution to the problem*/
    vector<int> sequence;
    vector<int> operations(n+1); // size is important, note common mistake
    vector<int> dp(n+1);
    dp[1] = 0;
    operations[1] = 1;
    
    int steps = 0;
    for (int i=2; i<=n; i++) {
        dp[i] = INT_MAX;
        if(i%3 == 0){
             steps = 1 + dp[i/3];
            if (steps < dp[i]){
                dp[i] = steps;
                operations[i] = 3;
            }
        }
        if (i%2 == 0){
            steps = 1 + dp[i/2];
            if (steps < dp[i]){
                dp[i] = steps;
                operations[i] = 2;
            }
        }
        steps = 1 + dp[i-1];
        if (steps < dp[i]){
            dp[i] = steps;
            operations[i] = 1;
        }
    }
    
    sequence.push_back(n);
    while(n >=1){
        if (n == 1)
            break;
        if (operations[n] == 1){
            n -= 1;
        }
        else{
            
            n /= operations[n];
        }
         sequence.push_back(n);
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    //vector<int> sequence = optimal_sequence(n);
    vector<int> sequence = min_sequence(n);
    std::cout << "Minimum Steps:" << sequence.size() - 1 << std::endl << "Steps: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    
}
