/*
 ============================================================================
 Name        : SinglyLinkedList.c
 Author      : Yi Chen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "SList.h"


/*
 *we have an Internet-based course for which class capacity has not been set,and that actual enrolment is unpredictable.
 * So, we need a container more flexible than an array with respect to:
 * growth in size
 * insertion/deletion of elements (especially "in the middle").
 * The task is to implement such a data structure:a singly-linked list.
 *
 *
 * struct sllist * mkList() - creates an empty list, returns its pointer.
 * void clear(struct sllist *) - delete all nodes;
 * int insert(struct sllist *, const struct student *)-  add a node before the first; returns 0, when fails, 1 otherwise)
 * int append(struct sllist *, const struct student *)-  add a node after the last; returns 0, when fails, 1 otherwise
 * int insertByName(struct sllist *, const struct student *) - add a node preserving alphabetic order of students
 *                                                              (by the last name); returns 0, when fails, 1 otherwise)
 * struct student * first(struct sllist)-  returns the first student (pointer); NULL if the list is empty.
 * struct student * last(struct sllist) - returns the last student (pointer); NULL if the list is empty.
 * struct student * find(struct sllist,  <student number/or ... >)- returns the student requested; or NULL, if not found)
 * int delFirst(struct sllist *)-  deletes the first node; returns 0, when fails, 1 otherwise
 * int delLast(struct sllist *)-  deletes the last node; returns 0, when fails, 1 otherwise
 * int delNode(struct sllist *, <student number/or ... >) -  deletes a node requested; returns 0, when fails, 1 otherwise)
 */

int main(void) {


    SLlist * list = mklist();  // empty list;

    printList(list);


    SLlist * list1 = mklist();

// Working on an empty list...
    //for (int i=0; i<100; i+=2)
// I wanted a list of values in ascending order
// - as I don't have append (at the tail) implemented
// I run the loop in reverse...
    for (int i=3; i>=0; i-=1)
        prepend(list1, i);

    printList(list1);

    //clear all list.
    clear(list1);

    SLlist * list2 = mklist();
    for (int i=3; i>=0; i-=1)
        prepend(list2, i);
    // Trying to test all the cases...
    // (for inserting into an empty list see above)
    insertInOrder(list2, -7);
    insertInOrder(list2, +2);
    insertInOrder(list2, 7);
    insertInOrder(list2, 120);
    printf("\nInsert numbers in order:");
    printList(list2);
    // As I haven't implemented & tested append(...),
    // I need to make sure that my insertInOrder
    // handles tail when appending correctly...
    printf("\nPointed by tail: %d", list2->tail->val);

    //Create a new node.
    student * node=(student *)malloc(sizeof(student));
    node->val=111;
    node->fn="Yi";
    node->ln="Chen";
    //And insert it in the very front of the first note.
    //test the insert function.
    //when call insert function, the student should be insert in the very beginning of the list.
    insert(list2, node);
    printList(list1);

    //test append function: assign student number and the first and last name of the student
    //when call append function, the student should be append in the end of the list.
    node->val=190;
    node->fn="Piotr";
    node->ln="Smith";
    append(list2,node);
    printList(list2);

    //Insert a student.
    // And the preserving alphabetic order of students (by the last name).
    node->val=121;
    node->fn="Nick";
    node->ln="Dc";
    insertByName(list2,node);
    printList(list2);

    //I want to test if the insertByName function works.
    //I insert a student last name starting by B.
    //The result should be that the student will be in the very beginning of the list.
    node->val=113;
    node->fn="Marry";
    node->ln="Bealy";
    insertByName(list2,node);
    printList(list2);

    //The first student will be print

    student * myfirst = first(list2);
    printNode(myfirst);

    //The last student will be print

    student * lastOne = last(list2);
    printNode(lastOne);
    //Find student by student number.
    student * findOne = find(list2, 0);
    printNode(findOne);


    //Delete first node.
    //The first node in the list is 113 Marry Bealy.
    //When the delFist execute, the 113 Marry Bealy will be deleted.
    printf("\n\n---------------------Delete first-------------------");
    delFirst(list2);
    printList(list2);

    //Delete Last node.
    //The Last node in the list is 190	Piotr	Smith.
    //When the delFist execute, the 190	Piotr	Smith will be deleted.
    printf("\n\n---------------------Delete last-------------------");
    delLast(list2);
    printList(list2);

    //Delete node which you specified 111.The whole node will be delete, once find.
    //if the node you specified doesn't here will be NULL.
    printf("\n\n---------------------Delete node-------------------");
    delNode(list2, 111);
    printList(list2);


    return EXIT_SUCCESS;
}


