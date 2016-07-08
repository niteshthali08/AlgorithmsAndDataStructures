//
//  main.cpp
//  DataStructures
//
//  Created by Nitesh Thali on 6/30/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack <int> ss;
    int j=0;
    while (j < s.size())
    {
        switch(s[j])
        {
            case '(':
            case '{':
            case '[': ss.push(s[j]); break;
            case ')':
                if (!ss.empty() && ss.top() == '(' )
                    ss.pop();
                else
                    return false;
                break;
            case '}':
                if (!ss.empty() && ss.top() == '{'  )
                    ss.pop();
                else
                    return false;
                break;
            case ']':
                if (!ss.empty() && ss.top() == '[' )
                    ss.pop();
                else
                    return false;
                break;
        }
        j++;
    }
    if (ss.empty()) return true;
    return false;
}

int main(){
    string str;
    cout << "Enter a string with parenthesis: ";
    cin >>str;
    cout << "\nValid Parenthesis: " << isValid(str) << endl;
    return 0;
    
}