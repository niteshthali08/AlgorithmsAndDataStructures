//
//  main.cpp
//  Adv_Closest_leaf_to_a_given_node
//
//  Created by Nitesh Thali on 6/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

/* Find closest leaf to the given node x in a tree */
#include<iostream>
using namespace std;

// A Tree node
struct Node
{
    int key;
    struct Node* left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// This function finds closest leaf to root.  This distance
// is stored at *minDist.
void findLeafDown(Node *root, int lev, int *minDist)
{
    // base case
    if (root == NULL)
        return ;
    
    // If this is a leaf node, then check if it is closer
    // than the closest so far
    if (root->left == NULL && root->right == NULL)
    {
        if (lev < (*minDist))
            *minDist = lev;
        return;
    }
    
    // Recur for left and right subtrees
    findLeafDown(root->left, lev+1, minDist);
    findLeafDown(root->right, lev+1, minDist);
}

// This function finds if there is closer leaf to x through
// parent node.
int findThroughParent(Node * root, Node *x, int *minDist)
{
    // Base cases
    if (root == NULL) return -1;
    if (root == x) return 0;
    
    // Search x in left subtree of root
    int l = findThroughParent(root->left, x,  minDist);
    
    // If left subtree has x
    if (l != -1)
    {
        // Find closest leaf in right subtree
        findLeafDown(root->right, l+2, minDist);
        return l+1;
    }
    
    // Search x in right subtree of root
    int r = findThroughParent(root->right, x, minDist);
    
    // If right subtree has x
    if (r != -1)
    {
        // Find closest leaf in left subtree
        findLeafDown(root->left, r+2, minDist);
        return r+1;
    }
    
    return -1;
}

// Returns minimum distance of a leaf from given node x
int minimumDistance(Node *root, Node *x)
{
    // Initialize result (minimum distance from a leaf)
    int minDist = INT_MAX;
    
    // Find closest leaf down to x
    findLeafDown(x, 0, &minDist);
    cout << "\nMin distance leaf down: " << minDist << endl;
    
    // See if there is a closer leaf through parent
    findThroughParent(root, x, &minDist);
    
    return minDist;
}

// Driver program
int main ()
{
    // Let us create Binary Tree shown in above example
    Node *root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);
    
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
    
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
    
    root->right->left->left->left  = newNode(1);
    root->right->left->left->left->left  = newNode(10);
    root->right->left->left->left->left->left  = newNode(100);
    
    root->right->left->left->right = newNode(2);
    root->right->left->left->right->right = newNode(20);
    root->right->left->left->right->right->right = newNode(200);
    
    root->right->left->right->left  = newNode(3);
    root->right->left->right->left->left  = newNode(30);
    root->right->left->right->left->left->left  = newNode(300);
    
    root->right->left->right->right = newNode(4);
    root->right->left->right->right->right = newNode(40);
    root->right->left->right->right->right->right = newNode(400);
    
    root->right->right->left->left  = newNode(5);
    root->right->right->left->right = newNode(6);
    root->right->right->right->left = newNode(7);
    root->right->right->right->right = newNode(8);
    
    Node *x = root->right->left;
    
    cout << "The closest leaf to the node with value "
    << x->key << " is at a distance of "
    << minimumDistance(root, x) << endl;
    
    return 0;
}
