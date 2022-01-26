#include<iostream>
using namespace std;

// bai toan 8 con hau - 8 queens
#define N 8

void display(int arr[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int arr[][N], int row, int col){
    int i, j;
    // check if any queen existing in this row 
    for (i = 0; i < col; i++){
        if(arr[row][i] == true){
            return false;
        }
    }
    // upper left
    i = row; j = col;
    while( i >= 0 && j >= 0){
        if(arr[i][j] == true)
            return false;
        --i;
        --j;
    }

    // bottom left 
    i = row; j = col;
    while( i <= N && j >= 0){
        if(arr[i][j] == true)
            return false;
        --j;
        ++i;
    }
    return true;
}

bool setQueen(int arr[][N], int col){
    if(col >= N)
        return true;
    for(int i = 0; i < N; i++){
        if(isValid(arr, i, col)){
            arr[i][col] = 1; // put 
            if (setQueen(arr, col+1))
                return true;
            arr[i][col] = 0; // back 
        }
    }
    return false;
}

int main(){
    int arr[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = 0;
        }
    }
    if(setQueen(arr, 0))
        display(arr);
    else
        cout << "No solution!" << endl;

    return 0;
}