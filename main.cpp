#include <iostream>
#include<conio.h>
#include <cstdlib>
#include"TList.h"
#include "E:\\Visual Studio 2013\\Projects\\TLink\\TLink\\TLink.h"
using namespace std;
int main()
{
	TList B;
	TList A;
	TList Sum;
	int m=0, n=0, k=0;
	int j = 1, l = 1, z = 1, c = 0, v = 1,x = 1, h = 1;
	int coef=0,cnt=0;
	char st[40]="";
	char step[10]="";
	do{
		cout << "Enter coeficient: " << endl;
		cin >> coef;
		if (coef != 0){
			cout << "Enter deg X ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
				{
					cout << "Enter deg X again:";
					cin >> step;
				}
			strcat_s(st,step);
			cout << "Enter deg Y ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
				{
					cout << "Enter deg Y again";
					cin >> step;
				}
			strcat_s(st, step);
			cout << "Enter deg Z ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
				{
					cout << "Enter deg Z again";
					cin >> step;
				}
			strcat_s(st, step);
		}
		B.insCurrent(atoi(st), coef);
		st[0] = '\0';
		cout << "Yet?" << endl;
		cin >> c;
	} while (c != 0);

	for (int i = 1; i < B.GetSize(); i++)
	{
		m = B[i] / 100;
		n = (B[i] / 10) % 10;
		k = B[i] % 10;
		if (B.koef(i)!=1)
		cout << B.koef(i);
		if (m == 1)
			cout << "x";
		else if (m != 0)
			cout << "*x^" << m;
		if (n == 1)
			cout << "*y";
		else if (n != 0)
			cout << "*y^" << n;
		if (k == 1)
			cout << "*z";
		else if (k != 0)
			cout << "*z^" << k;
		if ((j < B.GetSize() - 1) && (B.koef(i + 1)>0))
		{
			cout << "+";
		}
		j++;
	}
	cout << endl;
	do{
		cout << "Enter coeficient: " << endl;
		cin >> coef;
		if (coef != 0){
			cout << "Enter deg X ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
			{
				cout << "Enter deg X again:";
				cin >> step;
			}
			strcat_s(st, step);
			cout << "Enter deg Y ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
			{
				cout << "Enter deg Y again";
				cin >> step;
			}
			strcat_s(st, step);
			cout << "Enter deg Z ";
			cin >> step;
			while ((atoi(step)<0) || (atoi(step)>9))
			{
				cout << "Enter deg Z again";
				cin >> step;
			}
			strcat_s(st, step);
		}
		A.insCurrent(atoi(st), coef);
		cout << "Size A: " << A.GetSize() << endl;
		st[0] = '\0';
		cout << "Yet?" << endl;
		cin >> c;
	} while (c != 0);
	for (int i = 1; i < A.GetSize(); i++)
	{
		m = A[i] / 100;
		n = (A[i] / 10) % 10;
		k = A[i] % 10;
		if (A.koef(i) != 1)
			cout << A.koef(i);
		if (m == 1)
			cout << "x";
		else if (m != 0)
			cout << "*x^" << m;
		if (n == 1)
			cout << "*y";
		else if (n != 0)
			cout << "*y^" << n;
		if (k == 1)
			cout << "*z";
		else if (k != 0)
			cout << "*z^" << k;
		if ((l < A.GetSize() - 1) && (A.koef(i + 1)>0))
		{
			cout << "+";
		}
		l++;
	}
	cout << endl;
	cout << "Sum First: ";
	Sum = B + A;
	for (int i = 0; i < Sum.GetSize(); i++)
	{
		if (Sum.koef(i) != 0){
			m = Sum[i] / 100;
			n = (Sum[i] / 10) % 10;
			k = Sum[i] % 10;
			if (Sum.koef(i) != 1)
				cout << Sum.koef(i);
			if (m == 1)
				cout << "x";
			else if (m != 0)
				cout << "*x^" << m;
			if (n == 1)
				cout << "*y";
			else if (n != 0)
				cout << "*y^" << n;
			if (k == 1)
				cout << "*z";
			else if (k != 0)
				cout << "*z^" << k;
			if ((z < Sum.GetSize() - 1) && (Sum.koef(i + 1)>0))
			{
				cout << "+";
			}
			z++;
		}
		if (Sum.GetSize() == 1)
			cout << 0 << endl;

	}
	cout << endl;
	cout << "A: ";
	for (int i = 0; i < A.GetSize(); i++)
	{
		if (A.koef(i) != 0){
			m = A[i] / 100;
			n = (A[i] / 10) % 10;
			k = A[i] % 10;
			if (A.koef(i) != 1)
				cout << A.koef(i);
			if (m == 1)
				cout << "x";
			else if (m != 0)
				cout << "*x^" << m;
			if (n == 1)
				cout << "*y";
			else if (n != 0)
				cout << "*y^" << n;
			if (k == 1)
				cout << "*z";
			else if (k != 0)
				cout << "*z^" << k;
			if ((x < A.GetSize() - 1) && (A.koef(i + 1)>0))
			{
				cout << "+";
			}
			x++;
		}
		if (A.GetSize() == 1)
			cout << 0 << endl;
	}
	x = 1;
	cout << endl;
	cout << "B: ";
	for (int i = 0; i < B.GetSize(); i++)
	{
		if (B.koef(i) != 0){
			m = B[i] / 100;
			n = (B[i] / 10) % 10;
			k = B[i] % 10;
			if (B.koef(i) != 1)
				cout << B.koef(i);
			if (m == 1)
				cout << "x";
			else if (m != 0)
				cout << "*x^" << m;
			if (n == 1)
				cout << "*y";
			else if (n != 0)
				cout << "*y^" << n;
			if (k == 1)
				cout << "*z";
			else if (k != 0)
				cout << "*z^" << k;
			if ((h < B.GetSize() - 1) && (B.koef(i + 1)>0))
			{
				cout << "+";
			}
			h++;
		}
		if (B.GetSize() == 1)
			cout << 0 << endl;
	}
	h = 1;
	cout << endl;
	cout << "Sum Second: ";
	B=B.plus(A);
	for (int i = 0; i < B.GetSize(); i++)
	{
		if (B.koef(i) != 0){
			m = B[i] / 100;
			n = (B[i] / 10) % 10;
			k = B[i] % 10;
			if (B.koef(i) != 1)
				cout << B.koef(i);
			if (m == 1)
				cout << "x";
			else if (m != 0)
				cout << "*x^" << m;
			if (n == 1)
				cout << "*y";
			else if (n != 0)
				cout << "*y^" << n;
			if (k == 1)
				cout << "*z";
			else if (k != 0)
				cout << "*z^" << k;
			if ((v < B.GetSize() - 1) && (B.koef(i + 1)>0))
			{
				cout << "+";
			}
			v++;
		}
		if (B.GetSize() == 1)
			cout << 0 << endl;
	}
	cout << endl;
	cout << "A: ";
	for (int i = 0; i < A.GetSize(); i++)
	{
		if (A.koef(i) != 0){
			m = A[i] / 100;
			n = (A[i] / 10) % 10;
			k = A[i] % 10;
			if (A.koef(i) != 1)
				cout << A.koef(i);
			if (m == 1)
				cout << "x";
			else if (m != 0)
				cout << "*x^" << m;
			if (n == 1)
				cout << "*y";
			else if (n != 0)
				cout << "*y^" << n;
			if (k == 1)
				cout << "*z";
			else if (k != 0)
				cout << "*z^" << k;
			if ((x < A.GetSize() - 1) && (A.koef(i + 1)>0))
			{
				cout << "+";
			}
			x++;
		}
		if (A.GetSize() == 1)
		{
			cout << 0 << endl;
			break;
		}
		if (A.koef(i) == 0)
		{
			cout << 0 << endl;
			break;
		}
	}
	x = 1;
	cout << endl;
	cout << "B: ";
	for (int i = 0; i < B.GetSize(); i++)
	{
		if (B.koef(i) != 0){
		m = B[i] / 100;
		n = (B[i] / 10) % 10;
		k = B[i] % 10;
		if (B.koef(i) != 1)
			cout << B.koef(i);
		if (m == 1)
			cout << "x";
		else if (m != 0)
			cout << "*x^" << m;
		if (n == 1)
			cout << "*y";
		else if (n != 0)
			cout << "*y^" << n;
		if (k == 1)
			cout << "*z";
		else if (k != 0)
			cout << "*z^" << k;
		if ((h < B.GetSize() - 1) && (B.koef(i + 1)>0))
		{
			cout << "+";
		}
		h++;
		}
		if (B.GetSize() == 1)
			cout << 0 << endl;
	}
	h = 1;
	cout << endl;
	_getch();
	return 0;
}