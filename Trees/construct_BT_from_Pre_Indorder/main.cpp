//
//  main.cpp
//  construct_BT_from_Post_Inorder
//
//  Created by Nitesh Thali on 6/2/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.

/*  Construct a Binary Tree from Preorder and Inorder, using root from preorder get the size of leftsub tree and right subtree from inorder. THis will help to get proper indices into the preorder */

#include <iostream>
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
int get_root_index(int in[], int rt_value, int start, int end)
{
    int i;
    for (i=start; i<=end; i++) {
        if(in[i] == rt_value)
            break;
    }
    return i;
}
Node* constructBT(int in[], int inlow, int inhigh, int pre[], int plow, int phigh)
{
    if(inlow > inhigh || plow > phigh)
        return NULL;
    Node* root = getNode(pre[plow]);
    int index = get_root_index(in, pre[plow], inlow, inhigh);
    //int left_subtree_size = index - inlow;
    int right_subtree_size = inhigh - index;
    
    // Note continuous division between indices (left->right. )
    root->left = constructBT(in, inlow, index-1, pre, plow+1, phigh-right_subtree_size);
    root->right = constructBT(in, index+1, inhigh, pre, phigh-right_subtree_size+1, phigh);
    
    return root;
}
Node* buildTree(int in[], int pre[], int n)
{
    return constructBT(in, 0, n-1, pre, 0, n-1);
}
int main(int argc, const char * argv[])
{
//    int in[] = {4,2,5,1,6,3,7};
//    int pre[] = {1,2,4,5,3,6,7};
    /* Wors case example*/
//    int in[] = { 1,2,3,4,5};
//    int pre [] = {1,2,3,4,5};
    int in [] = {};
    int pre[] = {};
    int n = sizeof(in)/sizeof(int);
    Node* root = buildTree(in, pre, n);
    inorder(root);
    return 0;
}

/*
 The worst case complexity :  O(n^2), this will happen when tree is skewed.
 */
