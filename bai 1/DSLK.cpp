#include"DSLK.h"
//Ham khoi tao 1 node tu mot so nguyen cho truoc
NODE* createNODE(int data)
{
	NODE* p = new (std::nothrow) NODE;
	if (p != NULL)
	{
		p->key = data;
		p->p_next = NULL;
		return p;
	}
	return NULL;
}
//Ham khoi tao List tu mot NODE cho truoc
List* createList(NODE* p_node)
{
	List* L = new (std::nothrow) List;
	if (L != NULL)
	{
		L->p_head = p_node;
		L->p_tail = p_node;
		return L;
	}
	return NULL;
}
//Ham chen mot so nguyen vao dau mot List cho truoc
bool addHead(List*& L, int data)
{
	if (L == NULL)
		return false;
	NODE* p = createNODE(data);
	if (p == NULL)
		return false;
	p->p_next = L->p_head;
	L->p_head = p;
	return true;
}
//Ham chen mot so nguyen vao cuoi mot List cho truoc
bool addTail(List*& L, int data)
{
	if (L == NULL)
		return false;
	NODE* p = createNODE(data);
	if (p == NULL)
		return false;
	L->p_tail->p_next = p;
	L->p_tail = p;
	return true;
}
//Ham xoa NODE dau tien cua mot list cho truoc
void removeHead(List*& L)
{
	if (L->p_head != NULL)
	{
		if (L->p_head == L->p_tail)
		{
			delete L->p_head;
			L->p_head = NULL;
			L->p_tail = NULL;
			return;
		}
		NODE* p = L->p_head;
		L->p_head = p->p_next;
		delete p;
	}
}
//Ham xoa Node cuoi cung cua mot List cho truoc
void removeTail(List*& L)
{
	if (L->p_head != NULL)
	{
		if (L->p_head == L->p_tail)
		{
			delete L->p_head;
			L->p_head = NULL;
			L->p_tail = NULL;
			return;
		}
		NODE* k = L->p_head;
		for (k; k->p_next != L->p_tail; k = k->p_next);
		k->p_next = L->p_tail->p_next;
		delete L->p_tail;
		L->p_tail = k;
	}
}
//Ham xoa tat ca cac NODE cua mot List cho truoc
void removeAll(List*& L)
{
	while (L->p_head != NULL)
	{
		NODE* k = L->p_head;
		L->p_head = L->p_head->p_next;
		delete k;
	}
	L->p_head = L->p_tail = NULL;
}
//Ham in tat ca cac phan tu cua mot List cho truoc
void printList(List* L)
{
	cout << "\nDANH SACH CAC PHAN TU CUA LIST" << endl;
	if (L->p_head != NULL)
	for (NODE* k = L->p_head; k != NULL; k = k->p_next)
	{
		cout << k->key << " ";
	}

}
//Ham dem so luong cac phan tu cua mot List cho truoc 
int countElements(List* L)
{
	int i = 0;
	for (NODE* k = L->p_head; k != NULL; k = k->p_next)
	{
		i++;
	}
	return i;
}
//Ham dao mot List cho truoc(Tao ra 1 List moi)
List* reverseList(List* L)
{
	NODE* k = createNODE(L->p_head->key);
	List* P = createList(k);
	if (P == NULL || k == NULL)
		return NULL;
	removeHead(L);
	while (L->p_head != NULL)
	{
		int x = L->p_head->key;
		if(addHead(P, x)==true)
			removeHead(L);
	}
	delete L;
	return P;
}
//Xoa tat ca cac phan tu trung cua mot List cho truoc
void removeDuplicate(List*& L)
{
	bool ktra; // Kiem tra co phan tu nao trung nhau k
	bool ktra1;// kiem tra xem phan tu trung nhau co o vi tri dau khong
	NODE* j = L->p_head;
	for (NODE* k = L->p_head; k != NULL;)
	{
		ktra = false; 
		ktra1 = false; 
		for (NODE* i = k->p_next; i != NULL; i = i->p_next)
		{
			if (i->key == k->key)
			{
				ktra = true;
				break;
			}
		}
		if (ktra == false) //khong co phan tu trung nhau
		{
			k = k->p_next;
			if (j != k && j->p_next != k)
			{
				j = j->p_next;
			}
		}
		else 
		{
			if (k == L->p_head)
				ktra1 = true;
			removeElement(L, k->key);
			if (ktra1 == true)
			{
				k = L->p_head;
				j = L->p_head;
			}
			else
			{
				k = j;
			}
		}
	}
}
//Xoa gia tri key cua mot List cho truoc
bool removeElement(List*& L, int key)
{
	bool ktra =false;
	NODE* k = L->p_head;
	while(k!=L->p_tail)
	{
		if (k->p_next->key == key)
		{
			if (k->p_next == L->p_tail)
			{
				L->p_tail = k;
			}
			NODE* p = k->p_next;
			k->p_next = p->p_next;
			delete p;
			ktra = true;
			continue;
		}
		k = k->p_next;
	}
	if (L->p_head->key == key)
	{
		removeHead(L);
		return true;
	}
	return false;
}
