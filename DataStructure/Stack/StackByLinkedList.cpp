#include<iostream>
using namespace std;

struct Stack{
    int data; 
    Stack* next;
};

Stack* TOS = NULL;

void push(int value){
    Stack* new_node = new Stack();
    new_node->data = value;
    new_node->next = TOS;
    TOS = new_node;
}

void pop(){
    if(TOS == NULL){
        cout << "Stack is empty." << endl;
    }else{
        Stack* temp;
        temp = TOS;
        TOS = TOS->next;
        temp->next = NULL;
        delete temp;
    }
}

void display(){
    if(TOS == NULL){
        cout << "Stack is empty." << endl;
    }else {
        cout << "Top of stack is " << TOS->data << endl;

        if(TOS->next != NULL){
            cout << "Other Elements are: ";
            Stack* current = TOS->next;
            while(current){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
        push(i);
 
    display();
 
    for(int i = 0; i < 6; i++)
        pop();
 
    display();
 
    return 0;
}