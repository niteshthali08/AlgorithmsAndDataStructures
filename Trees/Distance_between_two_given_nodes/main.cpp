//
//  main.cpp
//  Distance_between_two_given_nodes
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to find distance between two given nodes. ***
    Idea is to calculate LCA first and then to calculate the distance based on the LCA.
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
Node* LCA(Node* root, int n1, int n2, int& d1, int& d2, int& lca_level, int level){
    if (root == NULL)
        return NULL;
    if (root->data == n1) {
        d1 = level;
        return root;
    }
    if (root->data == n2) {
        d2 = level;
        return root;
    }
    Node* left = LCA(root->left, n1, n2, d1, d2, lca_level, level+1);
    Node* right = LCA(root->right, n1, n2, d1, d2, lca_level, level+1);
    
    if(left && right){
        lca_level = level;
        return root;
    }
    if(left)
        return left;
    if(right)
        return right;
    return NULL;
}
int findLevel(Node* root, int n){
    if (root == NULL)
        return -1;
    if (root->data == n){
        return 0;
    }
    int left = findLevel(root->left, n);
    int right = findLevel(root->right, n);
    if (left != -1)
        return 1+left;
    if(right!= -1)
        return 1+right;
    return -1;
}
int findDistance(Node* root, int n1, int n2){
    int d1 = -1, d2= -1, level=0, lca_level=0;
    Node* lca = LCA(root, n1, n2, d1, d2, lca_level, level);
    if (lca == NULL) return -1; // Nodes are absent in the tree.
    if(d1 != -1 && d2 != -1) // this distance is summation of distance from root to each of the node. Therefore we will have to subtract 2 * (distance of LCA from root)
        return d1 + d2 - 2*lca_level;
    else if(d1 != -1){ // that means n2 is below n1, we have to find its distance from n1.
        return findLevel(lca, n2);
    }
    else if(d2 != -1){
       return findLevel(lca, n1);
    }
    else
        return -1;
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
    int n1 = 50, n2=150;// 2
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    n1 = 50, n2=2;// 3
    
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    n1 = 20, n2=60;// 4
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    
    n1 = 150, n2=55; //3
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    
    n1 = 150, n2=550; // -1
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    
    n1 = 550, n2=150; // -1
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    
    n1 = 550, n2=550; // -1
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    
    n1 = 10, n2=10; // 0
    cout << "Distance: " << findDistance(root, n1, n2) << endl;
    return 0;
}