#include "stdafx.h"
using namespace std;
/*    12. Считать из текстового файла слова в двусвязный список
и затем удалить из него симметричные слова – палиндромы
(например - АЛЛА). Вывести элементы списка на экран до и после удаления палиндромов. */

bool check_polindrom(char * word);
bool check_polindrom(string word);

typedef struct Node {
	Node *next, *prev;
	char name[20];
};
typedef Node *PNode;

int main()
{
	PNode Head = NULL, prohod = NULL, NewNode = NULL, tail = NULL, root, temp = NULL;
	setlocale(LC_ALL, "RUS");
	FILE * ws1, *ws2;
	PNode pn;
	char ch;
	//string text;
	//std::string str;
	//string str;
	char * str;
	char cr;
	//char sentence[256];

	/*printf("Enter sentence to append: ");
	fgets(sentence, 256, stdin);
	pFile = fopen("mylog.txt", "a");
	fputs(sentence, pFile);
	fclose(pFile);
	return 0;*/
	//ofstream  ofs;

	ws1 = fopen("words.txt", "r+");
	ws2 = fopen("words2.txt", "w");

	while (!feof(ws1))                  // Пока не конец файла
	{
		//str = new string();
		str = NULL;
		do {
			//ch = getc(ws1);
			str
				while (fread)

					str.append(ch);
		}

		while (ch != ' ' && ch != '\n');

		//cout << str << endl;
		if (!check_polindrom(str)) {
			fputs(str, ws2);
		}

	}

	fclose(ws1);
	fclose(ws2);

	cout << "first";
	_getch();
	return 0;
}

bool check_polindrom(char * wordO)
{
	std::string word(wordO);
	//string word = 
	int len = word.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool check_polindrom(string word)
{
	int len = word.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
/*Функция составляет список, записывая начальный элемент после заранее
проинициализированного Tail. Конечный элемент всегда ссылается(своим next) на
заранее проинициализированный Head;
Tail->prev - всегда NULL. Head->next всегда NULL.*/
PNode CreateNode(PNode &Head, PNode &NewNode, PNode &root, PNode &tail, PNode &temp) {
	NewNode = new Node;
	if (tail->next = NULL)tail->next = NewNode;
	NewNode->prev = temp;//в первую инициализацию темп хранит в себе ссылку на теил
	NewNode->next = Head;
	Head->prev = NewNode;
	temp = NewNode;
	return NewNode;
}
int mainn()
{
	string st;
	std::cin >> st;

	if (check_polindrom(st))cout << "true" << endl;
	else cout << "false" << endl;

	std::cout << "\n";
	system("pause");
	return 0;
}