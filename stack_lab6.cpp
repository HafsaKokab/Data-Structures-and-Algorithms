
/*
Remove k digits from a number (given as a string) to form the smallest possible number without leading zeros. If all digits are removed, return "0".
*/
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string kdigitremoval(string m,int k){

    stack<char> st;

    for(int i=0;i<m.size();i++){
        if(k>=m.size()){
            return "0";
        }

        while(!st.empty() && st.top() > m[i] && k>0){
            st.pop();
            k--;
        }

        st.push(m[i]);
    }

    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
  // string += char → character append hota hai
    string ans="";

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
     // remove leading zeros
    int i=0;
    while(i < ans.size() && ans[i]=='0'){
        i++;
    }

    ans = ans.substr(i);

    if(ans == ""){
        return "0";
    }

    return ans;
}

int main(){

    string m;
    int k;

    cout<<"enter number"<<endl;
    cin>>m;

    cout<<"digits to remove"<<endl;
    cin>>k;

    cout<<kdigitremoval(m,k)<<endl;

    return 0;
}


/*
Write a program to evaluate a Boolean expression given as a string. The expression may contain the operators ! (NOT), & (AND), | (OR) and operands t (true) and f (false). The program should parse the expression using a stack and return the final Boolean result.
Example:
Input:
!( &(f,t) )

Output:
true
*/
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