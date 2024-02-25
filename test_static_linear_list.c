/*
  Description:
    This file is used to test the array list implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "static_linear_list.h" 

//Constants
#define SAMPLES_AMOUNT 100

STATIC_LINEAR_LIST globalList;


ID_KEY knownKey = 0;
ID_KEY unknownKey = 420;//because key range between 0~100
RECORD knownItem;
RECORD unknownItem;
int knownPosition = 0;

void populateArrayList(STATIC_LINEAR_LIST *list, int n) {
    StaticLinearList_Init(list);
    knownItem.key = knownKey;
    StaticLinearList_InsertInOrder(list, knownItem);
    for (int i = 0; i < n; i++) {        
        RECORD item;
        item.key = rand() % 100;
        StaticLinearList_InsertInOrder(list, item);
    }    
}

int init_suite(void) {
    unknownItem.key = unknownKey;
    populateArrayList(&globalList, SAMPLES_AMOUNT);
    return 0;
}

int clean_suite(void) {
    StaticLinearList_Clear(&globalList);
    return 0;
}

void test_init_empty_list() {
    STATIC_LINEAR_LIST list;
    StaticLinearList_Init(&list);

    // Verify that the list size is 0 after initialization
    CU_ASSERT_EQUAL(list.size, 0);

    // If the list has a capacity field, you might also check if it's properly set
    // CU_ASSERT_EQUAL(list.capacity, EXPECTED_INITIAL_CAPACITY);

    // If there are any pointers (e.g., to an array of elements) in the list, check they are not NULL
    // CU_ASSERT_PTR_NOT_NULL(list.elements);

    // Add more assertions as needed based on what StaticLinearList_Init is supposed to do
}

void test_getSize() {    
    CU_ASSERT_EQUAL(StaticLinearList_GetSize(&globalList), SAMPLES_AMOUNT+1);
}

void test_not_isFull() {
    CU_ASSERT_FALSE(StaticLinearList_IsFull(&globalList));
}

void test_isFull() {
    STATIC_LINEAR_LIST list;
    populateArrayList(&list, MAX_LENGTH);
    CU_ASSERT_TRUE(StaticLinearList_IsFull(&list));
}

void test_not_isEmpty() {
    CU_ASSERT_FALSE(SataticLinearList_isEmpty(&globalList));
}

void test_isEmpty() {
    STATIC_LINEAR_LIST list;
    StaticLinearList_Init(&list);
    CU_ASSERT_TRUE(SataticLinearList_isEmpty(&list));
}

void test_linearSearch_knowItem() {        
    CU_ASSERT_EQUAL(StaticLinearList_LinearSearch(&globalList, knownKey), 0);
}

void test_linearSearch_unknownItem() {    
    CU_ASSERT_EQUAL(StaticLinearList_LinearSearch(&globalList, unknownKey), -1);
}

void test_sentinelLinearSearch_knowItem() {    
    CU_ASSERT_EQUAL(StaticLinearList_SentinelSearch(&globalList, knownKey), 0);
}

void test_sentinelLinearSearch_unknownItem() {    
    CU_ASSERT_EQUAL(StaticLinearList_SentinelSearch(&globalList, unknownKey), -1);
}

void test_binarySearch_knowItem() {    
    CU_ASSERT_EQUAL(StaticLinearList_BinarySearch(&globalList, knownKey), 0);
}

void test_binarySearch_unknownItem() {    
    CU_ASSERT_EQUAL(StaticLinearList_BinarySearch(&globalList, unknownKey), -1);
}

void test_insertAt_empty_list() {
    STATIC_LINEAR_LIST list;
    RECORD item = { /* initialize item here */ };
    int position = 0;
    StaticLinearList_Init(&list);

    CU_ASSERT_TRUE(StaticLinearList_InsertAt(&list, item, position));
    CU_ASSERT_EQUAL(list.size, 1);
    // Add more assertions as needed
}

void test_insertInOrder_empty_list() {
    STATIC_LINEAR_LIST list;
    StaticLinearList_Init(&list); // Initialize the list

    RECORD item1 = { /* initialize item1 with appropriate values */ };
    RECORD item2 = { /* initialize item2 with values such that item2 should come after item1 in order */ };
    RECORD item3 = { /* initialize item3 with values such that item3 should come before item1 and item2 in order */ };

    // Insert item1 and check if the list updates correctly
    CU_ASSERT_TRUE(StaticLinearList_InsertInOrder(&list, item1));
    CU_ASSERT_EQUAL(list.size, 1);
    // Optionally check the position of item1 in the list if applicable

    // Insert item2 and check if the list maintains order
    CU_ASSERT_TRUE(StaticLinearList_InsertInOrder(&list, item2));
    CU_ASSERT_EQUAL(list.size, 2);
    // Ensure item2 is inserted after item1

    // Insert item3 and check if the list maintains order with the new item inserted at the correct position
    CU_ASSERT_TRUE(StaticLinearList_InsertInOrder(&list, item3));
    CU_ASSERT_EQUAL(list.size, 3);
    // Ensure item3 is inserted before item1 and item2, maintaining order

    // Add more assertions as needed, such as verifying the actual order of elements in the list
}

void test_getAt_success() {
    int position = 0;
    RECORD* item = StaticLinearList_GetAt(position, &globalList);
    CU_ASSERT_PTR_NOT_NULL(item);
    CU_ASSERT_EQUAL(item->key, knownKey);
}

void test_getByKey_success() {
    RECORD* item = StaticLinearList_GetByKey(knownKey, &globalList, true);
    CU_ASSERT_PTR_NOT_NULL(item);
    CU_ASSERT_EQUAL(item->key, knownKey);
}

void test_removeByKey() {
    RECORD* removedItem = StaticLinearList_RemoveByKey(knownKey, &globalList, true);
    CU_ASSERT_EQUAL(removedItem->key, knownKey);
    CU_ASSERT_EQUAL(StaticLinearList_LinearSearch(&globalList, knownKey), -1);
    CU_ASSERT_EQUAL(StaticLinearList_GetSize(&globalList), SAMPLES_AMOUNT);
}

void test_removeAt() {
    int position = 0;
    RECORD* expectedRemoveItem = StaticLinearList_GetAt(position, &globalList);
    RECORD* removedItem = StaticLinearList_RemoveAt(position, &globalList);
    CU_ASSERT_EQUAL(removedItem->key, expectedRemoveItem->key);
    CU_ASSERT_EQUAL(StaticLinearList_LinearSearch(&globalList, knownKey), -1);
    CU_ASSERT_EQUAL(StaticLinearList_GetSize(&globalList), SAMPLES_AMOUNT-1);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("test_startArrayList_initializes_empty_list", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add test cases to the suite    
    CU_add_test(pSuite, "test_getSize", test_getSize);
    CU_add_test(pSuite, "test_not_isFull", test_not_isFull);
    CU_add_test(pSuite, "test_isFull", test_isFull);
    CU_add_test(pSuite, "test_not_isEmpty", test_not_isEmpty);
    CU_add_test(pSuite, "test_isEmpty", test_isEmpty);
    CU_add_test(pSuite, "test_linearSearch_knowItem", test_linearSearch_knowItem);
    CU_add_test(pSuite, "test_linearSearch_unknownItem", test_linearSearch_unknownItem);
    CU_add_test(pSuite, "test_sentinelLinearSearch_knowItem", test_sentinelLinearSearch_knowItem);
    CU_add_test(pSuite, "test_sentinelLinearSearch_unknownItem", test_sentinelLinearSearch_unknownItem);
    CU_add_test(pSuite, "test_binarySearch_knowItem", test_binarySearch_knowItem);
    CU_add_test(pSuite, "test_binarySearch_unknownItem", test_binarySearch_unknownItem);
    CU_add_test(pSuite, "test_insertInPosition_empty_list", test_insertAt_empty_list);
    CU_add_test(pSuite, "test_insertInOrder_empty_list", test_insertInOrder_empty_list);
    CU_add_test(pSuite, "test_getAt_success", test_getAt_success);
    CU_add_test(pSuite, "test_getByKey_success", test_getByKey_success);
    CU_add_test(pSuite, "test_removeByKey", test_removeByKey);
    CU_add_test(pSuite, "test_removeAt", test_removeAt);

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}