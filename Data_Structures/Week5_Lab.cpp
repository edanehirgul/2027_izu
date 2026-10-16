/*
------Stack Class------
1. #define MAX 5 and the lass and a loop
2 Constructor: top = -1 (empty)
3. isEmpty() and isFull()
4. push(): check full -> top++ -> store
5. pop(): check empty -> print -> top--
6. peek(): show arr[top]
7. display(): loop from top down to 0
8. main(): push 10 20 30 and test
*/

#include <iostream>
using namespace std;
#define MAX 5

class Stack
{
private:
    int arr[MAX];
    int top; // Index of the top element
public:
    // Constructor
    Stack()
    {
        top = -1; // Inıtialize the stack is empty
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
        if (isFull())
        {
            cout << "Stack Overflow! Cannot add" << value << endl;
        }
        top++;            // Moe top to the next position
        arr[top] = value; // Store the new element
        cout << value << " Pushed onto the stack." << endl;
        return;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack uderflow!";
            return;
        }
        cout << arr[top] << " Popped from the stack." << endl;
        top--;
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! It is empty." << endl;
            return;
        }
        cout << "Stack elements(from top to bottom)" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack a;
    a.push(10);
    a.push(15);
    a.push(20);
    a.push(25);
    a.display();
    a.pop();
    a.display();
    a.peek();
    return 0;
}
