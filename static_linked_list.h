/*
Description: This file implements a Linked List using static memory allocation.

Author: Maicon de Menezes
Creation Date: 25/02/2024
Version: 0.1.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "record.h"

#define MAX_LENGTH 10000
#define INVALID_POSITION -1

typedef struct{
    RECORD record;
    int next;
} ITEM;

typedef struct{
    ITEM items[MAX_LENGTH];
    int first;
    int available;
} STATIC_LINKED_LIST;

/* Function: StaticLinkedList_Init
  Description: This function initializes the linked list structure by setting the first and available pointers to INVALID_POSITION.
  Parameters:
    STATIC_LINKED_LIST* list: pointer to the linked list structure.    
  Return:
    void
*/
void StaticLinkedList_Init(STATIC_LINKED_LIST* list);

/* Function: StaticLinkedList_GetSize
  Description: This function returns the number of elements in the linked list by iterating through the list and counting the number of elements.
  Parameters:
    STATIC_LINKED_LIST* list: pointer to the linked list structure.    
  Return:
    int: the number of elements in the list.
*/
int StaticLinkedList_GetSize(STATIC_LINKED_LIST* list);

/* Function: StaticLinkedList_Print
  Description: This function prints the elements of the linked list.
  Parameters:
    STATIC_LINKED_LIST* list: pointer to the linked list structure.    
  Return:
    void
*/
void StaticLinkedList_Print(STATIC_LINKED_LIST* list);

/* Function: StaticLinkedList_LinearSearch
  Description: This function searches for a given key in the linked list.
  Parameters:
    STATIC_LINKED_LIST* list: pointer to the linked list structure.
    ID_KEY key: the key to be searched.
  Return:
    int: the position of the element in the list. If the element is not found, it returns INVALID_POSITION.
*/
int StaticLinkedList_LinearSearch(STATIC_LINKED_LIST* list, ID_KEY key, bool isSorted);

/* Function: StaticLinkedList_InsertInOrder
  Description: This function inserts an element in the linked list in order.
  Parameters:
    STATIC_LINKED_LIST* list: pointer to the linked list structure.
    RECORD item: the item to be inserted.
  Return:
    bool: true if the element was inserted, false otherwise.
*/
bool StaticLinkedList_InsertInOrder(STATIC_LINKED_LIST* list, RECORD item);