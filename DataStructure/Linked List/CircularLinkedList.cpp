#include<iostream>
using namespace std;

// Circular Linked List where first element points to last element and lst element points to first element 

struct node{
    int data;
    int key;

    struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

bool isEmpty(){
    return head == NULL;
}

int length(){
    int length = 0;

    if(head == NULL){
        return 0;
    }

    current = head->next;

    while(current != head){
        length++;
        current = current->next;
    }

    return length;
}

// insert link at the first position 
void insertFirst(int key, int data){
    struct node* link = new node();
    link->key = key;
    link->data = data;

    if(isEmpty()){
        head = link;
        head->next = head;
    }else{
        link->next = head;
        head = link;
    }
}

// delete first link
struct node* deleteFirst(){
    struct node* tempLink = head;

    if(head->next == head){
        head = NULL;
        return tempLink;
    }

    head = head->next;
    return tempLink;
}

// show list 
void displayList(){
    struct node* ptr = head;

    cout << "[ ";

    if(head != NULL){
        while(ptr->next != ptr){
            cout << "(" << ptr->key << "," << ptr->data << ") ";
            ptr = ptr->next;
        }
    }

    cout << "] " << endl;
}

// check 
int main(){

    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56); 

    cout << "Danh sach ban dau: " << endl;  
    displayList();
 
    while(!isEmpty()){            
       struct node *temp = deleteFirst();
       cout << "Gia tri bi xoa:" << endl;  
       cout << "(" << temp->key << "," << temp->data << ")" << endl;        
    }   
	
    cout << "Danh sach sau khi da xoa tat ca phan tu: " << endl;          
    displayList();   
    return 0;
}