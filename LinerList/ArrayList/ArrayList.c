#include "ARRAYLIST.h"
#define InitSize 20
#include<stdio.h>
#include<stdlib.h>
bool InitList(SqList& L)
{
	L.data = (ElemType *)malloc(sizeof(ElemType)* InitSize);
	if (L.data == NULL)
		return false;
	L.length = 0;
	return true;
	
}

bool DestroyList(SqList& L)
{
	free(L.data);
	L.data = NULL;
	L.length = 0;
	return true;
}

int Length(SqList L)
{
	return  L.length;
}

int LocateElem(SqList L, ElemType e)
{
	int rank =0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			rank = i + 1;
			break;
		}
	}
	if(rank>L.length)
		return -1;//返回-1：代表查找失败没有该元素。
	return rank;
}

ElemType getElem(SqList L, int i)
{
	if (Empty(L))
	{
		printf("线性表为空,返回-1");
		return -1;
	}
	if (i<1 || i>L.length)
	{
		printf("输入的位序i非法，返回第一个元素的值");
		return L.data[0];
	}
	
	return L.data[i-1];
}

bool ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)
	{
		printf("插入的位置非法");
		return false;
	}
	if (L.length == InitSize)
	{
		printf("线性表已满");
		return false;
	}
	for (int r = L.length; r >i ; r--)
	{
		L.data[r] = L.data[r - 1];
	}
	L.length++;
	L.data[i] = e;
	return true;

}

bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (Empty(L))
	{
		printf("线性表为空,删除失败");
		return false;
	}
	if (i<1 || i>L.length)
	{
		printf("删除的位置非法");
		return false;
	}
	for (int r = i; r < L.length-1; r++)
	{
		L.data[r] = L.data[r + 1];
	}
	L.length--;
	return true;
}

bool Empty(SqList L)
{	
	return L.length==0;
}

void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf(" %d ", L.data[i]);
		printf("\n");
	}
}
