//
//  main.cpp
//  Adv_Closest_leaf_to_a_given_node
//
//  Created by Nitesh Thali on 6/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//

/* Find closest leaf to the given node x in a tree  
    ANOTHER Solution would be to keep all ancesstors in an array and call calculateDownDistance() on all of them when the target is found.
 
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
int calculateDownDistance(Node* root){ // prints the nodes below the target
    if(root == NULL)
        return INT_MAX; // this is important, since this is not a leaf.
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int left = calculateDownDistance(root->left);
    int right = calculateDownDistance(root->right);
    return 1 + min(left, right);
    
}
bool findMinDistance(Node* root, int target, int level, int &targetLevel, int &mindist){
    if(root == NULL)
        return false;
    if(root->data == target){
        targetLevel = level;
        mindist = calculateDownDistance(root); // if root matches,calculate min down distance to leaf.
        return true;
    }
    
    if (findMinDistance(root->left, target, level+1, targetLevel, mindist)){
        
        int dist = calculateDownDistance(root->right); // dont add a number to INT_MAX, it will become negative.
        if (dist != INT_MAX) // that means leaf isn't present (single node)
            dist += (targetLevel - level+1);
        mindist = min (mindist,dist);
        return true;
    }
    if(findMinDistance(root->right,target, level+1, targetLevel, mindist)){
       
        int dist = calculateDownDistance(root->left); // dont add a number to INT_MAX, it will become negative.
        if (dist != INT_MAX) // that means leaf isn't present (single node)
            dist += (targetLevel - level+1);
        mindist = min (mindist,dist);
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
      10     100
      /  \    /\
      5   20 60 150
           \
           30
             \
              2
               \
                1
                 \
                  11
                   \
                    12
     */
    Node *root = getNode(50);
    
    root->left = getNode(10);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->right->right = getNode(30);
    root->left->right->right->right = getNode(2);
    root->left->right->right->right->right = getNode(1);
    root->left->right->right->right->right->right = getNode(11);
    root->left->right->right->right->right->right->left = getNode(12);
    
    root->right = getNode(100);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    
    
    int level = 0, targetLevel = 0, target = 10, mind=0;
    findMinDistance(root, target, level, targetLevel, mind);
    cout << "Closest leaf to the given node is: " << mind << endl;
    
    /*********************TEST2*********************************/
     /*
         50
         /  \
       10     100
          \    /\
          20 60 150
            \
            30
            \
             2
             \
             1
              \
              11
                \
                12
     */
    root = getNode(50);
    
    root->left = getNode(10);
    root->left->right = getNode(20);
    root->left->right->right = getNode(30);
    root->left->right->right->right = getNode(2);
    root->left->right->right->right->right = getNode(1);
    root->left->right->right->right->right->right = getNode(11);
    root->left->right->right->right->right->right->left = getNode(12);
    
    root->right = getNode(100);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    
    
    level = 0, targetLevel = 0, target = 10, mind=0;
    findMinDistance(root, target, level, targetLevel, mind);
    cout << "Closest leaf to the given node is: " << mind << endl;
    /*********************TEST3*********************************/
    level = 0, targetLevel = 0, target = 50, mind=0;
    findMinDistance(root, target, level, targetLevel, mind);
    cout << "Closest leaf to the given node is: " << mind << endl;
    return 0;
}

