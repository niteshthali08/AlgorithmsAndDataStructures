//
//  main.cpp
//  check_if_tree_is_balanced
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

#include <iostream>
#include <algorithm>
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
bool checkIfBalance(Node* root, int& mx, int& mn){
    if (root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    int left, right;
    if(checkIfBalance(root->left, left, right)){
        return true;
    }
    if(checkIfBalance(root->right, left, right)){
        return true;
    }
    
       
       
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
    int m = 0, n = 0;
    checkIfBalance(root, m, n);
    cout << "Inorder: "; inorder(root); cout << "\n";
    return 0;
}