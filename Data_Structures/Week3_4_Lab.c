
// Example 1: Sİngly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{                      // kendi değişken tipini oluşturur
    int data;          // bu node'daki data
    struct Node *next; // Diğer node'un düğümü
};
// Değişkenin tipi oluştu, kendisi değil!!

// Create a new node

struct Node *createNode(int data)
{
    // bellekten yer ayır
    struct Node *newNode = malloc(sizeof(struct Node));

    // Düğümün data alanına gelen değeri yaz
    newNode->data = data;

    // newNode'daki next değerini NULL'a ata
    // Şimdilik sonraki düğüm yok
    newNode->next = NULL;

    return newNode;
}

// Add node at the end
void append(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    // current pointer'ı ilk düğümü göstersin

    while (current->next != NULL)
    {
        // son düğüme ulaşana kadar devam et

        // bir sonraki düğüme ilerle
        current = current->next;
    }

    // son düğümü yeni düğüme bağla
    current->next = newNode;
}

// Insert node at a spesific position
void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    // Insert at the beginning
    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *current = *head;

    // Move to the node before the desired position
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }

    // Position doesn't exist
    if (current == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    // Insert the new node

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the list

void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("Before insertation:\n");
    printList(head);

    insertAtPosition(&head, 25, 2);

    printf("Aafter insertaiton:\n");
    printList(head);

    freeList(head);
    return 0;
}
