#pragma once
#include <iostream>
#include "E:\\Visual Studio 2013\\Projects\\TLink\\TLink\\TLink.h"
using namespace std;
class TList
{
protected:
	pLink Head;
	int size=0;
public:
	TList();
	//void insFirst(int _data);
	//void insLast(int _data);
	void insCurrent(int _data,int _data2);
	void deleteCurrent(int Numb);
	void printList();
	pLink search(int _data);
	int& operator[](const int index);
	int& koef(const int index);
	TList operator + (TList list);
	int GetSize();
	TList plus(TList list);
};

