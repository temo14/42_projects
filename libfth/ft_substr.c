/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:34:48 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/08 16:49:27 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	alloc_size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len < s_len - start)
		alloc_size = len;
	else
		alloc_size = s_len - start;
	substr = malloc(alloc_size + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, alloc_size);
	substr[alloc_size] = '\0';
	return (substr);
}
