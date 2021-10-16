#include<iostream>
#include<stack>
using namespace std;

// input : ())(()(()())()()())())())(()()((())
// check thu tu xem dung ko 

//algorithm 
// 1. initialize stack S, i - index of expression 
// 2. repeat steps 3 4 5 when exp[i] != '/0'
// 3. if S empty and exp[i] == ')' -> wrong 
// 4. if exp[i] == '(' -> push on S
// 5. if exp[i] == ')' -> pop S
// 6. if stack is empty -> the precedence of expression is true 

bool checkPrecedence(char expression[]){
    stack<char> S;
    int i = 0;

    while(expression[i] != '\0'){
        if(S.empty() && expression[i] == ')'){
            return false;
        }
        if(expression[i] == '('){
            S.push('(');
        }
        if(expression[i] == ')'){
            S.pop();
        }
        i++;
    }
    if(!S.empty()){
        return false;
    }
    return true;
}

int main(){
    char A[30];
    cout << "Get expression: ";
    cin >> A;
    (checkPrecedence(A)) ? cout << "the precedence of expression is true." : cout << "the precedence of expression is wrong" << endl ;
    return 0;
}