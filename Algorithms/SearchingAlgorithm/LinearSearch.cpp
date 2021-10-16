#include<iostream>
using namespace std;
//Divide and Conquer - O(n)
int LinearFind(int arr[],int n, int data ){
    int comparation = 0; // count number;
    // int index = -1;
    for(int i = 0; i < n; i++){
        comparation++;
        if(arr[i] == data){
            cout << "Comparation : " << comparation << endl;
            // index = i;
            return i;
        }
    }

    cout << "Comparation : " << comparation << endl;
    // return index;
    return -1;
}

void display(int arr[],int n){
    cout << "Array: " ;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {2,3,6,5,4,7,8,9,3,4};
    int index = -1;
    int item;
    cout << "The number you want to find: ";
    cin >> item;

    index = LinearFind(arr,10, item);
    if(index == -1 )
        cout << "Cannot find out your number!" << endl;
    else
    cout << "Index of the number is " << index << endl;

    return 0;
}

