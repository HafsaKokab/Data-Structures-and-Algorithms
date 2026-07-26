#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // Max Heap
        priority_queue<int> p;

        // Insert all stones into the heap
        for (int i = 0; i < stones.size(); i++) {
            p.push(stones[i]);
        }

        while (p.size() > 1) {

            int first = p.top();
            p.pop();

            int second = p.top();
            p.pop();

            int weight = first - second;

            if (weight > 0) {
                p.push(weight);
            }
        }

        return p.empty() ? 0 : p.top();
    }
};

int main() {

    int n;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stones(n);

    cout << "Enter stone weights: ";
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    Solution obj;

    cout << "Last Stone Weight = " << obj.lastStoneWeight(stones) << endl;

    return 0;
}
