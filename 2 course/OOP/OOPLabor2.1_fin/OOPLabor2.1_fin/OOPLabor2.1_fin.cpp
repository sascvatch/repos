// OOPLabor2.1_fin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#include <conio.h>
#include <time.h>
#include<cstdlib>// for rand
#include<stdlib.h>// for srand


#define N 10
/*



Объектно-ориентированное программирование

Занятие 2 Использование динамических структур
данных (список, стек, очередь)

Задание 1 Написать процедуры и функции для работы со списком
	A. добавление элемента после к-ого элемента списка
	B. удаление из списка к-ого элемента
	C. подсчет числа элементов в списке
	D. перемещение р-ого элемента списка после к-ого элемента
С помощью этих процедур и функций создать список следующим образом.
Включать в список полные квадраты из одномерного массива целых чисел (типа Byte).
Удалить повторяющиеся элементы списка. Определить длину полученного списка.
*/
typedef unsigned char byte;

struct item {
	item *next;
	byte data;
};

item* createList(byte firstValue) {
	item *result = new item;
	result->data = firstValue;
	result->next = NULL;
	return result;
}

item* insertAfterIndex(item *head, int k, byte value) {
	item *p = head;//для пробегания
	while (p) {
		if (k <= 0) {//if p = p->next played a needed number of times(k times)
			item *it = new item;
			it->data = value;
			it->next = p->next;//it's next points to what p pointed before(and continues to point before the lower line)
			p->next = it;//it appeared  after p(went right)
			return it;
		}
		k--;
		p = p->next;
	}
	return NULL;
}

void removeAtIndex(item *&head, int k, byte &removedValue) {//*& - это ссылка на указатель. Просто чтобы в дальнейшем коде не писать звёздочки перед ссылками
	if (!head) {//removedValue just shows what was removed
		return;
	}
	if (k <= 0) {//if index equals 0, then just delete the memory, that head is pointed to
		item *t = head->next;
		removedValue = head->data;
		delete head;
		head = t;//and assign head to the 1 index element
		return;
	}
	item *p = head;
	while (p) {
		if (k <= 1) {
			item *t = p->next;
			p->next = t->next;
			removedValue = t->data;
			delete t;
			return;
		}
		k--;
		p = p->next;
	}
}

int countList(item *head) {
	item *p = head;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

void moveFromToIndex(item *&head, int p, int k) {
	byte value;
	removeAtIndex(head, p, value);
	if (k >= p) {
		k--;
	}
	insertAfterIndex(head, k, value);
}

void removeSameValues(item *&head) {
	int i = 0;
	for (item *p = head; p; p = p->next, i++) {
		int j = i + 1;
		item *s = p->next;
		while (s) {
			if (p->data == s->data) {
				s = s->next;
				byte t;
				removeAtIndex(head, j, t);
			}
			else {
				s = s->next;
				j++;
			}
		}
	}
}

void printList(item *head) {
	int i = 0;
	for (item *p = head; p; p = p->next) {
		printf("%2d) %d\n", i++, p->data);
	}
}

int random(int g) { return rand() % g; }

int main() {
	srand(NULL);
	srand(time(NULL));//in main
	int aa = 0, bb = 8, *arr, i = 0;
	//arr[i++] = random(bb - aa + 1) + aa;


	byte numsArray[N];

	printf("Array:\n");
	for (int i = 0; i < N; i++) {
		numsArray[i] = random(bb - aa + 1) + aa;;
		printf("%2d", numsArray[i]);
	}

	printf("\n\nCalculated list:\n");
	item *head = NULL;
	int index = 0;

	for (int i = 0; i < N; i++)
	{
		int value = numsArray[i] * numsArray[i];
		if (insertAfterIndex(head, index, value)) {
			index++;
		}
		else {
			head = createList(value);
		}

	}
	printList(head);
	system("pause");

	printf("\n\nRemoved same values:\n");
	removeSameValues(head);
	printList(head);
	printf("\nSize of list = %d\n\n", countList(head));
	system("pause");
}
