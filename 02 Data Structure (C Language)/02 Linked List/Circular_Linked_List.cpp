// Program: circular linked list.cpp
// Descriptions: First Try

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

// define the type of node value
typedef int ElementType;

// define the structure of the circular linked node
typedef struct LNode {
    ElementType data;
    struct LNode *next;
} LNode, *LinkList;

// initialize the circular linked list
int InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return 1;
}

// insert a node into the circular linked list
int Insert(LinkList &L, ElementType e, int index)
{
    LNode *a = L;
    LNode *p;
    int i = 0;
    while ( a && i<(index-1))
    {
        a = a->next;
        i++;
    }
    if ( a == NULL || i>index )
        return 0;
    p = (LNode *) malloc(sizeof(LNode));
    p->data = e;
    p->next = a->next;
    a->next = p;
    if (p->next == NULL)
        p->next = L->next;
    if (index == 1)
    {
        a = p->next->next;
        while ( a->next != p->next )
            a = a->next;
        a->next = p;
    }
    return 1;
}

// display30
int Display30(LinkList L)
{
    LNode *a = L->next;
    int i = 0;
    if (a==NULL) return 0;
    while(i<30)
    {
        cout << a->data << "  ";
        a = a->next;
        i += 1;
        if(i%5==0)
            cout << endl;
    }
    return 1;
}

// get length of list
int GetLength(LinkList L)
{
    LNode *a = L->next;
    LNode *b = L->next;
    int i = 0;
    if (b==NULL)
        return 0;
    while ( b->next != a)
    {
        b = b->next;
        i++;
    }
    return i + 1;
}

// delete element
int Delete(LinkList &L, int index)
{
    LNode *a = L->next;
    LNode *b = L->next;
    LNode *c = L;
    int i = 0;

    if (a==NULL || index<1 )
        return 0;
    
    if (index==1)
    {
        if (a == a->next)
        {
            c->next = NULL;
            free(a);
            return 1;
        }
        else
        {
            while (b->next != a)
                b = b->next;
            b->next = a->next;
            c->next = a->next;
            free(a);
            return 1;
        }
    }

    while (a->next != b && i<(index-1))
    {
        a = a->next;
        c = c->next;
        i++;
    }

    c->next = a->next;
    free(a);
    return 1;
}

// display to end
int Display(LinkList L)
{
    LNode *a = L->next;
    LNode *b = L->next;

    if (a == NULL)
        return 0;

    while (a->next != b)
    {
        cout << a->data << "  ";
        a = a->next;
    }

    cout << a->data << endl;
    return 1;
}

int main ( int argc, char *argv[])
{
	LinkList L;
    InitList(L);
    Insert(L, 3, 1);
    Insert(L, 5, 2);
    Insert(L, 1, 1);
    Insert(L, 1, 1);
    Insert(L, 9, 5);
    Display30(L);
    cout << GetLength(L) << endl;
    Display(L);
    cout << endl;
    Delete(L, 3);
    Display30(L);
    cout << GetLength(L) << endl;
    // Delete(L, 1);
    // Display30(L);
    // cout << GetLength(L) << endl;
    // Delete(L, 1);
    // Display30(L);
    // cout << GetLength(L) << endl;
    // Delete(L, 1);
    // Display30(L);
    // cout << GetLength(L) << endl;
    Delete(L, 1);
    Display30(L);
    cout << GetLength(L) << endl;
    Delete(L, 3);
    Display30(L);
    cout << GetLength(L) << endl;
    Display(L);

    return 0;
}




