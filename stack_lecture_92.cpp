
//1: Largest Rectangle in Histogram: https://leetcode.com/problems/largest...
#include <iostream>
#include<stack>
#include<vector>
using namespace std; 


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;

        // next smallest right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // stack ko empty karo
        while (!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // next smallest left
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && heights[j] < heights[st.top()]) {
                left[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        // stack ko empty karo
        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }


int main() {
    

    // Example input (you can change it)
    vector<int> heights = {2,3,4,2,6,5,4,5,3};

    int result = largestRectangleArea(heights);

    cout << "Largest Rectangle Area = " << result << endl;

    return 0;
}


//optimise code 
#include <iostream>
#include<stack>
#include<vector>
using namespace std; 


    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        int index;
        stack<int>st;
        for(int i=0;i<n;i++){
           
            while( !st.empty() && heights[st.top()]>heights[i]){
                 int index=st.top();
                 st.pop();
                 if (!st.empty()){
                  ans=max(ans,heights[index]*(i-st.top()-1)); 
                 }
                 else{
                   ans=max(ans,heights[index]*i);  
                 }
            }
            st.push(i);
        }
        while(!st.empty()){
            int index=st.top();
                 st.pop();
                 if (!st.empty()){
                  ans=max(ans,heights[index]*(n-st.top()-1)); 
                 }
                 else{
                   ans=max(ans,heights[index]*n);  
                 } 
        }
        return ans;
        }
        
  

int main() {
    

    // Example input (you can change it)
    vector<int> heights = {2,3,4,2,6,1,4,5,3};

    int result = largestRectangleArea(heights);

    cout << "Largest Rectangle Area = " << result << endl;

    return 0;
}

// 2: Maximal Rectangle: https://leetcode.com/problems/maximal...

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();

                if (!st.empty()) {
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                } else {
                    ans = max(ans, heights[index] * i);
                }
            }
            st.push(i);
        }

        while (!st.empty()) {
            int index = st.top();
            st.pop();

            if (!st.empty()) {
                ans = max(ans, heights[index] * (n - st.top() - 1));
            } else {
                ans = max(ans, heights[index] * n);
            }
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example test matrix
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int result = obj.maximalRectangle(matrix);

    cout << "Maximal Rectangle Area = " << result << endl;

    return 0;
}