#include <iostream>
using namespace std;

// sử dụng khi lưu trữ, truy xuất chuỗi dữ liệu có tính liên tục ở trong bộ nhớ 
// khi cân IO buffer
// search table 
// kieu du lieu tra ve 

// Do phuc tap 
//             Dynamic Array         Static Array 
//Access        O(1)                    O(1)
//Search        O(n)                    O(n)
//insertion     O(n)                    N/A
//appending     O(1)                    N/A
//delete        O(n)                    N/A

// Operator insert element
// LA is an linear array with N elements and K is a positive integer satisfying K <= N
// insert element A into the K-th position of LA array 
//algorithm:
// 1. start 
// 2. assign j = n 
// 3. assign n = n + 1 
// 4. repeat step 5 and 6 when j >= k 
// 5. assign LA[j+1] = LA[j]
// 6. assign j = j - 1
// 7. assign LA[k] = item 
// 8. end 
//code:
void insertElement(int arr[], int& n, int k, int item){
    int j = n;
    n++;
    while(j >= k){
        arr[j+1] = arr[j];
        j--;
    }
    arr[k] = item;
}

void showArray(int arr[], int n){
    for (int i = 0; i < n; i ++){
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

// Operator delete element 
// delete element at the k-th position of LA array
//algorithm:
// 1. start
// 2. assign j = k
// 3. repeat step 4 and 5 when j < n 
// 4. assign LA[j] = LA[j+1]
// 5. assign j = j + 1 
// 6. assign n = n - 1
// 7. end
// code:

void deleteElement(int arr[], int& n, int k){
    int j = k;
    while(j < n){
        arr[j] = arr[j+1];
        j++;
    }
    --n;
}

// Operator search element
// search element item 
//algorithm 
// 1. start
// 2. assign j = 0
// 3. repeat step 4 and 5 when j < n
// 4. if LA[j] == item -> go to step 6
// 5. assign j = j + 1
// 6. print j and item 
// 7. end
//code:

void searchElement(int arr[], int n, int item){
    for(int i = 0; i < n; i++){
        if(arr[i]==item){
            cout << "Found item: " << item << " at the " << i <<"-th position of array" << endl;
        }
    }
}

void searchFirstItem(int arr[], int n, int item){
    int j = 0;
    while (j < n){
        if (arr[j] == item){
            break;
        }
        j++;
    }
    cout << "Found fisrt item: " << item << " at the " << j <<"-th position of array" << endl;
}

// Operator update element
// update value of element at the k-th position of array
//algorithm
// 1. start
// 2. assign LA[k-1] = item
// 3. end
//code

void updateElement(int arr[], int n, int k, int item){
    LA[k-1] = item;
}

int main(){
    int n = 5;
    int LA[] = {1,3,5,7,9};
    int item = 10;
    int k = 3;

    //show original array
    cout << "Element list of original array: " << endl; 
    showArray(LA, n);

    // delete 1 element
    deleteElement(LA, n, k);
    cout << "Element list after delete element: " << endl;
    showArray(LA, n);

    // insert 1 element
    insertElement(LA, n, k, item);
    cout << "Element list after insert element: " << endl;
    showArray(LA, n);

    // search item 
    searchElement(LA, n, item);
    // search fisrt item 
    searchFirstItem(LA, n, item);

    // update element 
    updateElement(LA, n, k, item);

    

    return 0;
}

