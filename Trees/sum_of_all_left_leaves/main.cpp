//
//  main.cpp
//  sum_of_all_left_leaves
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Find sum of all left leaves in a given Binary Tree
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
void getSumLeftLeaves(Node* root, Node* parent, int &sum){
    /*****************************************
     NOTE: Below code will add all the leaves
     if(root == NULL)
        return;
        
    getSumLeftLeaves(root->left, sum);
    if (root->left == NULL && root->right == NULL)
        sum += root->data;
    getSumLeftLeaves(root->right, sum);
    *******************************************/
    if(root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL){
        if(parent->left == root)
            sum += root->data;
    }
    getSumLeftLeaves(root->left,root, sum);
    getSumLeftLeaves(root->right, root, sum);

    /*Please note sometimes writting separate functions also help a lot. We could have avoided sending extra parameters in function call by writting a separate method to test if left child is a leaf.
        if (isLeaf(root->left))
            sum += root->left->data;
     
     */
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /  \
      10   100
     / \   / \
     5 20 60 150
     /\     /  \
     2 6   55   555
          /
         52
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->left->left->right = getNode(6);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->right->right = getNode(50);
    root->right->left->left = getNode(555);
    root->right->left->left->left = getNode(52);
    cout << "Sum of left leaves: ";
    int sum = 0;
    getSumLeftLeaves(root, NULL, sum);
    cout << sum << "\n";
    return 0;
}
