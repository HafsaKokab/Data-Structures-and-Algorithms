
//method 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumBetweenK1K2(vector<int>& arr, int k1, int k2)
{
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    int sum = 0;

    // Step 2: Sum elements between k1th and k2th smallest
    for (int i = k1; i < k2 - 1; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3;
    int k2 = 6;

    cout << "Sum = " << sumBetweenK1K2(arr, k1, k2) << endl;

    return 0;
}
//method 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sumBetweenK1K2(vector<int>& arr, int k1, int k2)
{
    int n = arr.size();

    priority_queue<int> p1;
    priority_queue<int> p2;

    int sum1 = 0;
    int sum2 = 0;

    // Max Heap for first k1 elements
    for (int i = 0; i < k1; i++)
    {
        p1.push(arr[i]);
    }

    // Max Heap for first (k2 - 1) elements
    for (int i = 0; i < k2 - 1; i++)
    {
        p2.push(arr[i]);
    }

    // Find k1 smallest elements
    for (int i = k1; i < n; i++)
    {
        if (arr[i] < p1.top())
        {
            p1.pop();
            p1.push(arr[i]);
        }
    }

    // Find (k2 - 1) smallest elements
    for (int i = k2 - 1; i < n; i++)
    {
        if (arr[i] < p2.top())
        {
            p2.pop();
            p2.push(arr[i]);
        }
    }

    // Sum of k1 smallest elements
    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }

    // Sum of (k2 - 1) smallest elements
    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    // Required sum
    return sum2 - sum1;
}

int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3;
    int k2 = 6;

    cout << "Sum = " << sumBetweenK1K2(arr, k1, k2) << endl;

    return 0;
}