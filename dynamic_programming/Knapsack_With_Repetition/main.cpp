//
//  main.cpp
//  Knapsack_Without_repetition
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
  Program to obtain maximum weight which can be carried given capacity W. The items can be only taken in full and can be repeated.
 */

#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
    
    vector <int> dp(W +1);
    dp[0] = 0;
    for(int capacity = 1; capacity <= W; capacity++){
        dp[capacity] = 0;
        int max_weight = 0;
        for (size_t item =0; item < w.size(); item++) {
            if(capacity >= w[item]){
                max_weight = w[item] + dp[capacity - w[item]];
                if (max_weight > dp[capacity]){
                    dp[capacity] = max_weight;
                }
            }
        }
    }
    return dp[W];
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
