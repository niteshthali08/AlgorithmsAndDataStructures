//
//  main.cpp
//  Longest_Common_Subsequence
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.

#include <iostream>
#include <vector>

using namespace std;

int lcs(vector<int> &a, vector<int> &b) {
    int m = (int)a.size(), n = (int)b.size();
    vector < vector <int> > dp (m+1, vector <int> (n+1));
    int i, j;
    for (i=0; i<=m; i++){
        for (j=0; j<=n; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    return dp[m][n];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    
    std::cout << "LCS: " << lcs(a, b) << std::endl;
}
/*
 Sample Input Output:
 5
 8 3 2 1 7
 7
 8 2 1 3 8 10 7
 LCS: 4
 */
