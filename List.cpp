// List.cpp : The List will have a head node, data node begins from position 1.
//

#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node{
	ElementType Data;
	struct Node *Next;
}List;

//���
int Length(List *PtrL)
{
	//�ȱ�֤������ͷ���
	if (PtrL==NULL || PtrL->Next==NULL)
	{
		return 0;
	} 
	//��ͷ����Next��ʼ����
	List *p=PtrL->Next;
	int j=0;
	while(p)
	{
		j++;
		p=p->Next;
	}
	return j;
}
//���ң����ص�K��Ԫ�أ�ͷ���λ����0��ͷ����Nextָ���1��Ԫ��
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
//����
List *Insert(ElementType X,int i,List *PtrL)
{
	List *p,*s;
	if(i<=0)
	{
		printf("����i��");
		return NULL;
	}
		
	//���ҵ�ǰһ��λ�ã�i����>=1
	p=FindKth(i-1,PtrL);
	//λ�ô���Ļ�����NULL����ʾ����
	if(p==NULL)
	{
		printf("����i��");
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
//ɾ��
List *Delete(int i,List *PtrL)
{
	List *p,*s;
	if(i<1)
	{
		printf("����i��");
		return NULL;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL)
	{
		printf("��%d����㲻����",i-1);
		return NULL;
	}
	else if(p->Next==NULL)
	{
		printf("��%d����㲻����",i);
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
		printf("��ʼ��ͷ���ʧ��");
		return -1;
	}
	PtrL->Next = NULL;
	//����һ��Ԫ��
	PtrL = Insert(1, 1, PtrL);
	//������
	int length = Length(PtrL);
	printf("�����һ��Ԫ�أ������ȣ�%d\n", length);
	//���ҵ�һ��Ԫ��
	List *Node = FindKth(1, PtrL);
	printf("���ҵ�һ��Ԫ�أ���1��Ԫ���ǣ�%d\n", Node->Data);
	//ɾ����һ��Ԫ�أ�������
	PtrL = Delete(1, PtrL);
	length = Length(PtrL);
	printf("ɾ����һ��Ԫ�أ������ȣ�%d\n", length);

	return 0;
}
