
/*
------------------------------
1: Detect Loop in Linked List
 https://www.geeksforgeeks.org/problem...
 -----------------------------------------

 🟣 1. Detect Loop (Using Visited Array)
❓ Question

👉 Check if a linked list contains a cycle using visited nodes.

📥 Input
1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←
📤 Output
True (Loop detected)
*/
#include <iostream>
#include <vector>
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

// same check function
bool check(vector<Node*> &visited ,Node * curr){
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == curr){
            return true;
        }
    }
    return false;
}

// same detect loop logic
bool detectLoop(Node* head) {

    Node * curr = head;
    vector<Node*> visited;

    while(curr){
        if(check(visited, curr)){
            return true;
        }
        visited.push_back(curr);
        curr = curr->next;
    }
    return false;
}

// helper to print result
int main() {

    // create list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 🔥 loop bana dete hain (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    if(detectLoop(head)){
        cout << "Loop detected\n";
    } else {
        cout << "No Loop\n";
    }
}

////////////////////////////////
//🟣 2. Detect Loop (Floyd Cycle Detection)
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

// same logic (Floyd Cycle Detection)
bool detectLoop(Node* head) {

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    // create list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 🔥 loop bana dete hain (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head)) {
        cout << "Loop detected\n";
    } else {
        cout << "No Loop\n";
    }
}
/*

Find Length of Loop
 https://www.geeksforgeeks.org/problem...

 🟣 3. Find Length of Loop
❓ Question

👉 Find the number of nodes in the loop of a linked list.
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

int lengthOfLoop(Node *head) {

    Node *slow = head;
    Node *fast = head;

    // detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // no loop
    if (fast == NULL || fast->next == NULL) {
        return 0;
    }

    // count loop length (only slow)
    int count = 1;
    slow = slow->next;

    while (slow != fast) {
        slow = slow->next;
        count++;
    }

    return count;
}

int main() {

    // create list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 🔥 loop bana dete hain (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    cout << "Loop length: " << lengthOfLoop(head);
}