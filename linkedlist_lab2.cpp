/*
-------------------------------------------
             (Rectangle Representation)   
-------------------------------------------- 
👉 Each node stores (x, y) coordinates of rectangle vertices.
👉 Find area using: (maxX − minX) × (maxY − minY).

Example:

Input:  (0,0) → (4,0) → (4,3) → (0,3)
Output: 12
---------------------------------------------------




FUNCTION calculateArea(head)

    IF head is NULL
        RETURN 0

    minX = head.x
    maxX = head.x
    minY = head.y
    maxY = head.y

    temp = head

    WHILE temp is not NULL
        IF temp.x < minX
            minX = temp.x

        IF temp.x > maxX
            maxX = temp.x

        IF temp.y < minY
            minY = temp.y

        IF temp.y > maxY
            maxY = temp.y

        temp = temp.next

    width = maxX - minX
    height = maxY - minY

    area = width * height

    RETURN area          
*/
#include <iostream>
using namespace std;

class Node {
public:
    int x, y;
    Node* next;

    Node(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        next = NULL;
    }
};

// insert at end
void insert(Node*& head, int x, int y) {
    if (!head) {
        head = new Node(x, y);
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(x, y);
}

// calculate area
int calculateArea(Node* head) {
    if (!head) return 0;

    int minX = head->x, maxX = head->x;
    int minY = head->y, maxY = head->y;

    Node* temp = head;

    while (temp) {
        if (temp->x < minX) minX = temp->x;
        if (temp->x > maxX) maxX = temp->x;

        if (temp->y < minY) minY = temp->y;
        if (temp->y > maxY) maxY = temp->y;

        temp = temp->next;
    }

    int width = maxX - minX;
    int height = maxY - minY;

    return width * height;
}

// print
void print(Node* head) {
    while (head) {
        cout << "(" << head->x << "," << head->y << ") -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insert(head, 0, 0);
    insert(head, 4, 0);
    insert(head, 4, 3);
    insert(head, 0, 3);

    print(head);

    cout << "Area = " << calculateArea(head);

    return 0;
}

/*
-------------------------------------------
           (Linked List Compression)     
-------------------------------------------- 

Task 02 – Linked List Compression

👉 Replace consecutive duplicate values with value followed by count.
👉 Return compressed list only if it is shorter than original.

Example:

Input:  1 → 1 → 2 → 3 → 3 → 3
Output: 1 → 2 → 2 → 3 → 3

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

// insert at end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// count size
int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// 🔥 main function
Node* compressList(Node* head) {
    if (!head) return head;

    int originalSize = getSize(head);

    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* curr = head;

    while (curr) {
        int value = curr->data;
        int count = 0;

        // count duplicates
        while (curr && curr->data == value) {
            count++;
            curr = curr->next;
        }

        // add value
        Node* node1 = new Node(value);
        if (!newHead) {
            newHead = newTail = node1;
        } else {
            newTail->next = node1;
            newTail = node1;
        }

        // add count if >1
        if (count > 1) {
            Node* node2 = new Node(count);
            newTail->next = node2;
            newTail = node2;
        }
    }

    int newSize = getSize(newHead);

    if (newSize < originalSize)
        return newHead;
    else
        return head;
}

// print
void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example: 1→1→2→3→3→3
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 3);

    cout << "Original: ";
    print(head);

    head = compressList(head);

    cout << "Compressed: ";
    print(head);

    return 0;
}


/*
-------------------------------------------
        (Secure Message Transmission in a Spy Network) 
-------------------------------------------- 

Task 03 – Remove Zero Sum Sublist

👉 Remove all consecutive nodes whose sum becomes 0.
👉 Return the cleaned linked list.

Example:

Input:  4 → 6 → -10 → 8 → 9 → -8 → -9 → 2
Output: 2
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

// insert at end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// 🔥 main function
Node* removeZeroSumSublist(Node* head) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* start = dummy;

    while (start != NULL) {
        int sum = 0;
        Node* curr = start->next;

        while (curr != NULL) {
            sum += curr->data;

            if (sum == 0) {
                // delete nodes between start and curr
                start->next = curr->next;
                break;
            }

            curr = curr->next;
        }

        start = start->next;
    }

    return dummy->next;
}

// print
void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example: 4 → 6 → -10 → 8 → 9 → -8 → -9 → 2
    int arr[] = {4, 6, -10, 8, 9, -8, -9, 2};

    for (int i = 0; i < 8; i++) {
        insert(head, arr[i]);
    }

    head = removeZeroSumSublist(head);

    print(head);

    return 0;
}