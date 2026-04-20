/*
-------------------------------------------
               1. Insert GCD in Linked List
         Insert Greatest Common Divisors in Linked List
--------------------------------------------  

Insert GCD in Linked List (from your file )

👉 Insert GCD of every two adjacent nodes between them.
👉 New nodes are added in between original nodes.

Example:

Input:  18 → 6 → 10 → 3
Output: 18 → 6 → 6 → 2 → 10 → 1 → 3
*/
#include <iostream>
#include <numeric>   // for gcd
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

// Function (your logic)
ListNode* insertGreatestCommonDivisors(ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* main = head;
    ListNode* next1 = main->next;

    while (next1) {
        int g = gcd(main->val, next1->val);

        ListNode* newnode = new ListNode(g);

        newnode->next = next1;
        main->next = newnode;

        main = next1;
        next1 = next1->next;
    }

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
    // List: 18 6 10 3
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    cout << "Before: ";
    printList(head);

    head = insertGreatestCommonDivisors(head);

    cout << "After: ";
    printList(head);

    return 0;
}

///////////////////////////////////
#include <iostream>
using namespace std;

// GCD function (your code)
int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

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

// Function to insert GCD nodes
ListNode* insertGreatestCommonDivisors(ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* main = head;
    ListNode* next1 = main->next;

    while (next1) {
        int g = gcd(main->val, next1->val);  // use your gcd

        ListNode* newnode = new ListNode(g);

        newnode->next = next1;
        main->next = newnode;

        main = next1;
        next1 = next1->next;
    }

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
    // List: 18 6 10 3
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    cout << "Before: ";
    printList(head);

    head = insertGreatestCommonDivisors(head);

    cout << "After: ";
    printList(head);

    return 0;
}

/*
-------------------------------------------
                Delete Duplicates (Sorted List II)
         https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
--------------------------------------------    
5. Delete Duplicates (Sorted List II)

👉 Remove all duplicate values completely from a sorted list.
👉 Only distinct elements remain.

Example:

Input:  1 → 2 → 2 → 3 → 3 → 4
Output: 1 → 4


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

// Function (your logic)
ListNode* deleteDuplicates(ListNode* head) {

    if (head == NULL) return head;

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {

        // check adjacent duplicates
        if (curr->next != NULL && curr->val == curr->next->val) {

            int v = curr->val;

            // skip all duplicates
            while (curr != NULL && curr->val == v) {
                curr = curr->next;
            }

            if (prev != NULL) {
                prev->next = curr;
            } else {
                head = curr;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

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
    // List: 1 2 2 3 3 4 5 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(5);

    cout << "Before: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After: ";
    printList(head);

    return 0;
}

/*
-------------------------------------------
                Boats to Save People
         https://leetcode.com/problems/boats-to-save-people/
--------------------------------------------              
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function
int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(), people.end());

    int i = 0;
    int j = people.size() - 1;
    int cnt = 0;

    while (i <= j) {

        if (people[i] + people[j] <= limit) {
            i++;
            j--;
        }
        else {
            j--;
        }

        cnt++;
    }

    return cnt;
}

int main() {

    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    int boats = numRescueBoats(people, limit);

    cout << "Minimum boats needed: " << boats << endl;

    return 0;
}


/*
-------------------------------------------
                (Loneliest Element)  
--------------------------------------------  

Loneliest Element (from your file )

👉 For each node, calculate sum of absolute differences with all others.
👉 Return the element with maximum score.

Example:

Input:  2 → 6 → 8 → 7 → 1
Output: 1
*/


#include <iostream>
#include <cmath>   // abs() ke liye
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function to insert at end
void insertAtEnd(Node*& head, int val)
{
    Node* newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find loneliest element
int loneliest(Node* head)
{
    if (head == NULL)
        return -1;

    int maxScore = -1;
    int loneliestElement = head->data;

    Node* i = head;

    while (i != NULL)
    {
        int score = 0;

        Node* j = head;

        while (j != NULL)
        {
            if (i != j)
            {
                score += abs(i->data - j->data);
            }
            j = j->next;
        }

        if (score > maxScore)
        {
            maxScore = score;
            loneliestElement = i->data;
        }

        i = i->next;
    }

    cout << "Loneliness Score = " << maxScore << endl;

    return loneliestElement;
}

// Main function
int main()
{
    Node* head = NULL;

    insertAtEnd(head, 2);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAtEnd(head, 7);
    insertAtEnd(head, 1);

    int result = loneliest(head);

    cout << "Loneliest Element = " << result << endl;

    return 0;
}


//////////////////////////////////
#include <iostream>
#include <cmath>
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

// Function to find loneliest element
int loneliest(Node* head) {
    int maxScore = 0;
    int result = head->data;

    Node* temp1 = head;

    while (temp1 != NULL) {
        int score = 0;
        Node* temp2 = head;

        while (temp2 != NULL) {
            if (temp1 != temp2) {
                score += abs(temp1->data - temp2->data);
            }
            temp2 = temp2->next;
        }

        if (score > maxScore) {
            maxScore = score;
            result = temp1->data;
        }

        temp1 = temp1->next;
    }

    cout << "Loneliness Score = " << maxScore << endl;
    return result;
}

int main() {
    // Simple list manually banayi
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(1);

    int ans = loneliest(head);

    cout << "Loneliest Element = " << ans << endl;

    return 0;
}



/*
-------------------------------------------
             (Fold Operation)   
--------------------------------------------  

Fold Operation (from your file )

👉 Add first + last, second + second-last, and so on.
👉 Print or return the folded values.

Example:

Input:  2 → 6 → 8 → 7 → 1
Output: 3 13 8
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

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// EASY fold function
void fold(Node* head) {

    // Step 1: Linked list → array
    int arr[100], n = 0;
    Node* temp = head;

    while (temp != NULL) {
        arr[n++] = temp->data;
        temp = temp->next;
    }

    // Step 2: folding logic
    int i = 0, j = n - 1;

    while (i < j) {
        cout << arr[i] + arr[j] << " ";
        i++;
        j--;
    }

    // Step 3: middle element (odd case)
    if (i == j) {
        cout << arr[i];
    }

    cout << endl;
}

// Main
int main() {
    Node* head = NULL;

    insertAtEnd(head, 2);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAtEnd(head, 7);
    insertAtEnd(head, 1);

    fold(head);

    return 0;
}