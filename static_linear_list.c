#include "static_linear_list.h"

void StaticLinearList_Init(STATIC_LINEAR_LIST* list) {
  list->size = 0;
}

int StaticLinearList_GetSize(STATIC_LINEAR_LIST* list) {
  return list->size;
}

bool StaticLinearList_IsFull(STATIC_LINEAR_LIST* list) {
  return list->size == MAX_LENGTH;
}

bool SataticLinearList_isEmpty(STATIC_LINEAR_LIST* list) {
  return list->size == 0;
}

void StaticLinearList_print(STATIC_LINEAR_LIST* list) {
  int index;
  printf("List: [ ");
  for (index=0; index < list->size; index++)
    printf("%i, ", list->A[index].key);
  printf("]\n");
}

int StaticLinearList_LinearSearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey) {
  int index = 0;
  while (index < list->size) {
    if ( searchedKey == list->A[index].key ) return index;
    else index++;
  }
  return -1;
}

int StaticLinearList_SentinelSearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey) {
  int index = 0;
  list->A[list->size].key = searchedKey;
  while (list->A[index].key != searchedKey) index++;
  if (index == list->size) return -1;
  return index;
}

int StaticLinearList_BinarySearch(STATIC_LINEAR_LIST* list, ID_KEY searchedKey) {
  int left = 0, rigth = list->size - 1, middle;
  while (left <= rigth) {
    middle = (left + rigth) / 2;
    if (list->A[middle].key == searchedKey) return middle;
    else {
      if (list->A[middle].key < searchedKey) left = middle + 1;
      else rigth = middle - 1;
    }
  }
  return -1;
}

bool StaticLinearList_InsertAt(STATIC_LINEAR_LIST* list, RECORD item, int position) {
  int innerIndex;
  if ( StaticLinearList_IsFull(list) || position < 0 || position > list->size)
    return false;
  for (innerIndex = list->size; innerIndex > position; innerIndex--) list->A[innerIndex] = list->A[innerIndex -1];
  list->A[position] = item;
  list->size++;
  return true;
}

bool StaticLinearList_InsertInOrder(STATIC_LINEAR_LIST* list, RECORD item) {    
  if (StaticLinearList_IsFull(list)) return false;
  int position = list->size;
  while (position  > 0 && list->A[position-1].key > item.key) {
    list->A[position] = list->A[position-1];
    position--;
  };
  list->A[position] = item;
  list->size++;
  return true;
}

RECORD* StaticLinearList_GetAt(int position, STATIC_LINEAR_LIST* list) {
  if (position < 0 || position >= list->size ) return NULL;
  return &(list->A[position]);
}

int _getPosition(STATIC_LINEAR_LIST* list, ID_KEY searchKey, bool isSorted) {
  int position;
  if (isSorted) position = StaticLinearList_BinarySearch(list, searchKey);
  else position = StaticLinearList_LinearSearch(list, searchKey);
  return position;
}

RECORD* StaticLinearList_GetByKey(ID_KEY searchKey, STATIC_LINEAR_LIST* list, bool isSorted) {
  int position = _getPosition(list, searchKey, isSorted);
  if (position == -1) return NULL;
  return &(list->A[position]);
}

RECORD* StaticLinearList_RemoveByKey(ID_KEY removedItem, STATIC_LINEAR_LIST* list, bool isSorted) {
    int position = _getPosition(list, removedItem, isSorted);  
    if (position == -1) return NULL;

    RECORD* removedRecord = (RECORD*)malloc(sizeof(RECORD));
    if (!removedRecord) return NULL;
    
    *removedRecord = list->A[position];

    for (int index = position; index < list->size - 1; index++) {
        list->A[index] = list->A[index + 1];
    }
    
    list->size--;

    return removedRecord;
}

RECORD* StaticLinearList_RemoveAt(int position, STATIC_LINEAR_LIST* list) {
  RECORD* removedRecord = StaticLinearList_GetAt(position, list);
  int index;
  if (position < 0 || position >= list->size || removedRecord == NULL) return NULL;  
  
  for (index =  position; index < list->size; index++ )
    list->A[index] = list->A[index+1];
  list->size--;
  
  return removedRecord;
}

bool StaticLinearList_Clear(STATIC_LINEAR_LIST* list) {  
  list->size = 0;
  return true;
}