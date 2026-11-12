
// EXAMPLE 1: Implementing a queue using two stacks

#include <iostream>
#include <stack>

using namespace std;

class Queue
{
private:
    stack<int> s1, s2;
    // s1 ana stack ama ters çevirip s2'ye aktarıyoruz Queueu mantığı için FIFO

public:
    void enqueue(int x)
    {
        s1.push(x);
        cout << x << " added to the queue" << endl;
        return;
    }
    void dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << s2.top() << " removed from the queue." << endl;
        s2.pop();
    }
    void peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                // s1'leri s2'ye aktarıyoruz böylece ters dönüyo
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Front element: " << s2.top() << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();

    q.dequeue();
    q.dequeue();

    q.enqueue(40);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}