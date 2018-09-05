#include "TList.h"
using namespace std;
TList::TList()
{
	Head = new TLink(-1,0, Head);
	Head->pNext = Head;
	size =1;
}
void TList::insCurrent(int _data, int _data2)
{
	pLink ptr, tmp, cnt, n;
	ptr = tmp = cnt = n = Head;
	if (_data2 != 0){
		while ((cnt->pNext->data != -1) && (cnt->pNext->data != _data))
		{
			n = n->pNext;
			cnt = cnt->pNext;
		}
		cnt = cnt->pNext;
		n = n->pNext;
		if (cnt->data == _data)
		{
			while (ptr->pNext != cnt)
				ptr = ptr->pNext;
			cnt->data2 = cnt->data2 + _data2;
			if (cnt->data2 == 0)
			{
				ptr->pNext = cnt->pNext;
				delete cnt;
				size--;
			}
		}
		if (n->data == -1){
			if (_data > tmp->pNext->data)
			{
				pLink p = new TLink(_data, _data2, tmp->pNext);
				Head->pNext = p;
			}
			else
			{
				while (_data < tmp->pNext->data)
					tmp = tmp->pNext;
				pLink p = new TLink(_data, _data2, tmp->pNext);
				tmp->pNext = p;
			}
			size++;
		}
	}
}
void TList::deleteCurrent(int Numb)
{
	pLink ptr,tmp,p;
	p = Head;
	ptr = Head;
	tmp = search(Numb);
	//cout << "***** "<<tmp->data << endl;
	while (ptr->getNext() != tmp)
	{
		ptr = ptr->getNext();
	}
	//cout << "----" << ptr->data << endl;
	ptr->pNext = tmp->pNext;
	//cout << "---" << tmp->pNext->data << endl;
	delete tmp;
	tmp = NULL;
	size--;
}

TList TList::operator+(TList list)
{
	TList J;
	TList B = list;
	pLink ptr, tmp, temp, n, m, k;
	temp = ptr = tmp = Head;
	n = m = k = B.Head;
	int flag = 1;
	while ((ptr->pNext->data != -1) || (n->pNext->data != -1))
	{
		if ((ptr->data == -1) && (n->data == -1))
		{
			ptr = ptr->pNext;
			n = n->pNext;
		}
			if ((ptr->data > n->data)&&(flag==1))
			{
				J.insCurrent(ptr->data, ptr->data2);
				
				ptr = ptr->pNext;
				flag = 0;
			}
			if ((ptr->data < n->data) && (flag == 1))
			{
				J.insCurrent(n->data, n->data2);
				
				n = n->pNext;
				flag = 0;
			}
			if ((ptr->data == n->data) && (flag == 1))
			{
				J.insCurrent(ptr->data, ptr->data2 + n->data2);
				
				flag = 0;
				ptr = ptr->pNext;
				n = n->pNext;
			}
			flag = 1;
			if ((ptr->data == -1) && (n->data == -1))
				break;
		}
	if ((ptr->data == n->data) && (ptr->data != -1) && (n->data!=-1))
	{
		J.insCurrent(ptr->data, ptr->data2 + n->data2);
	
	}
	if (ptr->data != n->data)
	{
		if (ptr->data == -1)
		{
			J.insCurrent(n->data, n->data2);
			
		}
		else if (n->data == -1)
		{
			J.insCurrent(ptr->data, ptr->data2);
			
		}
		if ((ptr->data != -1) && (n->data != -1))
		{
			J.insCurrent(n->data, n->data2);
			J.insCurrent(ptr->data, ptr->data2);
			
		}
	}
	return J;
}
pLink TList::search(int _data)
{
	pLink ptr, tmp, res;
	tmp = ptr = res = Head;
	if (tmp->pNext == Head)
	{
		res  = tmp;
		//cout << "&&& " << res->data << endl;
		res->data = tmp->data;
	}
	else
	{
		//cout << "hui" << endl;
		while (tmp->pNext!=Head)
		{
			if (tmp->data == _data)
			{
				res  = tmp;
				//cout << "&&" << tmp->data << endl;
				res->data = tmp->data;
				break;
			}
			tmp = tmp->getNext();
		}
		if (tmp->data == _data)
		{
			res = tmp;
		/*	cout << "&&" << tmp->data << endl;*/
			res->data = tmp->data;
		}
	}
	//cout << "& " << res->data << endl;
	return res;
}
int& TList::operator[](const int index)
{
	int count = 0;
	int res = 0;
	pLink ptr = Head;
	if (ptr->pNext == Head)
	{
		res = ptr->getData();
		
	}
	else
	{
		while (ptr->pNext != Head)
		{
			if (count == index)
			{
				res = ptr->getData();
				/*cout << "^^^^" << res << endl;*/
				break;
			}
			/*cout << "^^^" << ptr->data << endl;*/
			ptr = ptr->getNext();
			count++;
		}
		if (ptr->pNext == Head)
		{
			res = ptr->data;
			/*cout << "^^" << res << endl;
			cout << "^^^" << ptr->data << endl;*/
		}
	}
	return res;
}
int& TList::koef(const int index)
{
	int count = 0;
	int res = 0;
	pLink ptr = Head;
	if (ptr->pNext == Head)
	{
		res = ptr->data2;
		
	}
	else
	{
		while (ptr->pNext != Head)
		{
			if (count == index)
			{
				res = ptr->data2;
				/*cout << "^^^^" << res << endl;*/
				break;
			}
			/*cout << "^^^" << ptr->data << endl;*/
			ptr = ptr->getNext();
			count++;
		}
		if (ptr->pNext == Head)
		{
			res = ptr->data2;
			/*cout << "^^" << res << endl;
			cout << "^^^" << ptr->data << endl;*/
		}
	}
	return res;
}
int TList::GetSize()
{
	return size;
}
TList TList::plus(TList list)
{
	pLink tmp, ptr, temp, prev1, prev2, cnt,n;
	tmp = prev1 = cnt = Head;
	ptr = prev2 =temp= n=list.Head;
	size=this->GetSize();
	int flag = 1;
	while ((tmp->pNext->data != -1) && (ptr->pNext->data != -1))
	{
		if ((ptr->data == -1) && (tmp->data == -1))
		{
			ptr = ptr->pNext;
			tmp = tmp->pNext;
			temp = temp->pNext;
			cnt = cnt->pNext;
		}
		if ((tmp->data > ptr->data)&&(flag == 1))
		{
			ptr = ptr->pNext;
			this->insCurrent(temp->data, temp->data2);
			list.deleteCurrent(temp->data);
			temp = ptr;
			flag = 0;
		}
		if ((tmp->data < ptr->data) && (flag == 1))
		{
			ptr = ptr->pNext;
			tmp = tmp->pNext;
			this->insCurrent(temp->data, temp->data2);
			list.deleteCurrent(temp->data);
			temp= ptr;
			flag = 0;
		}
		if ((tmp->data == ptr->data) && (flag == 1))
		{
			this->insCurrent(tmp->data,tmp->data2 + ptr->data2);
			if ((tmp->data2 + ptr->data2) == 0)
			{
				while ((prev1->pNext != tmp) && (n->pNext != ptr))
				{
					prev1 = prev1->pNext;
					n = n->pNext;
				}
				tmp = tmp->pNext;
				ptr = ptr->pNext;
				this->deleteCurrent(cnt->data);
				list.deleteCurrent(temp->data);
				cnt = tmp;
				temp = ptr;
				/*prev1->pNext = tmp;
				n->pNext = ptr;
				delete cnt;
				delete temp;
				cnt = NULL;
				temp = NULL;
				size--;*/
			}
			flag = 0;
		}
		flag = 1;
	}
	if ((ptr->data == tmp->data) && (ptr->data != -1) && (tmp->data != -1))
	{
		this->insCurrent(ptr->data, tmp->data2 + ptr->data2);
		if ((tmp->data2 + ptr->data2) == 0)
		{
			while ((prev1->pNext != tmp) && (n->pNext != ptr))
			{
				prev1 = prev1->pNext;
				n = n->pNext;
			}
			tmp = tmp->pNext;
			ptr = ptr->pNext;
			this->deleteCurrent(cnt->data);
			list.deleteCurrent(temp->data);
			list.size--;
			cnt = tmp;
			temp = ptr;
			/*prev1->pNext = tmp;
			n->pNext = ptr;
			delete cnt;
			delete temp;
			cnt = NULL;
			temp = NULL;
			size--;*/
		}
	}
	if (ptr->data != tmp->data)
	{
		if (tmp->data == -1)
		{
			while (ptr->pNext != list.Head)
			{
				this->insCurrent(ptr->data, ptr->data2);
				ptr = ptr->pNext;
				list.size--;
			}
	    }
		if ((ptr->data != -1) && (tmp->data != -1))
			{
				this->insCurrent(ptr->data, ptr->data2);
				list.deleteCurrent(ptr->data);
			}
		}

	return *this;
}