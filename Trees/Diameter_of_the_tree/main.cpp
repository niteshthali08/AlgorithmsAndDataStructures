//
//  main.cpp
//  Diameter_of_the_tree
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Diameter of the tree.
    Find the diameter of the tree which is the largest distance between any two leaves of the tree. Remember that this distance may not always pass through root of the tree.
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
int findDiameter(Node* root, int& maxDiam){
    if(root == NULL)
        return 0;
    
    int left = findDiameter(root->left, maxDiam);
    int right = findDiameter(root->right, maxDiam);
    
    
    maxDiam  = max(maxDiam, 1 + left + right);
    return 1 + max(left, right);
    
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
    
    cout << "Inorder: "; inorder(root); cout << "\n";
    int maxDiam = INT_MIN;
    findDiameter(root, maxDiam);
    cout << "Diameter of the tree: " << maxDiam << "\n";
    
    Node *root2 = getNode(50);
    root2->left = getNode(10);
    root2->right = getNode(100);
    root2->left->left = getNode(5);
    root2->left->right = getNode(20);
    root2->left->right->left = getNode(21);
    root2->left->right->left->left = getNode(22);
    root2->left->right->left->left->right = getNode(23);
    root2->left->right->left->left->right->right = getNode(24);
    
    root2->left->left->right = getNode(2);
    cout << "Inorder: "; inorder(root2); cout << "\n";
    maxDiam = INT_MIN;
    findDiameter(root2, maxDiam);
    cout << "Diameter of the tree: " << maxDiam << "\n";
    
    Node *root3 = getNode(50);
    root3->left = getNode(10);
    root3->right = getNode(100);
    cout << "Inorder: "; inorder(root3); cout << "\n";
    maxDiam = INT_MIN;
    findDiameter(root3, maxDiam);
    cout << "Diameter of the tree: " << maxDiam << "\n";
    
    
    Node *root4 = getNode(1);
    root4->left        = getNode(2);
    root4->right       = getNode(3);
    root4->left->left  = getNode(4);
    root4->left->right = getNode(5);
    cout << "Inorder: "; inorder(root4); cout << "\n";
    maxDiam = INT_MIN;
    findDiameter(root4, maxDiam);
    cout << "Diameter of the tree: " << maxDiam << "\n";
    
    return 0;
}