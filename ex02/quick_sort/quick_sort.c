#include <stdio.h>

void	print_arr(int *arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *arr, int start_index, int end_index)

{
	int pivot;
	int i;
	int j;

	if (start_index >= end_index)
		return ;
	pivot = arr[end_index];
	i = start_index;
	j = start_index;
	while (i < end_index)
	{
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	swap(&arr[j], &arr[end_index]);

	quick_sort(arr, start_index, j - 1);
	quick_sort(arr, j + 1, end_index);
}

int	main(void)
{
	int	arr[] = {3, 1, 5, 42, 2, 11, 8};

	print_arr(arr, 7);
	quick_sort(arr, 0, 6);
	printf("\n");
	print_arr(arr, 7);
	return (0);
}
