//
//  main.cpp
//  3-way_Quick_sort
//
//  Created by Nitesh Thali on 6/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    3-way partition helps to speed up the sorting when array contains duplicate elements
    Partition is such a way that <x | =x | >x
    randomized_quick_sort2, partition2 -> Normal quick sort with randomization.
    randomized_quick_sort3, partition3 -> partition to speed up sorting when array contains duplicate elements.
 */

#include <iostream>
#include <vector>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort2(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);
    
    randomized_quick_sort2(a, l, m - 1);
    randomized_quick_sort2(a, m + 1, r);
}
void partition3(vector<int> &a, int l, int r, int &m1, int &m2) {
    int x = a[l];
    int j = l;
    m1 = -99;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    m2 = j;
    int k = m2-1;
    for(int i=k-1; i>=0; i--) // finding m2, sifting all elements equal to x near x. Left most partition.
    {
        if (a[i] == x){
            swap(a[i], a[k]);
            k--;
        }
    }
    
        m1  = k+1;
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    int m1, m2;
    swap(a[l], a[k]);
    partition3(a, l, r, m1, m2);
    
    randomized_quick_sort3(a, l, m1 - 1);
    randomized_quick_sort3(a, m2 + 1, r);
}
int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort3(a, 0, (int)a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}

