//
//  main.cpp
//  check_if_all_leaves_at_same_level
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
bool areLeavesAtSameLevel(Node* root, int level, int& leafLevel){
    if(root == NULL)
        return true;
    if (!root->left && !root->right){
        if (leafLevel == -1){
            leafLevel = level;
        }
        else{
            if(level == leafLevel)
                return true;
            return false;
        }
    }
    if(! areLeavesAtSameLevel(root->left, level+1, leafLevel)){
        return false;
    }
    if(!areLeavesAtSameLevel(root->right, level+1, leafLevel))
        return false;
    
    return true;
    
    
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
    //root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->right = getNode(2);
    root->left->left->left = getNode(12);
    //root->right->left = getNode(60);
    //root->right->right = getNode(150);
    //root->right->left->left = getNode(55);
    int level = 0, leafLevel = -1;
    cout << "All leaves at same level ? : ";
    (areLeavesAtSameLevel(root, level, leafLevel) == true)? cout << "True\n" : cout << "False\n";
    return 0;
}