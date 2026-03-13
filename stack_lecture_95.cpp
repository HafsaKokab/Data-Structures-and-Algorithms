//1: Implement two stacks in an array: https://www.geeksforgeeks.org/problem...

#include <iostream>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    twoStacks(int n=100) {
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if(top1 + 1 == top2){
            cout << "Stack Overflow\n";
            return;
        }
        top1++;
        arr[top1] = x;
    }

    void push2(int x) {
        if(top2 - 1 == top1){
            cout << "Stack Overflow\n";
            return;
        }
        top2--;
        arr[top2] = x;
    }

    int pop1() {
        if(top1 == -1){
            return -1;
        }
        int element = arr[top1];
        top1--;
        return element;
    }

    int pop2() {
        if(top2 == size){
            return -1;
        }
        int element = arr[top2];
        top2++;
        return element;
    }
};

int main() {

    twoStacks st(10);   // array size = 10

    st.push1(2);
    st.push1(3);
    st.push2(4);

    cout << "pop1: " << st.pop1() << endl;
    cout << "pop2: " << st.pop2() << endl;
    cout << "pop2: " << st.pop2() << endl;

    return 0;
}

//2: N Stack in an array: https://www.codingninjas.com/studio/p...