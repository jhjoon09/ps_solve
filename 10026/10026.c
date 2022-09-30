#include <stdio.h>
#define MAX 100

int normal[MAX][MAX];
int color[MAX][MAX];
int n;

int search_n(int, int, int);
int search_c(int, int, int);

int main(void)
{
	scanf("%d", &n);
	while(getchar() != '\n');

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char input;

			scanf("%c", &input);
			switch(input)
			{
				case 'R' :
					normal[i][j] = 1;
					color[i][j] = 1;
					break;
				case 'G' :
					normal[i][j] = 2;
					color[i][j] = 1;
					break;
				case 'B' :
					normal[i][j] = 3;
					color[i][j] = 3;
					break;
			}
		}
		while(getchar() != '\n');
	}

/*
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%d", color[i][j]);
		}
		printf("\n");
	}
*/

	int n_count = 0;
	int c_count = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(normal[i][j] != 0)
			{
				search_n(i, j, normal[i][j]);
				++n_count;
			}

			if(color[i][j] != 0)
			{
				search_c(i, j, color[i][j]);
				++c_count;
			}
		}
	}

	printf("%d %d\n", n_count, c_count);

	return 0;
}

int search_n(int i, int j, int comp)
{
	if(i < 0 || i >= n || j < 0 || j >= n)
		return 0;

	if(normal[i][j] != comp)
		return 0;

	normal[i][j] = 0;

	search_n(i-1,j,comp);
	search_n(i+1,j,comp);
	search_n(i,j-1,comp);
	search_n(i,j+1,comp);

	return 1;
}

int search_c(int i, int j, int comp)
{
	if(i < 0 || i > n || j < 0 || j > n)
		return 0;

	if(color[i][j] != comp)
		return 0;

	color[i][j] = 0;

	search_c(i-1,j,comp);
	search_c(i+1,j,comp);
	search_c(i,j-1,comp);
	search_c(i,j+1,comp);

	return 1;
}
