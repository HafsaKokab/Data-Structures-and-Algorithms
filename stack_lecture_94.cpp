//1: Get Minimum Element from Stack: https://www.geeksforgeeks.org/problem...

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> st1;  // original values
    stack<int> st2;  // minimum values

public:
    SpecialStack() {
        // constructor
    }

    void push(int x) {
        if(st1.empty()) {
            st1.push(x);
            st2.push(x);
        }
        else {
            st1.push(x);
            st2.push(min(x, st2.top()));
        }
    }

    void pop() {
        if(st1.empty()) {
            return;
        }
        st1.pop();
        st2.pop();
    }

    int peek() {
        if(st1.empty()) {
            return -1;
        }
        return st1.top();
    }

    bool isEmpty() {
        return st1.empty();
    }

    int getMin() {
        if(st2.empty()) {
            return -1;
        }
        return st2.top();
    }
};

// -----------------------------------------
//                MAIN FUNCTION
// -----------------------------------------

int main() {

    SpecialStack s;

    // Example operations
    s.push(2);
    s.push(3);
    cout << "Top = " << s.peek() << endl;        // 3
    cout << "Min = " << s.getMin() << endl;      // 2

    s.pop();
    cout << "Min after pop = " << s.getMin() << endl;   // 2

    s.push(1);
    cout << "New Min = " << s.getMin() << endl;  // 1

    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
//another solution if range is given

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> st; 
public:
    SpecialStack() {
        // constructor
    }

    void push(int x) {
       if(st.empty()){
        st.push(x*101+x);
       }
       else{
        st.push(x+min(x,st.top()%101))
       }
    }

    void pop() {
       if(st.empty()){
        return -1;
       }
       else{
        int element=st.top()%101;
        st.pop();
        return element;

       }
    }

   

    int getMin() {
       if(st.empty()){
        return -1;
       }
       else{
        return st.top()%101;
       }
    }
};

// -----------------------------------------
//                MAIN FUNCTION
// -----------------------------------------

int main() {

    SpecialStack s;

    // Example operations
    s.push(2);
    s.push(3);
     cout << "Min = " << s.getMin() << endl;      // 2

    s.pop();
    cout << "Min after pop = " << s.getMin() << endl;   // 2

    s.push(1);
    cout << "New Min = " << s.getMin() << endl;  // 1

   
    return 0;
}
//2: Maximum of minimum for every window size: https://www.geeksforgeeks.org/problem...
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {10,20,15,50,10,70,30};  // you can change input
    int n = arr.size();

    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++)          // window size i+1
    {
        for(int j = 0; j < n - i; j++)  // window start
        {
            int num = INT_MAX;

            for(int k = j; k < j + i + 1; k++)   // window j → j+i
            {
                num = min(num, arr[k]);
            }

            ans[i] = max(ans[i], num);
        }
    }

    // print output
    for(int x : ans)
        cout << x << " ";

    return 0;
}