#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float	x;
	float	y;
}			City;

void	build_dist_matrix(int n, float dist[n][n], City cities[n])
{
	float	dx;
	float	dy;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				dist[i][j] = 0.0f;
			else
			{
				dx = cities[i].x - cities[j].x;
				dy = cities[i].y - cities[j].y;
				dist[i][j] = sqrtf((dx * dx) + (dy * dy));
			}
		}
	}
}

void	calculate(int n, int *arr, float dist[n][n], float *result)
{
	float	total;
	int		prev;

	total = 0.0f;
	prev = 0;
	for (int i = 0; i < n - 1; i++)
	{
		total += dist[prev][arr[i]];
		prev = arr[i];
	}
	if (total < *result)
		*result = total;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	solve(int pos, int n, int *arr, float dist[n][n], float *result)
{
	if (pos == n - 1)
	{
		calculate(n, arr, dist, result);
		return ;
	}
	for (int i = pos; i < n; i++)
	{
		swap(&arr[pos], &arr[i]);
		solve(pos + 1, n, arr, dist, result);
		swap(&arr[pos], &arr[i]);
	}
}

int	main(int ac, char *av[])
{
	City cities[12];
	int count = 0;
	int *arr;
	float best;

	// Read cities from input
	while (count < 11 && fscanf(stdin, "%f, %f", &cities[count].x,
			&cities[count].y) == 2)
		count++; // Why count++? Increment after successful read

	if (count == 0)
		return (1);

	float dist[count][count];
	build_dist_matrix(count, dist, cities);

	arr = malloc((count - 1) * sizeof(int));
	for (int k = 0; k < count - 1; k++)
		arr[k] = k + 1;
	float result = 10000;

	solve(0, count, arr, dist, &result);
	fprintf(stdout, "%.2f\n", result);
	return (0);
}