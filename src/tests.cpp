#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <sstream>
#include <iostream>

// ============================================================
// STAGE 0 Tests
// ============================================================

// I used Geeks for Geeks to help me create the union.

/// Create a LegacyData union with an int (42). Call printLegacyData.
/// Verify the returned string matches "42".
void test_printLegacyData_int(void) 
{
    LegacyData int1;
    int1.i = 42;
    std::string result = printLegacyData(int1, 'i');
    TEST_ASSERT_EQUAL_STRING("42", result.c_str());

}

/// Create a LegacyData union with a double (3.14). Call printLegacyData.
/// Verify the returned string matches "3.14".
void test_printLegacyData_double(void) 
{
    union LegacyData int1;
    int1.d = 3.14;
    printLegacyData(int1, 'd');
    TEST_ASSERT_TRUE_MESSAGE(3.14, "TODO: Implement this test");
}

// ============================================================
// STAGE 1 Tests
// ============================================================

/// Call createTwoStructNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoStructNodes_links_correctly(void) 
{
    structNode* Node1 = createTwoStructNodes();
    TEST_ASSERT_NOT_NULL(Node1);
    TEST_ASSERT_EQUAL_CHAR('i', Node1->typeData);
    TEST_ASSERT_EQUAL_INT(5, Node1->value.i);
    structNode* Node2 = Node1->nextPtr;
    TEST_ASSERT_NOT_NULL(Node2);
    TEST_ASSERT_EQUAL_CHAR('d', Node2->typeData);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 3.14, Node2->value.d);
    delete Node1;
    delete Node2;
}

// ============================================================
// STAGE 2 Tests
// ============================================================

/// Call createTwoClassNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoClassNodes_links_correctly(void) 
{
    classNode* Node1 = createTwoClassNodes();
    TEST_ASSERT_NOT_NULL(Node1);
    TEST_ASSERT_EQUAL_CHAR('i', Node1->typeData);
    TEST_ASSERT_EQUAL_INT(5, Node1->value.i);
    classNode* Node2 = Node1->nextPtr;
    TEST_ASSERT_NOT_NULL(Node2);
    TEST_ASSERT_EQUAL_CHAR('d', Node2->typeData);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 3.14, Node2->value.d);
    TEST_ASSERT_NULL(Node2->nextPtr);
    delete Node2;
    delete Node1;
}

// ============================================================
// STAGE 3 Tests
// ============================================================

/// Call createTwoTemplateNodes().
/// Verify head->value is 5 and head->nextPtr->value is 3.
/// Clean up allocated memory.
void test_createTwoTemplateNodes_links_correctly(void) 
{
    classNodeT<int>* Node1 = createTwoTemplateNodes();
    TEST_ASSERT_NOT_NULL(Node1);
    TEST_ASSERT_EQUAL_INT(5, Node1->value);
    classNodeT<int>* Node2 = Node1->nextPtr;
    TEST_ASSERT_NOT_NULL(Node2);
    TEST_ASSERT_EQUAL_INT(3, Node2->value);
    TEST_ASSERT_TRUE_MESSAGE(Node2->nextPtr == nullptr, "TODO: Implement this test");
    delete Node1;
    delete Node2;
}

// ============================================================
// STAGE 4: LinkedList Tests
// ============================================================

/// Create a LinkedList. Add two nodes using addFirst.
/// Verify listLength() returns 2 after insertions.
void test_linkedList_addFirst_updates_counter(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(1);
    classNodeVariant* Node2 = new classNodeVariant(2);
    link.addFirst(Node1);
    link.addFirst(Node2);
    TEST_ASSERT_TRUE_MESSAGE(link.listLength() == 2, "TODO: Implement this test");
}

/// Create a LinkedList. Add nodes (10, then 20) using addLast.
/// Capture std::cout and verify elements appear in order ("10" before "20").

//I used copilot to Capture std::cout.
void test_linkedList_addLast_places_at_end(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(10);
    classNodeVariant* Node2 = new classNodeVariant(20);
    link.addLast(Node1);
    link.addLast(Node2);
    std::stringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());
    link.printList();
    std::cout.rdbuf(old);
    TEST_ASSERT_TRUE_MESSAGE(output.str() == "10 20 \n", "TODO: Implement this test");
}

/// Create a LinkedList with an int, double, and string.
/// Call deleteValue() with the double value (3.14).
/// Verify list length decreases to 2 and second call returns -1.
void test_linkedList_deleteValue_removes_variant(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(10);
    classNodeVariant* Node2 = new classNodeVariant(3.14);
    classNodeVariant* Node3 = new classNodeVariant(std::string("hello"));
    link.addLast(Node1);
    link.addLast(Node2);
    link.addLast(Node3);
    int e1 = link.deleteValue(3.14);
    int e2 = link.deleteValue(3.14);
    bool e3 = (e1 == 0) && (link.listLength() == 2) && (e2 == -1);
    TEST_ASSERT_TRUE_MESSAGE(e3, "TODO: Implement this test");
}

/// Create a LinkedList and insert three nodes.
/// Call destroyList().
/// Verify listLength() becomes 0.
void test_linkedList_destroyList_clears_all(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(10);
    classNodeVariant* Node2 = new classNodeVariant(3.14);
    classNodeVariant* Node3 = new classNodeVariant(std::string("hello"));
    link.addLast(Node1);
    link.addLast(Node2);
    link.addLast(Node3);
    link.destroyList();
    TEST_ASSERT_TRUE_MESSAGE(link.listLength() == 0, "TODO: Implement this test");
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteFirst().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteFirst(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(10);
    classNodeVariant* Node2 = new classNodeVariant(20);
    classNodeVariant* Node3 = new classNodeVariant(30);
    link.addLast(Node1);
    link.addLast(Node2);
    link.addLast(Node3);
    int result = link.deleteFirst();
    TEST_ASSERT_TRUE_MESSAGE(result == 0 && link.listLength() == 2, "TODO: Implement this test");
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteLast().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteLast(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(10);
    classNodeVariant* Node2 = new classNodeVariant(20);
    classNodeVariant* Node3 = new classNodeVariant(30);
    link.addLast(Node1);
    link.addLast(Node2);
    link.addLast(Node3);
    int result = link.deleteLast();
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(2, link.listLength());

}
// I used copilot to help me redirect the buffer.
/// Create a LinkedList with nodes (1, 2.5, "test").
/// Redirect std::cout buffer and call printList().
/// Verify printed output contains "1", "2.5" (or "2.50"), and "test".
void test_linkedList_printList(void) 
{
    LinkedList link;
    classNodeVariant* Node1 = new classNodeVariant(1);
    classNodeVariant* Node2 = new classNodeVariant(2.5);
    classNodeVariant* Node3 = new classNodeVariant(std::string("test"));
    link.addLast(Node1);
    link.addLast(Node2);
    link.addLast(Node3);
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    int result = link.printList();
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    bool e = (output.find("1") != std::string::npos) && 
                             ((output.find("2.5") != std::string::npos) || (output.find("2.50") != std::string::npos)) && 
                             (output.find("test") != std::string::npos);
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(3, link.listLength());
    TEST_ASSERT_TRUE_MESSAGE(e, "TODO: Implement this test");
}