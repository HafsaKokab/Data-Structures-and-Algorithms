/*
--------------------------------
    deletion in a singly linkedlist
--------------------------------


*/


// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// int main()
// {
//     Node *Head;
//     Head = NULL;
//     Node *tail=NULL;
//     int arr[] = {2, 4, 6, 8, 10};

//     // insert the value at end 
//     for(int i=0;i<5;i++){
        
//         if(Head==NULL){
//             Head=new Node(arr[i]);
//             tail=Head;
//         }
//         else{
//             tail->next=new Node(arr[i]);
//             tail=tail->next;
//         }

//     }
//     //delete a node at the start
//     if(Head !=NULL){
//         Node * temp=Head;
//         Head=Head->next;
//         delete temp;
//     }
//     //printing the value
//     Node * temp=Head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }

// }
//////////////////////////////////////////
/*
----------------------------
delete a last node
----------------------------
*/

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// int main()
// {
//     Node *Head;
//     Head = NULL;
//     Node *tail=NULL;
//     int arr[] = {2, 4,6,8,10};

//     // insert the value at end 
//     for(int i=0;i<5;i++){
        
//         if(Head==NULL){
//             Head=new Node(arr[i]);
//             tail=Head;
//         }
//         else{
//             tail->next=new Node(arr[i]);
//             tail=tail->next;
//         }

//     }
//     // delete a node at end
//     if(Head != NULL){
//         //only one node is present
//         if(Head->next ==NULL){
//             Node * temp=Head;
//             delete temp;
//             Head=NULL;
//         }

//         //more than one node is present 
//         else {
//             Node * curr=Head;
//             Node * prev=NULL;
//             while (curr->next !=NULL)
//             {
//                 prev=curr;
//                 curr=curr->next;
//             }
//             prev->next=NULL;
//             delete curr;
            
//         }
//     }
//     //printing the value
//     Node * temp=Head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }

// }
/////////////////////////////////////////////
/*
----------------------------
deleting a particular node
----------------------------

*/

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// int main()
// {
//     Node *Head;
//     Head = NULL;
//     Node *tail=NULL;
//     int arr[] = {2, 4,6,8,10};

//     // insert the value at end 
//     for(int i=0;i<5;i++){
        
//         if(Head==NULL){
//             Head=new Node(arr[i]);
//             tail=Head;
//         }
//         else{
//             tail->next=new Node(arr[i]);
//             tail=tail->next;
//         }

//     }
//     int x=4;
//     if(x==1){
//      Node * temp=Head;
//      Head=Head->next;
//      delete temp;
//     }
//     x--;
//     Node *curr=Head;
//     Node *prev=NULL;
//     while(x--){
//         prev=curr;
//         curr=curr->next;
//     }
//     prev->next=curr->next;
//     delete curr;
//     //printing the value
//     Node * temp=Head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }

// }
/////////////////////////////////
#include <iostream>
using namespace std;

// Node banaya
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Delete function (without head)
void deleteNode(Node* curr) {
    Node *temp=curr->next;
    curr->data = temp->data;   // next ka data copy
    curr->next = temp->next;   // next ko skip
    delete temp;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List banai: 1 2 3 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Before: ";
    printList(head);

    deleteNode(head->next); // 2 delete

    cout << "After: ";
    printList(head);

    return 0;
}