/*
🟦 1. Sort Linked List (Merge Sort)
❓ Question

👉 Sort a singly linked list in ascending order using merge sort.

📥 Input
4 → 2 → 1 → 3
📤 Output
1 → 2 → 3 → 4
*/

#include <iostream>
using namespace std;

// 🔷 ListNode as CLASS
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
   ListNode* mergelist(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if(l1 != NULL)
            curr->next = l1;

        if(l2 != NULL)
            curr->next = l2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = NULL;

        // Find middle
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergelist(l1, l2);
    }

 

// 🔷 Print function
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// 🔷 Main function
int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);


    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

/*
725. Split Linked List in Parts
🟦 3. Split Linked List into K Parts
❓ Question

👉 Split a linked list into k consecutive parts as evenly as possible.

📥 Input
List: 1 → 2 → 3 → 4 → 5 → 6 → 7  
k = 3
📤 Output
Part 1: 1 → 2 → 3  
Part 2: 4 → 5  
Part 3: 6 → 7

*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// 🔹 Function (same logic)
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int count = 0;
    ListNode* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    int numnodes = count / k;
    int extra = count % k;

    vector<ListNode*> result(k, NULL);
    ListNode* curr = head;

    for (int i = 0; i < k; i++) {
        result[i] = curr;
        int size = numnodes + (extra > 0 ? 1 : 0);

        ListNode* prev = NULL;

        for (int j = 0; j < size; j++) {
            prev = curr;
            if (curr) curr = curr->next; // important safety
        }

        if (prev) prev->next = NULL;

        if (extra > 0) extra--;
    }

    return result;
}

// 🔹 Helper: print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🔹 MAIN function
int main() {
    // Create linked list: 1→2→3→4→5→6→7
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    int k = 3;

    vector<ListNode*> parts = splitListToParts(head, k);

    // Print result
    for (int i = 0; i < k; i++) {
        cout << "Part " << i + 1 << ": ";
        printList(parts[i]);
    }

    return 0;
}

/*
203. Remove Linked List Elements
🟦 4. Remove Linked List Elements
❓ Question

👉 Remove all nodes from the linked list that have a specific value.

📥 Input
List: 1 → 2 → 6 → 3 → 4 → 5 → 6  
val = 6
📤 Output
1 → 2 → 3 → 4 → 5
*/

#include <iostream>
using namespace std;

// 🔹 Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// 🔹 Function (tumhara logic)
ListNode* removeElements(ListNode* head, int val) {

    // Step 1: remove starting nodes
    while (head && head->val == val) {
        head = head->next;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;

    // Step 2: traverse rest
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

// 🔹 Helper function: print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🔹 MAIN function
int main() {

    // Create linked list: 1 → 2 → 6 → 3 → 4 → 5 → 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;

    cout << "Original List:\n";
    printList(head);

    head = removeElements(head, val);

    cout << "\nAfter Removing " << val << ":\n";
    printList(head);

    return 0;
}