#pragma once
#include <iostream>
using namespace std;
class TLink;
	typedef TLink* pLink;
class TLink
{
public:
	int data;
	int data2;
	pLink pNext;
public:
	TLink(int data,int data2, pLink pNext);
	void setData(int d);
	void setpNext(pLink pn);
	pLink getNext() const;
	int getData() const; 
};