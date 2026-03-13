#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if full
    bool isFull() {
        return (top == capacity - 1);
    }

    // Push element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed\n";
    }

    // Pop element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Current size
    int size() {
        return top + 1;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Popped: " << s.pop() << endl;
    cout << "Top: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    s.display();

    return 0;
}