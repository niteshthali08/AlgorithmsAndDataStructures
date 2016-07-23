//
//  main.cpp
//  Height_Binary_TREE_given_parent_array
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Ref: http://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/
 
 
    We can recursively calculate height of each of the node using parent array representation. We can additional array depth represeinting depth of each node and return the max from this array. We knoe depth[root] = 1; Hence we can return this value and calculate height of the each of the node. This is like a Dynamic Programming question.
 
 */

#include <iostream>
using namespace std;
int calculateDepthHelper(int parent[], int depth[], int index){
    if (parent[index] == -1)
       return 1;
    if (depth[index] != -1)
       return depth[index];

    depth[index] = 1 + calculateDepthHelper(parent, depth, parent[index]);
    return depth[index];
}

int calculateDepth(int parent[], int len){
    int depth[len];
    for (int i=0; i<len; i++) {
        depth[i] = -1;
    }
    int height = INT_MIN;
    for(int i=0; i<len; i++){
        if(depth[i] == -1)
             depth[i] = calculateDepthHelper(parent, depth, i);
        if (depth[i] > height)
            height = depth[i];
    }
    return height;
}
int main(int argc, const char * argv[]) {
    //int  parent[] = {1, 5, 5, 2, 2, -1, 3};
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
    int len = sizeof(parent)/sizeof(int);
    cout << "Height of the given tree: " << calculateDepth(parent, len) << endl;
    
}
