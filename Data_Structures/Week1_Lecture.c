#include <stdio.h>

// We use type definition syntax, and the pointer type will be node itself !!

typedef struct node
{
    int data;
    struct node *next; // this node structure for creating a linked list
    // Node* next; we can write it inside of it
} Node; // the naming is applied in this line, compiler doesnt know it, thats why we cant use

int main()
{
    // create a node n
    Node n;
    Node n1;
    Node n2;

    n.data = 5;
    n.next = &n1;

    n1.data = 19;
    n1.next = &n2;

    n2.data = 15;
    n2.next = NULL;

    printf("1.node shows: %p\n", n.next);
    printf("2.node shows: %p\n", n1.next);
    printf("3.node shows: %p\n", n2.next);

    return 0;
}
