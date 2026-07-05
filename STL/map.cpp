#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // It store data in key-value pair
    // Key should be unique
    // It uses Red-Black Tree or AVL for implementation
    // Insertion, deletion, and search operations have logarithmic time
    // (O(log n)), making them fast for most use cases.

    map<int, int> m;

    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 310));
    m.insert(make_pair(40, 230));
    m.insert(make_pair(20, 230));
    m.insert(make_pair(50, 30));

    m[100] = 60; // It can insert and also update the value
    m[100] = 70;

    m.erase(20);

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // if(m.count(20))
    // {
    //     cout << m[20] << " ";
    // }

    return 0;
}