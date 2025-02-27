// saod_L4.cpp : Defines the entry point for the console application.
//
/*Лабораторная работа №4

1). Разработать процедуру построения АВЛ-дерева.
2). Построить АВЛ-дерево из 100 вершин, распечатать обход дерева слева направо.
3). Для построенного АВЛ-дерева вычислить размер, контрольную сумму, высоту и
среднюю высоту, сравнить их с аналогичными характеристиками случайного дерева поиска, построить таблицу вида:

n=100    Размер  Контр. сумма   Высота Средн.высота
СДП
АВЛ
4). Дополнительное задание (на 5+):
Реализовать графическую процедуру изображения дерева на экране.
*/
#include "stdafx.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>

using namespace std;
typedef struct tabTree Tree;//Tree теперь просто новое имя структуры tabTree

void AddTree(Tree **root, int D);
Tree *BalansTree(int L, int R, int *mass);
int TreeFind(Tree *p);
int HeightTree(Tree *p);
int Find(Tree *root, int X);
int op;
struct tabTree {
	int Key;
	int data;
	struct tabTree *pleft;
	struct tabTree *pright;
	int Bal;
};

void quicksort(int mass[], int pleft, int pright) {
	int x = mass[(pleft + pright) / 2];
	int i = pleft;
	int j = pright;
	while (i <= j) {
		while (mass[i] < x)i++;
		while (mass[j] > x)j--;
		if (i <= j) {
			swap(mass[i], mass[j]);
			++i; j--;
		}
	}
	if (j > pleft) quicksort(mass, pleft, j);
	if (i < pright) quicksort(mass, i, pright);
}


/* СДПk */
void AddTree(Tree **root, int D) {
	Tree **p = root;

	while ((*p) != NULL) {
		if (D < (**p).data)
			p = &((**p).pleft);
		else
			p = &((**p).pright);
	}
	if ((*p) == NULL) {
		(*p) = (Tree*)malloc(sizeof(Tree));
		(**p).data = D;
		(**p).pleft = (**p).pright = NULL;
	}
}
/* rectree */
void addrec(tabTree *&p, int D) {
	if ((p) == NULL) {
		(p) = (Tree*)malloc(sizeof(Tree));
		(*p).data = D;
		(*p).pleft = (*p).pright = NULL;
	}
	else
		if (D < (*p).data)
			addrec(p->pleft, D);
		else if (D > (*p).data)
			addrec(p->pright, D);
}

/*АВЛ дерево*/

		void LLrotate(tabTree *&p) {
	tabTree *q = (*p).pleft;
	(*q).Bal = 0;
	(*p).Bal = 0;
	(*p).pleft = q->pright;
	(*q).pright = p;
	p = q;

}

void RRrotate(tabTree *&p) {
	tabTree *q = (*p).pright;
	(*q).Bal = 0;	
	(*p).Bal = 0;
	(*p).pright = q->pleft;
	(*q).pleft = p;
	p = q;
}





void LRrotate(tabTree *&p) {
	tabTree *q = (*p).pleft;
	tabTree *r = (*q).pright;
	if (r->Bal < 0)
		(*p).Bal = 1;
	else
		(*p).Bal = 0;
	if (r->Bal > 0)
		(*q).Bal = -1;
	else (*q).Bal = 0;
	r->Bal = 0;
	q->pright = r->pleft;
	(*p).pleft = r->pright;
	r->pleft = q;
	r->pright = p;
	p = r;
}

void RLrotate(tabTree *&p) {
	tabTree *q = (*p).pright;
	tabTree *r = (*q).pleft;
	if (r->Bal < 0)
		(*p).Bal = 1;
	else (*p).Bal = 0;
	if (r->Bal > 0)
		(*q).Bal = -1;
	else (*q).Bal = 0;
	r->Bal = 0;
	q->pleft = r->pright;
	(*p).pright = r->pleft;
	r->pleft = p;
	r->pright = q;
	p = r;
}






















int grow;
int addtree(int D, tabTree *&p) {

	if (!p) {
		p = new tabTree;
		(*p).data = D; (*p).pleft = NULL;
		(*p).pright = NULL; (*p).Bal = 0; grow = 1;
	}
	else if ((*p).data > D) {//compare root's data and inserted data
		addtree(D, p->pleft);
		if (grow == 1) {
			if (p->Bal > 0)
			{
				p->Bal = 0; grow = 0;
			}
			else if ((*p).Bal == 0)
			{
				(*p).Bal = -1; grow = 1;
			}
			else {
				if ((*p).pleft->Bal < 0)
				{
					LLrotate(p); grow = 0;
				}
				else { LRrotate(p); grow = 0; }
			}
		}
	}

	else if ((*p).data < D) {
		addtree(D, p->pright);
		if (grow == 1) {
			if (p->Bal < 0)
			{
				p->Bal = 0; grow = 0;
			}
			else if ((*p).Bal == 0)
			{
				(*p).Bal = 1; grow = 1;
			}
			else {
				if ((*p).pright->Bal > 0) { RRrotate(p); grow = 0; }
				else { RLrotate(p); grow = 0; }
			}
		}
	}
	return 0;
}









/* высота дерева */
int HeightTree(Tree *p) {
	int pl = 0;
	int pr = 0;
	if (p == NULL) return 0;
	else {
		pl = HeightTree(p->pleft);
		pr = HeightTree(p->pright);
		return 1 + ((pl > pr) ? pl : pr);
	}
}

int treesize(Tree *root) {//size
	if (!root)
		return 0;
	return 1 + treesize(root->pleft) + treesize(root->pright);
}

int treesrsize(Tree *root, int level = 1) {
	if (!root)
		return 0;
	return level + treesrsize(root->pleft, level + 1) + treesrsize(root->pright, level + 1);
}

float treessize(Tree *root) {//average height
	return(float)treesrsize(root) / treesize(root);
}

int checksum(Tree *root) {
	if (!root) return 0;
	return root->data + checksum(root->pleft) + checksum(root->pright);
}

/*вывод дерева*/
int printtree(Tree *root) {
	if (!root)
		return 0;
	printtree(root->pleft);
	printf("%3d", root->data);
	printtree(root->pright);
}

int main() {
	//Tree *root = NULL;
	Tree *sroot = NULL;//авл
	Tree *troot = NULL;//сдп
	int n, i, X, q1, q2;
	int *mass;
	float h1, h2;
	setlocale(0, "RUS");
#define n 100

	printf("\n Массив случайных чисел:\n");
	srand((unsigned)time(NULL));
	mass = (int*)malloc(sizeof(int) * n);
	int cnt = 0;
	for (i = 0; i < n; i++) {
		mass[i] = rand() % 99 + 1;
		printf("%d ", mass[i]);
		AddTree(&troot, mass[i]);
		grow = 0;
		addtree(mass[i], sroot);
	}

	printf("\n ________________________________________________________\n");
	printf("| n=100 | Размер | Контр. сумм | Высота | Средняя высота |\n");
	printf("|--------------------------------------------------------|\n");
	printf("| СДП  | %3d    |       %5d|    %3d |        %0.2f     |\n", treesize(troot), checksum(troot), HeightTree(troot), treessize(troot));
	printf("|--------------------------------------------------------|\n");
	printf("| АВЛ  | %3d    |       %5d|    %3d |        %0.2f     |\n", treesize(sroot), checksum(sroot), HeightTree(sroot), treessize(sroot));


	getchar();
}

