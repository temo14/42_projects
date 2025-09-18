#include <stdio.h>
#include <stdlib.h>

void	print_board(int num, int *board)
{
	for (int i = 0; i < num; i++)
	{
		fprintf(stdout, "%d ", board[i]);
	}
	fprintf(stdout, "\n");
}

int	is_safe(int row, int col, int *board)
{
	for (int i = row - 1; i >= 0; i--)
	{
		if (board[i] == col)
			return (0);
		if (row - i == board[i] - col)
			return (0);
		if (row - i == col - board[i])
			return (0);
	}
	return (1);
}

void	solve(int row, int num, int *board)
{
	if (row == num)
	{
		print_board(num, board);
		return ;
	}
	for (int i = 0; i < num; i++)
	{
		if (is_safe(row, i, board))
		{
			board[row] = i;
			solve(row + 1, num, board);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int num = atoi(av[1]);
	int board[num];
	solve(0, num, board);
	return (0);
}