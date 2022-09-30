#include <stdio.h>

int main(void)
{
	int n;
	int reco;
	int number;

	int stu[101] = {0, };
	int picture[20] = {0, };

	scanf("%d", &n);
	scanf("%d", &reco);

	for(int i = 0; i < reco; ++i)
	{
		scanf("%d", &number);
		++stu[number];

		int flag = 1;

		for(int j = 0; j < n; ++j)
		{
			if(picture[j] == number)
			{	
				flag = 0;
				break;
			}

			if(picture[j] == 0)
			{
				flag = 0;
				picture[j] = number;
				break;
			}

		}

		if(flag)
		{
			int small = 0;

			for(int j = 0; j < n; ++j)
			{
				if(stu[picture[j]] < stu[picture[small]])
					small = j;
			}

			stu[picture[small]] = 0;

			for(int j = small; j < n-1; ++j)
				picture[j] = picture[j+1];

			picture[n-1] = number;
		}

	}

	for(int i = 0; i < n-1; ++i)
	{
		for(int j = 0; j < n-1 - i; ++j)
		{
			if(picture[j] > picture[j+1])
			{
				int temp = picture[j];
				picture[j] = picture[j+1];
				picture[j+1] = temp;
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{	
		if(picture[i] != 0)
			printf("%d ", picture[i]);
	}

	printf("\n");

	return 0;
}
