#include <iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
/*
Complexity	Value
Time Complexity	O(n)
Space Complexity	O(n)
*/
// void printqueue(queue<int>&q){
//     vector<int>ans;
// while(!q.empty()){
//     cout<<q.front()<<endl;
//     ans.push_back(q.front());
//     q.pop();
// }
// for(int i=0;i<ans.size();i++){
//     q.push(ans[i]);
// }
// };
// int main() {
//      queue<int>q;
//      q.push(2);
//      q.push(4);
//      q.push(6);
//      q.push(3);
//      q.push(5);
//      printqueue(q);
//     return 0;
// }

////////////////////////////
// void printqueue(queue<int>&q){
//    int n=q.size();
//    while(n--){
//     cout<<q.front()<<" ";
//     q.push(q.front());
//     q.pop();
//    }
// };
// int main() {
//      queue<int>q;
//      q.push(2);
//      q.push(4);
//      q.push(6);
//      q.push(3);
//      q.push(5);
//      printqueue(q);
//     return 0;
// }

//1: Reverse Queue: https://www.geeksforgeeks.org/problem...
/*
Complexity	Value
Time Complexity	O(n)
Space Complexity	O(n)
*/

// void queuereverse(queue<int>&q){
//    stack<int>st;
//     // Step 1: Queue → Stack
//    while(!q.empty()){
//     st.push(q.front());
//     q.pop();
//    }
//     // Step 2: Stack → Queue
//    while(!st.empty()){
//     q.push(st.top());
//     st.pop();
//    }
// }
// int main() {
//      queue<int>q;
//      q.push(2);
//      q.push(4);
//      q.push(6);
//      q.push(3);
//      q.push(5);
//      queuereverse(q);
//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         q.pop();
//     }     

//     return 0;
// }

//2: Reverse First K Elements of Queue: https://www.geeksforgeeks.org/problem...

 void queuereverse(queue<int>&q,int k){
     if(k > q.size()){
        cout<<"invalid "<<endl;
        return;
     }
            
   stack<int>st;
   while(k--){
    st.push(q.front());
    q.pop();
   }
   int n=q.size();
    while(! st.empty()){
    q.push(st.top());
    st.pop();
   }
   while(n--){
    q.push(q.front());
    q.pop();
    
   }
}
int main() {
     queue<int>q;
     int k;
     cin>>k;
     q.push(2);
     q.push(4);
     q.push(6);
     q.push(3);
     q.push(5);
     queuereverse(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }     

    return 0;
}

//3: TIme Needed To Buy Tickets: https://leetcode.com/problems/time-ne...
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();

    queue<int> q;

    // push all indices in queue
    for(int i = 0; i < n; i++){
         //queue contain only idx for that ele that still wants ticket
        q.push(i);
    }

    int time = 0;

    while(tickets[k] != 0){
        int idx = q.front();
        q.pop();

        tickets[idx]--;   // person buys one ticket
        time++;

        if(tickets[idx] > 0){
            q.push(idx);  // go back to line
        }
    }

    return time;
}

int main() {

    vector<int> tickets = {2,3,2};
    //k = index hi hota hai
    int k = 2;

    cout << timeRequiredToBuy(tickets, k);

    return 0;
}


////////////////////
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();

    queue<int> q;
    int time =0;
    // push all indices in queue
    for(int i = 0; i <=k; i++){
        time+=min(tickets[k],tickets[i]);
    }
    for(int i = k+1; i <n; i++){
        time+=min(tickets[k]-1,tickets[i]);
    }
    return time;


   
}

int main() {

    vector<int> tickets = {2,6,4,3,7};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k);

    return 0;
}

 //5:  Implement Queue using Stacks: https://leetcode.com/problems/impleme...
 #include <iostream>
#include<stack>
#include <queue>
#include <vector>
using namespace std;
/*

Push: -->  is implement in stack 1
Add the element to st1.

Pop / Peek: --> pop operation in stack2
If st2 is empty, move all elements from st1 to st2.
This reverses the order so the oldest element comes on top of st2.
Then pop or peek from st2.

Empty:
Queue is empty if both stacks are empty.
*/

class MyQueue {
public:
 stack<int>st1;
 stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
       st1.push(x);
    }
    
    int pop() {
        //empty()
          if(empty()){
            return 0;
         }
         //if st2 is not empty
         else if(!st2.empty()){
             int ele=st2.top();
             st2.pop();
             return  ele;
         }
         //if st2 is empty()
         else{
            while(!st1.empty()){
             st2.push(st1.top());
             st1.pop();
            }
            int ele= st2.top();
            st2.pop();
            return ele;
         } 
    }
    
    int peek() {
         if(empty()){
            return 0;
         }
         //if st2 is not empty
         else if(!st2.empty()){ 
             return  st2.top();
         }
         else{
            while(!st1.empty()){
             st2.push(st1.top());
             st1.pop();
            }
            return st2.top();
         }
    }
    
    bool empty() {
        return st1.empty() &&st2.empty();
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front element: " << q.peek() << endl;

    if(q.empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}

//4: Implement Stack Using Queue: https://leetcode.com/problems/impleme..
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
   queue<int> q1;
   queue<int> q2;

    MyStack() {}

    void push(int x) {
      if(empty()){
        q1.push(x);
      }
      else if(q1.empty()){
        q2.push(x);
      }
      else{
        q1.push(x);
      }
    }

    int pop() {
        if(empty()){
            return 0;
        }
        else if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else{
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }

    int top() {
        if(empty()){
            return 0;
        }
        else if(q1.empty()){
            return q2.back();
        }
        else{
            return q1.back();
        }
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {

    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;

    cout << "Top element: " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}





