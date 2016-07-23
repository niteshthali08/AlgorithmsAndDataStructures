//
//  main.cpp
//  Convert_all_leaves_to_DLL_inplace
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

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
Node* convertLeavesToDLL(Node* root, Node* &prev, Node* &head){
    if(root == NULL)
        return NULL;
    if(!root->left && !root->right){
        if(!prev){
            prev = root;
            head = root;
        }else{
            prev->right = root;
            root->left = prev;
            prev = root;
        }
        return NULL;
    }
    root->left = convertLeavesToDLL(root->left, prev, head);
    root->right = convertLeavesToDLL(root->right, prev, head);
    return root;
}
void printDLL(Node* head){
    while(head){
        cout << head->data << "->";
        head = head->right;
    }
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
    Node* prev = NULL, *head = NULL;
    convertLeavesToDLL(root, prev, head);
    cout << "DLL of leaves: "; printDLL(head); cout<<"NULL\n";
    cout << "Inorder traversal for remaining tree after reoving leaves: \n";
    inorder(root);
    cout << endl;
    cout << "Test2\n";
    /***********Test2 **************/
    root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    prev = NULL; head = NULL;
    convertLeavesToDLL(root, prev, head);
    cout << "DLL of leaves: "; printDLL(head); cout<<"NULL\n";
    cout << "Inorder traversal for remaining tree after reoving leaves: \n";
    inorder(root);
    cout << endl;
    
    return 0;
}