//
//  main.cpp
//  construct_infix_from_postfix
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program is to convert a postfix expression into a infix expression tree. Infix expression can be evaluated by doing a post order traversal on the tree.
    INFIX can also be evaluated by using two stacks one for operands and other for operators.
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node{
    char data;
    Node *left, *right;
};

Node* getNode(char data)
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
Node* constructInfixTree(string infix){
    
    // use a stack to construct interediate nodes and store then for further linking in the stack.
    
    stack <Node*> st;
    
    for(int i=0; i< infix.length(); i++){
        Node* post = getNode(infix[i]);
        if(!(infix[i] <= 58 && infix[i] > 48)){
            post->right = st.top();
            st.pop();
            post->left = st.top();
            st.pop();
        }
         st.push(post);
    }
    return st.top();
    
}

int main(int argc, const char * argv[]) {
    string expr = "12+34+*";
    Node* infixTree = constructInfixTree(expr);
    cout << "Inorder for Infix expression Tree: ";
    inorder(infixTree);
    cout<< endl;
    
    return 0;
}
