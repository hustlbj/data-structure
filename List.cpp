// List.cpp : The List will have a head node, data node begins from position 1.
//

#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node{
	ElementType Data;
	struct Node *Next;
}List;

//求表长
int Length(List *PtrL)
{
	//先保证链表有头结点
	if (PtrL==NULL || PtrL->Next==NULL)
	{
		return 0;
	} 
	//从头结点的Next开始计数
	List *p=PtrL->Next;
	int j=0;
	while(p)
	{
		j++;
		p=p->Next;
	}
	return j;
}
//查找，返回第K个元素，头结点位置是0，头结点的Next指向第1个元素
List *FindKth(int K,List *PtrL)
{
	if(PtrL==NULL)
	{
		return NULL;
	}
	List *p=PtrL;
	int i=0;
	while(p!=NULL && i<K)
	{
		p=p->Next;
		i++;
	}
	if(i==K)
		return p;
	else
	{
		return NULL;
	}
}
//插入
List *Insert(ElementType X,int i,List *PtrL)
{
	List *p,*s;
	if(i<=0)
	{
		printf("参数i错");
		return NULL;
	}
		
	//先找到前一个位置，i必须>=1
	p=FindKth(i-1,PtrL);
	//位置错误的话返回NULL，表示错误！
	if(p==NULL)
	{
		printf("参数i错");
		return NULL;
	}
	else
	{
		s=(List *)malloc(sizeof(List));
		s->Data=X;
		s->Next=p->Next;
		p->Next=s;
		return PtrL;
	}
}
//删除
List *Delete(int i,List *PtrL)
{
	List *p,*s;
	if(i<1)
	{
		printf("参数i错");
		return NULL;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL)
	{
		printf("第%d个结点不存在",i-1);
		return NULL;
	}
	else if(p->Next==NULL)
	{
		printf("第%d个结点不存在",i);
		return NULL;
	}
	else
	{
		s=p->Next;
		p->Next=s->Next;
		free(s);
		return PtrL;
	}
}

int main(int argc, char* argv[])
{
	List *PtrL = (List *)malloc(sizeof(List));
	if(PtrL == NULL)
	{
		printf("初始化头结点失败");
		return -1;
	}
	PtrL->Next = NULL;
	//插入一个元素
	PtrL = Insert(1, 1, PtrL);
	//看长度
	int length = Length(PtrL);
	printf("插入第一个元素，链表长度：%d\n", length);
	//查找第一个元素
	List *Node = FindKth(1, PtrL);
	printf("查找第一个元素，第1个元素是：%d\n", Node->Data);
	//删除第一个元素，看长度
	PtrL = Delete(1, PtrL);
	length = Length(PtrL);
	printf("删除第一个元素，链表长度：%d\n", length);

	return 0;
}
