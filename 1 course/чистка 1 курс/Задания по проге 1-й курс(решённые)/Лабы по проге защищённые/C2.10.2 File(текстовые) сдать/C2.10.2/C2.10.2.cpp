#include "stdafx.h"
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>//  for cout(for C++ only)
using namespace std;// for cout(for C++ only)
/*В новый файл переписать каждую  строку наоборот*/

void clear_file(const std::string& file_name)
{
	std::fstream(file_name, std::fstream::out);
}

int main()
{
	int n;
	char ch;
	char text[200];
	//char text2[200] = "human";

	FILE *txtF, *nbr;                      // Указатели на файлы

	txtF = fopen("текст.txt", "w");  // Создание нового файла текст.txt
	nbr = fopen("наоборот.txt", "r+");

	clear_file("наоборот.txt");//чищу файл перед работой
	fclose(nbr);
	nbr = fopen("наоборот.txt", "w");

	system("CLS");

	//fprintf(txtF, "%s\n", text);
	//fprintf(txtF, "%s\n", text2);
	//fclose(txtF);
	printf("Vvedite chislo strok ");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		printf("\nVvedite tekst novoi stroki na latinice \n");
		cin >> text;
		fprintf(txtF, "%s\n", text);
	}
	fclose(txtF);
	txtF = fopen("текст.txt", "r");
	

	while (!feof(txtF))                  // Пока не конец файла
	{
		char ch = 'G';
		for (; n > 0; n--)
		{
			ch = getc(txtF);//символ переноса строки заменяю следующим чаром
			int i, cnt;
			char a[300];

			for (i = 0; ch != '\n'; i++)
			{
				
				a[i] = ch;
				ch = getc(txtF);
			}
			
			for (i = i - 1; i >= 0; i--)
			{
				putc(a[i], nbr);
			}putc('\n', nbr);
		}
		ch = getc(txtF);

	}
	fclose(nbr);                           // Закрытие файла pr
	fclose(txtF);
	return 0;
}