//
//  main.cpp
//  Remove_nodes_on_path_lengthLessThan_K
//
//  Created by Nitesh Thali on 7/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Remove nodes on root to leaf paths of length < K
 
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
Node* removeNodes(Node* root, int k, int depth){
    if (root == NULL)
        return root;
    if(root->left == NULL && root->right == NULL){
        if(depth < k)
            return NULL;
        else
            return root;
    }
    root->left = removeNodes(root->left, k, depth+1);
    root->right = removeNodes(root->right, k, depth+1);
    
    if (root->left == NULL  && root->right == NULL && depth < k) // after deletion if root becomes a leaf.
        return NULL;
    else
        return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
               50
              /  \
            10    100
           / \   /  \
          5 20  60 150
             \   /
              4  55
                 /
                52
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->right->right = getNode(4);
//    //root->left->left->left = getNode(2);
//    root->right->left = getNode(60);
//    root->right->right = getNode(150);
//    root->right->left->left = getNode(55);
//    root->right->left->left->left = getNode(52);
    int k=4, depth = 1;
    root = removeNodes(root, k, depth);
    cout << "Inorder after deletion: "; inorder(root); cout << "\n";
    return 0;
}
