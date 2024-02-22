#include <stdio.h>
#include "array_list.h"

int main() {
  ARRAY_LIST list;
  startArrayList(&list);
  for (int i = 0; i < 10; i++) {
    RECORD record;
    record.key = i^2;
    insertInOrder(&list, record);
  }
  printList(&list);
  return 0;
}