#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    multimap does not support [] because one key can have multiple values.
    Use insert() instead.
    */

    multimap<int, int> m;

    m.insert({100, 60});
    m.insert({100, 70});
    m.insert({100, 80});

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}