#include<iostream>
using namespace std;

int fibonaccy(int n, int a, int b){
    if(n == 2){
        cout << a << " ";
        cout << b << " ";
        cout << endl;
        return b;
    }
    cout << a << " ";
    return fibonaccy(n-1, b, a+b);
}

int main(){
    int n;
    cout << " select n: ";
    cin >> n;
    int f = fibonaccy(n, 0, 1);
    cout << "the value of n-th element of fibonaccy: " << f;
    return 0;
}