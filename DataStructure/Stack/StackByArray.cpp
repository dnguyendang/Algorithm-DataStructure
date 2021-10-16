#include<iostream>
using namespace std;

// Stack - is an abstract data structure (Abstract Data Type - ADT).
// The stack abstract data structure allows only data manipulations at the top position.
// At any given time, we can only access the top element of the stack. 
// data structure dang LIFO (Last-In-First-Out) 
// insert -> PUSH and delete -> POP 

// Một ngăn xếp có thể được triển khai theo phương thức 
//của Mảng (Array), Cấu trúc (Struct), Con trỏ (Pointer) và Danh sách liên kết (Linked List)

//chung ta luon duy tri 1 con tro toi phan tu du lieu vua duoc push cuoi cung vao tren ngan xep
// con tro nay luon bieu dien vi tri tren cung cua ngan xep nen co ten la top.

int MAXSIZE = 8;
int stack[8];
int top = -1;

// peek() - lay phan tu du lieu o tren cung cua ngan xep ma khong xoa phan tu nay di 
int peek(){
    return stack[top];
}

// isFull() - kiem tra xem ngan xep da day hay chua 
bool isFull(){
    if(top == MAXSIZE){
        return true;
    }else{
        return false;
    }
}

// isEmpty() - kiem tra xem  ngan xep co trong hay khong
bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

// operator PUSH 
//algorithm 
// 1. start
// 2. check stack is full or not
// 3. if stack is full, -> skip to step 6
// 4. if not, increase top to point next free memory 
// 5. add element data to new memory which pointer top pointing on stack 
// 6. end
//code
void push(int data){
    if(!isFull()){
        top++;
        stack[top] = data;
    }else{
        cout << "Cann't insert more data bcs Stack is full." << endl;
    }
}

// operator POP
//algorithm
// 1. start
// 2. check stack is full or not
// 3. if stack is full, -> skip to step 6
// 4. if not, access element data at top pointing to 
// 5. decrease top -1  
// 6. end
//code
int pop(){
    int data; 

    if(!isEmpty()){
        data = stack[top];
        top--;
        return data;
    }else{
        cout << "Cann't get data bcs Stack is empty." << endl;
        return 0;
    }
}

//check 
int main(){
// chen cac phan tu vao ngan xep
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   cout << "Phan tu tai vi tri tren cung cua ngan xep: " << peek() << endl;
   cout << "Cac phan tu: " << endl;

   // in cac phan tu trong stack 
   while(!isEmpty()){
       int data = pop();
       cout << data << endl;
   }

   cout << "Ngan xep da day: " << isFull()?"true":"false";
   cout << endl;
   cout << "Ngan xep la trong: " << isEmpty()?"true":"false";

   return 0;
}

// application
// - Tinh gia tri bieu thuc, xu ly ngat 
