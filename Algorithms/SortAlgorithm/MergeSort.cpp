#include<iostream>
using namespace std;

// based on divide and conquer
// O(nlogn)

void merging(int arr[], int b[], int low, int mid, int high) {
    int l1, l2, i;

    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if(arr[l1] <= arr[l2])
            b[i] = arr[l1++];
        else
            b[i] = arr[l2++];
    }

    while(l1 <= mid)    
        b[i++] = arr[l1++];

    while(l2 <= high)   
        b[i++] = arr[l2++];

    for(i = low; i <= high; i++)
        arr[i] = b[i];
}

void sort(int arr[], int b[], int low, int high) {
    int mid;
   
    if(low < high) {
        mid = (low + high) / 2;
        sort(arr, b, low, mid);
        sort(arr, b, mid+1, high);
        merging(arr, b, low, mid, high);
    }else { 
        return;
    }   
}

void display(int arr[], int n){
    cout << "arr: " << endl;
    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main(){
    int arr[20] = {5,4,8,6,9,7,4,2,3,5,1,4,8,6,3,2,4,5,16,4};
    int b[20];

    sort(arr, b, 0, 19);
    display(arr,20);

    return 0;
}