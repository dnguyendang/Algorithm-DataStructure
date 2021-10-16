#include<iostream>
using namespace std;

// Linear Probing 
//key       Hash         index      index after technique LinearProbing
// 1       1%20 = 1        1                 1
// 2       2%20 = 2        2                 2
// 42      42%20 = 2       2                 3
// 4       4%20 = 4        4                 4
// 12      12%20 = 12      12                12
// 14      14%20 = 12      14                14
// 17      17%20 = 17      17                17
// 13      13%20 = 13      13                13
// 37      37%20 = 17      17                18

#define SIZE 20

struct DataItem{
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
    return key%SIZE;
}

struct DataItem* search(int key){
    //lay gia tri hash
    int hashIndex = hashCode(key);

    //di chuyen trong mang cho toi khi gap 1 o trong (empty cell)
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];
        //di chuyen toi o tiep theo 
        ++hashIndex;
        //bao quanh hashtable
        hashIndex %= SIZE;
    } 

    return NULL;
}

void insert (int key, int data){
    struct DataItem* item = new DataItem();
    item->data = data;
    item->key = key;

    //lay gia tri hash
    int hashIndex = hashCode(key);

    //di chuyen trong mang cho toi khi gap mot o trong (empty cell) hoac o bi xoa 
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        //di chuyen toi o tiep theo
        ++hashIndex;
        //bao quanh hash table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;

}

struct DataItem* deleteItem(struct DataItem* item){
    int key = item->key;

    //lay gia tri hash
    int hashIndex = hashCode(key);

    //di chuyen trong mang toi khi gap mot o trong (empty cell)
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == key){
            struct DataItem* temp = hashArray[hashIndex];

            //gan mot phan tu gia tai vi tri bi xoa 
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        // di chuyen toi o tiep theo 
        ++ hashIndex;
        // bao quanh hash table 
        hashIndex %= SIZE;
    }
    return NULL;
}

void display(struct DataItem* hashArray[]){
    for(int i = 0; i < SIZE; i++){
        if (hashArray[i] != NULL)
            cout << i << " : " << hashArray[i]->key << "  " << hashArray[i]->data << endl;
        else 
            cout << i << " : " << "~  ~" << endl;
    }
}

int main(){
    dummyItem = new DataItem();
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display(hashArray);

    item = search(37);

    if(item != NULL){
        cout << "Tim thay phan tu: " << item->data << endl;
    }else{
        cout << "Khong tim thay phan tu." << endl;
    }

    item = deleteItem(item);
    display(hashArray);

    insert(37, 97);
    display(hashArray);

    insert(33,77);
    display(hashArray);

    // insert(-1, 0);
    // display(hashArray);

    return 0;
}


// application 
//map set trong c++ la nhung mang bam cuc ki huu dung 
// multimap va multiset trong c++ cho phep luu tru key trung nhau voi gia tri khac nhau -> xu ly va cham da duoc thiet lap 
// voi cac bai toan dac thu -> se can phai tu viet ham bam va xay dung cau truc du lieu bang bam phu hop
// + Associatetive array
// + lap chi muc CSDL
// + caches
// + bieu dien cac doi tuong -> su dung bang bam de trien khai cac doi tuong
// + su dung trong cac thuat toan khac nhau de tang toc do tinh toan 

