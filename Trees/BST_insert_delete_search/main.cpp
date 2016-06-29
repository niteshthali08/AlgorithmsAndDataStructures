#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
 author: Nitesh Thali
 BST implementation in c++ with insert, search and delete functionality.
 */
struct node {
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
};
node* getNode(int data)
{
    node *tmp = new node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    tmp-> data = data;
    return tmp;
}
void insert_data(node **root, node* z)
{
    // recursive insert
    if (*root == NULL)
    {
        //cout << "root is null";
        (*root) = z;
    }
    if(z->data < (*root)->data)
    {
        if((*root)->left == NULL)
        {
            (*root)->left = z;
            z->parent = (*root);
        }
        else
        {
            insert_data(&(*root)->left, z);
        }
    }
    if(z->data > (*root)->data)
    {
        if((*root)->right == NULL)
        {
            (*root)->right = z;
            z->parent = (*root);
        }
        else
        {
            insert_data(&(*root)->right, z); // important & this address of root->right (two level hop)
        }
    }
}
node* search_key(node **root,int key)
{
    if (*root == NULL || (*root)->data == key ){
        return (*root);
    }
    if ( key < (*root)->data ) {
        return search_key(&(*root)->left, key); // note return here very important. Because function has to return something at every stage.
    }
    else{
        return search_key(&(*root)->right, key);
    }
    
    
}
node* bst_minimum(node **root)
{
    while ((*root)->left !=NULL)
        root = &(*root)->left;
    return (*root);
}
node* bst_maximum(node **root)
{
    while ((*root)->right !=NULL)
        root = &(*root)->right;
    return (*root);
}
node* bst_successor(node *nodeToBeDeleted)
{	//finds suucessor of a node to be deleted. (just coded it)
    if (nodeToBeDeleted->right!= NULL)
        return (bst_minimum(&(nodeToBeDeleted->right)));
    
    node *y = nodeToBeDeleted->parent;
    while ( y !=NULL && nodeToBeDeleted == y->right)
    {
        nodeToBeDeleted = y;
        y = y->parent;
    }
    return y;
}
void transplant (node **root, node* u, node* v)
// replace tree rooted at u with that of v
{
    if(u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v)
        v->parent = u->parent;
}
void delete_key(node **root, int key)
{
    // have to handle the case when root == NULL
    node *max = bst_maximum(root);
    node *min = bst_minimum(root);
    //cout << max->data << " "<< min->data << endl;
    node *z = search_key(root, key);
    cout << "found node: " <<z->data << endl;
    node *y;
    if (z == NULL)
    {
        cout << "Key requested for deletion is not present in BST" << endl;
        return;
    }
    //actual deletion
    if (z->left == NULL)
    {
        //cout << "left is null" <<endl;
        transplant(root, z, z->right);
    }
    else if (z->right == NULL)
    {
        //cout<<"right is null" <<endl;
        transplant(root, z, z->left);
    }
    else
    {
        
        y = bst_minimum(&(z->right));
        //cout << "deleting node with successor value: "<<y->data<<" parent: " << y->parent->data << endl;
        if (y->parent != z)
        {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y; //important
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        //cout <<"root now: "<< (*root)->data <<endl;
        free(z);
    }
}
void traverse_inorder(node **root)
{
    if ( (*root) != NULL)
    {
        traverse_inorder(&(*root)->left); // like value, think of this as two level hop.
        cout << "->" << (*root)->data;
        traverse_inorder(&(*root)->right);
    }
}
int main(int argc, char const *argv[])
{
    int ch, data, key;
    node * root = NULL, *found, *z;
    while (1){
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Quit" << endl;
        cout << ":";
        cin >> ch;
        switch (ch)
        {
            case 1:
                //cout << "root: " << root;
                cout << "\nData: ";
                cin >> data;
                z = getNode(data);
                insert_data(&root, z);
                break;
            case 2:
                cout << "\nKey: ";
                cin >>key;
                found = search_key(&root, key);
                if (found == NULL)
                    cout << "Key not found in BST" << endl;
                else
                    cout << "key found in BST" << endl;
                break;
            case 3:
                cout << "\nKey: ";
                cin >> key;
                //cout << "calling delete function" <<endl;
                delete_key(&root, key);
                break;
            case 4:
                //cout << "root: "<< root;
                traverse_inorder(&root);
                cout << endl;
                break;
            case 5:
                exit(0);
                
        }
    }	
    return 0;
}