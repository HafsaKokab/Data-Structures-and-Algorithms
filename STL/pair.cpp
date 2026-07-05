#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<string, int> p;

    // Two methods of insertion
    // p = make_pair("Ashar", 20);

    p.first = "Ashar";
    p.second = 20;

    cout << p.first << " " << p.second << endl;

    pair<string, pair<int, int>> p2;
    p2.first = "Ashar";
    p2.second.first = 20;
    p2.second.second = 30;

    cout << p2.first << " " << p2.second.first << " " << p2.second.second;

    return 0;
}