#include <iostream> 
using namespace std;
class  dequeue{
int front,rear,size;
int *arr;
public:
dequeue(int n){
size=n;
arr=new int[n];
front=rear=-1;
}
bool isempty(){
    return front==-1;
}
bool isfull(){
    return front==(rear+1)%size;
}
void push_front(int x){
    //empty()
    if(isempty()){
         front=rear=0;
         cout<<"pushed "<<x<<"in front\n";
         arr[0]=x;
         return;   
    } 
    //full
    else if(isfull()){
        cout<<"dequeue overflow\n";
        return ;
    }
    //normal
    else{
        front=(front-1+size)%size;
        arr[front]=x;
        cout<<"pushed "<<x<<" in front\n"; 
        return;
    }
}
void push_back(int x){
    if(isempty()){
         front=rear=0;
         cout<<"pushed "<<x<<"in front\n";
         arr[0]=x;
         return;   
    } 
    else if(isfull()){
         cout<<"dequeue overflow\n";
        return ;
    }
    else{
     rear=(rear+1)%size;
      cout<<"pushed "<<x<<" in front\n"; 
     arr[rear]=x;
     return;
    } 
}
void pop_front(){
    //if array is empty()
    if(isempty()){
        cout<<"dequeue underflow\n";
        return;
    }
    else{
         cout<<"popped "<<arr[front]<<" from dequeue\n";
        //if only one element is present
       if(front==rear){
        front=rear=-1;
       } 
     //more than one element
       else{
        front=(front+1)%size;
       }
    }
}
void pop_back(){
     if(isempty()){
        return;
    }
    else{
        cout<<"popped "<<arr[rear]<<" from dequeue\n";
        //single element
        if(front==rear){
            front=rear=-1;
        }
        else{
            // when subtracting always add +size
            rear=(rear-1+size)%size;
        }
    }
}
int start(){
    if(isempty()){
        return -1;
    }
    else{
       return arr[front];
    }
}
int end(){
    if(isempty()){
        return -1;
    }
    else{
       return arr[rear];
    }
}

};
int main() {
    dequeue d(5);
    d.push_back(10);
    d.push_back(91);
     d.push_back(9);
    d.push_front(18);
    d.pop_back();
    d.pop_front();
    cout<<d.start()<<endl;

    return 0;
}




//using STL
#include <iostream>
#include<deque>
using namespace std;

int main() {
    deque<int>d;
    d.push_back(10);
    d.push_front(30);
    cout<<d.front()<<endl;
    d.pop_front();
    cout<<d.front()<<endl;
        return 0;
}


//Implementation of Stack using Deque in C++
#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> d;

public:

    void push(int x) {
        d.push_back(x);
    }

    void pop() {
        d.pop_back();
    }

    int top() {
        return d.back();
    }

    bool empty() {
        return d.empty();
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20

    return 0;
}


//Implementation of Queue using Deque in C++
#include <iostream>
#include <deque>
using namespace std;

class Queue {
    deque<int> d;

public:

    void push(int x) {      // enqueue
        d.push_back(x);
    }

    void pop() {            // dequeue
        d.pop_front();
    }

    int front() {
        return d.front();
    }

    bool empty() {
        return d.empty();
    }
};

int main() {

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;   // 10

    q.pop();

    cout << q.front() << endl;   // 20

    return 0;
}