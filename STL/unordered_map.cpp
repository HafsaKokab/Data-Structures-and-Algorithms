#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Unique keys are present, duplicate keys are not allowed
    // Not necessary it should be in sorted form
    // Hashing
    // Insert, search, delete have average constant time complexity

    unordered_map<int, int> m;

    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 310));
    m.insert(make_pair(40, 230));
    m.insert(make_pair(20, 230));
    m.insert(make_pair(50, 30));

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}