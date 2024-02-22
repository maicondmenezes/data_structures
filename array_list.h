/* 
Description: This program is a collection of data structures and algorithms related to this data structures based on lessons from Data Structure discipline on Computing Engeneering course at UNIVESP.

Author: Maicon de Menezes
Creation Date: 21/02/2024
Version: 0.1.0
*/
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX_LENGTH 10000
#define INVALID_POSITION -1

// Defination of ID_KEY type for the key of the one record it's used to get access to an record without deal with entire record data
typedef int ID_KEY;

// Defination of RECORD type, it's a struct that contains our record data
typedef struct{
  ID_KEY key;
  // Other fields
} RECORD;

typedef struct{
  // Array of records, it's have MAX_LENGTH+1 to use sentinel linear search
  RECORD A[MAX_LENGTH+1];
  int size;
} ARRAY_LIST;

/* Function: startArrayList
  Description: This function is used to start a list, it's set the size of the list to 0
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be started
  Return:
    void
*/
void startArrayList(ARRAY_LIST* list);

/* Function: getSize
  Description: This function is used to get the size of the list
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be get the size
  Return:
    int: The size of the list
*/
int getSize(ARRAY_LIST* list);

/* Function: isFull
  Description: This function is used to check if the list is full
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be checked
  Return:
    bool: If the list is full, the function returns true, otherwise, the function returns false
*/
bool isFull(ARRAY_LIST* list);

/* Function: printList
  Description: This function is used to print the list
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be printed
  Return:
    void
*/
void printList(ARRAY_LIST* list);

/* Function: linearSearch
  Description: This function is used to search for a record in the list
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1
*/
int linearSearch(ARRAY_LIST* list, ID_KEY searchedKey);

/* Function: sentinelLinearSearch
  Description: This function is used to search for a record in the list using sentinel linear search
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1

*/
int sentinelLinearSearch(ARRAY_LIST* list, ID_KEY searchedKey);

/* Function: binarySearch
  Description: This function is used to search for a record in the list using binary search
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1
*/
int binarySearch(ARRAY_LIST* list, ID_KEY searchedKey);

/* Function: insertInPosition
  Description: This function is used to insert a record in a specific position in the list
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be inserted the record
    RECORD item: The record that will be inserted
    int position: The position that the record will be inserted
  Return:
    bool: If the record was inserted, the function returns true, otherwise, the function returns false
*/
bool insertInPosition(ARRAY_LIST* list, RECORD item, int position);

/* Function: insertInOrder
  Description: This function is used to insert a record in the list in order
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be inserted the record
    RECORD item: The record that will be inserted
  Return:
    bool: If the record was inserted, the function returns true, otherwise, the function returns false
*/
bool insertInOrder(ARRAY_LIST* list, RECORD item);

/* Function: removeItem
  Description: This function is used to remove a record from the list
  Parameters:
    ID_KEY removedItem: The key of the record that will be removed
    ARRAY_LIST* list: Pointer to the list that will be removed the record
  Return:
    bool: If the record was removed, the function returns true, otherwise, the function returns false
*/
RECORD removeItem(ID_KEY removedItem, ARRAY_LIST* list);

/* Function: restartList
  Description: This function is used to restart the list
  Parameters:
    ARRAY_LIST* list: Pointer to the list that will be restarted
  Return:
    bool: If the list was restarted, the function returns true, otherwise, the function returns false
*/
bool freeList(ARRAY_LIST* list);
