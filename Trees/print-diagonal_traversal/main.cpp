//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to print elements according to diagonal. 
 
*/

#include <iostream>
#include <map>
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
void diagonalPrint(Node* root, int d, map<int, vector<int> > & mp)
{
    if(root == NULL)
        return;
    mp[d].push_back(root->data);
    diagonalPrint(root->left, d+1, mp);
    diagonalPrint(root->right, d, mp);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /   \
     10     100
     / \    /  \
     5 20  60  150
    /      /
    2      55
   /
  52
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
    root->left->left->left->left = getNode(52);
    cout << "Inorder: "; inorder(root); cout << "\n";
    int d = 0;
    map<int, vector<int> > mp;
    diagonalPrint(root, d, mp);
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i=0; i<it->second.size(); i++) {
            cout << it->second.at(i) << " ";
        }
        cout << endl;
    }
    return 0;
}
