//
//  main.cpp
//  print_cousin_nodes
//
//  Created by Nitesh Thali on 7/17/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Print cousins of a given node in Binary Tree
          50
         /  \
        10   100
        / \   / \
        5 20 60 150
 
    Input: 20
    Output : 6, 7
 */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};
struct MyNode{
    Node* node;
    int level;
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
MyNode* findNodeAndLevel(Node* root, int val, int level){
    if(root == NULL)
        return NULL; // returning 0 is important, it signifies we havn't found the node yet
    if(root->data == val){
        MyNode* mn = new MyNode();
        mn->node = root;
        mn->level = level;
        return mn;
    }
    MyNode* rlevel = findNodeAndLevel(root->left, val, level+1); // dont put expression in if
    if (rlevel)
        return rlevel; // that means we found the node, no need to look into RST.
    return findNodeAndLevel(root->right, val, level+1);
}

void printAllCousins(Node *root, int val, Node* node, int level){ // note we can avoid sending one more param by doing -- on level
    
    if(root == NULL || level < 2)
        return;
    
    if (level == 2){// this is the parent of required node.
        if(root->left != node && root->right != node){
            if(root->left)
                cout << root->left->data << " ";
            if(root->right){
                cout << root->right->data << " ";
            }
        }
        
    }
    if(level > 2){
        printAllCousins(root->left, val, node, level-1);
        printAllCousins(root->right, val, node, level-1);
    }
}
void printCousins(Node* root, int val){
    MyNode* mn = findNodeAndLevel(root, val, 1); // Note 1 here, level of the root is 1
    // return 0 if node is not present.
    cout << "Level of the node: " << mn->level << endl;
    printAllCousins(root, val, mn->node, mn->level);
    
}

int main(int argc, const char * argv[]) {
    /*
          50
         /  \
        10   100
       / \   / \
       5 20 60 150
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    printCousins(root, 50);
    return 0;
}

