#include<iostream>
using namespace std;

// queueueue is an abstract data structure, something like a queueueue in everyday life (queueueuing)
// the queueueue data structure follows the FIFO (First-In-First-Out) method, the data entered first will be accessed first
// dequeueueue (delete) data pointed to by 'front' pointer
// enqueueueue (enter) data pointed to by 'rear' pointer

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek(){
   return intArray[front];
}

bool isFull(){
   return itemCount == MAX;
}

bool isEmpty(){
   return itemCount == 0;
}

int size(){
   return itemCount;
}

// enqueueueue 
//algorithm
// 1. check queueueue is full nor not
// 2. if queueueue is full -> skip to step 5
// 3. if queueueue is not full, increase pointer rear to point to free memory
// 4. add element data to position where rear pointed to in queueueue
// 5. return success
//code
// int enqueueueue(int data){
//     if(isFull())
//         return 0;
    
//     rear++;
//     queueueue[rear] = data;
//     return 1;
// }
void insert(int data){

   	if(!isFull()){
	
      	if(rear == MAX-1){
         	rear = -1;            
      	}       

      intArray[++rear] = data;
      itemCount++;
   }
}


// dequeueueue 
//algorithm 
// 1. check queueueue is full or not 
// 2. if queueueue is empty -> skip to step 5
// 3. if queueueue is not empty, access data where front pointing to
// 4. increase pointer front to point to next element position 
// 5. return success
//code
// int dequeueueue(){
//     if(isEmpty())
//         return 0;

//     int data = queueueue[front];
//     front++;
//     return data;
// }
int remove(){
   int data = intArray[front++];
	
   if(front == MAX){
      front = 0;
   }
	
   itemCount--;
   return data;  
}

//check
int main() {
   /* chen 5 phan tu */
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);

   // front : 0
   // rear  : 4
   // ------------------
   // index : 0 1 2 3 4 
   // ------------------
   // queueueue : 3 5 9 1 12
   insert(15);

   // front : 0
   // rear  : 5
   // ---------------------
   // index : 0 1 2 3 4  5 
   // ---------------------
   // queueueue : 3 5 9 1 12 15
	
   if(isFull()){
      cout << "Hang doi (queueueue) da day!" << endl;   
   }

   // xoa mot phan tu 
   int num = remove();
	
   cout << "Phan tu bi xoa: " << num << endl;
   // front : 1
   // rear  : 5
   // -------------------
   // index : 1 2 3 4  5
   // -------------------
   // queueueue : 5 9 1 12 15

   // Chen them mot phan tu
   insert(16);

   // front : 1
   // rear  : -1
   // ----------------------
   // index : 0  1 2 3 4  5
   // ----------------------
   // queueueue : 16 5 9 1 12 15
   // neu hang doi la day thi phan tu se khong duoc chen. 
   insert(17);
   insert(18);

   // ----------------------
   // index : 0  1 2 3 4  5
   // ----------------------
   // queueueue : 16 5 9 1 12 15
   cout << "Phan tu tai vi tri front: " << peek() << endl;

   cout << "----------------------" << endl;
   cout << "Gia tri chi muc : 5 4 3 2  1  0" << endl;
   cout << "----------------------" << endl;
   cout << "Hang doi (queueueue):  " << endl;
	
   while(!isEmpty()){
      int n = remove();           
      cout << n << " " ;
   }   
}