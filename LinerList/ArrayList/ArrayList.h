#ifndef		 ARRAYLIST_H
#define 	 ARRAYLIST_H
typedef  int ElemType;

typedef struct {
	ElemType* data;
	int length;
}SqList;


bool InitList(SqList& L);
bool DestroyList(SqList &L);
int Length(SqList L);
int LocateElem(SqList L, ElemType e);
ElemType getElem(SqList L ,int i);
bool ListInsert(SqList& L, int i, ElemType e);
bool ListDelete(SqList &L ,int i ,ElemType &e);
bool Empty(SqList L);
void PrintList(SqList L);
#endif
