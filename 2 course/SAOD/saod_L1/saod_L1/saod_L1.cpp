// saod_L1.cpp : Defines the entry point for the console application.
//
/*Лабораторная работа №1

1). Разработать процедуру построения идеально сбалансированного дерева поиска (ИСДП).
2). Построить ИСДП из 100 вершин, распечатать обход дерева слева направо.
3). Для построенного дерева вычислить размер, контрольную сумму, высоту и среднюю высоту.

4). Дополнительное задание (на 5+):
Реализовать графическую процедуру изображения дерева на экране.

В соответствии с презентацией для построения исдп массив нужно сначала отсортировать.
Потом взять средний элемент и уже плясать от него.
*/

#include "stdafx.h"

void quickSort(int arr[], int left, int right);
int random(int N);
struct Vertex
{
	int data;
	Vertex* left;
	Vertex* right;
};

Vertex* ISDP(int L, int R, int *a, int m) {//perfectly balanced search tree
	
	if (L > R)return NULL;
	else m = ceil((L + R) / (double)2);
	Vertex *p = new Vertex;
    //printf("a vot i chislo m = %d\n", m);
	p->data = a[m];
	p->left = ISDP(L, m - 1, a, m);
	p->right = ISDP(m + 1, R, a, m);
	//printf("p->data = %d\n", p->data);
	return p;

}

void Obhod1(Vertex *p) {//from top to bottom
	if (p != NULL) {
		printf("p->data = %d\n", p->data);
		Obhod1(p->left);
		Obhod1(p->right);
		/*to change the go through one need to shift these 3 operators
		root left right = down
		left root right = to the left
		left right root = up*/
	}
}
void Obhod2(Vertex *p) {//to the left
	if (p != NULL) {
		Obhod2(p->left);
		printf("p-data = %d; ", p->data);
		Obhod2(p->right);
	}
}
int sizeoftree(Vertex* p, int &count)
{
	if (p == NULL) count = 0;
	else count = 1 + sizeoftree(p->left, count) + sizeoftree(p->right, count);
	return count;
}


int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

int htree(Vertex* p, int &count)
{
	if (p == NULL) count = 0;
	else count = 1 + max(htree(p->left, count), htree(p->right, count));
	return count;
}

int medsizetree(Vertex* p, int L, int &count)
{
	if (p == NULL) count = 0;
	else count = L + medsizetree(p->left, L + 1, count) +
		medsizetree(p->right, L + 1, count);
	return count;
}

int sum(Vertex *p, int &count)
{
	if (p == NULL) count = 0;
	else count = p->data + sum(p->left, count) + sum(p->right, count);
	return count;
}

int main()
{
	srand(NULL);
	int a[100];
	int aa = 0, bb = 1000, cnt = 0;
	//= { 100, 3, 23, 15,39, 70, 17 };
	for (int i = 0; i < 100; i++)
	{
		a[i] = random(bb - aa + 1) + aa;
	}
	quickSort(a, 0, 99);
	for (int i = 0; i <100; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	int m = 0;
	Vertex *root = ISDP(0, 99, a, m);
	/*int m = ceil((5 + 8) / (double)3);
	printf("%d", m);
	getchar();*/
	
	Obhod2(root);

	printf("\nsize of the tree is %d\n", sizeoftree(root, cnt));
	printf("height of the tree is %d\n", htree(root, cnt));
	printf("the average height of the tree is %f\n", 
		(float)medsizetree(root, 1, cnt) / (float)sizeoftree(root, cnt));
	printf("the control sum is %d", sum(root, cnt));
	getchar();
	return 0;
}

int random(int N) { return rand() % N; }


void quickSort(int arr[], int left, int right) {

	int i = left, j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];

	/* partition */

	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};



	/* recursion */

	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

}