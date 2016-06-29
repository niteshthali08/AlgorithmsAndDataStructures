//
//  main.cpp
//  Edit_Distance_Between_Two_Strings
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Calculating Edit Distance
    Operations: 1 Delete from string1
                2 Substitution
                3 Insert into string2
 
                if chars match
                    copy diagonal value
                else
                    1 + min(top, left, diagonal)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int m = (int)str1.size(), n= (int) str2.size();
    vector < vector <int> > dp(m+1, vector <int> (n+1));
    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    for(int i=0; i<=n; i++)
        dp[0][i] = i;
    
    for(int row = 1; row <=m; row++){
        for(int col=1; col<=n; col++){
            if(str1[row-1] == str2[col-1]){
                dp[row][col] = dp [row-1][col-1];
            }else{
                dp[row][col] = 1 + min(dp[row][col-1], dp[row-1][col]);
                dp[row][col] = min(dp[row][col], 1 + dp[row-1][col-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    cout << "Enter two space separated strings: ";
    cin >> str1 >> str2;
    cout <<"Edit Distance: "<< edit_distance(str1, str2) << std::endl;
    return 0;
}
/*
    Sample Input Output:
    Enter two space separated strings: editing
    distance
    Edit Distance: 5
 */