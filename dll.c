#include "dll.h"
#include <stdlib.h>

Dll *dllMake(void)
{
	Dll *out;
	out = malloc(sizeof(Dll));
	out->head = 0;
	out->tail = 0;
	out->size = 0;
	return out;
}

Node *nodeMake(int d)
{
	Node *out;
	out = malloc(sizeof(Node));
	out->data = d;
	out->prev = 0;
	out->next = 0;
	return out;
}

void dllInsert(Dll *dll, Node *node, int pos)
{
	if (dll->size == 0)
	{
		dll->head = node;
		dll->tail = node;
	}
	else if (pos == HEAD)
	{
		node->next = dll->head;
		dll->head->prev = node;
		dll->head = node;
	}
	else if (pos == TAIL)
	{
		node->prev = dll->tail;
		dll->tail->next = node;
		dll->tail = node;
	}
	dll->size++;
}

void dllInsertInt(Dll *dll, int d, int pos)
{
	Node *n;
	n = nodeMake(d);
	dllInsert(dll, n, pos);
}

void dllPop(Dll *dll, Node *node)
{
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	else 
	{
		dll->head = node->next;
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	else
	{
		dll->tail = node->prev;
	}
	node->next = 0;
	node->prev = 0;
	dll->size--;
}

void dllMove(Dll *dll, Node *node, int pos)
{
	dllPop(dll, node);
	dllInsert(dll, node, pos);
}