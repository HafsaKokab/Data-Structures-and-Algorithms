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
class stack{
    node *top;
    int size;
    public:
    stack(){
        top=NULL;
        size=0;
    }
    void push(int val){
      node *temp =new node(val);
      if(temp==NULL){
        cout<<"stack overflow\n";
        return;
      }
      else{
          temp->next=top;
      top=temp;
      size++;
      cout<<"pushed "<<val<<"  into the stack "<<endl;
      }
     

    }
    void pop(){
if(top==NULL){
     cout<<"stack underflow\n";
     return;
}
else{
 node* temp=top;
  cout<<"poped  "<<top->data<<" from stack "<<endl;
        top=temp->next;
        delete temp;
        size--;

}            
    }
int peek(){
    if(top==NULL){
        cout<<"stack is empty\n";
        return -1;
    }
    else{
        return top->data;
    }
}

bool isempty(){
    return top==NULL;
}
int issize(){
    return size;
}

};
int main() { 
    stack s;
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    cout<<s.peek();
    return 0;
}