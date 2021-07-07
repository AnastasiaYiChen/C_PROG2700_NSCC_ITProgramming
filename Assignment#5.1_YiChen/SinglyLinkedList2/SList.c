/*
 * SList.c
 *
 *  Created on: Mar. 12, 2020
 *      Author: Yi Chen
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SList.h"


//creates an empty list, returns its pointer.
SLlist * mklist() {
    SLlist * p=(SLlist *)malloc(sizeof(SLlist));
    p->head=p->tail=0;
    return p;
}

//delete all nodes;
void clear(SLlist * L) {
    puts("\nYou list all cleared!");

    Node * head=L->head;
    while (head) {

        Node * tmp=head->next;
        free(head);
        head=tmp;
    }
    L->head=L->tail=0;
}

//Add a node before the first; returns 0, when fails, 1 otherwise
int insert(SLlist * L, const student* x) {
    printf("\n\nInsert a new node in front of the head: ");

    student * tmp=(student *)malloc(sizeof(student));
    tmp->val=x->val;
    tmp->fn=x->fn;
    tmp->ln=x->ln;
    tmp->next = L->head;

    if(tmp->next){
        L->head=tmp;
        return 1;
    }
    return 0;
}

//add a node after the last; returns 0, when fails, 1 otherwise
int append(SLlist * L, const student * x){
    printf("\nAppend a node in the end of the list:");
//    student * tmp=(student *)malloc(sizeof(student));
    student * tmp = L->tail;
    tmp->val=x->val;
    tmp->fn=x->fn;
    tmp->ln=x->ln;

    if(tmp->val){
        L->tail=tmp;
        return 1;
    }

    if(tmp->fn){
        L->tail=tmp;
        return 1;
    }

    if(tmp->ln){
        L->tail=tmp;
        return 1;
    }
    return 0;
}

//add a node preserving alphabetic order of students
//(by the last name); returns 0, when fails, 1 otherwise)
int insertByName(SLlist * L, const student * x){
    printf("\n\n**Add a node preserving alphabetic order of students by the last name.**");

    student * cursor=L->head;

    student * tmp=(student *)malloc(sizeof(student));
    tmp->val=x->val;
    tmp->fn=x->fn;
    tmp->ln=x->ln;

    if (cursor==0 || strcmp(x->ln, cursor->ln) <= 0) {
        prependstudent(L, tmp);
        return 1;
    }

    while (cursor) {
        // Case "add at the tail"
        if (cursor->next == 0){
            // I could have used append, if I had it...
            L->tail=cursor->next=tmp;
            tmp->next=0;
            return 1;
        }
        // Case "adding in the middle"
        if (cursor->next->ln && strcmp(cursor->next->ln, tmp->ln) > 0) {
            tmp->next=cursor->next;
            cursor->next=tmp;
            return 1;
        }

        cursor=cursor->next;
    }
    return 0;

}
//returns the first student (pointer); NULL if the list is empty.
student * first(SLlist * L) {
    puts("\n\n\t ******The first student is:******");
    student * fistOne = L->head;
    while(L->head==0){
        return NULL;
    }
    return fistOne;
}
//returns the last student (pointer); NULL if the list is empty.
student * last(SLlist * L) {
    puts("\n\n\t ******The last student is:*******");
    student * lastOne = L->tail;
    while(L->tail==0){
        return NULL;
    }
    return lastOne;
}
//returns the student requested; or NULL, if not found).
student * find(SLlist * L, int v){
    printf("\n\n\t Find a student by student number:");

    student * cursor = L->head;

    while(NULL != cursor->next){
        cursor = cursor->next;
        if(cursor->val == v){
            printf("\t%d",v);
            return cursor;
        }
    }
    return 0;
}

//deletes the first node; returns 0, when fails, 1 otherwise.
int delFirst(struct sllist * list) {
    if (list->head == 0){
        return 0;
    }
    list->head = list->head->next;
    return 1;
}

//deletes the last node; returns 0, when fails, 1 otherwise.
int delLast(struct sllist * list) {
    if (list->head == 0){
        return 0;
    }
    Node * current=list->head;
    Node * tail=list->tail;
    Node * previous;
    while (current) {
        if (current == tail) {
            previous->next=NULL;
            list->tail=previous;
            return 1;
        } else {
            previous=current;
            current=current->next;
        }

    }
    return 0;
}

//deletes a node requested; returns 0, when fails, 1 otherwise).
int delNode(struct sllist * list, int val) {
    if (list->head == 0){
        return 0;
    }
    Node * current=list->head;
    Node * previous;
    while (current) {
        if (current->val == val) {
            if (previous) {
                previous->next=current->next;
            } else {
                list->head=current->next;
            }
            free(current);
            return 1;
        } else {
            previous=current;
            current=current->next;
        }
    }
    return 0;
}

void prepend(SLlist * L, int v) {
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp->val=v;

    tmp->next=L->head;
    L->head=tmp;
    if (L->tail==0)
        L->tail=tmp;
}

void prependstudent(SLlist * L, student * tmp) {
    tmp->next=L->head;
    L->head=tmp;
    if (L->tail==0)
        L->tail=tmp;
}

//Print List.
void printList(const SLlist * L) {
    puts(" \nHere goes your list:");
    Node * head=L->head;
    while (head) {
        printf("\t%d\t%s\t%s", head->val,head->fn,head->ln);
        head=head->next;
    }
}
//Print node.
void printNode(const student * s) {
    puts(" \n\tThe node information:");
    printf("\t%d\t%s\t%s", s->val,s->fn,s->ln);
}


// Inserts a number after a smaller and before a one that is not larger
// Hence, if we start with a list in ascending order, we will preserve
// the order...
int insertInOrder(SLlist * L, int x) {

    // Case "add at the head"
    Node * cursor=L->head;
    if (cursor==0 || cursor->val >=x) {
        prepend(L, x);
        return 1;
    }

    // A new node with value x prepared:
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp->val=x;

    while (cursor) {
        // Case "add at the tail"
        if (cursor->next == 0){
            // I could have used append, if I had it...
            L->tail=cursor->next=tmp;
            tmp->next=0;
            return 1;
        }
        // Case "adding in the middle"
        if (cursor->next->val >= x) {
            tmp->next=cursor->next;
            cursor->next=tmp;
            return 1;
        }

        cursor=cursor->next;
    }
    return 0;
}

