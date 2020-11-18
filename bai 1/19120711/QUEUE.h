#pragma once
#include<iostream>
using namespace std;
struct NODE
{
	int key;
	NODE* pNext;
};
struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};
//khoi tao mot hang doi tu mot gia tri cho truoc
QUEUE* createQUEUE(int data);
//enqueue mot gia tri vao hang doi
void Enqueue(QUEUE*& q, int data);
//Dequeue mot gia tri ra khoi hang doi tra ve gia tri cua phan tu do
int Dequeue(QUEUE*& q);
//Dem so luong phan tu trong hang doi
int countElementsInQueue(QUEUE* q);
//Xac dinh mot hang doi co rong hay khong
bool IsEmpty(QUEUE*& q);