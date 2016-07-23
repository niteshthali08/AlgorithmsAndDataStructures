//
//  main.cpp
//  Check_BT_is_Subtree_of_another_BT
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Check if a binary tree is subtree of another binary tree.
    O(n^2) solution is straighforward, for each node check if a subtree is present in other tree with that node.
   O(n): Solution would be to do say preorder and inorder traversal for both the trees and store them in array. Now if binary tree is a subtree then its inorder and preorder array element would be sub array of the original tree.
 
    NOTE: for this subarray method, we have to handle another case separately which is, a tree can present in another tree but not as a subtree (leaves are not NULL). Simple solution would be to add -1 for the leaves and then find subarray matching using KMP.
    THIS IS DIFFERENT FROM FINDING IF GIVEN STRUCTURE IS PRESENT IN THE BINARY OR NOT
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
bool match(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return root1->data == root2->data && match(root1->left, root2->left) && match(root1->right, root2->right);
    
}
bool isSubTree(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL)
        return true;
    if(root1){
        if(root1->data == root2->data){
            bool res = match(root1, root2);
            if(res) return true;
        }
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
        
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
          50
         /  \
       10   100
      / \   / \
     5 20 60 150
     /     /
     2    55
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    /********* Test 1 ******** False*/
    Node* root2 = getNode(50);
    (isSubTree(root, root2) == true)? cout <<"True\n" : cout << "False\n";
    
    /********* Test 2 ******** True*/
    root2 = getNode(100);
    root2->left = getNode(60);
    root2->right = getNode(150);
    root2->left->left = getNode(55);
    
   (isSubTree(root, root2) == true)? cout <<"True\n" : cout << "False\n";
    /********* Test 3 ******** False*/
    root2 = getNode(10);
    root2->left = getNode(5);
    root2->right = getNode(20);
    (isSubTree(root, root2) == true)? cout <<"True\n" : cout << "False\n";
    
    /********* Test 4 ******** True*/
    root2 = getNode(2);
    (isSubTree(root, root2) == true)? cout <<"True\n" : cout << "False\n";
    
    /********* Test 2 ******** False (different data)*/
    root2 = getNode(100);
    root2->left = getNode(160);
    root2->right = getNode(150);
    root2->left->left = getNode(155);
    (isSubTree(root, root2) == true)? cout <<"True\n" : cout << "False\n";
    return 0;
}
