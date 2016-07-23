//
//  main.cpp
//  check_BT_mirror_of_itself
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Ref: http://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/
    Symmetric Tree (Mirror Image of itself)
    Given a binary tree, check whether it is a mirror of itself.
    
           1
          /  \
         2     2
        / \   / \
       3   4 4   3
    Mirro but following tree isn't a mirro of itslef
              1
             / \
            2   2
            \    \
             3    3
 
 Soln: This is a simple question, can be broken down to see if two trees are mirror images of each other. Here two trees will be the subtrees of the root.
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
bool checkMirror(Node* root1, Node* root2){
    if(root1 == NULL && root2 ==NULL)
        return true;
    if(root1 == NULL || root2 ==NULL)
        return false;
    return (root1->data == root2->data) && checkMirror(root1->left, root2->right) && checkMirror(root1->right, root2->left);

}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   10
     / \   / \
     5 20 20  5
    
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(10);
    //root->left->left = getNode(5);
    root->left->right = getNode(20);
   
    //root->right->left = getNode(20);
    root->right->right = getNode(5);
    cout << "Self Miroor ?: ";
    checkMirror(root->left, root->right) == true ? cout << "True\n" : cout << "False\n";
    return 0;
}

