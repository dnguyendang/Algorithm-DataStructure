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
            cout<< current->data << " ";
        cout << endl;
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

// in-order traversal 
// cây con bên trái được truy cập đầu tiên, sau đó là nút gốc và sau đó là cây con bên phải.
// Nếu một cây nhị phân được duyệt trung thứ tự, kết quả tạo ra sẽ là các giá trị khóa được sắp xếp theo thứ tự tăng dần
void inorder_traversal(struct node* root){
    if(root != NULL){
        inorder_traversal(root->leftChild);
        cout << root->data << " ";
        inorder_traversal(root->rightChild);
    }
}

// pre-order traversal 
// nút gốc được duyệt đầu tiên, sau đó sẽ duyệt cây con bên trái và cuối cùng sẽ duyệt cây con bên phải
void pre_order_traversal(struct node* root){
    if(root != NULL){
        cout << root->data << " ";
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

// post-order traversal
// nút gốc của cây sẽ được truy cập cuối cùng, do đó bạn cần chú ý
void post_order_traversal(struct node* root){
    if(root != NULL){
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        cout << root->data << " ";
    }
}

// check main
int main() {
    int i;
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(i = 0; i < 7; i++)
        insert(array[i]);

    i = 31;
    struct node * temp = search(i);

    if(temp != NULL) {
        cout << "Da tim thay phan tu: " <<  temp->data << endl;
    }else {
        cout << "Khong tim thay phan tu: " <<  i << endl ;
    }

    i = 15;
    temp = search(i);

    if(temp != NULL) {
        cout << " Da tim thay phan tu: " <<  temp->data << endl;
    }else {
        cout << "Khong tim thay phan tu: " <<  i << endl ;
    }     

    cout << "Cach duyet tien thu tu: ";
    pre_order_traversal(root);
    cout << endl;

    cout << "Cach duyet trung thu tu: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Cach duyet hau thu tu: ";
    post_order_traversal(root);       
    cout << endl;

    return 0;
}