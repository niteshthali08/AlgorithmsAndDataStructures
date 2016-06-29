//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*  Program to traverse tree in inorder fashion using recursive and iterative fucntion */
#include <iostream>
#include <stack>
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
void inorder_iterative(Node* root)
{
    stack <Node*> st;
    while (true)
    {
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty())
                break;
            else{
                Node * item = st.top();
                st.pop();
                cout << item->data << " ";
                root = item->right;
            }
            
        }
    }
    cout << endl;
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
    root->right->left->left->left = getNode(52);
    cout << "Recursive Inorder: "; inorder(root); cout << "\n";
    cout << "Iterative Inorder: "; inorder_iterative(root);
    return 0;
}
