/*
🧠 Concept ek line mein:

👉 Circular + Doubly =

1 <-> 3 <-> 5 <-> 7
↑                 ↓
←←←←←←←←←←←←←←←←←←

✔ last node → first ko point kare
✔ first node → last ko point kare

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() {
        head = NULL;
    }

    // Insert at start
    void insertAtStart(int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
        } 
        else {
            Node* tail = head->prev;

            temp->next = head;
            temp->prev = tail;

            tail->next = temp;
            head->prev = temp;

            head = temp;
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
        } 
        else {
            Node* tail = head->prev;

            tail->next = temp;
            temp->prev = tail;

            temp->next = head;
            head->prev = temp;
        }
    }

    // Delete from start
    void deleteFromStart() {
        if (head == NULL) return;

        // single node
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head->prev;
        Node* temp = head;

        head = head->next;

        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    void print() {
    if (head == NULL) return;

    Node* temp = head;

    while (true) {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head)
            break;
    }

    cout << endl;
}
};

int main() {
    DoublyCircularLinkedList dcll;

    dcll.insertAtStart(3);
    dcll.insertAtStart(1);
    dcll.insertAtEnd(5);
    dcll.insertAtEnd(7);

    dcll.print();   // 1 3 5 7

    dcll.deleteFromStart();
    dcll.print();   // 3 5 7
}