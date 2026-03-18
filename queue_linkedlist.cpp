#include <iostream>
using namespace std;
class node{
    public:  
    int data;
    node *next;
    node(int val){
        data=val;
        next=nullptr;
    }

};
class queue{
  node *front;
  node *rear;
  public:
  queue(){
    front=rear=nullptr;
  }
  //queue is empty or not
  bool isempty(){
    return front==nullptr;
  }
  //push element into queue
  void push(int x){
    //if empty
    if(isempty()){
        cout<<"pushed "<<x<<"into the queue "<<endl;
     front=rear=new node(x);
    return;
    }
    //if it is not empty
    else{
       cout<<"pushed "<<x<<"into the queue "<<endl;  
     
      rear->next= new node(x); 
      rear=rear->next ;
    }
  }
  void pop(){
    if(isempty()){
        cout<<"queue is under flow "<<endl;
        return;
    }
   else{
    cout<<"poped "<<front->data<<" from the queue "<<endl;
    node*temp=front;
    front=front->next;
    delete temp;
   }
  }
  int start(){
    if(isempty()){
        cout<<"queue is empty "<<endl;
        return -1;
    }else{
        return front->data;
    }
  }
};
int main() {
   
    queue q;

    q.push(10);
    q.push(20);
    q.push(30);

   q.pop();

    cout << "Front element: " << q.start() << endl; 
    return 0;
}