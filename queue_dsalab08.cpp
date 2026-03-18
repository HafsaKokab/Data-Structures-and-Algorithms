#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {

    queue<string> q;
    string command;

    while(cin >> command) {

        // ARRIVE <name>
        if(command == "ARRIVE") {
            string name;
            cin >> name;
            q.push(name);
        }

        // SERVE
        else if(command == "SERVE") {
            if(q.empty()) {
                cout << "Queue is empty" << endl;
            } else {
                cout << "Serving: " << q.front() << endl;
                q.pop();
            }
        }

        // SKIP
        else if(command == "SKIP") {
            if(q.size() >= 2) {
                string front = q.front();
                q.pop();
                q.push(front);
            }
        }

        // COUNT
        else if(command == "COUNT") {
            cout << "Count: " << q.size() << endl;
        }

        // DISPLAY
        else if(command == "DISPLAY") {
            if(q.empty()) {
                cout << "Queue is empty" << endl;
            } else {
                queue<string> temp = q; // copy for printing

                cout << "Queue: ";
                while(!temp.empty()) {
                    cout << temp.front();
                    temp.pop();
                    if(!temp.empty()) cout << "-> ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

/////////////////////////
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int W, n;
    cin >> W;   // truck ki max capacity
    cin >> n;   // number of boxes

    queue<pair<string,int>> q;

    string id;
    int weight;

    // input lena (fixed n boxes)
    for(int i = 0; i < n; i++) {
        cin >> id >> weight;
        q.push({id, weight});
    }

    int total = 0;//ab tak load hua weight

    queue<pair<string,int>> loaded; //jo boxes truck me gaye
    queue<pair<string,int>> remaining; //jo bach gaye
    string notLoadedID = "";//jo first box fail hua

    while (!q.empty()) {
        auto box = q.front();
        q.pop();

        if (total + box.second <= W) {
            total += box.second;
            loaded.push(box);
        } else {
            notLoadedID = box.first;
            remaining.push(box);

            while (!q.empty()) {
                remaining.push(q.front());
                q.pop();
            }
            break;
        }
    }
    /*
    loaded = (B1,40), (B2,35)
remaining = (B3,50), (B4,20)
notLoadedID = B3
*/

    // Output
    if (loaded.empty()) {
        cout << "Loaded: none\n";
    } else {
        cout << "Loaded: ";
        while (!loaded.empty()) {
            cout << loaded.front().first << "(" << loaded.front().second << ") ";
            loaded.pop();
        }
        cout << endl;
    }

    if (remaining.empty()) {
        cout << "Remaining in Queue: none\n";
    } else {
        cout << "Remaining in Queue: ";
        while (!remaining.empty()) {
            cout << remaining.front().first << "(" << remaining.front().second << ") ";
            remaining.pop();
        }
        cout << endl;
    }

    if (notLoadedID != "") {
        cout << "Note: " << notLoadedID << " was not loaded -- would exceed capacity\n";
    }

    return 0;
}


//////////////////////////////////////////
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 🔹 Struct
struct Task {
    string name;
    int burstTime;
};

int main() {

    int n;
    cin >> n;   // number of tasks

    queue<Task> q;

    for (int i = 0; i < n; i++) {
        Task t;
        cin >> t.name >> t.burstTime;
        q.push(t);
    }

    int turn = 1;
    vector<string> completed;

    // 🔥 Round Robin
    while (!q.empty()) {

        Task current = q.front();
        q.pop();

        current.burstTime--;

        if (current.burstTime == 0) {
            cout << "Turn " << turn << ": " << current.name
                 << " ran | Remaining: 0 -> "
                 << current.name << " COMPLETED\n";

            completed.push_back(current.name);
        }
        else {
            cout << "Turn " << turn << ": " << current.name
                 << " ran | Remaining: "
                 << current.burstTime << endl;

            q.push(current);
        }

        turn++;
    }

    // 🔹 Completion order
    cout << "Completion Order: ";
    for (int i = 0; i < completed.size(); i++) {
        cout << completed[i];
        if (i != completed.size() - 1)
            cout << ", ";
    }

    return 0;
}