// Hash1.cpp : Defines the entry point for the console application.
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

void add(node *&pt, int x) {
  auto *t = new node;
  t->data = x;
  t->next = nullptr;
  pt = pt->next = t;
}

void print(node *ph) {
  while (ph) {
    printf(" %d", ph->data);
    ph = ph->next;
  }
  printf("\n");
}

void Build(int *a, int n, queue *q, int m) {
  for (int i = 0; i < n; ++i)
    add(q[a[i] % m].tail, a[i]);
}

void Print(queue *q, int m) {
  for (int i = 0; i < m; ++i) {
    printf("%2d:  ", i);
    if (q[i].tail != (node *)&(q[i].head))
      print(q[i].head);
    else
      printf("-\n");
  }
}

void Search(int k, queue *q, int m) {
  int i = k % m, c = 0;
  bool f = false;
  if (&q[i].tail != &q[i].head) {
    while (q[i].head) {
      if (q[i].head->data == k) {
        f = true;
        break;
      }
      q[i].head = q[i].head->next;
      c++;
    }
  }
  if (f)
    printf("Element found in %d list at number: %d\n", i, c + 1);
  else
    printf("Element not found\n");
}

int main() {
  const int n = 30;
  int a[n];
  printf("Random array: ");
  for (int &i : a) {
    i = rand() % 50;
    printf("%d ", i);
  }
  printf("\n");

  const int m = 11;
  queue q[m];

  for (auto &i : q)
    i.tail = (node *)&(i.head);

  Build(a, n, q, m);
  printf("\nTable: \n");
  Print(q, m);
  printf("\nInput key: \n");
  fflush(stdout);
  int k;
  scanf_s("%d", &k);
  Search(k, q, m);
  system("Pause");
}
