// Program: Single Linked List 0803.cpp
// Descriptions: First Learning

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

// define the element type
typedef int Elemtype;

// define the linknode
typedef struct LNode				// ? why this LNode? for the pointer field to use the name 
{
	Elemtype data;					// data field
	struct LNode * next;			// pointer field
}LNode, *LinkList;					// ! differentiate the list pointer and node

// operation functions
// initialization of link list
int InitList ( LinkList &L )
{
	// L is the pointer of the list, it's same as a pointer to a node
	L = (struct LNode *) malloc ( sizeof(LNode) * 1);			// C
	// L = new LNode;											// C++
	
	// * L->next point to the first node of the linklist
	// * L->data is the value of head node, the headnode make every node of the list generalization
	L->next = NULL;
	
	// * the grammer of structure & its pointer is different
	// * use . or -> to visit it
	return 1;
}

// get length of linklist
int ListLength ( LinkList L )
{
	LNode *a = L->next;
	int len;
	// traverse
	for ( len = 0; a != NULL ; len++, a = a->next );
	return len;
}

// get value from the special location of the list, return the element to e
// ? why the formal parameter have *, & or nothing? 
// ? * represent the address( pointer or array), & represent the cite, nothing represent the value
int GetElem ( LinkList L, int loc, Elemtype &e )
{
	LNode *a = L->next;
	int j;
	
	// find the location
	for ( j = 1; a && j < loc; j++, a = a->next);
	
	// i overflow
	if ( a == NULL || j > loc )
		return 0;
	
	e = a->data;
	return 1;
}

// find location of the first e 
LNode * LocateElem ( LinkList L, Elemtype e)
{
	LNode *a = L->next;
	/*
	while ( a )
	{
		if ( a->data == e)
			return a;
		a = a->next;
	}
	return NULL;
	*/
	while ( a && a->data != e)
		a = a->next;
	return a;
}

// insert element
int ListInsert ( LinkList &L, int loc, Elemtype e)
{
	LNode *a = L;
	LNode *p;
	int i = 0;
	// find location
	while ( a && i<(loc-1))
	{
		a = a->next;
		i++;
	}
	// judge overflow
	if ( a==NULL || i > loc)
		return 0;
	// new
	p = ( LNode * ) malloc ( sizeof(LNode) * 1);
	//p = new LNode;
	p->data = e;
	// change pointer (core thought)
	p->next = a->next;
	a->next = p;
	return 1;
}

// delete element at the location
int ListDelete ( LinkList &L, int loc)
{
	LNode *a = L->next;
	LNode *d;
	int i = 0;
	// find location
	while ( a && i<loc )
	{
		a = a->next;
		i++;
	}
	// judge overflow
	if ( i>loc || a == NULL)
		return 0;
	// change pointer
	d = a->next;
	a->next = d->next;
	// free memory
	free(d);				// C
	// delete d;			// C++
	return 1;
}

// display the list in order
int DisplayList( LinkList L)
{
	LNode *a = L->next;
	while (a)
	{
		cout << a->data << "  ";
		a = a->next;
	}
	cout << endl;
	return 1;
}

int main ( int argc, char *argv[])
{
	// declare the linklist L
	LinkList L;
	Elemtype e;
	// initialization of the list
	InitList(L);
	// insert elements
	ListInsert(L, 1, 6);
	ListInsert(L, 2, 9);
	ListInsert(L, 3, 6);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);
	// display the linklist
	DisplayList(L);
	// length of list
	cout << ListLength(L) << endl;
	// get value of the second element 
	GetElem(L, 2, e);
	cout << e << endl;
	// delete the third element
	ListDelete(L, 3);
	// display the linklist
	DisplayList(L);
	// length of list
	cout << ListLength(L) << endl;
	
	return 0;
}




