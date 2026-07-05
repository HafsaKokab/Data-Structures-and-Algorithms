#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Only Unique value will be stored
    // Store value in sorted order (ascending)
    // Insertion, deletion, and search operations have logarithmic time complexity
    // (O(log n)), making them fast for most use cases.
    // Generally Implemented using Red-Black Tree
    // We can sort it in descending Order also using greater<type>

    set<int, greater<int>> s;

    // insert
    s.insert(10);
    s.insert(20);
    s.insert(110);
    s.insert(200);
    s.insert(10);
    s.insert(20);
    s.insert(110);
    s.insert(210);

    // find
    /*
    if(s.find(110) != s.end()){
        cout << "present\n";
    }
    else{
        cout << "absent\n";
    }
    */

    // count
    if (s.count(210))
    {
        cout << "Present\n";
    }
    else
    {
        cout << "Absent\n";
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}