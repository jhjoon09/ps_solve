#include <stdio.h>                                                                                                      
int func(int a, int b, int c);

int w[51][51][51] = {0,};

int main(void)
{
	int a=0,b=0,c=0;
	
	scanf("%d %d %d", &a, &b, &c);

	while(1)
	{
		if(a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, func(a, b, c));

		scanf("%d %d %d", &a, &b, &c);
	}
	return 0;

}

int func(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;

	if(a > 20 || b > 20 || c > 20)
	{
		if(w[20][20][20] != 0)
			return w[20][20][20];


		w[20][20][20] = func(20, 20, 20);
		return w[20][20][20];
	}

	if(w[a][b][c] != 0)
		return w[a][b][c];

	if(a < b && b < c)
	{
		w[a][b][c] = func(a,b,c-1) + func(a, b-1, c-1) - func(a, b-1, c);
		return w[a][b][c];
	}

	w[a][b][c] = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);

	return w[a][b][c];
}
