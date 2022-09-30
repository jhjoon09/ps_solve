#include <stdio.h>
#include <stdlib.h>

/*
   0 is none;
   1 is apple
   2 is wall
   3 is snake
 */
typedef struct _body
{
	int x_pos;
	int y_pos;
	struct _body* next;
	struct _body* pre;
}BODY;

typedef struct _snake
{
	int rotate;
	int count;

	BODY* head;
	BODY* tail;
}SNAKE;

int board[102][102];

SNAKE* init_Snake(void);
int go(SNAKE*);
int grow(SNAKE*);
int die_Snake(SNAKE*);

int main(void)
{
	int N, K, L;
	/*
	   0 is up
	   1 is right
	   2 is down
	   3 is left
	 */
	int rotate = 1;
	//-1 is turn left
	//1 is turn right
	int order[100][2] = { 0, };
	scanf("%d", &N);

	scanf("%d", &K);

	SNAKE* bam = init_Snake();

	for (int i = 0; i <= N + 1; ++i)
	{
		board[i][0] = 2;
		board[i][N + 1] = 2;
		board[0][i] = 2;
		board[N+1][i] = 2;
	}

	for (int i = 0; i < K; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		board[x][y] = 1;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; ++i)
	{
		char temp;
		scanf("%d %c", &order[i][0], &temp);

		if (temp == 'L')
			order[i][1] = -1;
		else
			order[i][1] = 1;
	}

	int time = 1;
	int order_pos = 0;

	while (go(bam) != -1)
	{
		if (order[order_pos][0] == time)
		{
			bam->rotate = (bam->rotate + order[order_pos][1] + 4) % 4;
			++order_pos;
		}
		++time;
	}

	printf("%d\n", time);

	die_Snake(bam);

	return 0;
}

SNAKE* init_Snake(void)
{
	BODY* head = (BODY*)malloc(sizeof(BODY));
	head->x_pos = 1;
	head->y_pos = 1;
	head->pre = NULL;
	head->next = NULL;

	board[1][1] = 3;

	SNAKE* bam = (SNAKE*)malloc(sizeof(SNAKE));
	bam->count = 1;
	bam->head = head;
	bam->tail = head;
	bam->rotate = 1;

	return bam;
}

int go(SNAKE* bam)
{
	int x[] = { -1, 0, 1, 0 };
	int y[] = { 0, 1, 0, -1 };
	int rot = bam->rotate;

	BODY* temp = bam->head;
	BODY* n_head = bam->tail;
	int go_x = temp->x_pos + x[rot];
	int go_y = temp->y_pos + y[rot];


	if (board[go_x][go_y] == 2 || board[go_x][go_y] == 3)
		return -1;



	if (board[go_x][go_y] == 1)
	{
		grow(bam);
		return 1;
	}
	else
	{
		board[n_head->x_pos][n_head->y_pos] = 0;
		n_head->x_pos = go_x;
		n_head->y_pos = go_y;

		board[n_head->x_pos][n_head->y_pos] = 3;

		if (bam->count != 1)
		{
			n_head->next = temp;
			temp->pre = n_head;
			bam->tail = n_head->pre;
			(bam->tail)->next = NULL;
			bam->head = n_head;
			n_head->pre = NULL;
		}
	}
	return 1;
}

int grow(SNAKE* bam)
{
	int x[] = { -1, 0, 1, 0 };
	int y[] = { 0, 1, 0, -1 };
	int rot = bam->rotate;

	++(bam->count);
	BODY* temp = bam->head;

	BODY* n_body = (BODY*)malloc(sizeof(BODY));


	n_body->x_pos = temp->x_pos + x[rot];
	n_body->y_pos = temp->y_pos + y[rot];
	n_body->pre = NULL;
	n_body->next = temp;

	board[n_body->x_pos][n_body->y_pos] = 3;

	temp->pre = n_body;

	bam->head = n_body;

	return 0;
}

int die_Snake(SNAKE* bam)
{
	BODY* temp = bam->head;

	while (temp = NULL)
	{
		BODY* trash = temp;
		temp = temp->next;
		free(trash);
	}

	free(bam);

	return 0;
}
