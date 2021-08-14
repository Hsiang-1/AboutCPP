// Program: Sequence List 0802.cpp
// Descriptions: First Learning of SqList

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 100

// storage reprentation: RANDOM ACCESS
typedef int Elemtype;
typedef struct
{
	Elemtype * elem;			// the array
	int length;					// the quantity of elements
}SqList;

// operation functions 
// initialization
int InitList ( SqList &L )
{
	// create a empty new sequence list
	L.elem = (Elemtype *) malloc ( sizeof(Elemtype) * MAXSIZE);		// C
	// L.elem = new Elemtype[MAXSIZE];								// C++
	if ( !L.elem )
		exit(0);		// overflow
	L.length = 0;
	return 1;
}
 
// get the value of element
int GetElem ( SqList L, int loc, Elemtype &e)
{
	if ( L.length < loc || loc < 1)
		return 0;		// overflow
	e = L.elem[loc-1];	
	return 1;
}

// find the first element e, return the location
int LocateElem ( SqList L, Elemtype e)
{
	int i;
	for ( i = 0; i < L.length; i++)
		if ( L.elem[i] == e )
			return i + 1;
	return 0;
}

// insert new element e to location i
int ListInsert ( SqList &L, Elemtype e, int loc)
{
	int i;
	
	if ( L.length == MAXSIZE )
		return 0;				// array full
	if ( loc < 1 || loc > L.length+1)
		return 0;				// overflow
	
	// tips: location( 1 ~ length)  &  subscript( 0 ~ length-1)
	for ( i = L.length; i >= loc; i--)
		L.elem[i] = L.elem[i-1];
	
	L.elem[i] = e;
	L.length += 1;
	return 1;
}

// delete an element at the loc
int ListDeleteLoc ( SqList &L, int loc, Elemtype &e)
{
	int i;
	
	if ( L.length == 0)
		return 0;
	if ( loc < 1 || loc > L.length)
		return 0;						// overflow
	
	e = L.elem[loc];
	for( i = loc-1; i < L.length-1; i++)
		L.elem[i] = L.elem[i+1];
	L.length -= 1;
	
	return 1;
}

// display elements
int DisplayList ( SqList L)
{
	int i;
	for ( i = 0; i < L.length ; i ++)
		cout << L.elem[i] << "  ";
	cout << endl;
	return 1;
}


int main ( int argc, char *argv[])
{
	// declare a new seqence list
	SqList q;
	Elemtype e;
	
	// initialization of q
	InitList( q );
	
	// Insert elements
	ListInsert( q, 2, 1);
	ListInsert( q, 1, 1);
	ListInsert( q, 5, 1);
	ListInsert( q, 6, 1);
	ListInsert( q, 4, 1);
	
	// display elements
	DisplayList( q);
	
	// find element 1
	cout << LocateElem( q, 1) << endl;
	
	// get the 2 loc element
	GetElem( q, 2, e);
	cout << e << endl;
	
	// delete the 3 loc element
	ListDeleteLoc( q, 3, e);
	DisplayList( q);
	cout << e << endl;
	
	return 0;
}

