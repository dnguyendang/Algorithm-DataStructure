#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

void BubbleSort(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        bool flag = false; // check xem con su thay doi nao khong 
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j], arr[j+1]);
                count++;
                flag = true;
            }
        }
        if(!flag) break;
    }
    cout << "Count = " << count << endl;
}

void display(int arr[], int n){
    cout << "arr: " << endl;
    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main(){
    int arr[18] = {6,2,3,5,6,8,7,4,9,1,3,5,7,2,3,6,3,5};
    BubbleSort(arr, 18);
    display(arr, 18);
    return 0;
}

