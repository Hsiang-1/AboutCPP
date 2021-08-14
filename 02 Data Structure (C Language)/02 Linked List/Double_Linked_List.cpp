// Program: double linked list.cpp
// Descriptions: first try

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

typedef int ElementType;

typedef struct Node
{
	ElementType data;
	struct Node *next;
	struct Node *prev;
}Node, *LinkList;

int InitList(LinkList &L)
{
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	L->prev = NULL;
	return 1;
}

int Insert(LinkList &L, ElementType e, int loc)
{
	Node *a = L;
	Node *elem;
	int i = 0;

	if(a->next == NULL && loc != 1)
		return 0;

	if(a->next == NULL && loc == 1)
	{
		elem = (Node *)malloc(sizeof(Node));
		elem->data = e;
		a->next = elem;
		elem->prev = elem;
		elem->next = elem;
		return 1;
	}
	
	while ( i<loc-1)
	{
		i++;
		a = a->next;
	}

	elem = (Node *)malloc(sizeof(Node));
	elem->data = e;

	a = a->next;

	elem->next = a;
	elem->prev = a->prev;
	a->prev->next = elem;
	a->prev = elem;

	if (loc==1)
		L->next = elem;

	return 1;
}

int Display20(LinkList L)
{
	int i = 0;
	Node *a = L->next;
	if(a == NULL)
		return 0;
	while (i<20)
	{
		cout << a->data << "  ";
		a = a->next;
		i++;
	}
	cout << endl;
	return 1;
}

int GetLength(LinkList L)
{
	Node *a = L->next;
	Node *b = L->next;
	int i = 0;

	if (a == NULL)
		return 0;
	
	while ( a->next!=b )
	{
		a = a->next;
		i++;
	}
	return i+1;
}

int Delete(LinkList &L, int loc)
{
	Node *a = L;
	Node *b;
	int i = 0;

	if (a->next == NULL)
		return 0;
	
	while ( i<loc-1 )
	{
		a = a->next;
		i++;
	}

	a = a->next;
	b = a->next;		// a!=b

	if(loc==1)
		if( a!=b )
			L->next = b;
		else
			L->next = NULL;

	a->prev->next = a->next;
	a->next->prev = a->prev;
	free(a);

	return 1;
}

int main ( int argc, char *argv[])
{
	LinkList L;
	InitList(L);
	cout << GetLength(L) << endl;
	Insert(L, 1, 1);
	Insert(L, 2, 2);
	Insert(L, 3, 1);
	Display20(L);
	cout << GetLength(L) << endl;
	Delete(L, 1);
	Display20(L);
	cout << GetLength(L) << endl;
	Delete(L, 1);
	Display20(L);
	cout << GetLength(L) << endl;
	Delete(L, 1);
	Display20(L);
	cout << GetLength(L) << endl;

	return 0;
}





