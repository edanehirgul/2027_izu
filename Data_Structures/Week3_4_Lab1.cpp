
// Example 2: Doubly Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning

    // value'ı newNode'ın içine koy
    void insertAtBeginning(int value)

    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            // head = ... her zaman sonda, en sonda head'i tekrar belirlenir
        }
        cout << "Node inserted successfully.\n";
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert in the middle
    // Inserts newValue after afterValue

    void insertInMiddle(int afterValue, int newValue)
    {
        Node *current = head;

        // Find the node containing afterValue
        while (current != nullptr &&current->data = !afterValue)
        {
            current = current->next;
        }

        // Value not found
        if (current == nullptr)
        {
            cout << "Value not found.\n";
            return;
        }

        Node *newNode = new Node(newValue);
        // oluşturulan newNode düğümüne newValue yazacağız.

        // Connect new node to the next node
        newNode->next = current->next;
        newNode->prev = current;

        // If current is not the last node
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        else
        {
            // If inserting after the last node
            tail = newNode;
        }

        // Connect current node to new node
        current->next = newNode;
        cout << "Node inserted succwsfullt.\n";
    }

    // Delete a node
    void deleteNode(int value)
    {
        Node *current = head;

        // Find the node
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Value not found.\n";
            return;
        }
        // If deleting the head
        if (current == head)
        {
            head = current->next;
        }
        if (current == tail)
        {
            tail = current->prev;
        }

        // Update previous node
        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        // Update next node
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Node deleted succesfully.\n";
    }

    // Search for a value
    void search(int value)
    {
        Node *current = head;
        int position = 1;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Value found at position " << position << ".\n";
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Value  not found.\n";
    }

    // Display from beginning to end
    void displayForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *current = head;
        cout << "Forward: ";

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Display from end to beginnig
    void displayBackward()
    {
        if (tail == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *current = tail;
        cout << "Backward: ";

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int choice;
    int value;
    int newValue;
    int afterValue;
    do
    {
        cout << "\n=================================\n";
        cout << " DOUBLY LINKED LIST\n";
        cout << "=================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert in Middle\n";
        cout << "4. Delete Node\n";
        cout << "5. Search Node\n";
        cout << "6. Display Forward\n";
        cout << "7. Display Backward\n";
        cout << "8. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Insert after which value: ";
            cin >> afterValue;
            cout << "Enter new value: ";
            cin >> newValue;
            list.insertInMiddle(afterValue, newValue);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 6:
            list.displayForward();
            break;
        case 7:
            list.displayBackward();
            break;
        case 8:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}