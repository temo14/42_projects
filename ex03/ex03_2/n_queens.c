#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		*board;
int		size;

void	print_board(void)
{
	for (int i = 0; i < size; i++)
		fprintf(stdout, "%d ", board[i]);
	fprintf(stdout, "\n");
}

int	conflicts(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i] == col || board[i] - col == i - row || board[i]
			- col == row - i)
			return (1);
	}
	return (0);
}

void	solve(int row)
{
	if (row == size)
	{
		print_board();
		return ;
	}
	for (int col = 0; col < size; col++)
	{
		if (!conflicts(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (1);
	size = atoi(av[1]);
	board = malloc(size * sizeof(int));
	solve(0);
	free(board);
	return (0);
}