#include <iostream>
using namespace std;
//implement queue using circular aray,cicular queue
class queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    queue(int n){
     arr=new int[n];
     front=-1;
     rear=-1;
     size=n;
    }
    //if queue is empty or not
    bool isfull(){
      return (rear++)%size==front;
    }
    bool isempty(){
     return front== -1;
    }
    //push element in queue...queue happens at the end of queue
    void push(int x){
      if(isempty()){
        cout<<"pushed "<<x<<" into the queue"<<endl;
        front++;
        rear++;
        arr[0]=x;
      }
      else if(isfull()){
        cout<<" queue overflow\n "<<endl;
        return ;
      }
      else{
        (rear++)%size;
        arr[rear]=x;
         cout<<"pushed "<<x<<" into the queue"<<endl;
      }
    }
     //pop element in queue...queue happens at the start of queue
    void pop(){
        if(isempty()){
            cout<<"queue underflow "<<endl;
            return ;
        }
        else{
        if(front==rear){
            cout<<"pop "<<arr[front]<<" into the queue"<<endl;
            front=rear=-1;
        }
        else{
             cout<<"pop "<<arr[front]<<" into the queue"<<endl;
            (front++)%size;
        }         
        }
    }
    int start(){
        if(isempty()){
            cout<<"no element is present "<<endl;
            return -1;
        }
        else{
               return arr[front];
         
        }
    }

};

int main() {
    queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.pop(); 
    int x=q.start();
    if(!q.isempty()){
        cout<<x<<" ";
    }

    return 0;
}