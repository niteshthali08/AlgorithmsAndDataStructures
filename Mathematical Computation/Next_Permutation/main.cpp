//
//  main.cpp
//  Next_Permutation
//
//  Created by Nitesh Thali on 7/14/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 We can either do this recursively or using clever technique of finding next permutation in place without any extra memory.
    Steps:
    1. find first i, a[i] < a[i+1] from right end of the array.
    2. a[i+1] to a[end] will be a non decreasing sequence.
    3. find smallest number greater than a[i] and swap it.
    4. reverse a[i+1] to a[end]
 
 */

#include <iostream>
using namespace std;
bool findNextPermutation(int a[], int len){
    int i = len-2;
    while(i>=0 && a[i] >= a[i+1]){ // finding location where a[i] < a[i+1]
        i--;
    }
    if (i == -1)
        return false;
    // swap with first smallest element from the a[i+1] till a[len-1]
    for(int j=len-1; j >= i+1; j--){
        if(a[j] > a[i]){ //swap
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            break;
         }
    }
    // reverse all elements from i+1 till len-1
    int end = len-1;
    int start = i+1;
    while(start < end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
    return true;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //int nums[] = {0,1,2,2};
    int nums[] = {0,1,2};
    int len = sizeof(nums)/sizeof(int);
    for (int i=0; i<len; i++) {
        cout << nums[i];
    }
    cout <<endl;
    
    while(findNextPermutation(nums, len)){
        for (int i=0; i<len; i++) {
            cout << nums[i];
        }
        cout <<endl;
    }
    
}