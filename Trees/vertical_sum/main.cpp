//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    PROGRAM to print all vertical sums (sum of nodes which are at same vertical distance from root)
 
 */
#include <iostream>
#include <map>
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
void verticalSum(Node* root, int vd, map<int, int> & mp)
{
    if(root == NULL)
        return;
    mp[vd] += root->data;
    verticalSum(root->left, vd+1, mp);
    verticalSum(root->right, vd - 1, mp);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
         1
        /  \
       2    3
     / \    / \
     4  5  6   7
     */
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    
    cout << "Inorder: "; inorder(root); cout << "\n";
    int vd = 0;
    map <int , int > mp;
    verticalSum(root, vd, mp);
    cout << "Vertical Sum: ";
    for (auto it = mp.begin(); it != mp.end(); it++ )
    {
        cout << it->second<< " ";
    }
    cout << endl;
    return 0;
}
