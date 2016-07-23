//
//  main.cpp
//  construct_BT_from_parent_array_representation
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
    Output: root of below tree
              5
            /  \
           1    2
          /    / \
         0    3   4
        /
        6
    Solution: Idea is to do reverse mapping by using extra space. Time Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
}
void construct(Node* root, unordered_map<int, vector<int> > &mp, int p){
    
    if(mp.find(p) == mp.end())
       return;
    if(mp[p].size() == 1)
        root->left = getNode(mp[p][0]);
    if(mp[p].size() == 2){
        root->left = getNode(mp[p][0]);
        root->right = getNode(mp[p][1]);
    }
    if(root->left)
        construct(root->left, mp, root->left->data);
    if(root->right)
        construct(root->right, mp, root->right->data);
}

Node* constructTree(int parent[], int len){
    unordered_map <int , vector<int> > rev_map;
    for(int i=0; i< len; i++){
        rev_map[parent[i]].push_back(i);
    }
    Node* root = getNode(rev_map[-1][0]);
    construct(root, rev_map, root->data);
    return root;
}
int main(int argc, const char * argv[]) {
    //int parent[] = {1, 5, 5, 2, 2, -1, 3};
    // output: 0 1 5 6 3 2 4
    int parent [] = {-1, 0, 0, 1, 1, 3, 5};
    // output: 6 5 3 1 4 0 2
    int len = sizeof(parent)/sizeof(int);
    
    Node* root = constructTree(parent, len);
    cout << "Inorder traversal for tree constructed from parent array representaion is:" <<endl;
    inorder(root);
    cout << endl;
    
    return 0;
}