/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:02:46 by tbaindur          #+#    #+#             */
/*   Updated: 2025/09/05 22:09:27 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	print_solution(int *board, int n)
{
	for (int i = 0; i < n; i++)
		ft_putnbr(board[i]);
}

int	is_safe(int *board, int row, int col)
{
	int	square;
	int	diff_columns;
	int	diff_rows;

	for (int i = 0; i < row; i++)
	{
		square = board[i];
		if (square == col)
			return (0);
		diff_columns = square - col;
		diff_rows = i - row;
		if (diff_columns == diff_rows || diff_columns == -diff_rows)
			return (0);
	}
	return (1);
}

void	solve_nqueens(int *board, int row, int n)
{
	if (row == n)
	{
		print_solution(board, n);
		fprintf(0, "\n");
		return ;
	}
	for (int col = 0; col < n; col++)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve_nqueens(board, row + 1, n);
			board[row] = -1;
		}
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*board;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n <= 0)
		return (1);
	board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	for (int i = 0; i < n; i++)
		board[i] = -1;
	solve_nqueens(board, 0, n);
	free(board);
	return (0);
}
