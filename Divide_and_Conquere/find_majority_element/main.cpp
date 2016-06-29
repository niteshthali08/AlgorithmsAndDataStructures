//
//  main.cpp
//  find_majority_element
//
//  Created by Nitesh Thali on 6/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/* 
    A majority element is one which appears more than n/2 times in given array.
    This can be obtained in O(n) time using voting algorithm.
    Below is a divide and conquere algo which runs in O(nlogn) time
    INPUT:
    first line - n
    aecond line - elements in array
    OUTPUT:
    1 - if maj ele is present else
    0
 */
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int count(vector<int> &a, int left, int right, int x)
{
    int c = 0;
    for (int i=left; i<=right; i++) {
        if (a[i] == x)
            c++;
    }
    return c;
}
int get_majority_element(vector<int> &a, int left, int right) {
    /*
     if size of a == 1 handle it separately.
     */
    if (left > right)
        return -1;
    else if (left == right) // one element
        return a[left];
    else{
        int mid = left + (right - left)/2;
        int l = get_majority_element(a, left, mid);
        int r = get_majority_element(a, mid+1, right);
        
        if ( l == r ) return l;
        if (l>0) // this is important, check if greater than 0, otherwise [1] will return as maj ele.
            if ( count(a, left, right, l) > (right -left + 1)/2)
                return l;
        if (r>0) // this is important, check if greater than 0, otherwise [1] will return as maj ele.
            if ( count(a, left, right, r) > (right -left+ 1)/2) /*  **** +1 is important, a= [1,2] trace*/
                return r;
        
        return -1;
    }
    
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, (int)a.size()-1) != -1) << '\n';
}
