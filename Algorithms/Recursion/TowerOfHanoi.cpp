#include<iostream>
#include<vector>
using namespace std;

// 2 thuoc tinh can phai nho cua ham de qui:
// dieu kien co ban: phai co it nhat 1 dieu kien de khi ma gap dieu kien nay thi viec goi chinh ham do (goi de qui) se dung lai
// tiem can: moi khi ham de qui duoc goi thi no cang tiem can toi dieu kien co ban 
// ham goi - caller , ham duoc goi - callee 

//rule
// Only one disk may be moved at a time.
// Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
// No disk may be placed on top of a disk that is smaller than it.

// A - source
// B - auxiliary
// C - destination 

/* Bai toan thap HN */
#include<iostream>
using namespace std;
void Tower(int n , char a, char b, char c ){
    if(n==1){
        cout<<"\t"<<a<<"->"<<c<<endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
    }
int main(){
    char a='A', b='B', c='C';
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Tower(n,a,b,c);
}