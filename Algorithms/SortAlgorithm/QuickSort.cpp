#include<iostream>
using namespace std;

// O(nlogn)

void swap(int& a, int& b){
    int temp = a;
    a = b; 
    b = temp;
}

int partition (int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }    
    }
    swap(arr[++i], arr[right]);
    return i;
}

void QuickSort(int arr[], int left, int right){
    if(left < right){
        int midPoint = partition(arr, left, right);
        QuickSort(arr, left, midPoint - 1);
        QuickSort(arr, midPoint + 1, right);
    }
}

void display(int arr[], int n){
    cout << "arr: " << endl;
    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main(){
    int arr[20] = {15,26,45,35,12,45,15,12,65,78,45,12,48,65,25,35,95,48,75,15};
    QuickSort(arr, 0, 19);
    display(arr, 20);
    return 0;
}




