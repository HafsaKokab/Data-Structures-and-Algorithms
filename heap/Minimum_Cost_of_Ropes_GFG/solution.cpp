#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& arr) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }

        int cost = 0;

        while (pq.size() > 1) {

            int first = pq.top();
            pq.pop();

            first += pq.top();
            pq.pop();

            cost += first;

            pq.push(first);
        }

        return cost;
    }
};

int main() {

    int n;
    cout << "Enter number of ropes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter rope lengths: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Minimum Cost = " << obj.minCost(arr);

    return 0;
}  
