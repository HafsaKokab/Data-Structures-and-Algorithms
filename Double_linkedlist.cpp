#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at start
    void insertAtStart(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    // Insert at end
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
        temp->prev = curr;
    }

    // Insert at position
    void insertAtPosition(int pos, int val)
    {
        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node *curr = head;

        for (int i = 0; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node *temp = new Node(val);

        // insert at end
        if (curr->next == NULL)
        {
            curr->next = temp;
            temp->prev = curr;
        }
        // insert in middle
        else
        {
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;
        }
    }

    // Delete from start
    void deleteFromStart()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == NULL)
            return;

        Node *curr = head;

        // single node
        if (curr->next == NULL)
        {
            delete curr;
            head = NULL;
            return;
        }

        while (curr->next != NULL) //last node tak jao 1->3>5>7 tu matlab 7 tak jao
        {
            curr = curr->next;
        }

        curr->prev->next = NULL;
        delete curr;
    }

    // Delete at position
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 0)
        {
            deleteFromStart();
            return;
        }

        Node *curr = head;

        for (int i = 0; i < pos && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        // last node
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    // Reverse DLL
    void reverse()
    {
        Node *curr = head;
        Node *temp = NULL;

        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != NULL)
            head = temp->prev;
    }

    // Print list
    void print()
    {
        Node *trav = head;

        while (trav)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtStart(3);
    dll.insertAtStart(1);
    dll.insertAtEnd(5);
    dll.insertAtEnd(7);

    dll.insertAtPosition(2, 100);

    dll.print();   // 1 3 100 5 7

    dll.deleteAtPosition(2);

    dll.print();   // 1 3 5 7

    dll.reverse();

    dll.print();   // 7 5 3 1
}
/*

real life application of doublelinked list 
undo/redo (text editor)
brower history(back /forward) 
music playlist(next/previous)

*/


