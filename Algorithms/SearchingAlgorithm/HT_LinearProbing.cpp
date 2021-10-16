#include<iostream>
using namespace std;

// the index space must be made so that there is always room for the new element 

string hashTable[20];
int hashTableSize = 20;

int hashFunc(string s){
    int sum = 0;
    for(int i = 0 ; i < s.length() ; i++){
        sum += s[i];
    }
    return sum % hashTableSize;
}

void insert (string s){
    // compute the index using the hash function
    int index = hashFunc(s);
    //search for an unused slot and if the index will exceed the hash table then roll back 
    while(hashTable[index] != ""){
        index = (index + 1) % hashTableSize;
    }
    hashTable[index] = s;
}

void search(string s){
    //compute the index using the hash hunction
    int index = hashFunc(s);
    //search for an unused slot and if the index will be exceed the hashtablesize then roll back
    while(hashTable[index] != s and hashTable[index] != "")
        index = (index + 1) % hashTableSize;
    //check if the element is present in the hash table 
    if(hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;    

}

void display(){
    for(int i = 0 ; i < hashTableSize; i++){
        cout << i << " :  " << hashTable[i] << endl;
    }
}

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