//2. Задан двумерный динамический массив А  размерности   m x n. 
//(m и n вводить с клавиатуры).
//Заполнить его случайными числами.Создать массив D  размером m + 1 на  n + 1, 
//в который записать элементы массива А и суммы элементов соответствующих строк 
//и столбцов исходного массива А.
//В элемент D[m + 1][n + 1] поместить сумму всех элементов исходного массива.

//чтобы дебаггер не вызывал отказ всего проекта надо после эксепшена жать continue, а 
//не красный квадратик

#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<time.h>
#include<clocale>
using namespace std;
int random(int N) { return rand() % N; }
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int m, n, x = -9, y = 9, **a, **d, sumV = 0;
	cout << "Введите m и n через пробел\n";
	cin >> m >> n;
	cout << "m = " << m << " n = " << n << endl;
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];//каноническая? инициализация массива(выделение памяти под него)
		for (int q = 0; q < n; q++)
		{
			a[i][q] = random(y - x + 1) + x;
			cout.width(5);
			cout << a[i][q];
		}cout << endl;
	}
	cout << "---------------" << endl;
	d = new int*[m + 1];
	for (int i = 0; i < m; i++)
	{
		d[i] = new int[n + 1];
		d[i][n] = 0;

		for (int q = 0; q < n; q++)
		{
			d[i][q] = a[i][q];
			d[i][n] += a[i][q];
		}sumV += d[i][n];
	}
	d[m] = new int[n + 1];
	for (int s = 0; s < n + 1; s++)
	{
		d[m][s] = 0;
	}
	for (int i = 0; i < m; i++)// А ведь можно внешним циклом идти по столбцам, а внутренним по строкам?.. тогда получится то же самое посчитать?
	{
		for (int q = 0; q < n; q++)
		{
			d[m][q] += d[i][q];
		}
	}
	d[m][n] = sumV;
	for (int i = 0; i < m + 1; i++)
	{
		for (int q = 0; q < n + 1; q++)
		{
			cout.width(5);
			cout << d[i][q];
		}cout << endl;
	}
	_getch();
	return 0;
}

