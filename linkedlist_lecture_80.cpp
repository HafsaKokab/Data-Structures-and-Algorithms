
/*
-------------------------------------------
              Reverse of linked_list
             Reverse Linked List: https://leetcode.com/problems/reverse...
--------------------------------------------              
*/
// #include <iostream>
// #include <vector>
// using namespace std;

// // ListNode structure
// class ListNode {
// public:
//     int val;
//     ListNode* next;

//     ListNode(int x) {
//         val = x;
//         next = NULL;
//     }
// };

// // Reverse function (your method)
// ListNode* reverseList(ListNode* head) {
//     vector<int> ans;

//     ListNode* temp = head;
//     while (temp) {
//         ans.push_back(temp->val);
//         temp = temp->next;
//     }

//     int i = ans.size() - 1;
//     ListNode* temp1 = head;

//     while (temp1) {
//         temp1->val = ans[i];
//         i--;
//         temp1 = temp1->next;
//     }

//     return head;
// }

// // Print function
// void printList(ListNode* head) {
//     while (head) {
//         cout << head->val << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main() {
//     // List banai: 1 2 3 4 5
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     cout << "Before: ";
//     printList(head);

//     head = reverseList(head);

//     cout << "After: ";
//     printList(head);

//     return 0;
// }
//////////////////////////////////
#include <iostream>
#include <vector>
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

// Reverse function (your method)
ListNode* reverseList(ListNode* head) {
   ListNode * curr=head, *prev=nullptr ,*fut=nullptr;
       while(curr){
        fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
       }
       head=prev;
    return head;
}

// Print function
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List banai: 1 2 3 4 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before: ";
    printList(head);

    head = reverseList(head);

    cout << "After: ";
    printList(head);

    return 0;
}

//////////////////////////////////////////
/*
-------------------------------------------
              middle of linked_list
             Middle of the Linked List: https://leetcode.com/problems/middle-...  
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

// Function to find middle node
ListNode* middleNode(ListNode* head) {
    int count = 0;
    ListNode* temp = head;

    // Count nodes
    while (temp) {
        count++;
        temp = temp->next;
    }

    count = count / 2;

    temp = head;

    // Move to middle
    while (count--) {
        temp = temp->next;
    }

    return temp;
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
    // List: 1 2 3 4 5 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "List: ";
    printList(head);

    ListNode* mid = middleNode(head);

    cout << "Middle Node: " << mid->val << endl;

    return 0;
}
////////////////////////////

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

// Function to find middle (slow-fast)
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    // List: 1 2 3 4 5 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "List: ";
    printList(head);

    ListNode* mid = middleNode(head);

    cout << "Middle Node: " << mid->val << endl;

    return 0;
}

/*
-------------------------------------------
               ROtate LIST
        Rotate List: https://leetcode.com/problems/rotate-...
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

// Rotate Right Function
ListNode* rotateRight(ListNode* head, int k) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    int count = 0;
    ListNode* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    k = k % count;

    if (k == 0) return head;

    int move = count - k;

    ListNode* curr = head;
    ListNode* prev = NULL;

    while (move--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;

    ListNode* tail = curr;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = head;

    return curr;
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

    int k = 2;

    head = rotateRight(head, k);

    cout << "After rotate: ";
    printList(head);

    return 0;
}