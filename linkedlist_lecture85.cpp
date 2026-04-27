/*
1: Remove loop in Linked List
 https://www.geeksforgeeks.org/problem...

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

// same logic function
void removeLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

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
        return;
    }

    // find starting point of loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // find last node of loop
    while (slow->next != fast) {
        slow = slow->next;
    }

    // break loop
    slow->next = NULL;
}

// print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    // remove loop
    removeLoop(head);

    // print (ab infinite loop nahi hoga)
    printList(head);
}

/////////////////////////////////////
//🟣 2. Remove Loop (Using Loop Length Method)
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

void removeLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    // detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    // no loop
    if (fast == NULL || fast->next == NULL) return;

    // 🔥 find length of loop
    int count = 1;
    slow = slow->next;

    while (slow != fast) {
        slow = slow->next;
        count++;
    }

    // 🔥 move fast ahead by loop length
    slow = head;
    fast = head;

    for (int i = 0; i < count; i++) {
        fast = fast->next;
    }

    // 🔥 find start of loop
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // 🔥 go to last node of loop
    while (fast->next != slow) {
        fast = fast->next;
    }

    // break loop
    fast->next = NULL;
}

// print
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    printList(head);
}

/*
2: Intersection Point in Y shaped Linked List: 
https://www.geeksforgeeks.org/problem...

🟣 3. Intersection Point of Two Linked Lists
❓ Question

👉 Find the intersection point of two linked lists.

📥 Input
List1: 3 → 6 → 8 → 10  
List2: 4 → 8 → 10
📤 Output
8
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

Node* intersectPoint(Node* head1, Node* head2) {

    Node* curr1 = head1;
    Node* curr2 = head2;

    int count1 = 0, count2 = 0;

    // count lengths
    while(curr1){
        count1++;
        curr1 = curr1->next;
    }

    while(curr2){
        count2++;
        curr2 = curr2->next;
    }

    curr1 = head1;
    curr2 = head2;

    // adjust lengths
    while(count1 > count2){
        curr1 = curr1->next;
        count1--;
    }

    while(count2 > count1){
        curr2 = curr2->next;
        count2--;
    }

    // find intersection
    while(curr1 && curr2){
        if(curr1 == curr2){
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return NULL;
}

// print from intersection
void print(Node* head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // common part: 8->10
    Node* common = new Node(8);
    common->next = new Node(10);

    // list1: 3->6->8->10
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = common;

    // list2: 4->8->10
    Node* head2 = new Node(4);
    head2->next = common;

    Node* intersection = intersectPoint(head1, head2);

    if(intersection){
        cout << "Intersection at node with data: " << intersection->data << endl;
    } else {
        cout << "No intersection\n";
    }
}

/////////////////////////////////
//🟣 4. Intersection (Using Cycle Detection Trick)
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

Node* intersectPoint(Node* head1, Node* head2) {

    if(head1 == NULL || head2 == NULL) return NULL;

    Node* curr1 = head1;

    // go to last node
    while(curr1->next){
        curr1 = curr1->next;
    }

    // make cycle
    curr1->next = head1;

    // detect loop in second list
    Node* slow = head2;
    Node* fast = head2;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }

    // no intersection
    if(fast == NULL || fast->next == NULL){
        curr1->next = NULL;   // restore list
        return NULL;
    }

    // find starting point of loop
    slow = head2;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    curr1->next = NULL;   // 🔥 restore original list

    return slow;
}

// print from intersection
void print(Node* head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // common part: 9 -> 10 -> 7
    Node* common = new Node(9);
    common->next = new Node(10);
    common->next->next = new Node(7);

    // list1: 3 -> 2 -> 7 -> (common)
    Node* head1 = new Node(3);
    head1->next = new Node(2);
    head1->next->next = common;

    // list2: 3 -> 3 -> 5 -> (common)
    Node* head2 = new Node(3);
    head2->next = new Node(3);
    head2->next->next = new Node(5);
    head2->next->next->next = common;

    Node* ans = intersectPoint(head1, head2);

    if(ans){
        cout << "Intersection at: " << ans->data << endl;
    } else {
        cout << "No intersection\n";
    }
}