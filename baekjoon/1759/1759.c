#include <stdio.h>
#include <stdlib.h>

char able[16];
int L,C;
char pass[15];

int compare(const void*, const void*);

int	make_pass(int, int, int);

int is_Vowels(char);

int main(void)
{
	scanf("%d %d", &L, &C);

	while(getchar() != '\n');
	for(int i = 0; i < C; ++i)
	{
		scanf("%c", pass + i);
		getchar();
	}
	
	able[L] = '\0';
	qsort(pass, C, sizeof(char), compare);

	make_pass(0, 0, 0);

	return 0;
}

int compare(const void* a, const void* b)
{
	char x = *(char*)a;
	char y = *(char*)b;

	if(x > y)
		return 1;
	else if(x == y)
		return 0;
	else
		return -1;
}

int make_pass(int pos, int count, int have_Vowles)
{
	if(pos >= C)
		return 0;

	able[count] = pass[pos];
	
	if(count + 1 == L)
	{
		int count_V = have_Vowles + is_Vowels(pass[pos]);

		if(count_V != 0 && L-count_V >= 2)
			printf("%s\n", able);
	}
	else
		make_pass(pos+1, count+1, have_Vowles + is_Vowels(pass[pos]));

	make_pass(pos+1, count, have_Vowles);

	return 0;
}

int is_Vowels(char a)
{
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	else
		return 0;
}
