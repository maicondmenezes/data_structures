#include "array_list.h"

void startArrayList(ARRAY_LIST* list) {
  list->size = 0;
}

int getSize(ARRAY_LIST* list) {
  return list->size;
}

bool isFull(ARRAY_LIST* list) {
  return list->size == MAX_LENGTH;
}

void printList(ARRAY_LIST* list) {
  int index;
  printf("List: [ ");
  for (index=0; index < list->size; index++)
    printf("%i, ", list->A[index].key);
  printf("]\n");
}

int linearSearch(ARRAY_LIST* list, ID_KEY searchedKey) {
  int index = 0;
  while (index < list->size) {
    if ( searchedKey == list->A[index].key ) return index;
    else index++;
  }
  return -1;
}

int sentinelLinearSearch(ARRAY_LIST* list, ID_KEY searchedKey) {
  int index = 0;
  list->A[list->size].key = searchedKey;
  while (list->A[index].key != searchedKey) index++;
  if (index == list->size) return -1;
  return index;
}

int binarySearch(ARRAY_LIST* list, ID_KEY searchedKey) {
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

bool insertInPosition(ARRAY_LIST* list, RECORD item, int position) {
  int innerIndex;
  if ( isFull(list) || position < 0 || position > list->size)
    return false;
  for (innerIndex = list->size; innerIndex > position; innerIndex--) list->A[innerIndex] = list->A[innerIndex -1];
  list->A[position] = item;
  list->size++;
  return true;
}

bool insertInOrder(ARRAY_LIST* list, RECORD item) {    
  if (isFull(list)) return false;
  int position = list->size;
  while (position  > 0 && list->A[position-1].key > item.key) {
    list->A[position] = list->A[position-1];
    position--;
  };
  list->A[position] = item;
  list->size++;
  return true;
}

RECORD removeItem(ID_KEY removedItem, ARRAY_LIST* list) {
  RECORD removedRecord = { -1 };
  int position, index;
  position = binarySearch(list, removedItem);
  if (position != -1) removedRecord = list->A[position];
  for (index =  position; index < list->size; index++ )
    list->A[index] = list->A[index+1];
  list->size--;
  return removedRecord;
}

bool freeList(ARRAY_LIST* list) {  
  list->size = 0;
  return true;
}