/*2. Написать функцию, определяющую вероятность того, что среди n детей будет m
девочек или m мальчиков. Предусмотреть контроль входных данных.
Вероятность рождения девочки p=0.45, мальчика q=1-p. Вероятность того, что из n детей будет m девочек  равна:
pd=cnm .pm.qn-m ,
для мальчиков
pm=cnm .qm.pn-m
 cnm=n!/(m! *(n-m)!)   Вероятности передать через параметры-ссылки.
*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;
int fact(int a) { if (a > 1)return fact(a - 1)*a; else return 1; }
void f(int n, int m, double &pd, double &pm) {

	double p = 0.45, q = 1 - p;
	double cnm = fact(n) / (fact(m)*fact(n - m));
	pd = cnm * pow(p, m)*pow(q, n - m);
	pm = cnm * pow(q, m)*pow(p, n - m);
}
int main()
{
	int n, m;
	double pd, pm;
	cout << "Vvedite n, m" << endl;
	cin >> n >> m;
	f(n, m, pd, pm);// здесь функция принимает pd, pm как обычные переменные, 
	//но параметры с амперсандами забирают от неё не значаение, а адрес
	//В итоге в функции можно работать с простым именем переменной,
	//и при этом передаваемые ей значения будут назначаться сразу для глобальной перемнной, без использования *
	cout << "pd = " << pd << endl << "pm = " << pm;

	_getch();
	return 0;
}

