#define TAIL 0
#define HEAD 1

typedef struct node Node;
typedef struct dll Dll;

struct dll
{
	int size;
	Node *head;
	Node *tail;
};

struct node
{
	int data;
	Node *prev;
	Node *next;
};

Dll *dllMake(void);
Node *nodeMake(int d);
void dllInsert(Dll *dll, Node *node, int pos);
void dllInsertInt(Dll *dll, int d, int pos);
void dllPop(Dll *dll, Node *node);
void dllMove(Dll *dll, Node *node, int pos);