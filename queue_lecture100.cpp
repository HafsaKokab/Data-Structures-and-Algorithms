//1: Sliding Window Maximum: https://leetcode.com/problems/sliding...
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    vector<int> nums = {4,3,7,5,2,3,1,2,8,7};
    int k = 4;

    int n = nums.size();
    vector<int> ans;

    for(int i = 0; i <= n - k; i++) {

        int total = INT_MIN;

        for(int j = i; j < i + k; j++) {
            total = max(nums[j], total);
        }

        ans.push_back(total);
    }

    // print result
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

//optimization
/*
Time Complexity = O(n)
Space Complexity = O(k)
*/
#include <iostream>
#include <vector>
#include<deque>
#include <climits>
using namespace std;

int main() {

    vector<int> nums = {4,3,7,5,2,3,1,2,8,7};
    int k = 4;
    deque<int>d;
    int n = nums.size();
    vector<int> ans;
 for(int i=0;i<k-1;i++){   //k times
    if(d.empty()){
      d.push_back(i); 
    }
    else{
        while( !d.empty() &&nums[i]>nums[d.back()]){
      d.pop_back();
        }
        d.push_back(i);
    }
 }
 for(int i=k-1;i<n;i++){  //n-k+1   appro ntimes
 while( !d.empty() &&nums[i]>nums[d.back()]){
      d.pop_back();
        }
        d.push_back(i);
        //check the window size
        if(d.front()<=i-k){
            d.pop_front();
        }
        ans.push_back(nums[d.front()]);
 }
 for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
    return 0;
}

//2: Minimum Number of K Consecutive Bit Flips: https://leetcode.com/problems/minimum..
#include <iostream>
#include <vector>
#include<deque>
#include <climits>
using namespace std;
/*
Time Complexity = O(nk)
Space Complexity = O(1)
*/

int main() {

    vector<int> nums = {0,0,1,0,0,1,1,0,1,0};
    int k = 4;
    deque<int>d;
    int n = nums.size();
    vector<int> ans;
    int flip=0;
 for(int i=0;i<n;i++){  //ntimes
    if(nums[i]==0){
        //if window is not found
        if(i+k-1>=n){
            return -1;
        }
        //window size
        for(int j=i;j<=i+k-1;j++){ //k times
            nums[j]=!nums[j];
        }
        flip++;
    }
 }
 cout<<flip;
    return 0;
}


//optimization
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    int flip = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {

        // if it is not a part of window
        if (!q.empty() && q.front() < i) {
            q.pop();
        }

        // we have to flip
        if (q.size() % 2 == nums[i]) {

            // window does not exist
            if (i + k - 1 >= n) {
                return -1;
            }

            // push that window end in queue
            q.push(i + k - 1);
            flip++;
        }
    }

    return flip;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0/1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int result = minKBitFlips(nums, k);

    cout << "Minimum K Bit Flips: " << result << endl;

    return 0;
}