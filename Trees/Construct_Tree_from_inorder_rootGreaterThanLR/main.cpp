//
//  main.cpp
//  Construct_Tree_from_inorder_rootGreaterThanLR
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Question: http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
    
    Construct Special Binary Tree from given Inorder traversal
    Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children, construct the Binary Tree and return root.
 
    Input: inorder[] = {5, 10, 40, 30, 28}
    Output: root of following tree
         40
        /   \
      10     30
     /         \
    5          28
    Solution: Since is the greatest, we can divide left subtree and right subtree at this index.
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
int findGreatest(int in[], int low, int high){
    int max = INT_MIN;
    for (int i=low; i<=high; i++) {
        if(in[i] > max){
            max = i;
         }
    }
    return max;
}
Node* constructTree(int in[], int low, int high){
    if(low > high)
        return NULL;
    int greatest = findGreatest(in, low, high);
    Node* root = getNode(in[greatest]);
    root->left = constructTree(in, low, greatest-1);
    root->right = constructTree(in, greatest + 1, high);
    return root;
    
}

int main(int argc, const char * argv[]) {
//    int in[] =  {5, 10, 40, 30, 28};
//    int len = sizeof(in)/sizeof(int), low = 0, high = len-1;
    int in[] = {1, 5, 10, 40, 30,15, 28, 20};
    int len = sizeof(in)/sizeof(int), low = 0, high = len-1;
    Node* root = constructTree(in,low, high);
    cout << "Inorder for constructed Tress:\n"; inorder(root); cout << endl;
    return 0;
}