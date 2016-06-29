//
//  main.cpp
//  Knapsack_Without_Repetition
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Standard Knapsack Problem: Goal is to carry items which provides maximum weight as the output. Items can be only taken in full and without repetition.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int optimal_weight(int W, const vector<int> &w) {
    /* WITHUOT REPETITION: will use 2-D matrix to store intermediate optimal values */
    vector < vector<int> > dp(w.size()+1, vector<int> (W+1));
    for(int i=0; i <= W; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i <= w.size(); i++){
        dp[i][0] = 0;
    }
    for (int i =0; i<w.size(); i++){
        for(int capacity = 1; capacity<= W; capacity++){
            if (capacity >= w[i]){
                dp[i+1][capacity] = max(dp[i][capacity], w[i] + dp[i][capacity - w[i]]);
            }
            else // this is important, we just copy value from top row.
                dp[i+1][capacity] = dp[i][capacity];
        
        }
    }
//    for (int i=0; i<=w.size(); i++) {
//        for (int j=0; j<=W; j++) {
//            cout << dp[i][j];
//        }
//        cout <<endl;
//    }
    return dp[w.size()][W];
}
int main() {
   int n, W;
   std::cin >> W >> n;
   vector<int> w(n);
   for (int i = 0; i < n; i++) {
       std::cin >> w[i];
   }
    std::cout << "Optimal Weight: " << optimal_weight(W, w) << '\n';
}
/*
 Sample Input Output
 10 3
 1 4 8
 Optimal Weight: 9
 */
