#include<iostream>
using namespace std;
// Heap la 1 truong hop dac biet cua ctdl cau nhi phan can bang 
// khoa cua nut goc duoc so sanh voi cac con cua no va duoc sap xep 1 cach phu hop 
// minHeap , maxHeap

int size = 0;

void swap_node(int* a, int* b){
    int c = *b;
    *b = *a;
    *a = c;
}

// tao cau truc Heap - heapify 
// max-heap
void heapify_tree(int arr[], int size, int i){
    if(size == 1){
        cout << "There is only element in tree" << endl;
    }else{
        int biggest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < size && arr[l] > arr[biggest])
            biggest = l;
        if(r < size && arr[r] > arr[biggest])
            biggest = r;
        if(biggest != i){
            swap_node(&arr[i], &arr[biggest]);
            heapify_tree(arr, size, biggest);
        }
    }
}

void add_node(int arr[], int new_data){
    if(size == 0){
        arr[0] = new_data;
        size += 1;
    }else{
        arr[size] = new_data;
        size += 1;
        for(int i = size/2 - 1; i >= 0; i--){
            heapify_tree(arr, size, i);
        }
    }
}

void remove_node(int arr[], int data){
    int i;
    for(i = 0; i < size; i++){
        if (data == arr[i])
            break;
    }
    swap_node(&arr[i], &arr[size-1]);
    size -= 1;
    for(int i = size/2 - 1; i >= 0; i--){
        heapify_tree(arr, size, i);
    }
}

void peek(int arr[]){
    cout << "Max value of tree: " << arr[0] << endl;

}

void display(int arr[], int size){
    for( int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
  int arr[10];
  add_node(arr, 4);
  add_node(arr, 6);
  add_node(arr, 10);
  add_node(arr, 7);
  add_node(arr, 3);
  cout << "Max-Heap: ";
  display(arr, size);
  remove_node(arr, 4);
  display(arr, size);
  peek(arr);
  return 0;
}

// Heap được sử dụng trong khi triển khai hàng đợi ưu tiên.
// Được sử dụng trong thuật toán Dijkstra
// Được sử dụng trong thực hiện sắp xếp đống (Heap sort).
// Heap chỉ cung cấp khả năng truy cập dễ dàng vào các phần tử nhỏ nhất hoặc lớn nhất. Tìm các phần tử khác trong Heap sẽ mất O(n) thời gian vì Heap không được đặt theo thứ tự

