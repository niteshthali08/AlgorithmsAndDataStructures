//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Program to find Lowest Common Ancesstor of given two nodes in a Binary tree.
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
Node* LCA(Node* root, int n1, int n2)
{
    /*
     Drawback of this method is that it will irrespective of whether a second node is present or not will return first node as LCA as soon as it is foind. This can be avoided by writting a wrapper by passing two boolean values. See LCA2 implemetation
     */
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node* left = LCA(root->left, n1, n2); // check if any node is present on the left sub tree of root
    Node* right = LCA(root->right, n1, n2); // check if any node is present on the right side of the root
    
    if (left && right) // that means root is LCA (both nodes found, one on left and other on the right)
        return root;
    
    if (left) // return the first node which is found(propagate it to the root) else it will return NULL
        return left;
    else
        return right;
    
}
bool find(Node* res, int val)
{
    if (res == NULL)
        return false;
        return res->data == val || find(res->left, val) || find(res->right, val);
}

Node* LCA2Helper(Node* root, int n1, int n2, bool &f1, bool &f2)
{
    if (root == NULL)
        return NULL;
    
    if (root->data == n1){
        f1 = true;
        return root;
    }
        
    if(root->data == n2){
        f2 = true;
        return root;
    }
    
    Node* left = LCA2Helper(root->left, n1, n2, f1, f2); // check if any node is present on left sub tree of root
    Node* right = LCA2Helper(root->right, n1, n2, f1, f2); // check if any node is present on right side oftheroot
    
    if (left && right) // that means root is LCA (both nodes found, one on left and other on the right)
        return root;
    
    if (left) // return the first node which is found(propagate it to the root) else it will return NULL
        return left;
    else
        return right;
    
}
Node* LCA2(Node* root, int n1, int n2)
{
    bool f1 = false, f2 = false;
    Node* res = LCA2Helper(root, n1, n2, f1, f2);
    if (res == NULL) return NULL;
    if (f1 == f2 || (f1 && find(res, n2)) || (f2 && find(res, n1)))
        return res;
    else
        return NULL;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
/*
        50
       /  \
     10   100
     / \   / \
     5 20 60 150
     /    /
     2   55
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
    cout << "LCA(2, 52):" << LCA(root, 2, 52)->data << endl;
    cout << "LCA(100, 150):" << LCA(root, 100, 150)->data << endl;
    cout << "LCA(10, 2):" << LCA(root, 10, 2)->data << endl;
    cout<<  "LCA(52, 150):" << LCA(root, 52, 150)->data << endl;
    //cout << "LCA(230, 200):" << LCA(root, 230, 200)->data << endl; //(return NULL);
    cout << "LCA(52, 1500):" << LCA(root, 52, 1500)->data << endl; // will return a node which is found first
    //***************************************************************************************************
    cout << "LCA(52, 1500):";
    Node* res = LCA2(root,52, 1500);
    (res)? cout << res->data<<endl : cout << "NULL\n";
    
    cout << "LCA(1152, 1500):";
    res = LCA2(root,52, 1500);
    (res)? cout << res->data<<endl : cout << "NULL\n";
    
    cout << "LCA(52, 2):";
    res = LCA2(root,52, 2);
    (res)? cout << res->data<<endl : cout << "NULL\n";

    cout << "LCA(20, 60):";
    res = LCA2(root,20, 60);
    (res)? cout << res->data<<endl : cout << "NULL\n";
    
    cout << "LCA(100, 52):";
    res = LCA2(root,100, 52);
    (res)? cout << res->data<<endl : cout << "NULL\n";

    return 0;
}
