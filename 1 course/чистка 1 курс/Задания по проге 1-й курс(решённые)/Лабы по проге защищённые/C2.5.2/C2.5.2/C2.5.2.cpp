#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
	int **m, a, b = 10, c = b, d, e, f = 0;
	m = new int*[b];
	for (int i = 0; i < b; i++)
	{
		m[i] = new int[b];
	}
	for (int i = 0; i < b; i++)
	{
		m[0][i] = i;
		m[i][0] = i;
	}
	for (int q = 1; q < b; q++)
	{
		for (c = 1; c < q + 1; c++)
		{
			m[q][c] = m[q][0] * m[0][c];
		}
	}
	for (int q = 0; q < b; q++)
	{
		cout.width(2); cout << m[0][q] << " ";
	}cout << endl;
	for (int i = 1; i < b; i++)
	{
		for (int q = 0; q < i + 1; q++)
		{
			cout.width(2);
			cout << m[i][q] << " ";
		}cout << endl;
	}
	_getch();
	return 0;
}

