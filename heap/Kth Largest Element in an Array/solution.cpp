  #include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minheap;

    int n = nums.size();

    // Insert first k elements
    for (int i = 0; i < k; i++)
    {
        minheap.push(nums[i]);
    }

    // Process remaining elements
    for (int i = k; i < n; i++)
    {
        if (minheap.top() < nums[i])
        {
            minheap.pop();
            minheap.push(nums[i]);
        }
    }

    return minheap.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth Largest Element = " << findKthLargest(nums, k) << endl;

    return 0;
}