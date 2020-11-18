#pragma once
#include<iostream>
using namespace std;
struct NODE {
	int key;
	NODE* p_next;
};
struct List
{
	NODE* p_head;
	NODE* p_tail;
};
//Ham khoi tao 1 node tu mot so nguyen cho truoc
NODE* createNODE(int data);
//Ham khoi tao List tu mot NODE cho truoc
List* createList(NODE* p_node);
//Ham chen mot so nguyen vao dau mot List cho truoc
bool addHead(List*& L, int data);
//Ham chen mot so nguyen vao cuoi mot List cho truoc
bool addTail(List*& L, int data);
//Ham xoa NODE dau tien cua mot list cho truoc
void removeHead(List*& L);
//Ham xoa Node cuoi cung cua mot List cho truoc
void removeTail(List*& L);
//Ham xoa tat ca cac NODE cua mot List cho truoc
void removeAll(List*& L);
//Ham in tat ca cac phan tu cua mot List cho truoc
void printList(List* L);
//Ham dem so luong cac phan tu cua mot List cho truoc 
int countElements(List* L);
//Ham dao mot List cho truoc(Tao ra 1 List moi)
List* reverseList(List* L);
//Xoa tat ca cac phan tu trung cua mot List cho truoc
void removeDuplicate(List*& L);
//Xoa gia tri key cua mot List cho truoc
bool removeElement(List*& L, int key);
