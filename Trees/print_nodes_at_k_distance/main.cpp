//
//  main.cpp
//  print_nodes_at_k_distance
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    This is an amazing question.
    Ref: http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
    Print all nodes at distance k from a given node.
    Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. So nodes which are above should also be printed.
 
    O(n): Solution:
    Printing nodes below target node is easy but printing nodes above target node requires a little bit of thinking.
 
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
void printNodesDown(Node* root, int k){ // prints the nodes below the target
    if(root == NULL)
        return;
    if(k == 0){
        cout << root->data << " ";
        return;
    }
    printNodesDown(root->left, k-1);
    printNodesDown(root->right, k-1);
    
}
bool printNodes(Node* root, int k, int target, int level, int &targetLevel){
    if(root == NULL)
        return false;
    if(root->data == target){
        targetLevel = level;
        printNodesDown(root, k); // if root matches, print the nodes below the target nodes.
        return true;
    }
   // bool left = printNodes(root->left, k, target, level+1, targetLevel);
   // bool right = printNodes(root->right, k, target, level+1, targetLevel);

    if (printNodes(root->left, k, target, level+1, targetLevel)){
        // this important, this handles the case when (k == 1)
        if( (k- (targetLevel - level)) == 0) // that means current root has to be printed.
            cout << root->data << " ";
        else
            printNodesDown(root->right, k-(targetLevel - level+1)); // +1 since we are calling on its child, we have found target as left child and hence explore right child
        return true;
    }
    if(printNodes(root->right, k, target, level+1, targetLevel)){
        // this important, this handles the case when (k == 1)
        if( (k- (targetLevel - level)) == 0) // that means current root has to be printed.
            cout << root->data<< " ";
        else// we got target on right side therefore explore left child of the root.
            printNodesDown(root->left, k-(targetLevel - level+1));
        return true;
    }
    // when backtracking reaches root, value of left and right gets swapped.
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /  \
     10   100
     / \   / \
   5    20 60 150
  / \   / \
 9   22 2  30
     / \
     25 39
      */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->left->left = getNode(9);
    root->left->right = getNode(20);
    root->left->right->left = getNode(2);
    root->left->right->right = getNode(30);
    
    root->left->left->right = getNode(22);
    root->left->left->right->left = getNode(25);
    root->left->left->right->right = getNode(39);
    
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    
    
    /**********TEST 1 - 2, 30, 100 ****************/
    int level = 0, targetLevel = 0;
    printNodes(root, 2, 2, level, targetLevel);
    
    return 0;
}