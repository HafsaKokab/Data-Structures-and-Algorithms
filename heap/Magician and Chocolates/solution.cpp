#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nchoc(int A, vector<int>& B) {

    priority_queue<int> pq;   // Max Heap

    // Insert all bags into the heap
    for (int i = 0; i < B.size(); i++) {
        pq.push(B[i]);
    }

    long long ans = 0;
    const int MOD = 1000000007;

    while (A > 0 && !pq.empty()) {

        int chocolates = pq.top();
        pq.pop();

        ans = (ans + chocolates) % MOD;

        // Refill the bag with floor(chocolates/2)
        pq.push(chocolates / 2);

        A--;
    }

    return ans;
}

int main() {

    int A, n;

    cout << "Enter A (minutes): ";
    cin >> A;

    cout << "Enter number of bags: ";
    cin >> n;

    vector<int> B(n);

    cout << "Enter chocolates in each bag: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    cout << "Maximum chocolates eaten = " << nchoc(A, B) << endl;

    return 0;
}
