//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Question from: http://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
 Print Binary Tree in 2-Dimensions
 Input : Pointer to root of below tree
     1
    /  \
   2    3
  / \   / \
 4   5  6  7
 
 Output :
                7
 
        3
 
                6
 
 1
 
                5
 
        2
 
                4
 
 Solution:
    1. If you observe carefully, nodes are printed in reverse inorder style i.e.right->node->left
 
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
void print2D(Node *root, int space)
{
    if(root)
    {
        
        print2D(root->right, space+4);
        for(int i=0; i<space; i++)
            cout << " ";
        cout << root->data << endl;
        print2D(root->left, space+4);
    }
    
}

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
         50
        /  \
     10     90
     / \    /  \
     15 20  60  95
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(90);
    root->left->left = getNode(15);
    root->left->right = getNode(20);
    root->right->left = getNode(60);
    root->right->right = getNode(95);
    int space = 0;
    print2D(root, space);
    return 0;
}
