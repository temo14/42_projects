/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:43:23 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/07 12:03:50 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scan;

	i = 0;
	scan = (unsigned char *)s;
	while (i < n)
	{
		if (scan[i] == (unsigned char)c)
			return ((void *)(scan + i));
		i++;
	}
	return (NULL);
}
