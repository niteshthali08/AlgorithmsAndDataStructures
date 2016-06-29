//
//  main.cpp
//  NUmber_of_Inversions
//
//  Created by Nitesh Thali on 6/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    PROGRAM to count the number of inversions in an array.
    INPUT: n, followed by n integers.
    OUTPUT: Number of inversions in an array.
 */

#include <iostream>
#include <vector>

using std::vector;
// pass another temporary array assisting in copying the elements.
int count_inversions(vector<int> &a,vector<int> &temp,int left, int mid, int right){
    
    int  i= left;
    int j = mid+1;
    int k = left;
    int inversions = 0;
    while((i <= mid) && (j <= right)){
        if ( a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            inversions += mid-i + 1; // this is important, number of elements left to be copied from first half.
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    
    while (j <= right)
        temp[k++] = a[j++];
     //overwrite original array with sorted part.
    
    for (i=left; i <= right; i++)
        a[i] = temp[i];
    
    return inversions;
}
int get_number_of_inversions(vector<int> &a,vector<int> &temp, int left, int right) {
    int inversions = 0;
    if (left ==right)
        return inversions;
    int mid = left + (right - left) / 2;
    inversions += get_number_of_inversions(a, temp, left, mid); // both sides mid should be included
    inversions += get_number_of_inversions(a, temp, mid+1, right);
    
    inversions += count_inversions(a, temp, left, mid, right);
    return inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> temp(a.size());
    std::cout << get_number_of_inversions(a, temp, 0, a.size()-1) << '\n';
}
