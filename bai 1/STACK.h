#pragma once
#include<iostream>
using namespace std;
struct NODE
{
	int key;
	NODE* pNext;
};
struct STACK
{
	NODE* pHead;
};
//Ham khoi tao mot STACK TU MOT GIA TRI CHO TRUOC
STACK* createSTACK(int data);
//Push mot gia tri vao ngan xep
void Push(STACK*& s, int data);
//Pop mot phan tu ra khoi ngan xep va tra ve gia tri cua phan tu
int Pop(STACK*& s);
//Dem so luong phan tu trong ngan xep
int countElementsInStack(STACK*& s);
//Xac dinh ngan xep co rong khong
bool IsEmpty(STACK*& s);