#include <iostream>
using namespace std;

int main() {

    int arr[] = {120,120,30,10};
    int n = 4;

    int current = 600;   // 10:00 AM
    int meet = 810;      // 13:30

    for(int i = 0; i < n; i++) {
//👉 Check when the task started and when it ended, and see whether the meeting time falls between it.
        int start = current;
        int end = current + arr[i];

// Check whether the meeting falls here or not
        if(meet >= start && meet < end) {
            cout << "Saif has to reschedule task " << i+1 << endl;
            return 0;
        }

        current = end; // move to next task
    }

    return 0;
}

//optimization
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of tasks: ";
    cin >> n;

    queue<int> q;

    // input durations
    for(int i = 0; i < n; i++) {
        int x;
        cout << "Enter duration of task " << i+1 << ": ";
        cin >> x;
        q.push(x);
    }

    string t;
    cout << "Enter meeting time (HH:MM): ";
    cin >> t;

    // convert time
    int h = stoi(t.substr(0,2));
    int m = stoi(t.substr(3,2));
    int meet = h * 60 + m;

    int current = 600; // 10:00 AM
    int i = 1;

    while(!q.empty()) {
        int d = q.front();
        q.pop();

        int start = current;
        int end = current + d;

        if(meet >= start && meet < end) {
            cout << "Saif has to reschedule task " << i << endl;
            return 0;
        }

        current = end;
        i++;
    }

    cout << "No task overlaps with the meeting time." << endl;

    return 0;
}



/*
You are given a queue Q1 containing integers. Transfer all elements from Q1 to another queue Q2 such that Q2 contains the elements in reverse order of Q1. You are not allowed to use any extra data structures like arrays, stacks, or recursion. Only queue operations are allowed, and the space complexity must remain constant.
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;
    queue<int> q2;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();  // store size once

    for(int i = 0; i < n; i++) {

        // rotate (remaining - 1 elements)
        for(int j = 0; j < n - i - 1; j++) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }

        // last element now at front
        q2.push(q.front());
        q.pop();
    }

    // print reversed queue
    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }

    return 0;
}

/*
There are n people standing in a circle and numbered from 1 to n. Starting from the first person, every k-th person is eliminated in a clockwise direction. After each elimination, counting continues from the next person in the circle. This process repeats until only one person remains.

Using a queue, simulate this process and determine the position of the last remaining person (the winner).

Constraints:
- You are only allowed to use queue operations (push, pop, front).
- Do not use arrays, stacks, or recursion.

Example:
Input:
n = 5, k = 2

Output:
3
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 2;

    while(q.size() > 1) {

        // rotate k-1 elements
        for(int j = 0; j < k-1; j++) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }

        // remove kth person
        q.pop();
    }

    cout << q.front(); // last person (winner)

    return 0;
}

//////////////////////////////////
/*
Simulate a bank queue system using FIFO queues. Customers are assigned to different counters based on their type (id). Each counter serves one customer at a time. If a counter is free, assign the customer; otherwise, they wait. Count how many customers are served by a given counter c and determine if any queue exceeds 10 customers (extra counter used).
*/
#include <iostream>
#include <queue>
using namespace std;

struct Customer {
    int id;
    int arrivalTime;
    int serviceTime;
};

int simulateBankQueue(Customer arr[], int n, int c) {

    // queues (FIFO)
    queue<Customer> senior;   // id = 3
    queue<Customer> business; // id = 2
    queue<Customer> regular;  // id = 1

    // counters free time
    int counter[6] = {0}; // index 1–5 use karenge

    int servedCount = 0;
    bool extraUsed = false;

    for(int i = 0; i < n; i++) {

        Customer cur = arr[i];

        // push into respective queue
        if(cur.id == 3) senior.push(cur);
        else if(cur.id == 2) business.push(cur);
        else regular.push(cur);

        // --- PROCESS SENIOR (1,2) ---
        while(!senior.empty()) {
            Customer s = senior.front();

            if(counter[1] <= s.arrivalTime) {
                counter[1] = s.arrivalTime + s.serviceTime;
                if(c == 1) servedCount++;
                senior.pop();
            }
            else if(counter[2] <= s.arrivalTime) {
                counter[2] = s.arrivalTime + s.serviceTime;
                if(c == 2) servedCount++;
                senior.pop();
            }
            else break;
        }

        // --- PROCESS BUSINESS (3) ---
        while(!business.empty()) {
            Customer b = business.front();

            if(counter[3] <= b.arrivalTime) {
                counter[3] = b.arrivalTime + b.serviceTime;
                if(c == 3) servedCount++;
                business.pop();
            }
            else break;
        }

        // --- PROCESS REGULAR (4,5) ---
        while(!regular.empty()) {
            Customer r = regular.front();

            if(counter[4] <= r.arrivalTime) {
                counter[4] = r.arrivalTime + r.serviceTime;
                if(c == 4) servedCount++;
                regular.pop();
            }
            else if(counter[5] <= r.arrivalTime) {
                counter[5] = r.arrivalTime + r.serviceTime;
                if(c == 5) servedCount++;
                regular.pop();
            }
            else break;
        }

        // check overcrowding
        if(senior.size() > 10 || business.size() > 10 || regular.size() > 10) {
            extraUsed = true;
        }
    }

    // OUTPUT
    cout << "Customers served by counter " << c << " : " << servedCount << endl;

    if(extraUsed)
        cout << "Extra counter used";
    else
        cout << "No extra counter used";

    return servedCount;
}

int main() {

    Customer customers[] = {
        {1,0,3},
        {2,2,15},
        {3,4,4},
        {1,6,6},
        {3,8,10}
    };

    int n = 5; //👉 n = total number of customers
    int c = 4;

    simulateBankQueue(customers, n, c);

    return 0;
}