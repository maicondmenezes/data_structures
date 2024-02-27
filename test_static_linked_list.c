/*
  Description:
    This file is used to test the array list implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "static_linked_list.h"

//Constants
#define SAMPLES_AMOUNT 100

STATIC_LINKED_LIST globalList;
ID_KEY knownKey = 0;
ID_KEY unknownKey = 420;//because key range between 0~100
RECORD knownItem;
RECORD unknownItem;
int knownPosition = 0;

void populateLinkedList(STATIC_LINKED_LIST *list, int n) {
    StaticLinkedList_Init(list);
    knownItem.key = knownKey;
    StaticLinkedList_InsertInOrder(list, knownItem);
    for (int i = 0; i < n; i++) {        
        RECORD item;
        item.key = rand() % 100;
        StaticLinkedList_InsertInOrder(list, item);
    } 
}

int init_suite(void) {
    unknownItem.key = unknownKey;
    populateLinkedList(&globalList, SAMPLES_AMOUNT);
    return 0;
}

int clean_suite(void) {
    //StaticLinkedList_Clear(&globalList);
    return 0;
}

void test_init_empty_list() {
    STATIC_LINKED_LIST list;
    StaticLinkedList_Init(&list);
    
    CU_ASSERT_EQUAL(StaticLinkedList_GetSize(&list), 0);   
}

void test_linear_search_known_key() {
    int position = StaticLinkedList_LinearSearch(&globalList, knownKey, true);    
    CU_ASSERT_EQUAL(position, knownPosition);
}


int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = CU_add_suite("StaticLinkedList Unit Test", init_suite, clean_suite);
    if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
    }
  
    CU_add_test(pSuite, "test_init_empty_list", test_init_empty_list);
    CU_add_test(pSuite, "test_linear_search_known_key", test_linear_search_known_key);
  
    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}