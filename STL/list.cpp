#include <iostream>
#include <list>
using namespace std;

int main()
{
    /*
    std::list uses non-contiguous memory, so <= is not supported by its iterators.
    Always use it != list.end() because end() points to the position after the last element.
    */

    list<int> l;

    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(80);
    l.push_front(15);

    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    for (auto it = l.rbegin(); it != l.rend(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}