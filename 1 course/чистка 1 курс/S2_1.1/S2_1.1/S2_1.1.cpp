// S2_1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<conio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<clocale>
using namespace std;

int fact(int x) {
	int res = x;  for(int i = x; i > 1; i--) { res *= (i - 1);} return res;
}

int main() {
	
	setlocale(LC_ALL, "RUS");
	cout << fact(3);
	_getch();
}






















//int max(int, int); //Прототип функции (можно указывать только тип  
//				   //формальных параметров)
//int main()
//{
//	int x, y, z;
//	printf(" input x,y ");
//	scanf_s("%d%d", &x, &y);
//	z = max(x, y);  //Вызов функции с фактическими параметрами
//	printf("x=%d y=%d max=%d", x, y, z);
//	_getch();
//}
//int max(int a, int b) //Заголовок функции с формальными параметрами
//{
//	int c;
//	if (a>b) c = a;
//	else c = b;
//	return c;
//}