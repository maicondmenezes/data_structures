/* 
Description: This file implements Linear List using static memory allocation.

Author: Maicon de Menezes
Creation Date: 21/02/2024
Version: 0.1.0
*/
#include<stdio.h>
#include<stdlib.h>
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
} STATIC_LINEAR_LIST;

/* Function: StaticLinearList_Init
  Description: This function is used to start a list, it's set the size of the list to 0
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be started
  Return:
    void
*/
void StaticLinearList_Init(STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_GetSize
  Description: This function is used to get the size of the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be get the size
  Return:
    int: The size of the list
*/
int StaticLinearList_GetSize(STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_IsFull
  Description: This function is used to check if the list is full
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be checked
  Return:
    bool: If the list is full, the function returns true, otherwise, the function returns false
*/
bool StaticLinearList_IsFull(STATIC_LINEAR_LIST* list);

/* Function: SataticLinearList_isEmpty
  Description: This function is used to check if the list is empty
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be checked
  Return:
    bool: If the list is empty, the function returns true, otherwise, the function returns false
*/
bool SataticLinearList_isEmpty(STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_print
  Description: This function is used to print the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be printed
  Return:
    void
*/
void StaticLinearList_print(STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_LinearSearch
  Description: This function is used to search for a record in the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1
*/
int StaticLinearList_LinearSearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey);

/* Function: StaticLinearList_SentinelSearch
  Description: This function is used to search for a record in the list using sentinel linear search
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1

*/
int StaticLinearList_SentinelSearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey);

/* Function: StaticLinearList_BinarySearch
  Description: This function is used to search for a record in the list using binary search
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be searched
    ID_KEY searchedKey: The key of the record that will be searched
  Return:
    int: The position of the record in the list, if the record is not found, the function returns -1
*/
int StaticLinearList_BinarySearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey);

/* Function: StaticLinearList_InsertAt
  Description: This function is used to insert a record in a specific position in the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be inserted the record
    RECORD item: The record that will be inserted
    int position: The position that the record will be inserted
  Return:
    bool: If the record was inserted, the function returns true, otherwise, the function returns false
*/
bool StaticLinearList_InsertAt(STATIC_LINEAR_LIST* list, RECORD item, int position);

/* Function: StaticLinearList_InsertInOrder
  Description: This function is used to insert a record in the list in order
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be inserted the record
    RECORD item: The record that will be inserted
  Return:
    bool: If the record was inserted, the function returns true, otherwise, the function returns false
*/
bool StaticLinearList_InsertInOrder(STATIC_LINEAR_LIST* list, RECORD item);

/* Function StaticLinearList_GetAt
  Description: This function is used to get a record from the list
  Parameters:
    int position: The position of the record that will be get
    STATIC_LINEAR_LIST* list: Pointer to the list that will be get the record
  Return:
    *RECORD: Pointer to the record that was get or NULL if the position is invalid
*/
RECORD* StaticLinearList_GetAt(int position, STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_GetFirst
  Description: This function is used to get the first record from the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be get the record
  Return:
    *RECORD: Pointer to the record that was get or NULL if the list is empty
*/
RECORD* StaticLinearList_GetFirst(STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_GetLast
  Description: This function is used to get the last record from the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be get the record
  Return:
    *RECORD: Pointer to the record that was get or NULL if the list is empty
*/
RECORD* StaticLinearList_GetLast(STATIC_LINEAR_LIST* list);

/* Funcion StaticLinearList_GetByKey
  Description: This function is used to get a record from the list using it's key
  Parameters:
    ID_KEY searchedKey: The key of the record that will be get
    STATIC_LINEAR_LIST* list: Pointer to the list that will be get the record
    bool isSorted: If the list is sorted, the function uses binary search, otherwise, the function uses linear search
  Return:
    *RECORD: Pointer to the record that was get or NULL if the record was not found
*/
RECORD* StaticLinearList_GetByKey(ID_KEY searchedKey, STATIC_LINEAR_LIST* list, bool isSorted);

/* Function: StaticLinearList_RemoveByKey
  Description: This function is used to remove a record from the list
  Parameters:
    ID_KEY removedItem: The key of the record that will be removed
    STATIC_LINEAR_LIST* list: Pointer to the list that will be removed the record
    bool isSorted: If the list is sorted, the function uses binary search, otherwise, the function uses linear search
  Return:
    RECORD: Pointer to the record that was removed or NULL if the record was not found
*/
RECORD* StaticLinearList_RemoveByKey(ID_KEY removedItem, STATIC_LINEAR_LIST* list, bool isSorted);

/* Function: StaticLinearList_RemoveAt
  Description: This function is used to remove a record from the list
  Parameters:
    int position: The position of the record that will be removed
    STATIC_LINEAR_LIST* list: Pointer to the list that will be removed the record
  Return:
    RECORD: Pointer to the record that was removed or NULL if the position is invalid
*/
RECORD* StaticLinearList_RemoveAt(int position, STATIC_LINEAR_LIST* list);

/* Function: StaticLinearList_Clear
  Description: This function is used to restart the list
  Parameters:
    STATIC_LINEAR_LIST* list: Pointer to the list that will be restarted
  Return:
    bool: If the list was restarted, the function returns true, otherwise, the function returns false
*/
bool StaticLinearList_Clear(STATIC_LINEAR_LIST* list);