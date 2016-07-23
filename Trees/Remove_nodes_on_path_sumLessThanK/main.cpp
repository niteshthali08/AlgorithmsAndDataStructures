//
//  main.cpp
//  Remove_nodes_on_path_sumLessThanK
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

//
//  main.cpp
//  Remove_nodes_on_path_lengthLessThan_K
//
//  Created by Nitesh Thali on 7/19/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Remove all nodes which don’t lie in any path with sum>= k
 
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
Node* removeNodes(Node* root,int sum, int k){
    if (root == NULL)
        return root;
    if(root->left == NULL && root->right == NULL){
        sum += root->data;
        if(sum < k)
            return NULL;
        else
            return root;
    }
    sum += root->data;
    root->left = removeNodes(root->left, sum, k);
    root->right = removeNodes(root->right, sum, k);
    
    if (root->left == NULL  && root->right == NULL) // after deletion if root becomes a leaf.
        return NULL;
    else
        return root;
}

int main(int argc, const char * argv[]) {
/*
          1
       /      \
      2        3
     /  \     /  \
    4    5   6    7
    / \     /     /
   8   9   12    10
      / \         \
     13  14        11
     /
    15
    */
    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->left->left = getNode(8);
    root->left->left->right = getNode(9);
    root->left->right->left = getNode(12);
    root->right->right->left = getNode(10);
    root->right->right->left->right = getNode(11);
    root->left->left->right->left = getNode(13);
    root->left->left->right->right = getNode(14);
    root->left->left->right->right->left = getNode(15);
//    cout << "Test1:\n";
//    int k=45, sum = 0;
//    cout << "Inorder before deletion: "; inorder(root); cout << "\n";
//    root = removeNodes(root,sum, k);
//    cout << "Inorder after deletion: "; inorder(root); cout << "\n";
    
    cout << "Test2:\n";
    int k=20,sum = 0;
    cout << "Inorder before deletion: "; inorder(root); cout << "\n";
    root = removeNodes(root,sum, k);
    cout << "Inorder after deletion: "; inorder(root); cout << "\n";
    return 0;
}

