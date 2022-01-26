// root - is a sequence of nodes along with the edges of a tree
// root node - the top node of the tree. 
// A tree will have only one root node and a path from the root to any other node. The root node is the only node that does not have any parent nodes.
// parent node - any node except the root node that has an edge pointing up another node
// child node - the node below a given node connected by its bottom edge 
// leaf node - doesn't have any child node 
// sub-tree 
// siblings 

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* root = NULL;

void insert(int data){
    struct node* tempNode = new node();
    struct node* current;
    struct node* parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if(root == NULL){
        root = tempNode;
    }else{
        current = root;
        parent = NULL;
        while(1){
            parent = current;

            //move on left tree
            if(data < parent->data){
                current = current->leftChild;
                //insert 
                if(current == NULL){
                    parent->leftChild = tempNode;
                    return;
                }
            }else{ // move on right tree
                current = current->rightChild;
                //insert
                if(current == NULL){
                    parent->rightChild = tempNode;
                    return;
                }
            }    
        }
    }
}

struct node* search(int data){
    struct node* current = root;
    cout << "access elements of tree" << endl;

    while(current->data != data){
        if(current != NULL)
            cout<< current->data;
        
        // move on left tree
        if(current->data > data){
            current = current->leftChild;
        }else{ // move on right tree
            current = current->rightChild;
        }

        // con not find 
        if(current == NULL){
            return NULL;
        }
    }
    
    return current;
}