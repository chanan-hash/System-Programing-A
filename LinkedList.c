#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void delFirst(Node **h)
{ // To ** ,One for list, and the second for the Node itself
    if (!*h)
    {
        return; // If it is null nothing to do
    }
    Node *p = *h;
    *h = p->next; // fowrding the NOde ot hte next one in the list
    free(p);      // usually using malloc for creating the Node or list
}

Node *newNode(int data, Node *next)
{ // creating a new Node, like a constructor
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = next;
    return p;
}

void freeNode(Node *p)
{
    free(p);
}

void insertLast(int data, Node **head)
{
    struct Node **p = head; // first of the list
    while (*p)
    { // while the Nodes are not null
        p = &((*p)->next);
    }
    *p = newNode(data, NULL);
}

void delFromList(int data, Node **head)
{
    if (!*head) // if the first Node is NUll so the is no List
    {
        return;
    }

    Node *p = *head;    // first Node
    Node **prev = head; // The list itself

    while (p)
    { // while it is not NULL
        if (p->data == data)
        {
            *prev = p->next;
            freeNode(p);
            p = *prev;
        }
        else
        {
            prev = &(p->next); // making prev pointing to the next address and not info
            p = p->next;
        }
    }
}

void dupllicateData(int data, Node **h)
{
    while (!*h)
    {
        if ((*h)->data == data)
        {
            *h = newNode(data, *h);
            h = &((*h)->next);
        }
        else
        {
            h = &((*h)->next);
        }
    }
}

/*******************************************/
// Binary Trees

typedef struct BTNode
{
    int data;
    struct Node *ls, *rs; // left son, right son
} BTNode;

Node *newNode(int data, BTNode *l, BTNode *r)
{ // creating a new Node, like a constructor
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p->data = data;
    p->ls = l;
    p->rs = r;
    return p;
}

// Insert for binary search tree
void inserdBST(BTNode **root, int data)
{
    while (*root) // While not Null
    {
        if (data < (*root)->data) // if the data is smaller, going to the left
        {
            root = &((*root)->ls);
        }
        else // going to the right
        {
            root = &((*root)->rs);
        }
        *root = newNodeBT(data, NULL, NULL);
    }
}

// Heaptree leaves num
int numOfLeaves(BTNode *p)
{
    if (!p)
    {
        return 0; // No tree
    }
    int tmp = numOfLeaves(p->ls) + numOfLeaves(p->rs); // recursive
    if (tmp == 0)
    {
        return 1; // getting to the leaf itself
    }
    return tmp; // What we have till now
}

int main()
{
    return 0;
}
