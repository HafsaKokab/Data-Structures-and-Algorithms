//method 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallest(vector<int>& arr, int k)
{
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Return the kth smallest element
    return arr[k - 1];
}

int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << "Kth Smallest Element = " << kthSmallest(arr, k);

    return 0;
}
//method 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& arr, int k)
{
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all elements into Min Heap
    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }

    // Remove first (k-1) smallest elements
    for (int i = 1; i < k; i++)
    {
        minHeap.pop();
    }

    // Top is the kth smallest element
    return minHeap.top();
}

int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << "Kth Smallest Element = " << kthSmallest(arr, k);

    return 0;
}

//method 3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& arr, int k)
{
    int n = arr.size();

    // Max Heap
    priority_queue<int> p;

    // Insert first k elements
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    // Process remaining elements
    for (int i = k; i < n; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << "Kth Smallest Element = " << kthSmallest(arr, k) << endl;

    return 0;
}
