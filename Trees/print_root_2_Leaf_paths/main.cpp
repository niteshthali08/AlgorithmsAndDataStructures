//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to print all paths from root to leaves
 
 */


#include <iostream>
#include <vector>
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
void printPath(Node* root, vector<int> path)
{
    if( root == NULL) return; // this important, required when there is only one child for a node, this will handle call for second child since it will be null
    if (root->left == NULL && root->right == NULL){
        for (int i=0; i<path.size(); i++) {
            cout<<path.at(i) << " ";
        }
        cout << root->data << endl;
        return;
    }
    path.push_back(root->data);
    printPath(root->left, path);
    printPath(root->right, path);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    /*
         50
       /   \
      10     100
     / \    /  \
     5 20  60  150
    / \    /
    2  9   55
    
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->left->left->right = getNode(9);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    
    root->right->left->left = getNode(55);

    cout << "Inorder: "; inorder(root);
    cout<<"\nPaths\n";
    vector <int> path;
    printPath(root, path);
    return 0;
}
