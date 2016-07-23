//
//  main.cpp
//  check_if_tree_completeBT_or_not
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to check if given binary treee is complerte or not.
    Complete tree has all the level filled except for the last one and has all nodes to the left on last level.
 
    solution: Simple Idea. Do level order traversal. Keep putting all the nodes in queue. Once you find a NULL value break from the loop. If this is a complete tree all the nodes remaining in the queue should be NULL otherwise it is not a complete tree.
 
 */

#include <iostream>
#include <queue>
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

bool checkCompleteTree(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* ele = q.front();
        q.pop();
        if (ele == NULL)
            break;
        q.push(ele->left);
        q.push(ele->right);
    }
    while(!q.empty()){
        if(q.front() != NULL){
            return false;
        }
        q.pop();
    }
    return true;
}
int main(int argc, const char * argv[]) {
    /*
        50
       /  \
      10   100
     / \   / \
     5 20 60 150
    
     */
    Node* root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    
    root->right->left = getNode(60);
    root->right->right = getNode(150);

    cout << "Is tree complete?: ";
    checkCompleteTree(root) == true ? cout <<"True\n" : cout << "False\n";
    
    return 0;
}

