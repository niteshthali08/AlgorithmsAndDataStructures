//
//  main.cpp
//  single_valued_subtrees
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    
    Ref: http://www.geeksforgeeks.org/find-count-of-singly-subtrees/
    Find Count of Single Valued Subtrees
    Input: root of below tree
          5
         / \
        1   5
        / \   \
        5   5   5
    Output: 4
    There are 4 subtrees with single values.
 
 
    Input: root of below tree
          5
         / \
        4   5
        / \   \
        4   4   5
 Output: 5
 There are five subtrees with single values.
 
 O(n^2): for every node check if all nodes below it are same.
 O(n): Bottom up approach return bool signifying if its a single node subtree to the parent.
 
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

bool countSingleSubtrees(Node* root, int &count){
    if (root == NULL)
        return true;
    // this is important, think what would be easy to return true or false.
    bool left = countSingleSubtrees(root->left, count);
    bool right = countSingleSubtrees(root->right, count);
    if(left && right){
        if(root->left && root->right){
            if (root->left->data == root->data && root->right->data == root->data){
                count++;
                return true;
            }
            else
                return false;
        }if(root->left && root->left->data == root->data){
            count++;
            return true;
        }if(root->right && root->right->data == root->data){
            count++;
            return true;
        }if(root->left == NULL && root->right == NULL){
            count++;
            return true;
        }
    }
        
    return false;
    
    /*
     OR FALSE CASES WERE EASY TO WRITE, from geeksforgeeks
     if (left == false || right == false)
        return false;
   
     if (root->left && root->data != root->left->data)
     return false;

     if (root->right && root->data != root->right->data)
     return false;
     
     count++;
     return true;
     
     */
    
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        5
       / \
      4   5
     / \   \
     4  4   5
     */
//    Node *root = getNode(5);
//    root->left = getNode(4);
//    root->right = getNode(5);
//    root->left->left = getNode(4);
//    root->left->right = getNode(4);
//    root->right->right = getNode(5);
    
    Node *root = getNode(5);
    root->left = getNode(1);
    root->right = getNode(5);
    root->left->left = getNode(5);
    root->left->right = getNode(5);
    root->right->right = getNode(5);
    
    int count = 0;
    countSingleSubtrees(root, count);
    cout << "Count of Single Sub Trees: " << count<< endl;
    return 0;
}



