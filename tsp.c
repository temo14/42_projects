#include <float.h>
#include <math.h>
#include <stdio.h>

int		n = 0;
float	x[12];
float	y[12];
int		used[12];
float	dist[12][12];
float	best = 100000;

void	tsp(int cur, int cnt, float len)
{
	if (len >= best)
		return ;
	if (cnt == n)
	{
		len += dist[cur][0];
		if (len < best)
			best = len;
		return ;
	}
	for (int i = 1; i < n; i++)
	{
		if (!used[i] == 1)
		{
			used[i] = 1;
			tsp(i, cnt + 1, len + dist[cur][i]);
			used[i] = 0;
		}
	}
}

float	distance(float dx, float dy)
{
	return (sqrtf(dx * dx + dy * dy));
}

int	main(void)
{
	while (fscanf(stdin, "%f, %f", &x[n], &y[n]) == 2)
		n++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = distance(x[i] - x[j], y[i] - y[j]);
	tsp(0, 1, 0);
	printf("%.2f\n", best);
	return (0);
}