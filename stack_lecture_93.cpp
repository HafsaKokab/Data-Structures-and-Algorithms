//1: The Celebrity Problem: https://www.geeksforgeeks.org/problem...
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

// Brute force check if a person is celebrity
int celebrity(vector<vector<int>>& mat) {
     int n=mat.size();
     for(int k=0;k<n;k++){
        bool knowsnobody=true;
        bool knowsbyall=true;
        //wo ksisi ko b na jaanata ho
        for(int j=0;j<n;j++){
             if(k!=j && mat[k][j]==1){
                knowsnobody=false;
                break;
             }
        }
        //sab us ko janta hon
        for(int i=0;i<n;i++){
            if(k!=i && mat[i][k]==0){
                knowsbyall=false;
                break;
            }
        }
        if(knowsnobody &&knowsbyall ){
            return k;
        }
     }
     return -1;
    }
int main() {
    vector<vector<int>> mat = {
        {0, 1, 0,1,1},
        {0,0,0,1,1 },
        {0, 1,0,1,0},
        {0,0,0,0,0},
        {1,0,1,1,0}
    };

    cout << celebrity(mat);
    return 0;
}

//////////////optimise sol
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        int n = mat.size();
        stack<int> st;

        // push all persons
        for(int i = n - 1; i >= 0; i--) {
            st.push(i);
        }

        // elimination using YOUR LOGIC
        while(st.size() > 1) {

            int first = st.top(); 
            st.pop();

            int second = st.top(); 
            st.pop();

            // your logic condition 1
            if(mat[first][second] == 1 && mat[second][first] == 0) {
                st.push(second);
            }
            // your logic condition 2
            else if(mat[first][second] == 0 && mat[second][first] == 1) {
                st.push(first);
            }
            else {
                // if both are 0,0 or 1,1 → none is celeb
                // do nothing (both eliminated)
            }
        }

        // if no candidate
        if(st.empty()) return -1;

        int num = st.top();
        st.pop();

        // verify candidate
        int row = 0, col = 0;
        for(int i = 0; i < n; i++) {
            if(i !=num){
             row += mat[num][i];   // candidate should know no one
             col += mat[i][num];   // everyone should know candidate
     
            }
               }

        return (row == 0 && col == n - 1) ? num : -1;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1,0,1,1},
        {0,1,1,1},
        {1,1,1,1},
        {0,0,0,1}
    };

    Solution s;
    cout << s.celebrity(mat);
}
