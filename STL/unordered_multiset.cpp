#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // It contain only unique elements
    // Search, insert and removal have average constant time Complex
    // It uses hashing technique to achieve it

    unordered_multiset<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(11);
    s.insert(10);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}