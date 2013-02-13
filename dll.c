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

DllNode *nodeMake(int d)
{
	DllNode *out;
	out = malloc(sizeof(DllNode));
	out->data = d;
	out->prev = 0;
	out->next = 0;
	return out;
}

void dllInsert(Dll *dll, DllNode *node, int pos)
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
	DllNode *n;
	n = nodeMake(d);
	dllInsert(dll, n, pos);
	return n;
}

void dllPop(Dll *dll, DllNode *node)
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

void dllMove(Dll *dll, DllNode *node, int pos)
{
	dllPop(dll, node);
	dllInsert(dll, node, pos);
}