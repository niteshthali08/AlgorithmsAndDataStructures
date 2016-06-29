//
//  main.cpp
//  construct_BT_from_Post_Inorder
//
//  Created by Nitesh Thali on 6/2/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*  Construct a Binary Tree from Postorder and Inorder
    Ref: http://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
    solution: 
    Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1}
 
    We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the end of postorder traversal.
 
    We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree.
    Do above steps recursively.

    Using root from postorder get the size of leftsub tree and right subtree from inorder. This will help to get proper indices into the postorder 
 */
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
Node* constructBT(int in[], int inlow, int inhigh, int post[], int plow, int phigh)
{
    if(inlow > inhigh || plow > phigh)
        return NULL;
    Node* root = getNode(post[phigh]);
    int index = get_root_index(in, post[phigh], inlow, inhigh);
    //int left_subtree_size = index - inlow;
    int right_subtree_size = inhigh - index;
    
    // Note continuous division between indices (left->right. )
    root->left = constructBT(in, inlow, index-1, post, plow, phigh-right_subtree_size-1);
    root->right = constructBT(in, index+1, inhigh, post, phigh-right_subtree_size, phigh-1);
    
    return root;
}
Node* buildTree(int in[], int post[], int n)
{
    return constructBT(in, 0, n-1, post, 0, n-1);
}
int main(int argc, const char * argv[])
{
   // int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    /* Wors case example*/
    int in[] = { 1,2,3,4,5};
    int post [] = {1,2,3,4,5};
    int n = sizeof(in)/sizeof(int);
    Node* root = buildTree(in, post, n);
    inorder(root);
    return 0;
}

/*
 The worst case complexity :  O(n^2), this will happen when tree is skewed.
 */
