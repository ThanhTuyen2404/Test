#include"QUEUE.h"
//khoi tao mot hang doi tu mot gia tri cho truoc
QUEUE* createQUEUE(int data)
{
	QUEUE* q = new(std::nothrow) QUEUE;
	if (q == NULL)
	{
		return NULL;
	}
	NODE* p = new(std::nothrow) NODE;
	if (p == NULL)
		return NULL;
	p->key = data;
	p->pNext = NULL;
	q->pHead = p;
	q->pTail = p;
	return q;
}
//enqueue mot gia tri vao hang doi
void Enqueue(QUEUE*& q, int data)
{
	if (q == NULL)
		return;
	NODE* p = new(std::nothrow) NODE;
	if (p == NULL)
		return;
	p->key = data;
	p->pNext = NULL;
	if (q->pHead == NULL)
	{
		q->pHead = p;
		q->pTail = p;
	}
	else
	{
		q->pTail->pNext = p;
		q->pTail = p;
	}
}
//Dequeue mot gia tri ra khoi hang doi tra ve gia tri cua phan tu do
int Dequeue(QUEUE*& q)
{
	if (IsEmpty(q))
	{
		return 0;
	}
	int x = q->pHead->key;
	NODE* p = q->pHead;
	q->pHead = p->pNext;
	delete p;
	if (q->pHead == NULL)
		q->pTail = NULL;
	return x;
}
//Dem so luong phan tu trong hang doi
int countElementsInQueue(QUEUE* q)
{
	int dem = 0;
	for (NODE* k = q->pHead; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
//Xac dinh mot hang doi co rong hay khong
bool IsEmpty(QUEUE*& q)
{
	if (q->pHead == NULL)
		return true;
	return false;
}