#include<iostream>
using namespace std;

// Linked List is a data structure with a group of nodes which create a chain. 
// Each node contains data at that node and a reference to the next node in the chain.
// Link - each node of linked list can contain 1 data be called 1 element.
// Next - each node of linked list contain 1 link to the next node be called Next
// First - 1 linked list consisting of nodes link to the first node is called First

struct node 
{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// Display Linked List 
void displayList()
{
    struct node *ptr = head;
    cout << "[ ";
    // start from fisrt node 
    while(ptr != NULL)
    {
        cout << "(" << ptr->key << "," << ptr->data << ") ";
        ptr = ptr->next;
    }
    cout << " ]" << endl;
}

// insert link at the first position 
void insertFirst(int key, int data)
{
    // create a link 
    struct node* link = new node();

    link->key = key;
    link->data = data;

    // point this link to old first node
    link->next = head;

    // point first to new first node
    head = link;
}

// delete fisrt link 
struct node* deleteFirst()
{
    // reference to first link
    struct node* tempLink = head;

    // mark next to first link is first 
    head = head->next;

    //return link was deleted 
    return tempLink;

    // tempLink->next is still pointing to new first link bcs we have deleted it 
}

// check list is empty or not.
bool isEmpty()
{
    return head == NULL;
}

// reutrn length of list 
int length()
{
    int length = 0;
    struct node* current;
    for(current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

// search the link by known key
struct node* findLinkByKey(int key)
{
    //start from fisrt link
    struct node* current = head;

    // if list is empty 
    if(head == NULL)
    {   
        return NULL;
    }

    // iterate over each link
    while(current->key != key)
    {
        // if this is last link 
        if(current->next == NULL)
        {
            return NULL;
        }
        else
        {
            //move to next link 
            current = current->next;
        }
    }

    return current;
}

// delete the link by known key
struct node* deleteLinkByKey(int key)
{
    struct node* current = head;
    struct node* previous = NULL;

    if(head == NULL)
    {
        return NULL;
    }

    //iterate list 
    while(current->key != key)
    {
        if(current->next == NULL)
        {
            return NULL;
        }
        else{
            previous = current;
            current = current->next;
        }
    }

    // update link 
    if(current == head) // if the link you wanna delete is the first link  
    {
        head = current->next;
    }
    else 
    {
        // skip current link
        previous->next = current->next; 
    }

    return current;
}

// sort function
void sortList()
{
    int tempKey, tempData;
    struct node* current;
    struct node* next;
    
    for (int i = 0; i < length(); i++)
    {
        current = head;
        next = head->next;

        for (int j = 1; j <length() - i; j++)
        {
            if(current->data > next->data)
            {
                tempData = current->data;
                current->data = next->data;
                next->data =tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}

// reverse list 
void reverseList(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// test program 
int main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   cout << "Danh sach ban dau: " << endl; 
   //print list 
   displayList();

   while(!isEmpty())
   {            
      struct node *temp = deleteFirst();
      cout << "Gia tri bi xoa:";  
      cout << "[" << temp->key << "," << temp->data << "]" << endl;        
   }  
	
   cout << "Danh sach sau khi da xoa gia tri: " << endl;          
   displayList();

   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 
   cout << "Phuc hoi danh sach: " << endl;  
   displayList();

   struct node* foundLink = findLinkByKey(4);
	
   if(foundLink != NULL)
   {
      cout << "Tim thay phan tu: ";  
      cout << "[" << foundLink->key << "," << foundLink->data << "]" << endl;  
   }
   else 
   {
      cout << "Khong tim thay phan tu." << endl;  
   }

   deleteLinkByKey(4);
   cout << "Danh sach, sau khi xoa mot phan tu: ";  
   displayList();

   foundLink = findLinkByKey(4);
	
   if(foundLink != NULL)
   {
      cout << "Tim thay phan tu: ";  
      cout << "[" << foundLink->key << "," << foundLink->data << endl;  
   }
   else 
   {
      cout << "Khong tim thay phan tu." << endl;
   }

   sortList();
   cout << "Danh sach sau khi duoc sap xep: " << endl;  
   displayList();
	
   reverseList(&head);
   cout << "Danh sach sau khi bi dao nguoc: " << endl;  
   displayList();

   return 0;
}