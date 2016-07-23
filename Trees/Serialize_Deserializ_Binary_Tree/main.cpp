//
//  main.cpp
//  Serialize_Deserializ_Binary_Tree
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to serialize deserialize a Binary tree.
    
 * If a tree is a BST then only pre-order or postorder is sufficient to maintain the structure of the tree.
 * (constructing BST is easy for preorder, use stack NGE method(last_pop), for post order use range stratergy)
 
 * For a complete Binary Tree, level order traversal is sufficient to store the tree.
 * For Full Binary tree, We can simply store preorder traversal and store a bit with every node to indicate whether the node is an internal node or a leaf node.
 
  * If tree is not a BST then you need "two traversal representations" to represent it.
    Binary tree it is little bit tricky. We will have to store two traversals and hence extra storage. We can avoid this by doing preorder traversal of tree and storing some indicator like (-1) for leaf nodes. This stratergy converts the tree into a complete binary tree. Using this we can deserialize tree very easily using the similar recursive procedure

    *Second option would be to use level-order traversal to serialize and deserialize a tree.
 */

#include <iostream>
#include <vector>
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
void preorder(Node *root)
{
    if(root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
void Serialize(Node* root, vector<int> & st){
    if (root == NULL){
        st.push_back(-1);
        return;
    }
    st.push_back(root->data);
    Serialize(root->left, st);
    Serialize(root->right, st);
    
}

Node* Deserialize(vector <int> st, int& index){
    if (st.at(index) == -1 || index > st.size())
        return NULL;
    
    Node* node = getNode(st.at(index));
    index++;
    node->left = Deserialize(st, index); // important lesson to learn from here, you cannot pass increament same variable and pass it as a reference.
    index++;
    node->right = Deserialize(st, index);
    return node;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
         50
        /  \
      10    100
       \    / \
        20  60 150
            /
           55
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->right = getNode(20);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    vector <int> serialized_tree;
    Serialize(root, serialized_tree);
    cout << "Serialized Tree Preorder: \n";
    for(int i=0; i<serialized_tree.size(); i++){
        cout << serialized_tree.at(i) << " ";
    }
    int i = 0;
    Node* root1 = Deserialize(serialized_tree, i);
    cout << "\nDeserialized Tree Preorder: \n";
    preorder(root1);
    cout << endl;
    return 0;
}
