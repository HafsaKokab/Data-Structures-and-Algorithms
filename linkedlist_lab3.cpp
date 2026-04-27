//(DoublyLinkedList NodeSplitting

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string val) {
        data = val;
        prev = next = NULL;
    }
};

// print function
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

// insert at end
void insertEnd(Node*& head, string val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// 🔹 tumhara function (same as given)
void splitNodes(Node* head) {
    Node* curr = head;

    while (curr != NULL) {
        string s = curr->data;
//👉 agar space nahi → skip
        if (s.find(' ') == string::npos) {
            curr = curr->next;
            continue;
        }

        Node* temp = curr;
        string word = "";
        bool first = true;

        for (int i = 0; i <= s.length(); i++) {

            if (i == s.length() || s[i] == ' ') {

                if (word != "") {
                    if (first) {
                        curr->data = word;
                        first = false;
                    } else {
                        Node* newNode = new Node(word);

                        newNode->next = temp->next;
                        if (temp->next != NULL)
                            temp->next->prev = newNode;

                        temp->next = newNode;
                        newNode->prev = temp;

                        temp = newNode;
                    }
                    word = "";
                }

            } else {
                word += s[i];
            }
        }

        curr = curr->next;
    }
}

// 🔥 MAIN FUNCTION
int main() {
    Node* head = NULL;

    // input list
    insertEnd(head, "hello world");
    insertEnd(head, "this is");
    insertEnd(head, "a test");

    cout << "Before Splitting:\n";
    printList(head);

    splitNodes(head);

    cout << "\nAfter Splitting:\n";
    printList(head);

    return 0;
}




//Task02(Circular Coin Distribution)
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

// 🔹 Insert at end (circular)
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}

// 🔹 Print circular list
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    cout << "[ ";
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]\n";
}

// 🔥 YOUR FUNCTION
int minimumMoves(Node* head) {
    if (head == NULL) return 0;

    int total = 0, n = 0;
    Node* temp = head;

    // first node
    total += temp->data;
    n++;
    temp = temp->next;

    // rest nodes
    while (temp != head) {
        total += temp->data;
        n++;
        temp = temp->next;
    }
//divide ho sakta hein kay nhi ho sakta even kay case mn divide hon gay odd kay case mn return ho jay ga
    if (total % n != 0)
        return -1;

    int target = total / n;

    int moves = 0;
    int balance = 0;

    temp = head;

    // first node
    balance += (temp->data - target);
    moves += abs(balance);
    temp = temp->next;

    // rest nodes
    
/*
Balance ka simple meaning
negative → coins chahiye
positive → extra coins
*/
    while (temp != head) {
        balance += (temp->data - target);
        moves += abs(balance);
        temp = temp->next;
    }

    return moves;
}

// 🔥 MAIN FUNCTION
int main() {
    Node* head = NULL;

    // example input: [1, 0, 5]
    insertEnd(head, 1);
    insertEnd(head, 0);
    insertEnd(head, 5);

    cout << "Houses: ";
    printList(head);

    int result = minimumMoves(head);

    cout << "Minimum moves required: " << result << endl;

    return 0;
}