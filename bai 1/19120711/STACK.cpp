#include"STACK.h"
//Ham khoi tao mot STACK TU MOT GIA TRI CHO TRUOC
STACK* createSTACK(int data)
{
	STACK* s = new(std::nothrow) STACK;
	if (s == NULL)
	{
		return NULL;
	}
	NODE* p = new(std::nothrow) NODE;
	if (p == NULL)
		return NULL;
	p->key = data;
	p->pNext = NULL;
	s->pHead = p;
	return s;
}
//Push mot gia tri vao ngan xep
void Push(STACK*& s, int data)
{
	if (s == NULL)
		return;
	NODE* p = new(std::nothrow) NODE;
	if (p == NULL)
		return;
	p->key = data;
	p->pNext = NULL;
	if (s->pHead == NULL)
		s->pHead = p;
	else
	{
		p->pNext = s->pHead;
		s->pHead = p;
	}
}
//Pop mot phan tu ra khoi ngan xep va tra ve gia tri cua phan tu
int Pop(STACK*& s)
{
	if (IsEmpty(s))
		return 0;
	int x = s->pHead->key;
	NODE* p = s->pHead;
	s->pHead = p->pNext;
	delete p;
	return x;
}
//Dem so luong phan tu trong ngan xep
int countElementsInStack(STACK*& s)
{
	int dem = 0;
	for (NODE* k = s->pHead; k != NULL; k=k->pNext)
	{
		dem++;
	}
	return dem;
}
//Xac dinh ngan xep co rong khong
bool IsEmpty(STACK*& s)
{
	if (s->pHead == NULL)
		return true;
	return false;
}