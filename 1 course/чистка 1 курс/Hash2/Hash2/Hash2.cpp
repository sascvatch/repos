// Hash2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>

struct node {
	node *next;
	int data;
};

struct queue {
	node *head;
	node *tail;
} Q;

int C;


void Insert1(int k, int *t, int m) {
	int j = k % m;
	while (j < m) {
		if (t[j] == 0) {
			t[j] = k;
			return;
		}
		j = (j + 1) % m;
		C++;
	}
}

int Search1(int k, const int *t, int m) {
	int j = k % m;
	while (t[j] != 0 && j < m) {
		if (t[j] == k)
			return j;
		j++;
	}
	return -1;
}

void Insert2(int k, int *t, int m) {
	int j = k % m;
	int inc = 1;
	while (inc < m) {
		if (t[j] == 0) {
			t[j] = k;
			return;
		}
		j = (j + inc) % m;
		inc += 2;
		C++;
	}
}

int Search2(int k, const int *t, int m) {
	int j = k % m;
	int inc = 1;
	while (t[j] != 0 && inc < m) {
		if (t[j] == k)
			return j;
		j = (j + inc) % m;
		inc += 2;
	}
	return -1;
}

int main() {
	const int n = 11;
	int a[n];

	printf("Array:\n");
	for (int &i : a) {
		i = rand() % 50 + 1;
		printf("%2d ", i);
	}
	printf("\n");

	const int m = 11;
	int t1[m], t2[m];
	for (int i = 0; i < m; i++) {
		t1[i] = 0;
		t2[i] = 0;
	}

	printf("\n\nSize of    N of       N of collisions\n");
	printf("table      elements   Linear     Quadratic\n");
	printf("%d         %d         ", m, n);

	C = 0;
	for (int i : a)
		Insert1(i, t1, m);
	printf("%d          ", C);

	C = 0;
	for (int i : a)
		Insert2(i, t2, m);
	printf("%d\n\n", C);

	printf("\nLinear samples: \n");
	for (int i = 0; i < m; i++)
		printf("%4d", i);
	printf("\n");
	for (int i : t1)
		printf("%4d", i);
	printf("\n");

	printf("\nQuadratic samples: \n");
	for (int i = 0; i < m; ++i)
		printf("%4d", i);
	printf("\n");
	for (int i : t2)
		printf("%4d", i);
	printf("\n");

	int k;
	printf("\nInput first table key: \n");
	fflush(stdout);
	scanf_s("%d", &k);
	if (Search1(k, t1, m) == -1)
		printf("Num not found");

	else printf("%d Position", Search1(k, t1, m));
	printf("\n");

	printf("\nInput second table key: \n");
	fflush(stdout);
	scanf_s("%d", &k);
	if (Search2(k, t1, m) == -1)
		printf("Num not found\n");

	else printf("%d Position:", Search2(k, t2, m));
	printf("\n");
	system("Pause");
}
