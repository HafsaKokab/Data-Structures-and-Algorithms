
//BaseballGameScoring
#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void score(stack<int>&st,string op){
    
     if(op == "+"){
        int x = st.top();
        st.pop();
        int y = st.top();
        st.push(x);
        st.push(x+y);
     }
     else if(op=="C"){
        st.pop();
     }
     else if(op=="D"){
       int x =st.top()*2;
       st.push(x);
     }
     else{
        st.push(stoi(op));
     }
}

int main() {

    int t;
    cin>>t;
    vector<int>ans;
    for(int i=0;i<t;i++){

        stack<int>st;
        string op;
        int k;
        cin>>k;

        for(int j=0;j<k;j++){
            cin>>op;
            score(st,op);
        }

        int sum=0;

        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        ans.push_back(sum);
        
    }
    cout<<"final answers are: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}

//Bracket Scoring Problem 
#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
 int bracket(string m){
    stack<char>st;
    int score=0;
    for(int i=0;i<m.size();i++){
      if(m[i]=='(' || m[i]=='{' || m[i]=='['){
    st.push(m[i]);
   }
   else{
   
      if(st.empty()){
        return 0;
      }
        int depth=st.size();
      if(st.top()=='(' && m[i]==')' ){  
         score+=1*depth;
         st.pop();
      }
       else if(st.top()=='{' && m[i]=='}' ){ 
        int depth=st.size();
         score+=3*depth;
         st.pop();
      }
       else if(st.top()=='[' && m[i]==']' ){
        int depth=st.size();
        score+=2*depth;
        st.pop();
      }
      else {
        return 0;
      }
      
   }
    }
    return score;
 
 }
    
int main() {
    int n;
    cin>>n;
    string m;
    vector<int>ans;
    int sum=0;
    while(n--){
        cin>>m;
     int x= bracket(m);
     ans.push_back(x);
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]==0){
            cout<<"invalid "<<endl;
        }
        else{
            cout<<ans[i]<<endl;
        }
    }

       
    return 0;
}