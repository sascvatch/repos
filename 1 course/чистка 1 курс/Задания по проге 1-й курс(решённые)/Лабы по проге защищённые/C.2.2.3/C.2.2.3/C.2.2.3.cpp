#include "stdafx.h"
#include <string>
#include <iostream>//  for cout
using namespace std;// for cout

int f(int a) {
	if (a == 0)return NULL;
	int t = a % 2;
	a /= 2;
	f(a);
	printf("%d", t);
}
int main()
{
	int n = 0;
	while (true) {
		cout << "\ninsert a number\n";
		cin >> n;
		f(n);
	}
	std::getchar();
	std::getchar();
	std::getchar();
    return 0;
}

