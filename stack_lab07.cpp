//VALIDATION CODE
#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

bool validate(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {

        if (islower(s[i])) continue;

        else if (s[i] == '(') {
            st.push(s[i]);
        }

        else if (s[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        }

        else if (isOperator(s[i])) {
            if (i == 0 || i == s.size()-1) return false;
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (validate(s))
        cout << "Valid\n";
    else
        cout << "INVALID\n";

    return 0;
}


// INFIX → POSTFIX
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int main() {
    string s;
    cin >> s;

    stack<char> st;
    vector<char> output;

    for (int i = 0; i < s.size(); i++) {

        if (islower(s[i])) {
            output.push_back(s[i]);
        }

        else if (s[i] == '(') {
            st.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        else if (isOperator(s[i])) {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                output.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        output.push_back(st.top());
        st.pop();
    }

    // print postfix
    for (char c : output) cout << c;
    
    return 0;
}

//Q3: POSTFIX EVALUATION + UPDATE

#include <iostream>
#include <stack>
using namespace std;

bool evalPostfix(string pf, int vars[], int &result) {
    stack<int> st;

    for (char c : pf) {

        if (islower(c)) {
            st.push(vars[c - 'a']);
        }

        else {
            if (st.size() < 2) return false;

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') {
                if (b == 0) return false;
                st.push(a / b);
            }
            else if (c == '^') {
                int res = 1;
                for (int i = 0; i < b; i++) res *= a;
                st.push(res);
            }
        }
    }

    result = st.top();
    return true;
}

int main() {

    // default values
    int vars[26];
    for (int i = 0; i < 26; i++) {
        vars[i] = i + 1;
    }

    string pf;
    cin >> pf;   // postfix input

    int result;
    if (evalPostfix(pf, vars, result))
        cout << "Result: " << result;
    else
        cout << "INVALID";

    return 0;
}


//////////////////////////
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 🔹 check operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

// 🔹 precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 🔹 VALIDATION
bool validate(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {

        if (islower(s[i])) continue;

        else if (s[i] == '(') st.push(s[i]);

        else if (s[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        }

        else if (isOperator(s[i])) {
            if (i == 0 || i == s.size()-1) return false;
        }
    }

    return st.empty();
}

// 🔹 INFIX → POSTFIX
vector<char> toPostfix(string s) {
    stack<char> st;
    vector<char> output;

    for (int i = 0; i < s.size(); i++) {

        if (islower(s[i])) {
            output.push_back(s[i]);
        }

        else if (s[i] == '(') {
            st.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        else if (isOperator(s[i])) {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                output.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        output.push_back(st.top());
        st.pop();
    }

    return output;
}

// 🔹 POSTFIX EVALUATION
bool evalPostfix(vector<char> pf, int vars[], int &result) {
    stack<int> st;

    for (char c : pf) {

        if (islower(c)) {
            st.push(vars[c - 'a']);
        }

        else {
            if (st.size() < 2) return false;

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') {
                if (b == 0) return false;
                st.push(a / b);
            }
            else if (c == '^') {
                int res = 1;
                for (int i = 0; i < b; i++) res *= a;
                st.push(res);
            }
        }
    }

    result = st.top();
    return true;
}

// 🔥 MAIN
int main() {

    string expr;
    cin >> expr;

    int Q;
    cin >> Q;

    // 🔹 default values
    int vars[26];
    for (int i = 0; i < 26; i++) {
        vars[i] = i + 1;
    }

    while (Q--) {

        char type;
        cin >> type;

        if (type == 'E') {
            /*
            👉 L = start index
            👉 R = end index
            */
            int L, R;
            cin >> L >> R;

            string sub = expr.substr(L, R - L + 1);

            // validation
            if (!validate(sub)) {
                cout << "Result: INVALID\n";
                continue;
            }

            // postfix
            vector<char> pf = toPostfix(sub);

            // evaluation
            int result;
            if (!evalPostfix(pf, vars, result)) {
                cout << "Result: INVALID\n";
            } else {
                cout << "Result: " << result << endl;
            }
        }

        else if (type == 'U') {
            /*
            U x value
            x = variable
            value = new value

            U d 1
            d = 1
            */
            char x;
            int val;
            cin >> x >> val;
            vars[x - 'a'] = val;
        }
    }

    return 0;
}