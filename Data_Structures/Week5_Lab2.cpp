// Example2: Advance Operations with STL STack

/*
The STL Stack is a container adapter provided by the C++ Standart
Temperate Library. In C++, std::stack provides 6 main member functions
that you can use directly without implementing them yourself. All built-in
STL stack functions:
    - push()     => Adds an element to the top
    - pop()      => Removes the top element
    - top()      => Returns the top element
    - empty()    => Checks whether the stack is empty
    - emplace()  => Returns the number of elements
    - push()     => Constructs an element directly at the top
    - swap()     => Exchanges the contents of two stacks
*/

#include <iostream>
#include <stack>
#include <limits>
using namespace std;

// Function to find the max element
void findMax(stack<int> s)
{ // Stack yapısında int tutan bir yapı: s değeri içeriyor
    if (s.empty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    int maximum = s.top(); // İlk elemanı max kabul ettik
    s.pop();               // Karşılaştırma yapacağımız ilk elemanı çıkardık(Eşitlik olmaması için)
    while (!s.empty())
    {
        if (s.top() > maximum)
        {
            maximum = s.top();
        }
        s.pop(); // Kontrol edilen elemanı çıkarır
    }
    cout << "Maximum element: " << maximum << endl;
}

// Function to find the min element
void findMin(stack<int> s)
{
    if (s.empty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    int min = s.top();
    s.pop();
    while (!s.empty())
    {
        if (s.top() < min)
        {
            min = s.top();
        }
        s.top();
    }
    cout << "Minimum element : " << min << endl;
}

// Function to remove all occurrences of a value
// belirlenen değere eşit elemanları silmek

void removeAllOccurrences(stack<int> s, int value)
{
    stack<int> temp; // Temporary stack to store necessary elements
    int removed = 0; // Kaç elemanın silindiğini tutan sayaç.
    // Remove matching elements and store the others
    while (!s.empty())
    {
        if (s.top() == value) // top istediğimiz elemente eşit mi
        {
            removed++; // sildim say, temp'e kaydetme
        }
        else
        {
            temp.push(s.top()); // kalan elemanları temp'e kaydet
        }
        s.pop(); // incelenen elemanı çıkar artık top bi sonraki -> loop'a gir
    }

    // Restore the remaning elements in the original order
    while (!temp.empty())
    {
        s.push(temp.top()); // temptekileri geri s'e koy
        temp.pop();         // top elemanı ilerlet
    }

    // Bilgilendirici satır
    if (removed > 0)
    { // Elemanlar silinmişse
        cout << removed << " occurence(s) of " << value << " removed." << endl;
    }
    else
    {
        cout << value << " was not found in the stack." << endl;
    }
}

int menu()
{
    int choice;
    cout << "\n--- STACK MENU ---" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display Top" << endl;
    cout << "4. Display Size" << endl;
    cout << "5. Check if Empty" << endl;
    cout << "6. Display All Elements" << endl;
    cout << "7.Find Maximum" << endl;
    cout << "8. Find Minimum" << endl;
    cout << "9. Remove All Occurrences" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";

    // If the user enters a non-numeric value,clear the input error,
    // discard the invalid input and return -1 to indicate an error.

    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    else
    {
        return choice;
    }
}

int main()
{
    stack<int> s;
    int choice, value;
    do
    {
        choice = menu();
        switch (choice)
            (
                case 1 :
                    // Push an element
                    cout << "Enter a value: ";
                if (!cin >> value) {
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!Enter an integer." << endl;
                    break;
                } s.push(value);
                cout << value << " pushed onto the stack." << endl;
                break case 2 :
                // Pop the element
                if (!s.empty()) {
                    cout << s.top() << " popped from the stack." << endl;
                    s.pop();
                } else {
                    cout << "Stack is empty!" << endl;
                } break;

                case 3 :
                // Display the top element
                if (!s.empty()) {
                    cout << "Top element: " << s.top() << endl;
                } else {
                    cout << "Stack is empty!" << endl;
                } break;
                case 4 :
                //
            )
    }
}