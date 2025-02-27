// saodL14Hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <cstring>
#include <cstdio>
#pragma warning(disable : 4996)
using namespace std;
typedef struct st { char *x; struct st *next; } str;
void Fill(char **arr, int n);
void Print(str *H);
void Print2(char(*arr1)[8], char(*arr2)[8], int n);
void PrintTable();
int Len(char(*arr)[8], int n);
int HashAdress(char *arr, int n);
int HashAdress2(char *arr, unsigned int &h, int n, int j);
int HashAdress3(char *arr, unsigned int &h, int n, int j);
int HashInsert(str **H, char *x);
int HashSearch(str *H, int key);
int Hash1(char(*arr)[8], int n);
int Hash2(char(*arr)[8], int n, bool T);
int arr0[] = { 0,1,2,3,5,7,11,13,17,19,23,10 };
int K1 = 0, K2 = 0;
int main()
{

	srand(time(NULL));
	int n, h, a, j, key, i;
	cout << "¬ведите колличество строк: ";
	cin >> n;
	char ** arr;
	arr = (char**)malloc(n * sizeof(char*));
	for ( i = 0; i < n; i++)
	{
		arr[i] = new char[8];
	}
	//char arr[n][8];
	Fill(arr, n);
	Hash1(arr, n);
	getch();
	system("cls");
	Hash2(arr, n, false);
	getch();
	system("CLS");
	PrintTable();
	//getch();
	system("CLS");
}
void Fill(char** arr, int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<7; j++)
			arr[i][j] = rand() % 25 + 97;
		arr[i][rand() % 4 + 4] = '\0';
	}
}
void Print(str *H)
{
	str *Temp;
	Temp = H;
	while (1)
		if (Temp == NULL)
		{
			printf("\n");
			break;
		}
		else
		{
			printf("%s ", Temp->x);
			Temp = Temp->next;
		}
}
void Print2(char(*arr1)[8], char(*arr2)[8], int n)
{
	printf("	    g(i)       g(i^2)\n");
	for (int i = 0; i<n; i++)
		printf("H=%d:	%9s	%9s\n", i, arr1[i], arr2[i]);
}
void PrintTable()
{
	for (int i = 100; i < 501; i += 100)
	{
		K1 = K2 = 0;
		char arr[i][8];
		Fill(arr, i);
		Hash2(arr, i, true);
		printf("%d	%d	%d	%d\n", i, Len(arr, i), K1, K2);
	}
}
int Len(char(*arr)[8], int n)
{
	int L = 0;
	for (int j = 0; j < n; j++)
		L += strlen(arr[j]);
	return L;
}
void Freespis(str *p)
{
	str *a, *q;
	q = a = p;
	while (a != NULL)
	{
		a = q->next;
		delete q;
		q = a;
	}
	p = NULL;
}
int HashAdress(char *arr, int n)
{
	unsigned int h = 0, i = 0;
	while (arr[i] != '\0')
	{
		h = (h * 256 + arr[i]) % n;
		i++;
	}
	return h;
}
int HashAdress2(char *arr, unsigned int &h, int n, int j)
{
	unsigned int i = 0;
	while (arr[i] != '\0')
	{
		h = (h * 256 + arr[i]) % n;
		i++;
	}
	h = (h + j) % n;
}
int HashAdress3(char *arr, unsigned int &h, int n, int j)
{
	unsigned int i = 0;
	while (arr[i] != '\0')
	{
		h = (h * 256 + arr[i]) % n;
		i++;
	}
	h = (h + j * j) % n;
}
int HashInsert(str **H, char *x)
{
	str *Temp, *Head;
	Temp = new str;
	Temp->x = x;
	Temp->next = NULL;
	Head = *H;
	if (*H == NULL)
		*H = Temp;
	else
	{
		Temp->next = *H;
		*H = Temp;
	}
}
int HashSearch(str *H, char *key)
{
	//   printf("%d\n",key[0]);
	//   printf("%d\n",H->x[0]);
	while (H != NULL)
	{
		if (strcmp(H->x, key) == 0)
			return 0;
		else {
			H = H->next;
		}
	}
	return 1;
}
int HashSearch2(char *H, char *key)
{
	if (!strcmp(H, key))
		return 0;
	else return 1;
}
int Hash1(char**arr, int n)
{
	char *key = new char[8];
	str *HashTable[n];
	for (int i = 0; i<n; i++) {
		HashTable[i] = new str;
		HashTable[i] = NULL;
	}
	for (int i = 0; i<n; i++)
		HashInsert(&HashTable[HashAdress(arr[i], n)], arr[i]);
	for (int i = 0; i<n; i++)
	{
		printf("Hash=%d: ", i);
		Print(HashTable[i]);

	}
	printf("Enter key: ");
	scanf("%s", key);
	if (!HashSearch(HashTable[HashAdress(key, n)], key))
	{
		printf("Done! H=");
		printf("%d\n", HashAdress(key, n));
	}
	else printf("Not found");
}
int Hash2(char(*arr)[8], int n, bool T)
{
	char HashTable1[n][8], HashTable2[n][8], *key;
	for (int i = 0; i<n; i++)
		HashTable1[i][0] = HashTable2[i][0] = '\0';
	for (int i = 0; i<n; i++)
	{
		int j = 0;
		unsigned int h = 0;
		while (1)
		{
			HashAdress2(arr[i], h, n, j);
			if (HashTable1[h][0] == '\0')
			{
				for (int y = 0; y<8; y++)
					HashTable1[h][y] = arr[i][y];
				break;
			}
			j++;
			h = 0;
			K1++;
		}
	}
	for (int i = 0; i<n; i++)
	{
		unsigned int h = 0;
		int j = 0;
		for (int j = 0; j<n; j++)
		{
			HashAdress3(arr[i], h, n, j);
			if (HashTable2[h][0] == '\0')
			{
				for (int y = 0; y<8; y++)
					HashTable2[h][y] = arr[i][y];
				break;
			}
			h = 0;
			K2++;
		}
	}
	if (!T) {
		Print2(HashTable1, HashTable2, n);
		printf("Enter key: ");
		scanf("%s", key);
		unsigned int h = 0;
		int i = 0;
		while (1)
		{
			HashAdress2(key, h, n, i);
			if (!HashSearch2(HashTable1[h], key))
			{
				printf("Done! H=%d", h);
				break;
			}
			i++;
			h = 0;
			if (i>n) { printf("Not found\n"); break; }
		}
		h = 0;
		for (i = 0; i < n; i++)
		{
			HashAdress3(key, h, n, i);
			if (!HashSearch2(HashTable2[h], key))
			{
				printf("\nDone! H=%d", h);
				break;
			}
			h = 0;
			if (i == n - 1) printf("Not found\n");
		}
	}
	return 0;
}
