/*
2: Add two numbers represented by linked lists
https://www.geeksforgeeks.org/problem...

🟣 Add Two Numbers Represented by Linked Lists
❓ Question

👉 Add two numbers represented by linked lists and return the result as a linked list.

📥 Input
List1: 1 → 2 → 3   (represents 123)  
List2: 4 → 5 → 6   (represents 456)

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// reverse function
Node* reverse(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }
    Node* front = curr->next;
    curr->next = prev;
    return reverse(front, curr);
}

// add two lists
Node* addTwoLists(Node* head1, Node* head2) {

    Node* first = reverse(head1, NULL);
    Node* second = reverse(head2, NULL);

    Node* curr1 = first;
    Node* curr2 = second;

    Node* head = new Node(0);
    Node* tail = head;

    int carry = 0;

    while(curr1 && curr2){
        int sum = curr1->data + curr2->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;

        carry = sum / 10;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while(curr1){
        int sum = curr1->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;

        carry = sum / 10;

        curr1 = curr1->next;
    }

    while(curr2){
        int sum = curr2->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;

        carry = sum / 10;

        curr2 = curr2->next;
    }

    while(carry){
        tail->next = new Node(carry % 10);
        tail = tail->next;
        carry /= 10;
    }

    Node* result = reverse(head->next, NULL);

    return result;
}

// print list
void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    =}
    cout << endl;
}

int main(){

    // list1: 1->2->3  (123)
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // list2: 4->5->6  (456)
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(6);

    Node* ans = addTwoLists(head1, head2);

    print(ans);   // 5 7 9
}