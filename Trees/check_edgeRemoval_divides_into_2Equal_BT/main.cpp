//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  Description: Starter code for creating a BST as drawn below. This code will be used by other program to qucikly generate a BST for testing their program.


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
int countNodes(Node* root)
{
    if (root == NULL)
        return 0;
    return 1+ countNodes(root->left) + countNodes(root->right);
}
int checkDividProperty(Node* root, int n, bool & res)
{
    if (root == NULL)
        return 0;
    int nodes = 1 + checkDividProperty(root->left, n, res) + checkDividProperty(root->right, n, res);
    
    if (n-nodes == nodes)
        res = true;
    //cout << nodes << " ";
    return nodes;
}

bool checkProperty(Node* root, int n)

{
    bool res = false;
    if (n&1) return res;
    checkDividProperty(root, n, res);
    return res;
}
int main(int argc, const char * argv[]) {
       /*
            50
           /   \
         10     100
        / \      / \
       5  20    60  150
      /   /\    / \
     2  15 30  55  65
    
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->right->left = getNode(15);
    root->left->right->right = getNode(30);
    root->left->left->left = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    root->right->left->right = getNode(65);
 
    cout << "Inorder: "; inorder(root); cout << "\n";
    int n = countNodes(root);
    cout << "Total Number of nodes: " << n << endl;
    cout <<"Can tree be divided into two parts by removing one edge ? " << checkProperty(root, n) <<endl;
    return 0;
}

/*
 Complexity: O(n) for finding n, O(n) for post order traversal finding size for each node. Therefore overall time complexity is O(n).
 */