#include<iostream>
#include<vector>
using namespace std;

//Separate Chaining (open hashing) - usually implemented with linked lists
// -> if a collision occurs, the molecules will be in the same linked list 
// 0   -> item -> item 
// 1   
// 2   -> item
// 3
// 4   -> item -> item -> item     
// 5
// 6   -> item 
// 7   -> item
// 8
// 9   -> item -> item 
// .
// .

vector <string> hashTable[20];
int hashTableSize = 20;

// hash function
int hashFunc(string s){
    int sum;
    for ( int i = 0 ; i < s.length() ; i++){
        sum += s[i];
    }
    return sum % hashTableSize;
}

// insert to hashTable
void insert(string s){
    //compute the index using hash function
    int index = hashFunc(s);
    //insert the element in the linked list at the particular index 
    hashTable[index].push_back(s);
}

// search element 
void search(string s){
    //compute the index by using the hash function
    int index = hashFunc(s);
    //search the linked list at that specific index
    for(int i = 0; i < hashTable[index].size(); i++){
        if(hashTable[index][i] == s){
            cout << s << " is found!" << endl;
            return;
        }
    }
    cout << s << " is not found!" << endl;
} 

void display(){
    for(int i = 0; i < hashTableSize; i ++){
        cout << i << " :  "; 
        for(int j = 0; j < hashTable[i].size() ; j++){
            cout << hashTable[i][j] << "  ";
        }
        cout << endl;
    }
}

// check 
int main(){
    insert("dung");
    insert("phuong");
    insert("duong");
    insert("thanh");
    insert("son");
    insert("chung");
    insert("tuan");
    insert("thu");

    search("minh");
    search("thanh");

    display();

    return 0;
}


