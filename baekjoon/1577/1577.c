#include <stdio.h>  
#include <limits.h>

long long road[101][101];
int n, m;

long long count_road(int, int);

int visit[101][101];

int main(void) {
	int k;

	scanf("%d %d", &n, &m);
	scanf("%d", &k);


	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j)
			road[i][j] = -1;
	}

	road[0][0] = 1;

	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2) {
			if (y1 > y2)
				visit[x1][y1] += 1;
			else
				visit[x1][y2] += 1;
		}
		else {
			if (x1 > x2)
				visit[x1][y1] += 10;
			else
				visit[x2][y1] += 10;
		}

	}

	printf("%lld\n", count_road(n, m));

	return 0;
};

long long count_road(int x, int y) {
	if (x < 0 || y < 0)
		return 0;

	if (visit[x][y] == 11) {
		road[x][y] = 0;

		return 0;
	}
	else if (visit[x][y] == 1) {
		road[x][y] = count_road(x - 1, y);
	}
	else if (visit[x][y] == 10) {
		road[x][y] = count_road(x, y - 1);
	}

	if (road[x][y] != -1)
		return road[x][y];

	road[x][y] = count_road(x - 1, y) + count_road(x, y - 1);

	return road[x][y];
}
