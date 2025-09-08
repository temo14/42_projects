/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:34:48 by tbaindur          #+#    #+#             */
/*   Updated: 2025/09/08 20:25:05 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	check_duplicates(char *str, int len)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)calloc(len, sizeof(int));
	while (str[i])
	{
		if (arr[i])
		{
			free(arr);
			return (1);
		}
		arr[i] = i;
		i++;
	}
	free(arr);
	return (0);
}

void	sort(char **string, int len)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while ((*string)[i])
	{
		j = 0;
		while ((*string)[i + j])
		{
			if ((*string)[i] > ((*string)[i + j]))
			{
				c = (*string)[i];
				(*string)[i] = (*string)[i + j];
				(*string)[i + j] = c;
				j = -1;
			}
			j++;
		}
		i++;
	}
}

void	print_permutations(char *str, int len)
{
}

int	main(int ac, char *av[])
{
	char	*str;
	int		*arr;
	int		len;

	if (ac != 2)
		return (1);
	str = av[1];
	len = str_len(str);
	if (check_duplicates(str, len))
		return (1);
	sort(&str, len);
	puts(str);
	print_permutations(str, len);
	return (0);
}
