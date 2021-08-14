// Program: sequence stack1.cpp
// Descriptions: first learn

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#define MAXSIZE 100					// max size of sequence stack

using namespace std;

// the type of elements in the sequence
typedef char element;

// the structure of the sequence stack
typedef struct
{
	element *base;		//the pointer to the base element of the sequence stack
	element *top;		//the pointer to the top element of the sequence stack
	int stacksize;
} SqStack;

// initialization of the sequence stack
int InitStack( SqStack &S)
{
	// mallocate an array of elements: element[MAXSIZE]
	S.base = (element *)malloc(sizeof(element) * MAXSIZE);
	if (!S.base)
		return 0;		// overflow
	// initialize the top pointer & size
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

// push into the stack
int Push( SqStack &S, element e)
{
	if (S.top-S.base == S.stacksize)
		return 0;	// overflow, the stack is full
	// not full, push the element to the top of the sequence stack
	*S.top++ = e;
	// equals to "*S.top =e, S.top++";
	return 1;
}

// pop from the stack
int Pop( SqStack &S, element &e)
{
	if(S.top==S.base)
		return 0;	// overflow, the stack is empty
	// not empty, pop the element from the base of the sequence stack
	e = *--S.top;
	return 1;
}

// get the top element but not change the pointer
element GetTop( SqStack S)
{
	if (S.top != S.base)
		return *(S.top - 1);
	return 0;
}

// the length of the sequence stack
int GetSequenceLength( SqStack S)
{
	return S.top - S.base;
}

int main ( int argc, char *argv[])
{
	// declare a sequence stack
	SqStack S;
	element e = 'a';
	// initialization
	InitStack(S);
	// push into the stack
	Push(S, 'a');
	Push(S, 'b');
	Push(S, 'c');
	Push(S, 'd');
	Push(S, 'e');
	// get the top element
	cout << GetTop(S) << endl;
	// pop from the stack
	Pop(S, e);
	cout << e << endl;
	Pop(S, e);
	cout << e << endl;
	Pop(S, e);
	cout << e << endl;

	return 0;
}





