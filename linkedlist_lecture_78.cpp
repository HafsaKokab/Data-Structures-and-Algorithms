
/*
-------------------
   linkedlist
-------------------


Linked List can grow or shrink dynamically at runtime by allocating memory using pointers.

*/
//-------------------------------------------------------
 //insertion of node at the start of linkedlist
//-------------------------------------------------------
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int value)
    {
        data=value;
        next=nullptr;
    }
};
int main() {
    node *head;
    head=nullptr;
    // head=new node(4);
    int arr[]={2,4,6,8,10};
    //insert the node at beginning

    //linked list doesnot exist
    for(int i=0;i<5;i++){
if(head==nullptr){
        head=new node(arr[i]);
    }
    //linked list exist
    else{
     node *temp;
     temp=new node(arr[i]);
     temp->next=head;
     head=temp;
    }
    }
    
    //print the value;

    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}

//-----------------------------------------------------------------
//insertion of node at the end of linkedlist
//-----------------------------------------------------------------
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *Head;
    Head = NULL;
    Node *tail=NULL;
    int arr[] = {2, 4, 6, 8, 10};

    // insert the value at end 
    for(int i=0;i<5;i++){
        
        if(Head==NULL){
            Head=new Node(arr[i]);
            tail=Head;
        }
        else{
            tail->next=new Node(arr[i]);
            tail=tail->next;
        }

    }
    //printing the value
    Node * temp=Head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

////////////////////////////////////////
//--------------------------------------------
//insertion of node at particular position
//--------------------------------------------
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *Head;
    Head = NULL;
    Node *tail=NULL;
    int arr[] = {2, 4, 6, 8, 10};

    // insert the value at end 
    for(int i=0;i<5;i++){
        
        if(Head==NULL){
            Head=new Node(arr[i]);
            tail=Head;
        }
        else{
            tail->next=new Node(arr[i]);
            tail=tail->next;
        }

    }
    int x=3;
    int value=30;
    Node *temp=Head;
    x--;
    while (x--)
    {
        temp=temp->next;
    }
    Node *temp2=new Node(value);
    temp2->next=temp->next;
    temp->next=temp2;
    

    //printing the value
    Node * temp3=Head;
    while(temp3){
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }

}
