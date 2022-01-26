#include<iostream>
using namespace std;

// based on insertion sort

void shellSort(int arr[], int n){
    int inner, outer;
    int valueToInsert;
    int interval = 1;   
    int elements = n;
    
    while(interval <= elements/3) {
        interval = interval*3 +1;                   
    }

    while(interval > 0) {
        for(outer = interval; outer < elements; outer++) {
            valueToInsert = arr[outer];
            inner = outer;

            while(inner > interval -1 && arr[inner - interval] 
                >= valueToInsert) {
                arr[inner] = arr[inner - interval];
                inner -=interval;
            }

            arr[inner] = valueToInsert;
        }

        interval = (interval -1) /3;           
    }          
}

void display(int arr[], int n){
    cout << "arr: " << endl;
    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main(){
    int arr[20] = {5,6,3,2,4,8,9,6,7,5,2,1,4,5,2,4,9,6,3,0};
    shellSort(arr, 20);
    display(arr, 20);
    return 0;
}