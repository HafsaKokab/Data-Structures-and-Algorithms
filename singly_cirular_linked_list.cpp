/*
🧠 Concept ek line mein:

👉 Circular Linked List = last node → first node ko point karta hai

1 → 3 → 5 → 7
↑           ↓
←←←←←←←←←←←←

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at start
    void insertAtStart(int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            Node* tail = head;

            // find last node
            while (tail->next != head) {
                tail = tail->next;
            }

            temp->next = head;
            tail->next = temp;
            head = temp;
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            Node* tail = head;

            while (tail->next != head) {
                tail = tail->next;
            }

            tail->next = temp;
            temp->next = head;
            head=temp;
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

        Node* tail = head;

        while (tail->next != head) {
            tail = tail->next;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;

        delete temp;
    }

    // Print list
   void print() {
    if (head == NULL) return;

    Node* temp = head;

    // first node print
    cout << temp->data << " ";
    temp = temp->next;

    // baaki nodes
    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
};

int main() {
    CircularLinkedList cll;

    cll.insertAtStart(3);
    cll.insertAtStart(1);
    cll.insertAtEnd(5);
    cll.insertAtEnd(7);

    cll.print();   // 1 3 5 7

    cll.deleteFromStart();
    cll.print();   // 3 5 7
}