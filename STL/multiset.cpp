#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Duplicate element will be present
    sorted order hoga
    Red-Black ,AVL
    */

    multiset<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}