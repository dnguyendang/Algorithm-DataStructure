#include<iostream>
using namespace std;

// Doubly Linked List can be preformed in two directions: forward and backward
// Link - each link can contain a data be called element
// Next - each link can contain a link to next link be called Next
// Prev - each link can contain a link to previous link be can Prev
// First and Last - a Doubly Linked List consisting link connected to first link be called First ad to last link be called Last 

struct node{
    int data;
    int key;

    struct node* next;
    struct node* prev;
};

// this link always points to first link
struct node* head = NULL;

// this link always points to last link
struct node* last = NULL;

struct node* current  = NULL;

// check list is empty or not
bool isEmplty(){
    return head == NULL;
}

int length(){
    int length = 0;
    struct node* current;

    for(current = head; current != NULL; current = current->next){
        length++;
    }

    return length;
}

// show list from first to last 
void displayForwardList(){
    struct node* ptr = head;
    cout << "[ "; 

    while (ptr != NULL){
        cout << "(" << ptr->key << "," << ptr->data << ") ";
        ptr = ptr->next;
    }

    cout << "]" << endl;
}

// show list from last to first
void displayBackWardList(){
    struct node* ptr = last;
    cout << "[ ";

    while(ptr!= NULL){
        cout << "(" << ptr->key << "," << ptr->data << ") ";
        ptr = ptr->prev;
    }

    cout << "]" << endl;
}

// insert link at the fisrt position 
void insertFirst(int key, int data){
    // create a link 
    struct node* link = new node();
    link->key = key;
    link->data = data;

    if(isEmplty()){
        // make it last link
        last = link;
    }else{
        // update prev old fisrt link
        head->prev = link; 
    }

    //point to old first link
    link->next = head;

    //point first to new first link (first != first link)
    head = link;
}

// insert link at the last position
void insertLast(int key, int data){
    struct node* link = new node();
    link->key = key;
    link->data = data;

    if(isEmplty()){
        last = link;
    }else{
        last->next = link;
        link->prev = last;
    }

    last = link;
}

// delete first element
struct node* deleteFirst(){
    // reference to first link
    struct node* tempLink = head;

    // if have only one link 
    if(head->next == NULL){
        last = NULL;
    }else{
        head->next->prev = NULL; 
    }

    head = head->next;
    return tempLink;
}

// delete last link
struct node* deleteLast(){
    struct node* tempLink = last;

    if(head->next == NULL){
        head = NULL;
    }else{
        last->prev->next = NULL;
    }

    last = last->prev;
    return tempLink;
}

// delete link by known key 
struct node* deleteLinkByKey(int key){
    struct node* current = head;
    struct node* previous = NULL;

    if(head == NULL){
        return NULL;
    }

    while(current->key != key){
        if(current->next == NULL){
            return NULL;
        }else{
            previous = current;
            current = current->next;
        }
    }

    // update link

    // chieu next
    if(current == head){
        //change first to point to next link 
        head = head->next;
    }else{
        // skip current link
        current->prev->next = current->next;
    }

    // chieu prev 
    if(current == last){
        last = current->prev;
    }else{
        current->next->prev = current->prev;
    }

    return current;
}

bool insertAfter(int key, int newKey, int data){
    struct node* current = head;

    if(head == NULL){
        return false;
    }
    
    //iterate list
    while(current->key != key){
        // if it's last node
        if(current->next == NULL){
            return false;
        }else{
            //move on next link
            current = current->next;
        }
    }

    // create link 
    struct node* newLink = new node();
    newLink->key = newKey;
    newLink->data = data;

    if(current == last){
        newLink->next = NULL;
        last = newLink;
    }else{
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;
    return true;
}

//check 
int main(){

    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56); 

    cout << "In danh sach (First ---> Last): " << endl;  
    displayForwardList();
	

    cout << "In danh sach (Last ---> first): " << endl; 
    displayBackWardList();

    cout << "Danh sach, sau khi xoa ban ghi dau tien: " << endl;
    deleteFirst();        
    displayForwardList();

    cout << "Danh sach, sau khi xoa ban ghi cuoi cung: " << endl;  
    deleteLast();
    displayForwardList();

    cout << "Danh sach, chen them phan tu sau key(4): " << endl;  
    insertAfter(4,7, 13);
    displayForwardList();

    cout << "Danh sach, sau khi xoa key(4) : " << endl;  
    deleteLinkByKey(4);
    displayForwardList();
    
    return 0;
}
