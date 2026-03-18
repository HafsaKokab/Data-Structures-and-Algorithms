/*
Short Logic Note:

First push k-1 elements into the queue.
Then for each step, push the next element to complete the window.
Print the queue (current window).
After that pop the front element (because queue follows FIFO) to maintain the window size = k.

Even shorter memory line
Push k-1 → Push next → Print window → Pop front → Next window
*/


//print all number in every window of size k

#include <iostream>
#include<queue>
using namespace std;
//pass by value not by reference 
void display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
          q.pop();
    }
    cout<<endl;
}
int main(){

    int arr[]={2,3,1,5,6,7,8};
    int n=7;
    int k=3;
    queue<int>q;
    // k-1 element ko push kar do queue kay andr
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    for(int i=k-1;i<n;i++){
        //push that index element
        q.push(arr[i]);
        //print the queue
       display(q);
       //pop
        q.pop();
    }


    return 0;
}

//1: first-negative-integer-in-every-window-of-size-k: https://www.geeksforgeeks.org/problem...

/*
In a queue, there is no indexing (you cannot access elements like q[0], q[1]).

Only these operations are allowed:

push() → Add an element at the back (end) of the queue.

pop() → Remove the element from the front of the queue.

front() → See the first element of the queue.

back() → See the last element of the queue.
*/
#include <iostream>
#include<queue>
#include <vector>
using namespace std;
//pass by value not by reference 
int display(queue<int>q){
    while(!q.empty()){
       if(q.front()<0){
        return q.front();
       }
        q.pop(); 
    }
    return 0;
}
int main(){

    int arr[]={2,-3,-4,-2,7,8,9,-10};
    int n=7;
    int k=3;
    queue<int>q;
    // k-1 element ko push kar do queue kay andr
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    vector<int>ans;
    for(int i=k-1;i<n;i++){
        //push that index element
        q.push(arr[i]);
        //print the queue
       ans.push_back(display(q));
       //pop
        q.pop();
    }
    for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
    return 0;
}


//optimization
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int arr[]={2,-3,-4,-2,7,8,9,-10};
    int n=8;
    int k=3;

    queue<int> q;

    // first k-1 elements
    for(int i=0;i<k-1;i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }

    vector<int> ans;

    for(int i=k-1;i<n;i++){

        // remove out of window index
        if(!q.empty() && q.front() <= i-k){
            q.pop();
        }

        // push current index
        if(arr[i] < 0){
            q.push(i);
        }

        // answer
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

//2: /first-non-repeating-character-in-a-stream-of-character: https://www.interviewbit.com/problems...
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string solve(string A) {

    string B = "";

    vector<int> repeated(26,0);
    queue<char> q;

    for(int i = 0; i < A.size(); i++)
    {

        // repeated
        if(repeated[A[i]-'a'] >= 1)
        {
            //increase the count in queue
            repeated[A[i]-'a']++;
           //remove the repeated element from queue
            while(!q.empty() && repeated[q.front()-'a'] > 1)
            {
                q.pop();
            }

            if(q.empty())
                B += '#';
            else
                B += q.front();
        }

        // non repeated
        else
        {
            //its first time increase count
            repeated[A[i]-'a']++;
            //place it in queue
            q.push(A[i]);

            while(!q.empty() && repeated[q.front()-'a'] > 1)
            {
                q.pop();
            }

            if(q.empty())
                B += '#';
            else
                B += q.front();
        }
    }

    return B;
}

int main()
{
    string A = "ababdc";

    cout << solve(A);

    return 0;
}