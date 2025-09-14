#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global board (easier than passing around)
int		*board;
int		size;

void	print_solution(void)
{
	char	c;

	for (int i = 0; i < size; i++)
	{
		if (board[i] >= 10)
			print_solution(); // This won't happen for reasonable n
		c = board[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

// Even simpler print function
void	print_digit(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	print_board(void)
{
	for (int i = 0; i < size; i++)
		print_digit(board[i]);
	write(1, "\n", 1);
}

// Check if queen at (row, col) conflicts with any previous queen
int	conflicts(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		// Same column or diagonal?
		if (board[i] == col ||
			board[i] - col == i - row ||
			board[i] - col == row - i)
			return (1);
	}
	return (0);
}

// Solve recursively
void	solve(int row)
{
	// All queens placed?
	if (row == size)
	{
		print_board();
		return ;
	}
	// Try each column
	for (int col = 0; col < size; col++)
	{
		if (!conflicts(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	size = atoi(argv[1]);
	if (size <= 0)
		return (1);
	board = malloc(size * sizeof(int));
	if (!board)
		return (1);
	solve(0); // Start with row 0
	free(board);
	return (0);
}

/*
🚀 EXAM LIGHTNING VERSION - MEMORIZE THIS:

int	conflicts(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col ||                    // same column
			board[i] - col == i - row ||          // diagonal \
			board[i] - col == row - i)            // diagonal /
			return (1);
	}
	return (0);
}

void	solve(int row) {
	if (row == n) { print_solution(); return ; }
	for (int col = 0; col < n; col++) {
		if (!conflicts(row, col)) {
			board[row] = col;
			solve(row + 1);
		}
	}
}

That's it! 15 lines of core logic.
*/