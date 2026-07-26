#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<int> &A, int B)
{
    // Max Heap
    priority_queue<int> p;

    // Insert all rows into the heap
    for (int i = 0; i < A.size(); i++)
    {
        p.push(A[i]);
    }

    long long profit = 0;

    // Sell tickets to B people
    while (B > 0 && !p.empty())
    {
        // Row with maximum vacant seats
        int x = p.top();
        p.pop();

        // Add ticket price to profit
        profit += x;

        // One seat becomes occupied
        x--;

        // Push back if seats are still available
        if (x > 0)
        {
            p.push(x);
        }

        B--;
    }

    return profit;
}

int main()
{
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter vacant seats in each row: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int B;

    cout << "Enter number of people: ";
    cin >> B;

    cout << "Maximum Profit = " << solve(A, B) << endl;

    return 0;
}
