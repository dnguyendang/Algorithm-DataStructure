#include<iostream>
using namespace std;
//O(log(logn))

int InterpolationFind(int arr[], int n, int data){
    int lowerBound = 0;
    int upperBound = n-1;
    int midPoint = - 1; 
    int comparation = 0;
    // int index = - 1;
    while(lowerBound <= upperBound){
        comparation++;
        midPoint = lowerBound + (((double)(upperBound - lowerBound)/(arr[upperBound] - arr[lowerBound]))*(data - arr[lowerBound]));

        if(arr[midPoint] == data){
            cout << "comparation: "  << comparation << endl;
            return midPoint;
        }else{
            if(arr[midPoint] < data)
                lowerBound = midPoint + 1;
            else 
                upperBound = midPoint - 1;
        }
    }

    return -1;
}

void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {0,5,6,8,9,14,26,45,78,96};
    int item;
    cout << "Select your number you want to find: ";
    cin >> item;

    int index = InterpolationFind(arr, 10, item);
    if(index == -1)
        cout << "Cannot find out your number!" << endl;
    else
        cout << "Index of the number: " << index << endl;

    return 0;
}