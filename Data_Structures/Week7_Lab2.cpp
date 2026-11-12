
// Eaxmple2 :STL Queue

#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q)
{
    cout << "Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    printQueue(q);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();
    cout << q.front() << " removed.\n";

    if (q.empty())
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        cout << "Queue is not empty.\n";
    }
    return 0;
}
