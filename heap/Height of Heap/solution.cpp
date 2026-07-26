#include <iostream>
using namespace std;

class Solution {
public:
    int heapHeight(int n, int arr[]) {
        if (n == 1)
            return 1;

        int height = 0;

        while (n > 1) {
            height++;
            n /= 2;
        }

        return height;
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter heap elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Heap Height = " << obj.heapHeight(n, arr) << endl;

    return 0;
}
