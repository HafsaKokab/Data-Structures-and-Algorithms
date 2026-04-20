/*
-------------------------------------------
               Remove Nth Node from end of list
        Remove Nth Node From End of List: https://leetcode.com/problems/remove-...
--------------------------------------------              
*/

 #include <iostream>
using namespace std;

// ListNode structure
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to remove Nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode* temp = head;

    // Count nodes
    while (temp) {
        count++;
        temp = temp->next;
    }

    count -= n;

    // Delete head
    if (count == 0) {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;

    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List: 1 2 3 4 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before: ";
    printList(head);

    int n = 2; // delete 2nd node from end (4)

    head = removeNthFromEnd(head, n);

    cout << "After: ";
    printList(head);

    return 0;
}
/*
-------------------------------------------
               Remove  every Kth node
         Remove every k'th node: https://www.geeksforgeeks.org/problem..
--------------------------------------------              
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

// Function to delete every Kth node
Node* deleteK(Node* head, int k) {
    if (k == 1) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while (curr) {
        if (count == k) {
            // delete node
            if (prev != NULL) {
                prev->next = curr->next;
            }

            Node* temp = curr;
            curr = curr->next;
            delete temp;

            count = 1;
        } else {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }

    return head;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List: 1 2 3 4 5 6 7 8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    cout << "Before: ";
    printList(head);

    int k = 3;
    head = deleteK(head, k);

    cout << "After deleting every 3rd node: ";
    printList(head);

    return 0;
}

/*
-------------------------------------------
               check palindrome
         Palindrome Linked List: https://leetcode.com/problems/palindr...
--------------------------------------------              
*/


#include <iostream>
using namespace std;

// ListNode structure
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Your Palindrome Function (same logic)
bool isPalindrome(ListNode* head) {

    // safety check
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // count nodes
    int count = 0;
    ListNode* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    count /= 2;

    ListNode* prev = NULL;
    ListNode* curr = head;

    // skip half
    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;

    // reverse second half
    ListNode* front;
    prev = NULL;

    while (curr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    // compare
    ListNode* head1 = head;
    ListNode* head2 = prev;

    while (head1 && head2) {   // ✅ safe loop
        if (head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Palindrome list: 1 2 3 2 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << "List: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}