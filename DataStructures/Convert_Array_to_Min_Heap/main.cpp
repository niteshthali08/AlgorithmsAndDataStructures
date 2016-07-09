//
//  main.cpp
//  Convert_Array_to_Min_Heap
//
//  Created by Nitesh Thali on 7/8/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Question: https://www.coursera.org/learn/data-structures/home/
    OUPUT: Number of swaps, followed by swaps
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;
    
    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }
    
    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }
    int left (int i)
    {
        return 2*i + 1;
    }
    int right (int i)
    {
        return 2*i + 2;
    }
    void swap(int *first, int *last)
    {
        int t = *first;
        *first = *last;
        *last = t;
    }
    void buildHeap(int index, int size){
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if( l <= size and data_[l] < data_[smallest])
            smallest = l;
        if (r <=size  and data_[r] < data_[smallest])
            smallest = r;
        if (smallest != index){
            swap(&data_[index], &data_[smallest]);
            swaps_.push_back(make_pair(index, smallest));
            buildHeap(smallest, size);
        }
    }
    void GenerateSwaps() {
        swaps_.clear();
        int size = (int)data_.size();
        // Note -1 if indexing from 0. Build heap is a recursive function.
        for (int index = size/2 - 1; index >=0; --index){
            buildHeap(index, size);
        }
    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
/*
 Sample 
 Input:
 5
 5 4 3 2 1
 Ouput:
 3
 1 4
 0 1
 1 3
 **************

 Input: 
 5
 1 2 3 4 5
 Output:
 0
 */
