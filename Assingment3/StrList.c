#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

typedef struct _node
{
    char *string;
    struct _node *_next;
} Node;

struct _StrList
{
    Node *head;
    size_t size;
};

// Node implemantation
Node *node_alloc(const char *string, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node)); // Allocation memory
    if (p == NULL)                          // If it wasn't allocatd
    {
        return NULL;
    }
    p->string = strdup(string); // Allocate a copy of a string up to specified size

    // checking if the data is not null
    if (p->string == NULL)
    {
        free(p); // Freeing the allocated memory
        return NULL;
    }

    p->_next = next; // pointing to the next Node
    return p;
}

void Node_free(Node *p)
{
    if (p != NULL)
    {
        free(p->string); // Nedd to free also the array of chars, that is call string
        free(p);
    }
}

/*******************8*/
// List implementation

StrList *StrList_alloc()
{
    StrList *list = (StrList *)malloc(sizeof(StrList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void StrList_free(StrList *list)
{
    if (list == NULL)
    {
        return;
    }
    Node *p1 = list->head;
    Node *p2;

    while (p1) // While it is not NULL
    {
        p2 = p1; // In struct is it copying all the data from One to each other
        p1 = p1->_next;
        Node_free(p2);
    }
    free(list); // Need to free the pointer to the list itself
}

size_t StrList_size(const StrList *StrList)
{
    return StrList->size;
}

void StrList_insertLast(StrList *StrList, const char *data)
{
    Node *p = node_alloc(data, NULL);
    if (p == NULL)
    {
        return;
    }

    if (StrList->head == NULL)
    {
        StrList->head = p;
    }

    else
    {
        Node *n = StrList->head;
        while (n->_next != NULL) // while (p->_next !=NULL)
        {
            n = n->_next;
            // p = &((*p)._next);
        }
        n->_next = p;
    }
    StrList->size++;
}

void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    if (index < 0 || index > StrList->size)
    {
        return; // Index Out Of Bound
    }

    Node *insert = node_alloc(data, NULL); // creating the node to insert
    if (insert == NULL)
    {
        return; // Couldn't allocate it
    }

    if (index == 0)
    { // put at start, can alsi use put insert_last function
        insert->_next = StrList->head;
        StrList->head = insert;
    }
    else
    {
        Node *p = StrList->head; // the running node
        for (int i = 0; i < index - 1; i++)
        {
            p = p->_next;
            // p = &((*p)._next);
        }
        // Now we've got to the place
        insert->_next = p->_next; // pointing to the next node
        p->_next = insert;        // p's next node will be the insert
    }
    StrList->size++;
}

// Returning the first data
char *StrList_firstData(const StrList *StrList)
{
    if (StrList->head == NULL)
    {
        return NULL;
    }
    return StrList->head->string;
}

void StrList_print(const StrList *StrList)
{
    if (StrList->head == NULL)
    {
        printf("\n");
        return;
    }

    Node *p = StrList->head;
    while (p)
    {
        printf("%s ", p->string);
        p = p->_next;
    }

    printf("%s\n", p->string); // printing the last value
}

void StrList_printAt(const StrList *Strlist, int index)
{
    if (index < 0 || index > Strlist->size) // Index Out Of Bound
    {
        return; // exiting program
    }

    Node *tmp = Strlist->head;
    for (int i = 0; i < index; i++) // finding the place to get to
    {
        tmp = tmp->_next;
    }
    printf("%s\n", tmp->string);
}

int StrList_printLen(const StrList *Strlist)
{
    int count = 0;
    Node *p = Strlist->head;
    while (p)
    {
        count += strlen(p->string); // By using strlen we are counting the size of each string
        p = p->_next;
    }
    return count;
}

int StrList_count(StrList *StrList, const char *data)
{
    int counter = 0;
    Node *tmp = StrList->head;
    while (tmp != NULL)
    {
        if (strcmp(data, tmp->string) == 0)
        { // By using comperator checking if they're equal
            counter++;
        }
        tmp = tmp->_next;
    }
    return counter;
}

void StrList_remove(StrList *StrList, const char *data)
{

    Node *tmp = StrList->head;
    Node *prev = NULL;

    while (tmp != NULL)
    {
        if (strcmp(tmp->string, data) == 0)
        {
            if (prev == NULL)
            {
                Node *current = tmp;
                StrList->head = tmp->_next;
                tmp = tmp->_next;
                Node_free(current);
            }

            else
            {
                prev->_next = tmp->_next;
                Node_free(tmp);
                tmp = prev->_next;
            }
        }
        else
        {
            prev = tmp;
            tmp = tmp->_next;
        }
    }
}

void StrList_removeAt(StrList *StrList, int index)
{

    if (index < 0 || index > StrList->size) // Index Out Of Bound
    {
        return; // exiting program
    }

    if (index == 0)
    {
        Node *del = StrList->head;
        StrList->head = StrList->head->_next;
        Node_free(del);
        StrList->size--;
        return;
    }

    Node *p = StrList->head;
    for (int i = 0; i < index - 1; i++) // finding the place to get to
    {
        p = p->_next;
    }
    Node *del = p->_next;
    p->_next = p->_next->_next;
    Node_free(del);
    StrList->size--;
}

int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    if (StrList1->size != StrList2->size)
    {
        return 0; // They cannot be equal
    }

    Node *t1 = StrList1->head;
    Node *t2 = StrList2->head;

    while (t1 != NULL && t2 != NULL)
    {
        if (strcmp(t1->string, t2->string) != 0)
        {
            return 0;
        }
        t1 = t1->_next;
        t2 = t2->_next;
    }
    return 1; // If we have finished all of this and didn't return 0, they are equal
}

StrList *StrList_clone(const StrList *List)
{
    StrList *newList = StrList_alloc();
    newList->size = List->size; // copying the size

    const Node *old = List->head;
    Node **copy = &(newList->head);

    while (old)
    {
        *copy = node_alloc(old->string, NULL);
        if (*copy == NULL)
        {
            StrList_free(newList); // something went worng so we want to free the memory
            return NULL;
        }
        old = old->_next;
        copy = &((*copy)->_next);
    }
    return newList;
}

void StrList_reverse(StrList *StrList)
{
    Node *curr = StrList->head;
    Node *p = NULL; // previouse
    Node *n = NULL; // next

    while (curr != NULL)
    { // running till the end of the list
        // Changing the node direction
        n = curr->_next;
        curr->_next = p; // will point back
        p = curr;
        curr = n;
    }
    StrList->head = p; // Making the last become the head
}

int StrList_isSorted(StrList *StrList)
{
    Node *temp = StrList->head;

    if (temp == NULL)
    {
        return 1;
    }

    while (temp->_next != NULL)
    {
        if (strcmp(temp->string, temp->_next->string) > 1)
        {
            return 0;
        }
        temp = temp->_next;
    }

    return 1;
}

void swapNode(Node *n1, Node *n2)
{
    char *tmp = n1->string;
    n1->string = n2->string;
    n2->string = tmp;
}

void bubbleSort(StrList *list)
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (list->head == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->_next != lptr)
        {
            if (strcmp(ptr1->string, ptr1->_next->string) > 0)
            {
                swapNode(ptr1, ptr1->_next);
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}

void StrList_sort(StrList *StrList)
{
    bubbleSort(StrList);
}
