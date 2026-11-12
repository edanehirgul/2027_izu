
// EXAMPLE 2: Stack implementation using two queues

#include <iostream>
#include <queue>

using namespace std;

class Stack
{
private:
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            // q1'in frontunu alıp q2'nin arkasına ekledik
            // baştaki eleman x kaldı => stack yapısı
            q1.pop();
        }

        // Swap q1 and q2
        // q1 becomes the main queue

        swap(q1, q2);
        cout << x << " added to the stack." << endl;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << q1.front() << " removed from the stack." << endl;
        q1.pop();
    }

    void top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element " << q1.front() << endl;
    }

    // !Ana queue nun q1 olduğunu unutma
};

int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.top();

    s.pop();
    s.pop();

    s.push(40);

    s.pop();
    s.pop();

    // try to remove from an empty stack

    s.pop();
}