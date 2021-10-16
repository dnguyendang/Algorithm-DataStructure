#include<iostream>
using namespace std;

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

Stack* createStack(unsigned capacity){
    struct Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int (stack->capacity);
    return stack;
}

int Full(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int Empty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item){
    if(Full(stack)){
        return;
    }
    stack->array[++stack->top] = item;
    cout << item << " pushed to stack" << endl;
}

int pop(Stack* stack){
    if(Empty(stack)){
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if(Empty(stack)){
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main()
{
    Stack* stack = createStack(100);
 	cout << peek(stack) << endl;
    push(stack, 14);
    push(stack, 25);
    push(stack, 38);
    push(stack, 48);
 
    cout << pop(stack) << " popped from stack" << endl;
 
    cout << "Top item is " << peek(stack) << endl;
 
    return 0;
}