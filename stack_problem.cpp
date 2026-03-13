//227. Basic Calculator II

#include <iostream>
#include <stack>
#include <string>
using namespace std;


    int calculate(string s) {

        stack<int> st;
        int len = s.length();
        int currentNumber = 0;
        char operation = '+';

        for(int i = 0; i < len; i++) {

            char currentChar = s[i];

            // build number
            if(isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }

            // if operator OR end of string
            if((!isdigit(currentChar) && !isspace(currentChar)) || i == len - 1) {

                if(operation == '-') {
                    st.push(-currentNumber);
                }
                else if(operation == '+') {
                    st.push(currentNumber);
                }
                else if(operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currentNumber);
                }
                else if(operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currentNumber);
                }

                operation = currentChar;
                currentNumber = 0;
            }
        }

        int result = 0;

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }

int main() {
    cout << calculate("3+5/2") << endl;
}

//496. Next Greater Element I
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> result;

        for(int i = 0; i < nums1.size(); i++) {

            int nextGreater = -1;
            int pos = -1;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) {
                    pos = j;
                    break;
                }
            }

            for(int k = pos + 1; k < nums2.size(); k++) {
                if(nums2[k] > nums1[i]) {
                    nextGreater = nums2[k];
                    break;
                }
            }

            result.push_back(nextGreater);
        }

        return result;
    }
};

int main() {

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    Solution obj;
    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}

// Infix → Postfix Conversion (Lab Favourite)
#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if(op=='+' || op=='-')
        return 1;
    if(op=='*' || op=='/')
        return 2;
    return 0;
}

int main()
{
    string infix;
    cin >> infix;

    stack<char> st;
    string postfix="";

    for(int i=0;i<infix.length();i++)
    {
        char c = infix[i];

        // if operand Alnum = Alphabet + Number0
        if(isalnum(c))
        {
            postfix += c;
        }

        // if '('
        else if(c=='(')
        {
            st.push(c);
        }

        // if ')'
        else if(c==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        // if operator
        else
        {
            while(!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}

//4️⃣ Prefix → Infix Conversion
/*
Example:

Input:
*+AB-CD

Output:

((A+B)*(C-D))
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string prefix;
    cin >> prefix;

    stack<string> st;

    for(int i = prefix.length()-1; i >= 0; i--)
    {
        char c = prefix[i];

        // operand
        if(isalnum(c))
        {
            //string(number_of_characters, character)
            string s(1,c);
            st.push(s);
        }

        // operator
        else
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string exp = "(" + op1 + c + op2 + ")";

            st.push(exp);
        }
    }

    cout << st.top();

    return 0;
}


/*
5️⃣ Postfix → Infix Conversion

Example:

Input:
AB+C*

Output:

(A+B)*C
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    cin >> postfix;

    stack<string> st;

    for(int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        // operand
        if(isalnum(c))
        {
            st.push(string(1,c));
        }
        else
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string exp = "(" + op2 + c + op1 + ")";

            st.push(exp);
        }
    }

    cout << st.top();
}