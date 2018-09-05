#include "TLink.h"
using namespace std;
TLink::TLink(int _data,int _data2,pLink _pNext)
{
	data = _data;
	data2 = _data2;
	pNext = _pNext;
}
void TLink::setData(int d)
{
	data = d;
}
void TLink::setpNext(pLink pn)
{
	pNext = pn;
}
pLink TLink::getNext() const
{
	return pNext;
}
int TLink::getData() const
{
	return data;
}