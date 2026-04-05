#include <iostream>
#include<vector>
#include<stack>
using namespace std;
/*
                                  stack
If a problem needs to compare the current element with the previous one, then it is a stack problem.
*/

/*
                      problem  Reverse Array:  https://leetcode.com/problems/reverse...
time complexity n+n=2(n)         O(n)
space complexity                 o(n)
*/


void reversestring(vector<char>&s){
      // Push all characters into stack
    stack<char>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
     // Pop characters back into vector (reversed)
    int i=0;
    while(!st.empty()){
        s[i]=st.top();
        i++;
        st.pop();
    }
}
int main() {
    vector<char> s={'h','e','l','l','o'};
    reversestring(s);
    for(char c: s){
        cout<<c;
    }
    cout<<endl;
    return 0;
}



/*
                   problem   Insert an Element at the Bottom of a Stack: https://www.geeksforgeeks.org/problem...
time complexity n+1+n           O(n)
space complexity                 o(n)
*/

#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> st, int x) {

    stack<int> temp;

    // Step 1: Move everything from st → temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Step 2: Push the new element at the bottom
    st.push(x);

    // Step 3: Move everything back from temp → st
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

int main() {
    stack<int> st;

    // Sample stack
    st.push(10);
    st.push(20);
    st.push(30);

    int x = 5; // Element to insert at bottom

    // Call function
    st = insertAtBottom(st, x);

    // Print final stack (top → bottom)
    cout << "Stack after inserting at bottom:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}


//                          Make the array beautiful: https://www.geeksforgeeks.org/problem...

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {

    stack<int> s;

    for(int i = 0; i < arr.size(); i++) {

        // stack empty
        if(s.empty()) {
            s.push(arr[i]);
        }

        // positive number
        else if(arr[i] >= 0) {
            if(s.top() >= 0) {
                s.push(arr[i]);
            } else {
                s.pop();
            }
        }

        // negative number
        else {
            if(s.top() < 0) {
                s.push(arr[i]);
            } else {
                s.pop();
            }
        }
    }

    // Convert stack to vector (correct order)
    vector<int> ans(s.size());
    int i = s.size() - 1;

    while(!s.empty()) {
        ans[i] = s.top();
        i--;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 2, -2, 1};   // You can change input here

    vector<int> result = makeBeautiful(arr);

    cout << "Beautiful Array: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//parenthesis valid or not
//time complexity   O(n)
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
bool check(string str){
    stack<char>s;
for(int i=0;i<str.size();i++){
    //opening
   if(str[i]=='('){
       s.push(str[i]);
    }
    //closing 
    else{
        if(s.empty()){
            return 0;
        }
        else{
            s.pop();
        }
    }
}
return s.empty();
};
int main() {
    string str="((())";
    cout<<check(str);
    return 0;
}

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
bool isValid(string s) {
        int count=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
             count++;
        }
        else{
            count--;
        }
        // if closing bracket comes before opening
            if(count < 0) return false;

       } 

        // at end, both must match
        return count == 0;
    }
int main() {
    string str="((())";
    cout<<isValid(str);
    return 0;
}


//                          Minimum Add to Make Parentheses Valid: https://leetcode.com/problems/minimum...
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minAddToMakeValid(string s) {

    stack<char> st;
    int count = 0;

    for(int i = 0; i < s.size(); i++) {

        // opening bracket
        if(s[i] == '('){
            st.push(s[i]);
        }
        // closing bracket
        else {
            if(st.empty()){
                count++;    // missing '('
            }
            else{
                st.pop();   // matched
            }
        }
    }

    return count + st.size();
}

int main() {
    string s = "()))((";   
    cout << "Minimum additions needed: " << minAddToMakeValid(s);
    return 0;
}


//6:                             Valid Parentheses:  https://leetcode.com/problems/valid-p...

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// your logic without class
bool isValid(string s) {
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {

        // opening
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }

        // closing
        else {

            // empty check
            if(st.empty()) {
                return false;
            }

            // )
            else if(s[i] == ')') {
                if(st.top() != '(') {
                    return false;
                }
                else {
                    st.pop();
                }
            }

            // }
            else if(s[i] == '}') {
                if(st.top() != '{') {   // Correct match
                    return false;
                }
                else {
                    st.pop();
                }
            }

            // ]
            else {
                if(st.top() != '[') {   // Correct match
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
    }

    return st.empty();
}

int main() {

    string s = "{[()]}";   

    if(isValid(s)) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }

    return 0;
}

//7:                       Backspace String Compare: https://leetcode.com/problems/backspa...
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool backspaceCompare(string s, string t) {

    stack<char> a;
    stack<char> b;

    // process s
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '#'){
            a.push(s[i]);
        } else {
            if(!a.empty()) a.pop();
        }
    }

    // process t
    for(int i = 0; i < t.size(); i++){
        if(t[i] != '#'){
            b.push(t[i]);
        } else {
            if(!b.empty()) b.pop();
        }
    }

    // Compare both stacks (C++20 and above)
    return a == b;
}

int main() {

    string s = "ab#c";
    string t = "ad#c";

    if(backspaceCompare(s, t))
        cout << "Strings are equal\n";
    else
        cout << "Strings are NOT equal\n";

    return 0;
}
//                            Print Bracket Number: https://www.geeksforgeeks.org/problem...
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<int> bracketNumbers(string str) {

    int count = 1;
    vector<int> ans;
    stack<int> st;

    for(int i = 0; i < str.size(); i++) {

        // opening bracket
        if(str[i] == '('){
            st.push(count);
            ans.push_back(count);
            count++;
        }

        // closing bracket
        else if(str[i] == ')'){
            if(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
    }

    return ans;
}

int main() {

    string str = "(a+(b*c)-((d/e)))";   // You can change input here

    vector<int> result = bracketNumbers(str);

    cout << "Bracket Numbers: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


//9:                                 Get min at pop: https://www.geeksforgeeks.org/problem...

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to push minimum-so-far values into stack
stack<int> _push(int arr[], int n) {
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            st.push(arr[i]);  // first element
        } else {
            st.push(min(arr[i], st.top()));  // store minimum so far
        }
    }

    return st;
}

// Function to print minimum at each pop
void _getMinAtPop(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {

    int arr[] = {1, 6, 43, 1, 2, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build special stack
    stack<int> st = _push(arr, n);

    // Print minimum at each pop
    cout << "Minimums at each pop: ";
    _getMinAtPop(st);

    return 0;
}

/*
1️⃣ Keep pushing characters into the stack until you see a )

(t, f, (, !, &, | — all go into the stack).

2️⃣ When you see ) → pop values until you reach (, convert them to true/false, and apply the operator

(! = flip the value,
& = check if ALL are true,
| = check if ANY is true)

3️⃣ Take the final true/false result, convert it back to 't' or 'f', and push it into the stack; the last value left is the final answer.*/
//10: 1106 parsing A Boolean Expression

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool parseBoolExpr(string e) {
stack<char>st;
for(int i=0;i<e.size();i++){
    if(e[i]=='&'||e[i]=='('||e[i]=='t'||e[i]=='f' ||e[i]=='!' ||e[i]=='|'){
        st.push(e[i]);
    }
    else if(e[i]==')'){
        vector<bool>values;
        while(st.top()!='('){
            char ch=st.top();
            values.push_back(ch=='t');
            st.pop();
        }
        st.pop();
        char op=st.top();
        st.pop();
        bool result;
        if(op=='!'){
            return !values[0];
        }
        else if(op=='&'){
             result=true;
         for(int i=0;i<values.size();i++){
            result &=values[i];
         }
        }
        else{
         result=false;
         for(int i=0;i<values.size();i++){
            result |=values[i];
         } 
        } 

        if(result==true){
           st.push('t');
        }
        else{
            st.push('f');
        }
    }
}
 return st.top()=='t';
    
};

int main() {

    string expr;
    cout << "Enter boolean expression: ";
    getline(cin, expr);

    bool ans = parseBoolExpr(expr);

   if(ans == true) {
    cout << "Result: true" << endl;}
   else {
    cout << "Result: false" << endl;}
    return 0;
}


//                                      problem Evaluate Reverse Polish Notation
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int Operate(int a, int b, string token) {
    if(token == "+") return a + b;
    if(token == "-") return a - b;
    if(token == "*") return a * b;
    if(token == "/") return a / b; 
    return 0;
}

// Evaluate Reverse Polish Notation
int evalRPN(vector<string>& tokens) {

    stack<int> st;

    
    for(int i = 0; i < tokens.size(); i++) {

        string token = tokens[i];

        // If operator found
        if(token == "+" || token == "-" || token == "*" || token == "/") {

            // Pop top 2 values
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            // Apply operator
            int result = Operate(a, b, token);

            // Push result back
            st.push(result);
        }
        else {
            // Otherwise it's a number → convert & push
            st.push(stoi(token));
        }
    }

    // Final element is answer
    return st.top();
}
int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};  
    int ans = evalRPN(tokens);

    cout << "Result = " << ans << endl;

    return 0;
}





/*                                              402. Remove K Digits
problem yeha sa agaa karna hein
 Technique:
        - Monotonic Increasing Stack
        - Jab chhota digit mile → bada digit pop
        - End me stack ko string me convert karna
        - Reverse karna kyunki stack ulta hota hai
        - Leading zeroes remove karna
*/

#include <iostream>
using namespace std;



    // Function to remove leading zeroes from final answer
    string removeLeadingZeroes(string& s) {
        int i = 0;

        // Count how many zeroes are at the beginning
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        // If whole string is zero (Example: "0000")
        if (i == s.size()) {
            return "0";
        }
        // Otherwise return substring starting after leading zeroes
        else {
            return s.substr(i); 
        }
    }

    // Main function to remove k digits to make smallest number
    string removeKdigits(string num, int k) {

        string ans;
        stack<char> st;

        // Step 1: Build monotonic increasing stack
        for (int i = 0; i < num.size(); i++) {

            // Remove bigger digits from stack if smaller digit found
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            // Push current digit
            st.push(num[i]);
        }

        // Step 2: If some k still left, remove from end (stack top)
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: Convert stack → string (stack gives reverse order)
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Step 4: Reverse to get correct order
        reverse(ans.begin(), ans.end());

        // If empty return "0"
        if (ans.empty())
            return "0";

        // Step 5: Remove leading zeros
        return removeLeadingZeroes(ans);
    }
int main() {

    string num;
    int k;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter k: ";
    cin >> k;

    string result = removeKdigits(num, k);

    cout << "Result: " << result << endl;

    return 0;
}



//2000           Reverse prefix of word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stack;
        string result;

        int index = 0;
        while (index < word.length()) {
            stack.push(word[index]);
            // Found ch
            if (word[index] == ch) {
                // Add characters through ch to the result in reverse order
                while (!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
                index++;
                // Add the rest of the characters to result
                while (index < word.length()) {
                    result.push_back(word[index]);
                    index++;
                }
                return result;
            }
            index++;
        }

        return word;
    }
};


//1021              remove outermost parentheses
/*
addded to anser if counter !=0
) after counter=0 counter--
 counter=0  before ( counter++
*/
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;

        for (int i=0;i<s.length();i++) {
            if (s[i] == '(') {
                if (balance > 0) result += s[i];
                balance++;
            } else {
                balance--;
                if (balance > 0) result += s[i]; 
            }
        }
        return result;
    }

//LeetCode 496 — Next Greater Element I
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);   // initialize all with -1
        for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 if (arr[j] > arr[i]) {
                    ans[i] = arr[j];   // store next greater
                    break;             // stop after first greater
                }

            }
        }

        return ans;
    }
};

  


//prolem      next greater
class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // stores indexes in the stack
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

//problem  next greater circular array
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Loop twice → circular effect
        for (int i = 0; i < 2 * n; i++) {

            int idx = i % n;  // circular index

            while (!st.empty() && arr[idx] > arr[st.top()]) {
                ans[st.top()] = arr[idx];
                st.pop();
            }

            // Only push indexes in first round
            if (i < n) st.push(idx);
        }

        return ans;
    }
};

//problem (Maximum Absolute Difference) 
#include <iostream>
using namespace std;

int maxAbsDiff(int arr[], int n) {

    vector<int> LS(n, 0);   // Left Smaller
    vector<int> RS(n, 0);   // Right Smaller
    stack<int> st;

    // ------------ LEFT SMALLER (LS[i]) ------------
    for (int i = 0; i < n; i++) {

        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // instead of: LS[i] = st.empty() ? 0 : st.top();
        if (st.empty()) {
            LS[i] = 0;
        } else {
            LS[i] = st.top();
        }

        st.push(arr[i]);
    }

    // clear stack for RS[]
    while (!st.empty()) st.pop();

    // ------------ RIGHT SMALLER (RS[i]) ------------
    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // instead of: RS[i] = st.empty() ? 0 : st.top();
        if (st.empty()) {
            RS[i] = 0;
        } else {
            RS[i] = st.top();
        }

        st.push(arr[i]);
    }

    // ------------ MAX ABSOLUTE DIFFERENCE ------------
    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
        int diff = abs(LS[i] - RS[i]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }

    return maxDiff;
} 
  
//problem  Next Smaller Element: https://www.codingninjas.com/studio/p...

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// ----------- NEXT SMALLER ELEMENT FUNCTION -----------
vector<int> nextSmaller(vector<int> &arr) {
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n,-1);
  for(int i=0;i<arr.size();i++){
    while(!st.empty() &&arr[st.top()]>arr[i]){
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

    cout << "Next Smaller Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

