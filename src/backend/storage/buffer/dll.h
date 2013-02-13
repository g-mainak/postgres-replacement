#define TAIL 0
#define HEAD 1

typedef struct dllnode DllNode;
typedef struct dll Dll;

struct dll
{
	int size;
	DllNode *head;
	DllNode *tail;
};

struct dllnode
{
	int data;
	DllNode *prev;
	DllNode *next;
};

Dll *dllMake(void);
DllNode *nodeMake(int d);
void dllInsert(Dll *dll, DllNode *node, int pos);
DllNode *dllInsertInt(Dll *dll, int d, int pos);
void dllPop(Dll *dll, DllNode *node);
void dllMove(Dll *dll, DllNode *node, int pos);

extern Dll *BufDLL;
extern DllNode **BufNodes;