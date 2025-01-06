#include <stdio.h>
#define MAX 100
#define EMPTY -1

char input[MAX + 1];
char output[MAX + 1];
char stack[MAX + 1];

int main(void)
{
	scanf("%s", input);

	int stack_pos = -1;
	int out_pos = 0;

	for (int in_pos = 0; input[in_pos] != '\0'; ++in_pos)
	{
		if (input[in_pos] >= 'A' && input[in_pos] <= 'Z')
		{
			output[out_pos] = input[in_pos];
			++out_pos;
		}
		else
		{
			if (stack_pos == EMPTY)
			{
				stack[0] = input[in_pos];
				++stack_pos;
				continue;
			}

			switch (input[in_pos])
			{
				case '+':
				case '-':

					while (stack_pos != EMPTY)              
					{                     
						if (stack[stack_pos] == '(')     
							break;

						output[out_pos++] = stack[stack_pos]; 
						--stack_pos;
					}

					++stack_pos;
					stack[stack_pos] = input[in_pos];

					break;

				case '*':
				case '/':


					while (stack_pos != EMPTY)
					{
						if (stack[stack_pos] != '*' && stack[stack_pos] != '/')
							break;

						output[out_pos++] = stack[stack_pos];
						--stack_pos;
					}

					++stack_pos;                 
					stack[stack_pos] = input[in_pos];

					break;

				case '(':
					++stack_pos;
					stack[stack_pos] = '(';
					break;

				case')':

					while (stack[stack_pos] != '(')
					{
						output[out_pos++] = stack[stack_pos];
						stack[stack_pos] = '\0';
						--stack_pos;
					}

					stack[stack_pos] = '\0';
					--stack_pos;
					break;
			}
		}

	}

	while (stack_pos >= 0)
	{
		output[out_pos++] = stack[stack_pos];
		--stack_pos;
	}

	output[out_pos] = '\0';

	printf("%s\n", output);

	return 0;
}
