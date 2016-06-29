//
//  main.cpp
//  binary_search
//
//  Created by Nitesh Thali on 6/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Input: 1st line: n =5, following elements are array elements
            2nd line m=5 (five numbers to search) followed by 5 numbers.
    5 1 5 8 12 13
    5 8 1 23 1 11
    Output: indexes 
    2 0 -1 0 -1
 
 */
#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
int bSearch(const vector<int> &a, int left, int right, int find){
    if (left > right)
        return -1;
    int mid = left + (right - left)/2;
    if (a[mid] == find) return mid;
    else if (find > a[mid])
        return bSearch(a, mid+1, right, find);
    else
         return bSearch(a, left, mid-1, find);
    
    return -1;
    
}

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size();
    return bSearch(a, left, right-1, x);
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return (int) i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
