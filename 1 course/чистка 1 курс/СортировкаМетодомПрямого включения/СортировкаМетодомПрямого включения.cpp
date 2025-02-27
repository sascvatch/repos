#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <iostream>//  for cout
using namespace std;// for cout
#include<conio.h>// for _getch()
#include<stdlib.h>// for srand
#include<conio.h>//for _getch()
#include<time.h>
// Функция сортировки прямыми включениями
void inclusionSort(int *num, int size)
{
	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while ((index > 0) && (num[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			num[index] = num[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}
int main()
{
	srand(time(0));
	int a[10]; // Объявляем массив из 10 элементов
			   // Вводим значения элементов массива
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
	}
	inclusionSort(a, 10);  // вызываем функцию сортировки
						   // Выводим отсортированные элементы массива
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
	_getch(); getchar();
	return 0;
}

