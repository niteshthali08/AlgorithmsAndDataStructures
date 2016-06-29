//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  Description: Program to covert BST into a Doubly linkd list. Elements of the list should be in sorted order
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
void printDLL(Node *head)
{
    cout << "head";
    while (head!=NULL)
    {
        cout << "->" << head->data;
        head = head->right;
    }
}
void getDoublyLinkedList(Node *root, Node* & head, Node** prev)
{
    if(root == NULL)
        return;
    
    /*  1. static Node* prev = NULL; this works but using static inside recursion is a bad idea. If this function is called on many trees then static variable will retain old value which is wrong. Therefore we can send double pointer as a third parameter to the function.

        2. Note for this implementation:
        Do not put *prev = NULL, here as we did for static implemetation because when left will get called after doing left most branch it will be initialized to NULL which is wrong. (In case of static it was working because static gets initialized only once, so in the second call it wont become NULL)
        3. Please see below for implementation using a reference variable.
     
     */
    getDoublyLinkedList(root->left, head, prev);
    if(*prev == NULL)
    {
        head = root;
    }
    else{
        (*prev)->right = root;
        root->left = *prev;
    }
    *prev= root;
    getDoublyLinkedList(root->right, head, prev);
}
/* Same implementation using a reference variable */
void getDoublyLinkedListRef(Node *root, Node* & head, Node* &prev)
{
    if(root == NULL)
        return;
   
    
    getDoublyLinkedListRef(root->left, head, prev);
    if(prev == NULL)
    {
        head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    prev= root;
    getDoublyLinkedListRef(root->right, head, prev);
}
int main(int argc, const char * argv[]) {
       /*
                   50
                 /    \
                10     100
                / \    /  \
                5 20  60  150
               /       /
              2       55
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
    cout << "Inorder: "; inorder(root); cout << "\n";
    Node *head = NULL;
    Node *prev = NULL;
    getDoublyLinkedList(root, head, &prev);
    cout << "DLL: "; printDLL(head); cout << "\n";
//    cout << "Using Reference variable implemetation: " << endl;
//    getDoublyLinkedListRef(root, head, prev);
//    cout << "DLL: "; printDLL(head); cout << "\n";
    
    return 0;
}
