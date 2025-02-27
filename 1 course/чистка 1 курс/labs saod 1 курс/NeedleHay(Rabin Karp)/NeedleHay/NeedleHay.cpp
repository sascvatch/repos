#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int straightSearch(char hs[], int n, char nl[], int m, int a[], int &nc) {
	int i = -1;
	int j = 0, k = -1;

	do {
		i++;
		j = 0;
		while ((j < m) && (hs[i + j] == nl[j])) {//the last comparison will be h[2]==n[2]
			nc++;
			j++;
		}
		if (j == m) {
			a[++k] = i;
		}

	} while ((i < (n - m)));

	return k;
}

// d is the number of characters in input alphabet
#define d 256


//q -> A prime number// the more it is the k less collisions there will be

int rksearch(char nl[], int dnl, char hs[], int dhs, int q, int b[], int &nc)
{

	int i, j, k = -1;
	int pattern = 0; // hash value for nl
	int text = 0; // hash value for hs
	int h = 1;
	

	// The value of h would be "pow(d, dnl-1)%q"
	for (i = 0; i < dnl - 1; i++)
		h = (h*d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < dnl; i++)
	{
		pattern = (d*pattern + nl[i]) % q;
		text = (d*text + hs[i]) % q;
	}

	// Slide the nl over text one by one
	for (i = 0; i <= dhs - dnl; i++)
	{

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters on by one
		if (pattern == text)
		{
			/* Check for characters one by one */
			for (j = 0; j < dnl; j++)
			{
				nc++;
				if (hs[i + j] != nl[j])
					break;
			}

			// if p == t and pat[0...dnl-1] = txt[i, i+1, ...i+dnl-1]
			if (j == dnl)
				b[++k] = i;
			//printf("Pattern found at index %d \n", i);
		}

		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if (i < dhs - dnl)

			//for (i = 0; i < dnl - 1; i++)	h = (h*d) % q;
		{
			text = (d*(text - hs[i] * h) + hs[i + dnl]) % q;


			//pattern = (d*pattern + nl[i]) % q;
			// We might get negative value of t, converting it
			// to positive
			if (text < 0)
				text = (text + q);
		}
	}return k;
}

int main()
{
	const int n = 200, m = 20;
	int a[100];
	int b[100];
	int nc = 0;//a number of comparisons
	printf("0123456789\n");
	char hs[n] = "mama mim milamama ramu mil";
	char nl[m] = "ma";
	int dnl = strlen(nl);
	int dhs = strlen(hs);
	int f = straightSearch(hs, dhs - 1, nl, dnl, a, nc);//why I can only add 19 chars? The last symbol is '\0'?
	printf(hs);
	printf("\n");
	printf(nl);

	if (f > -1) {
		printf("\nstraightSearch() found indexes:\n");
		for (int i = 0; i <= f; i++)
		{
			printf("%d\n", a[i]);
		}
		printf("A number of comparisons: %d\n", nc);
	}
	else printf("\nstraightSearch() can't find the needle");

	nc = 0;
	int q = 101; // A prime number
	f = rksearch(nl, dnl, hs, dhs, q, b, nc);

	if (f > -1) {
		printf("\nrksearch() found indexes:\n");
		for (int i = 0; i <= f; i++)
		{
			printf("%d\n", b[i]);
		}
		printf("A number of comparisons: %d\n", nc);
	}
	else printf("\nrksearch() can't find the needle");





	_getch();

	return 0;

}

