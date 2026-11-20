/*
                TREE DATA STRUCTURE
*A tree is a foundational, non linear hierarchical data structure.

*Unlike linear data (like arrays,linked lists,stacks,queues)
which store data sequentially, a tree organizes data in a parent-child
relationship braching out from a single point.

----   Tree Data Structure Terminology
 -Root: The topmost node of tree. It has no parent.
 -Node: An element containing data and pointers/references to its children
 -Edge:The link  connecting a parent node to a child node
 -Parent: A node that has branches leading to other nodes
 -Child: A node descended(inmek) directlt from a parent node
 -Leaf(Terminal Node): A node that has node children.
 -Subtree: Any node along with its own descendants, forming  smaller
 tree within the main tree.
-Depth (of a node): The number of edges on the longest path from the
root to any leaf node.

----    Where do we use trees?
 -Hierarchical Representation: Perfect for modeling real-world hierarchies
 like company
 -Fast Lookup & Modification: Sorted and balanced trees offer super-fast
 search,insertion and deletion speeds compared to linear lists.
 -Dynamic Size: Unlike arrays, trees can easily groe and shrink dynamically
 by allocating memory on the heap.


----    Tree Types

-General Binary Tree: Every node has at most two children (left and right), with no spesific ordering rules.

-Full Binary Tree: Every node other than the leaves has exactly two children
No node has only one child

-Complete Binary Tree: Every level of the tree (except possibily the last) is completely filled and all nodes in the last level are packed as far left as possible.

-Perfect Binary Tree: All interior(iç) nodes have two children and all leaf nodes are at the exact same depth

-Binary Search Tree(BST): A binary tree where the left child is strictly smaller than the parent and the right child is greater or equal. !! Left < Root < Right
Enables fast O(log n) searching.

-AVL Tree & Red-Black Tree: Self-balancing BSTs. If a BST becomes heavily skewed (like a straight line, degrading into linked list),
operations drop to O(n).
Self balancing trees automatically rotate themselves after intersections and deletions, to stay balanced and guarentee 0(log n)
performance.

-Skewed Tree (Degenerate Tree): is a special case in binary trees where the tree is compelety lopsided (dengesiz). Instead of branching out into a wide network, every parent node has only one child.


---         A General Binary Tree Ex

A binary tree is a hierarchical data structure where every node has at most two children (left and right). Unlike a Binary Search Tree (BST => (left < root < right)), a general binary tree has no
ordering rules.

Values can be placed in any position regardless of their size relative to the parent.

---        Tree Traversal Types & Categorization
Traversals are broadly(genel olarak) categorized into two main search strategies:

A. DEPTH-FIRST SEARCH (DFS) Traversal (!!Derine)
*Startegy: Dives as deep as possible down a branch before backtracking(geri izleme).

-Uses a stack (or recursion(öz yineleme) call stack),

-Types:
    1.Pre-order (Root->left->right)
    2.In-order  (Left-> root-> right)
    3.Post-order (Left->right->root)

========================================================
A. DEPTH-FIRST SEARCH (DFS) TRAVERSAL
========================================================

DFS (Depth-First Search):
- Visits nodes by going as deep as possible along a branch
  before backtracking (geri izleme).
- Uses a Stack or Recursion (call stack).
- Has 3 traversal types:

1. PRE-ORDER (Root -> Left -> Right)
   - Visit the ROOT first.
   - Then traverse the LEFT subtree.
   - Finally traverse the RIGHT subtree.
   - Remember: ROOT comes FIRST.

2. IN-ORDER (Left -> Root -> Right)
   - Traverse the LEFT subtree first.
   - Then visit the ROOT.
   - Finally traverse the RIGHT subtree.
   - Remember: ROOT comes in the MIDDLE.

3. POST-ORDER (Left -> Right -> Root)
   - Traverse the LEFT subtree first.
   - Then traverse the RIGHT subtree.
   - Visit the ROOT at the end.
   - Remember: ROOT comes LAST.


EXAMPLE TREE:

          A
         / \
        B   C
       / \
      D   E


PRE-ORDER:
Root -> Left -> Right
A -> B -> D -> E -> C

IN-ORDER:
Left -> Root -> Right
D -> B -> E -> A -> C

POST-ORDER:
Left -> Right -> Root
D -> E -> B -> C -> A


MEMORY TIP:
- PRE  = ROOT FIRST
- IN   = ROOT IN THE MIDDLE
- POST = ROOT LAST

IMPORTANT:
The tree structure does NOT change.
Only the order of visiting nodes changes.

========================================================


B. BREADTH-FIRST SEARCH (BFS) Traversal:
-Strategy: Explores the tree level by level, horizontally left->right.

-Uses a Queue (FIFO data structure)
-Type:
    1. Level-order(Top to bottom, tier(katman) by tier)

========================================================
B. BREADTH-FIRST SEARCH (BFS) TRAVERSAL
========================================================

BFS (Breadth-First Search):
- Explores the tree level by level.
- Visits nodes horizontally from left to right.
- It does NOT go as deep as possible like DFS.
- Uses a Queue (FIFO: First In, First Out).

Example Tree:

          A
        /   \
       B     C
      / \
     D   E

LEVEL 0:
A

LEVEL 1:
B -> C

LEVEL 2:
D -> E

BFS / LEVEL-ORDER:
A -> B -> C -> D -> E

IMPORTANT:
BFS is also called LEVEL-ORDER traversal.

MEMORY TIP:
DFS = Go DEEP
BFS = Go LEVEL BY LEVEL

DFS -> uses Stack / Recursion
BFS -> uses Queue

========================================================

*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for general binary tree

struct Node
{
   int data;
   struct Node *right;
   struct Node *left;
};

// Func to create a new tree node

struct Node *createNode(int value)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Memory allocaton failed!\n");
      exit(1); // Program hatayla bitti - an error occured
   }
   newNode->data = value;
   newNode->left = NULL;
   newNode->right = NULL;

   return newNode;
}

// DFS: Pre-Order Traversal (Root->Left->Right)

void preOrderTraversal(struct Node *root)
{
   if (root != NULL)
   {
      printf("%d", root->data);
      preOrderTraversal(root->left);  // recursion => call the func for left now
      preOrderTraversal(root->right); // recursion => call the func for right now
   }
}

// DFS: In_order Traversal (Left->Root->Right)

void inOrderTraversal(struct Node *root)
{
   if (root != NULL)
   {
      inOrderTraversal(root->left);
      printf("%d", root->data);
      inOrderTraversal(root->right);
   }
}

// To be cont..
