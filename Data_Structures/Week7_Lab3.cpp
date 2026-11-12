
// Eaxmple3 : Queue with a linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Queue
{
    Node *front;
    Node *rear;
    int count;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int x)
    {
        Node *newNode = new Node(x);

        // İçerisi boşsa baş ev son da eklenene eşit
        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << x << " added.\n";
    }
    int size()
    {
        return count;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        Node *temp = front;

        front = front->next; // baştan eksildiği için front bi sonrakine geçiyor
        cout << temp->data << " removed.\n";

        if (front == nullptr)
        {
            rear = nullptr;
            delete temp;
            count--;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front: " << front->data << endl;
    }

    void
    display()
    {
        cout << "Queue: ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;
    q.dequeue();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.peek();
    cout << "Size: " << q.size() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();
    return 0;
}