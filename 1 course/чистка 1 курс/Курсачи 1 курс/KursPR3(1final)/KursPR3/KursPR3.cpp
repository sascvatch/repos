#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct list {
	list *next, *prev;
	char str[20];
} List;

int main()
{
	setlocale(LC_ALL, "RUS");
	FILE *file;
	char str[100];
	if (file = fopen("words.txt", "rt"));
	else perror("Error");

	printf("Программа прочитает файл words.txt,\n");
	printf("Найдет в нем слова палиндромы и удалит их.\n\n");
	printf("\t\tТекст\n\n");

	List *head, *tail, *point;
	head = new List;
	head->next = nullptr;
	head->prev = nullptr;
	strcpy(head->str, "");
	tail = head;
	point = new List;
	point->next = nullptr;
	point->prev = tail;
	tail->next = point;
	tail = point;
	int i, j = 0;
	while (fgets(str, 100, file)) {
		printf("%s", str);
	
		for (i = 0; i < strlen(str); i++) {
			if ((str[i] == ' ' || str[i] == '\n') && (str[i - 1] != ' ')) {
				if (!feof(file)) {
					point->str[j] = '\0'; 
					point = new List;
					point->next = nullptr;
					point->prev = tail;
					tail->next = point;
					tail = point;
					j = 0;
				}
			}
			else {

				point->str[j++] = str[i];
			}
		}
	}
	fclose(file);

	printf("before:\n");
	point = head;
	while (point->next) {
		printf("%s ", point->str);
		point = point->next;
	}

	int flag;
	point = head->next;
	while (point->next) {
		flag = 1;
		for (i = 0; i < strlen(point->str) / 2; i++) {
			if (point->str[i] == point->str[strlen(point->str) - 1 - i]);
			else flag = 0;
		}
		if (flag) {
			tail = point;
			point->prev->next = point->next;
			point->next->prev = point->prev;
			point = point->next;
			delete tail;
		}
		else point = point->next;
	}

	printf("\n\nAfter:\n");
	point = head;
	while (point->next) {
		printf("%s ", point->str);
		point = point->next;
	}
	point = tail = head;
	while (point) {
		point = tail->next;
		delete tail;
		tail = point;
	}
	head = nullptr;

	getchar();
	return 0;
}