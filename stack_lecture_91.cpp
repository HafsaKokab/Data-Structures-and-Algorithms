//problem Smallest Number on Left: https://www.geeksforgeeks.org/problem...
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ---------- YOUR LOGIC (unchanged) ----------
vector<int> leftSmaller(vector<int> arr) {

    int n = arr.size();
    stack<int> st;               // stack stores INDEXES
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] > arr[i]) {
            ans[st.top()] = arr[i];   // left smaller found
            st.pop();
        }

        st.push(i);    // push index
    }

    return ans;
}

// -------------- MAIN FUNCTION --------------
int main() {

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = leftSmaller(arr);

    cout << "Left Smaller: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}


//Problem  NEAREST GREATER ELEMENT
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// ----------- NEAREST GREATER ELEMENT FUNCTION -----------
vector<int> nextSmaller(vector<int> &arr) {
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n,-1);
  for(int i=n;i>0;i--){
    while(!st.empty() &&arr[st.top()]<arr[i]){
        ans[st.top()]=arr[i];
        st.pop();
    }
    st.push(i);
  }
  return ans;
    
}

// ------------------- MAIN FUNCTION -------------------
int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextSmaller(arr);

    cout << "Next GREATER Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
//problem  Stock Span: https://www.geeksforgeeks.org/problem...

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        if(st.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - st.top();

        st.push(i);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = calculateSpan(arr);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}