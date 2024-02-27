#include "static_linked_list.h"

void StaticLinkedList_Init(STATIC_LINKED_LIST* list){    
    for(int index = 0; index < MAX_LENGTH-1; index++){
        list->items[index].next = index + 1;
    }
    list->first = INVALID_POSITION;    
    list->items[MAX_LENGTH - 1].next = INVALID_POSITION;
    list->available = 0;
}

int StaticLinkedList_GetSize(STATIC_LINKED_LIST* list){
    int size = 0;
    int current = list->first;
    while(current != INVALID_POSITION){
        size++;
        current = list->items[current].next;
    }
    return size;
}

void StaticLinkedList_Print(STATIC_LINKED_LIST* list){
    int current = list->first;
    printf("List: [ ");
    while(current != INVALID_POSITION){
        printf("%d ", list->items[current].record.key);
        current = list->items[current].next;
    }
     printf("]\n");
}

int StaticLinkedList_LinearSearch(STATIC_LINKED_LIST* list, ID_KEY key, bool isSorted){
    int current = list->first;
    int position = 0;
    while(current != INVALID_POSITION){
        if(isSorted && list->items[current].record.key > key) return INVALID_POSITION;                
        if(current != INVALID_POSITION && list->items[current].record.key == key){
            return position;
        }        
        current = list->items[current].next;
        position++;
    }
    return INVALID_POSITION;
}

int _getAvailablePosition(STATIC_LINKED_LIST* list){
    int position = list->available;
    if(position != INVALID_POSITION){
        list->available = list->items[position].next;
    }
    return position;
}

bool StaticLinkedList_InsertInOrder(STATIC_LINKED_LIST* list, RECORD item){
  if (list->available == INVALID_POSITION) return false;
  int previous = INVALID_POSITION;
  int current = list->first;
  ID_KEY key = item.key;
  while ((current != INVALID_POSITION) && (list->items[current].record.key < key)) {
    previous = current;
    current = list->items[current].next;
  }
  int position = _getAvailablePosition(list);
  list->items[position].record = item;
  if (previous == INVALID_POSITION) {
    list->items[position].next = list->first;
    list->first = position;
  } else {
    list->items[position].next = list->items[previous].next;
    list->items[previous].next = position;
  }
  return true;    
}






























































