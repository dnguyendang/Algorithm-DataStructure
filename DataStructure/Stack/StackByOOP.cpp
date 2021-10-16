#include<iostream>
using namespace std;

#define Maxsize 10

class stacks{
    public:
    int Top = -1;
    int s[10];
    void push(int);
    void pop();
    void display();
};

void stacks::push(int x){
    if(Top==Maxsize){
        cout << "Error : cannot insert" << endl;
    }else{
        Top++;
        s[Top] = x;
    }
}

void stacks::pop(){
    if(Top<0){
        cout << "Error : cannot delete" << endl;
    }else{
        Top--;
        return;
    }
}

void stacks::display(){
    cout << "Stack: ";
    for(int i = Top; i >= 0 ; i--){
        cout << s[i];
    }
}

int main(){
    stacks S;
    int e;
    for(int i=0;i<5;i++)
    {
        cin>>e;
        S.push(e);
    }
    S.pop();
    S.display();
}