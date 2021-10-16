#include<iostream>
#include<stack>
using namespace std;
// cac bieu thuc dai so duoc bieu dien duoi dang Trung to (Infix)
// de may tinh tinh duoc gia tri cua mot bieu thuc thi can bieu dien cac bieu thuc sang dang khac la Tien to () hoac Hau to (Postfix)

// Profix is an algorithm that is expressed by placing operatos after the operands

// Infix               Postfix
// A / B - C * D        A B / C D * -
// A / ( B - C * D )      A B C D * - / 
// A / ( B - C ) * D    A B C - / D * 

//code
// Consider the precedence of operators 
int precedence (char x){
    if (x == '('){
        return 0;
    }
    if (x == '+' || x == '-'){
        return 1;
    }
    if (x == '*' || x == '/' || x == '%'){
        return 2;
    }
    return 3;
}

//algorithm to convert form infix to postfix 
// 1. Initialize empty stack 
// 3. iterate loop from i = 1 to the end of infix:
// 4. if infix[i] is operand then put in postfix
// 5. if infix[i] is operator then push on stack S
// 6. if infix[i] is ")" then Pop of S (get value on top S) and put in postfix
// 7. get postfix 
//code 
void infixToPostfix (char infix[], char postfix[]){
    stack<char> S;
    int j = 0; // i - index of infix, j - index of postfix
    for(int i = 0; infix[i] != '\0'; i++){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }else{
            if(infix[i] == '('){
                S.push('(');
            }else{
                if(infix[i] == ')'){
                    while ( S.top() != '('){
                        postfix[j++] = S.top();
                        S.pop();
                    }
                }else{
                    while (precedence(infix[i]) <= precedence(S.top()) && !S.empty()){
                        postfix[j++] = S.top();
                        S.pop();
                    }
                    S.push(infix[i]);
                }
            }
        }
    }
    while(!S.empty()){
        postfix[j++] = S.top();
        S.pop();
    }
    postfix[j] = '\0';
}

//algorithm to calculate the value of the postfix expression
// duyet bieu thuc dang chuoi tu trai sang phai va dung ham isdigit de kiem tra
// 1. if operand then push on stack S
// 2. if operator then pop 2 operands from S then calculate value and push result back on S
// 3. repeat until the character \0 (ket thuc chuoi)
// 4. The final result is last remaining element on stack S
//code 
float Evaluate (char *Postfix){
    stack<char> S;
    char *p;
    float op1, op2, op3, result;
    p = &Postfix[0];

    while(*p != '\0'){
        while(*p == ' ' || *p == '\t'){
            p++;
        }
        if(isdigit(*p)){
            int num = 0;
            while(isdigit(*p)){
                num = num *10 + *p - 48;
                *p++;
            }
            S.push(num);
        }else{
            op1 = S.top();
            S.pop();
            op2 = S.top();
            S.pop();
            switch(*p){
            case '+': 
                result = op1 + op2;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '/':
                result = op2/op1;
                break;
            case '*':
                result = op2*op1;
                break;
            default:
                cout << "Invalid Operator" << endl;
                return 0;
            }
            S.push(result);
        }
        p++;
    }
    result = S.top();
    S.pop();
    return result;
}

// check

int main(){
    // char infix[] = "2+3*4/6+3-6";
    // char postfix[sizeof(infix)];
    // infixToPostfix(infix, postfix);
    // float result = Evaluate(&postfix[0]);
    // cout << result << endl;

    char B[50] = "2 3 4 + * 5 - 2 2 * +";
	// cout << "Infix : ";
	// cin >> A;
	// infixToPostfix(A, B);
	cout << "Postfix: " << B << endl;
	cout << "Equals is " <<  Evaluate(&B[0]) << endl;
    

	return 0;
}