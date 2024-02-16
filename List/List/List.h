#pragma once

#include <stdlib.h>

/********************************************************************************
 *
 * A List library.
 *
 * This library provides a List of doubles data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * List represents a List data structure.
 */
struct _List;
typedef struct _List List;

/*
 * Allocates a new empty List.
 * It's the user responsibility to free it with List_free.
 */
List* List_alloc();

/*
 * Frees the memory and resources allocated to list.
 * If list==NULL does nothing (same as free).
 */
void List_free(List* list);

/*
 * Returns the number of elements in the list.
 */
size_t List_size(const List* list);

/*
 * Inserts an element in the begining of the list.
 */
void List_insertFirst(List* list,
					  double data);

/*
 * Returns the list first data.
 */
double List_firstData(const List* list);

/*
 * Prints the list to the standard output.
 */
void List_print(const List* list);

/*
 * Checks if two lists have the same elements
 * returns 0 if not and any other number if yes
 */
int List_equal(const List* list1, const List* list2);

/*
 * Clones the given list. 
 * It's the user responsibility to free it with List_free.
 */
List* List_clone(const List* list);


