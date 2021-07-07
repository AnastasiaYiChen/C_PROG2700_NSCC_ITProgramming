/*
 * SList.h
 *
 *  Created on: Mar. 12, 2020
 *      Author: Yi Chen
 */

#ifndef SLIST_H_
#define SLIST_H_


struct node {
    int val;
    char * fn;
    char * ln;
    struct node * next;
};

typedef struct node Node;
typedef struct node student;

struct sllist {
    Node * head;
    Node * tail;
};

typedef struct sllist SLlist;


SLlist * mklist();
void prepend(SLlist *, int);
void prependstudent(SLlist *, student *);
void printList(const SLlist *);
void printNode(const student *);
int insertInOrder(SLlist *, int);
int insert(SLlist *, const student *);
int append(SLlist *, const student *);
int insertByName(SLlist *, const student *);
int delFirst(struct sllist *);
int delLast(struct sllist *);
int delNode(struct sllist *, int);
void clear(SLlist *);
student * first(SLlist *);
student * last(SLlist *);
student * find(SLlist *, int);
//.......



#endif /* SLIST_H_ */
