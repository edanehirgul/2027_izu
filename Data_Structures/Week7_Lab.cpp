#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
    int arr[MAX];
    int front, rear, count;

public:
    // Constructor
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0; // size
    }

    bool isEmpty()
    {
        return (count == 0);
    }

    bool isFull()
    {
        return (count == MAX); // size olduğu için -1 no need
                               //  index olsaydı olurdu
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!" << x << " not added!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
        cout << x << " added" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << " removed" << endl;
        front = (front + 1) % MAX;
        count--;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front: " << arr[front] << endl;
    }

    void display()
    {
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % MAX] << " " << endl;
            // Our queue may not start at 0 ...
            /*


            */
        }
    }
};

int main()
{
    Queue q;
    q.dequeue();

    for (int i = 1; i <= 6; i++)
    {
        q.enqueue(i * 10);
    }

    q.display();
    q.peek();

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}

