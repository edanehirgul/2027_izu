// Example 1: Basic Stack Operations

#include <iostream>
using namespace std;
#define MAX 5 // Max size of the stack

class Stack
{
private:
    int arr[MAX]; // Array ile tanımladık, içerisi şuan boş
    int top;      // Index of the top element
public:
    // Constructor
    Stack()
    {
        top = -1; // Initialize the stack is empty
        // En üstteki elemanın indexi -1 yani yok -> stack is empty
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(int value)
    {
        if (isFull() == 1)
        {
            cout << "Stack overflow! Cannot add " << value << endl;
            return;
        }
        else
        {
            top++;            // Move top to the next position
            arr[top] = value; // Store the element
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }
        else
        {
            cout << arr[top] << " popped from the stack." << endl;
            top--;
        }
    }

    // Displays the top element without removing it
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        cout << "Top element " << arr[top] << endl;
    }

    // Displays all the elements from top to bottom
    void traversal()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " " << endl;
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " " << endl;
        }
    }
};

int main()
{

    Stack s; // Create a stack object
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
