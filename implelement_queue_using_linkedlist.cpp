#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{

 node *front;
 node *rear;
 public:
  queue(){
    front=rear=NULL;
  }
  bool isempty(){
    return front==NULL;
  }
  void push(int val){
    //empty
    if(isempty()){
          cout<<"pushed "<<val<<" in the queue "<<endl;
        front=rear=new node(val);
        return ;
    }
    // not empty 
    else{
       rear->next=new node(val);
       cout<<"pushed "<<val<<" in the queue "<<endl;
        rear=rear->next;
    }
  }
 void pop(){
    //is empty()
    if(isempty()){
        cout<<"queue is underflow "<<endl;
        return;
    }
     else{
        cout<<"poped "<<front->data<<" from the queue "<<endl;
        node *temp=front;
        front=front->next;
        delete temp;
     }
 }

 int start(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    else{
       return front->data; 
    }
 }
};
int main() {
    queue q;
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(50);
    q.pop();
   cout<< q.start();
    return 0;
}