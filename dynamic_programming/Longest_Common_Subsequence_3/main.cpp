//
//  main.cpp
//  Longest_Common_Subsequence
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Question Ref: https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
 Program to calculate LCS of 3 sequences.
 Algorithm: To length of LCS of two sequences and then generate all the sequences of that length. Then one at a time and look for LCS in third sequnce.
 */

#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = (int)a.size(), n = (int)b.size(), l=(int) c.size();
    vector < vector <vector<int > > > dp (m+1, vector < vector <int> > (n+1, vector<int> (l+1)));
    int i, j, k;
        for (i=0; i<=m; i++){
            for (j=0; j<=n; j++){
                 for (j=0; j<=n; j++){
                     if (i == 0 || j == 0 || k==0)
                         dp[i][j][k] = 0;
                     else if (a[i-1] == b[j-1] == c[k-1])
                         dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                     else
                         dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-1][k]);
                 }
            }
        }
    return dp[m][n][k];
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
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
