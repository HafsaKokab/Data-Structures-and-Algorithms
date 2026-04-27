

/*

1: Remove duplicate element from sorted Linked List
 https://www.geeksforgeeks.org/problem...

 🟢 1. Remove Duplicates from Sorted Linked List
❓ Question

👉 Remove duplicate elements from a sorted linked list.

📥 Input
1 → 1 → 2 → 3 → 3
📤 Output
1 → 2 → 3
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

Node* removeDuplicates(Node* head) {

    if (head == NULL) return head;   // 🔥 safety (warna crash ho sakta tha)

    vector<int> ans;

    ans.push_back(head->data);

    Node* curr = head->next;

    while (curr) {
        // duplicate nahi hai
        if (ans[ans.size() - 1] != curr->data) {
            ans.push_back(curr->data);
        }
        curr = curr->next;
    }

    curr = head;
    int index = 0;
    Node* prev = NULL;

    while (index < ans.size()) {
        curr->data = ans[index];
        index++;
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;

    return head;
}

// print function
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // 1->1->2->3->3
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    head = removeDuplicates(head);

    printList(head);
}
/////////////////////////////
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

Node* removeDuplicates(Node* head) {

    if (head == NULL) return head;   // 🔥 safety

    Node* curr = head->next;
    Node* prev = head;

    while (curr) {

        if (curr->data == prev->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return head;
}

// print function
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // 1->1->2->3->3
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    head = removeDuplicates(head);

    printList(head);
}

/*
2: Merge two sorted linked lists
 https://www.geeksforgeeks.org/problem...
 🟢 2. Merge Two Sorted Linked Lists
❓ Question

👉 Merge two sorted linked lists into one sorted list.

📥 Input
List1: 1 → 3 → 5  
List2: 2 → 4 → 6
📤 Output
1 → 2 → 3 → 4 → 5 → 6
 
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(Node* head1, Node* head2) {

    Node *head = new Node(0);
    Node *tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }

    // 🔥 fixed if-else (same logic)
    if (head1) {
        tail->next = head1;
    }
    else {
        tail->next = head2;
    }

    // dummy remove
    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

// print function
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1->3->5
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    // List 2: 2->4->6
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    Node* result = sortedMerge(head1, head2);

    printList(result);
}


/*
3: Given a linked list of 0s, 1s and 2s, sort it
 https://www.geeksforgeeks.org/problem...
 3. Sort Linked List of 0s, 1s, and 2s
❓ Question

👉 Sort a linked list containing only 0s, 1s, and 2s.

📥 Input
1 → 2 → 0 → 1 → 2 → 0
📤 Output
0 → 0 → 1 → 1 → 2 → 2
 
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

Node* segregate(Node* head) {

    Node* curr = head;

    int count_0 = 0, count_1 = 0, count_2 = 0;

    // count 0,1,2
    while (curr) {
        if (curr->data == 0) count_0++;
        else if (curr->data == 1) count_1++;
        else count_2++;

        curr = curr->next;
    }

    // overwrite list
    curr = head;

    while (count_0--) {
        curr->data = 0;
        curr = curr->next;
    }

    while (count_1--) {
        curr->data = 1;
        curr = curr->next;
    }

    while (count_2--) {
        curr->data = 2;
        curr = curr->next;
    }

    return head;
}

// print function
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Example: 1->2->0->1->2->0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    head = segregate(head);

    printList(head);
}