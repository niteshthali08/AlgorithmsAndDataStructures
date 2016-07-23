//
//  main.cpp
//  Connect_nodes_at_same level
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Connect nodes at same level.
    Without constant space:
    1. Level order traversal
    2. Pre order traversal(Best method, connect parents before connecting childs). Implemented below.
 
 
 */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right, *next;
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
void connectUsingRecursion(Node * root){
    if(!root) // do preorder traversal
        return;
    if(root->left)
        root->left->next = root->right;
    if(root->right){
        Node* tmp = root;
        while(tmp->next){
            if(tmp->next->left){
                root->right->next = tmp->next->left;
                break;
            }
            if(tmp->next->right){
                root->right->next = tmp->next->right;
                break;
            }
            tmp = tmp->next;
        }
    }
    connectUsingRecursion(root->left);
    connectUsingRecursion(root->right);
    
}
void printLevelOrder(Node* root){
    if (!root)
        return;
    if (root->left)
    {
        Node* tmp = root;
        while(tmp){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
        printLevelOrder(root->left);
        
    }else{
        Node* tmp = root;
        while(tmp){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
        printLevelOrder(root->right);
    }
    
}
int main(int argc, const char * argv[]) {
    /*
        50
       /  \
     10   100
     / \   / \
     5 20 60 150
     \    /
      2  55
     
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
    connectUsingRecursion(root);
    cout << "Level order connection using recursion (preorder):\n";
    printLevelOrder(root);
    return 0;
}