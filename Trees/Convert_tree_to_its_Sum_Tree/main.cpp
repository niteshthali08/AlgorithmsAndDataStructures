//
//  main.cpp
//  Convert_tree_to_its_Sum_Tree
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Convert a given tree to its Sum Tree
    10
   /      \
 -2        6
 /  \      /  \
 8  -4    7    5
 
 Output
    20(4-2+12+6)
    /    \
 4(8-4)   12(7+5)
 /   \     /  \
 0    0   0    0

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
int getSumTree(Node* root){
    if (root == NULL)
        return 0;
    
    int left = getSumTree(root->left);
    int right = getSumTree(root->right);
    
    int data = root->data;
    root->data = left+ right;
    return root->data + data;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   100
     / \   / \
     5 20 60 150
     \    /
     2   55
     Output:
         402
        /  \
      27   265
     / \   / \
     2  0  55 0
     \    /
      0  0
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->right = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    cout << "Inorder for normal tree:\n"; inorder(root); cout << "\n";
    getSumTree(root);
    cout << "Inorder for sum tree:\n"; inorder(root); cout << "\n";
    /*
     
        10
       /    \
     -2       6
     / \     /  \
     8 -4   7    5
     
     */
    Node* root2 = getNode(10);
    root2->left = getNode(-2);
    root2->right = getNode(6);
    root2->left->left = getNode(8);
    root2->left->right = getNode(-4);
    root2->right->left = getNode(7);
    root2->right->right = getNode(5);
    
    cout << "Inorder for normal tree:\n"; inorder(root2);  cout<< "\n";
    getSumTree(root2);
    cout << "Inorder for sum tree:\n"; inorder(root2); cout << "\n";
    return 0;
}