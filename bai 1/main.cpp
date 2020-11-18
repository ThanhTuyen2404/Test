//#include"DSLK.h"
#include"QUEUE.h"
int main()
{
	QUEUE* q = createQUEUE(5);
	Enqueue(q, 9);
	Enqueue(q, 8);
	Enqueue(q, 7);
	Enqueue(q, 6);
	Enqueue(q, 5);
	Enqueue(q, 4);
	for (NODE* k = q->pHead; k != NULL; k = k->pNext)
	{
		cout << k->key << " ";
	}
	cout << countElementsInQueue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	cout << Dequeue(q) << endl;
	for (NODE* k = q->pHead; k != NULL; k = k->pNext)
	{
		cout << k->key << " ";
	}
	cout << countElementsInQueue(q) << endl;
	while (q->pHead != NULL)
	{
		NODE* k = q->pHead;
		q->pHead = q->pHead->pNext;
		delete k;
	}
	delete q;
}