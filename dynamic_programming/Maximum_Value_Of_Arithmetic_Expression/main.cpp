//
//  main.cpp
//  Maximum_Value_Of_Arithmetic_Expression
//
//  Created by Nitesh Thali on 6/29/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Question Ref: https://www.coursera.org/learn/algorithmic-toolbox/home/welcome
    Maximize the Value of an Arithmetic Expression
    Given arithmetic expression containing of digits (0-9) and operations (+, -, *) implemnt an algorithm such that applying this operations in any order resuilts in the maximum resultant value for the expression. Example
        input: 1 + 5
        output: 6
        input: 5-8+7*4-8+9
        output: 200
    In other words we have to fina a way to parenthesize this expression to obtain maximum value.
    We will use dynamic programming to find max value of expression.
 
    Algorithm:
    For each length of expression, calculate max and min value you can obtain by applying the operation.
    For example, if operation is '*', then we can obtain max product by either multiplying two min values or multiplying two max values and record the maximum.
    Time Complexity : O(n^3)
 */
#include <iostream>
#include<string>
#include <vector>

using namespace std;
pair<int, int> apply(char op, pair<int, int>op1, pair<int, int>op2){
    if (op == '+'){
        return make_pair(op1.first + op2.first, op1.second + op2.second);
        
    }else if (op == '-'){
        return make_pair(op1.first - op2.second, op1.second - op2.first);
    }
    else{
        int mx = max((op1.first * op2.first), (op1.second * op2.second));
        int mn = min((op1.first * op2.second), (op1.second * op2.first));
        return make_pair(mx, mn);
    }
}
int obtain_max_value(vector<char> &operations, vector<int> &operands){
    int n = (int) operands.size();
    vector <vector <pair <int, int> > > dp (n, vector<pair<int, int> > (n));
    for(int i=0; i<n; i++){
        dp[i][i] = pair<int, int>(operands[i], operands[i]);
    }
    
    for(int len =2; len <= n; len++){
        for(int i=0; i<= n-len; i++){
            int j = i+len-1; // right point of the length;
            dp[i][j] = make_pair(INT_MIN, INT_MAX);
            // apply operation on all intermediate length results and find global minimum and maximum.
            for(int k=i; k< j; k++){
                pair<int, int> max_pair = apply(operations[k], dp[i][k], dp[k+1][j]);
                if (max_pair.first > dp[i][j].first){
                    dp[i][j].first = max_pair.first;
                }
                if (max_pair.second < dp[i][j].second){ // this is important. (find max, min amongst all operations)
                    dp[i][j].second = max_pair.second;
                }
            }
        }
    }
    /* for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j].first<<","<<dp[i][j].second << " ";
        }
        cout << endl;
    } */
    return dp[0][n-1].first;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Enter Expression: ";
    string expr;
    getline(cin, expr);
    vector<int> operands;
    vector <char> operations;
    for(int i=0; i< expr.size(); i++){
        if (i%2){
            operations.push_back(expr[i]);
        }else{
            operands.push_back(expr[i] - 48);
        }
    }
    int m = obtain_max_value(operations, operands);
    cout << "Max value: " <<m <<endl;
    return 0;
}
/*
 Sample Input Output:
 Enter Expression: 5-8+7*4-8+9
 Max value: 200
 Explanation:
 200 = (5 - ((8 + 7)  (4 - (8 + 9))))
 */