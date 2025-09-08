/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:39:42 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/30 19:36:35 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*reminder = NULL;

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line_from_reminder(void)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reminder)
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	while (j <= i)
	{
		result[j] = reminder[j];
		j++;
	}
    if (reminder[i] == '\n')
        result[j++] = '\n';
    result[j] = '\0';
    return (result);
}

void	update_reminder(void)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	j = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (ft_strlen(reminder) == i)
	{
		free(reminder);
		reminder = NULL;
		return ;
	}
	temp = malloc(ft_strlen(reminder) - i + 1);
	if (!temp)
		return ;
	i++;
	while (reminder[i])
		temp[j++] = reminder[i++];
	temp[j] = '\0';
	free(reminder);
	reminder = temp;
}

char	*get_next_line(int fd)
{
	int		bytes;
	char	*temp;
	char	*result;
	char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(reminder, '\n'))
	{
		result = extract_line_from_reminder();
		update_reminder();
		return (result);
	}
	bytes = 0;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
		{
			if (ft_strlen(reminder))
			{
				result = extract_line_from_reminder();
				update_reminder();
				return (result);
			}
			return (NULL);
		}
		buf[bytes] = '\0';
		temp = ft_strjoin(reminder, buf);
		free(reminder);
		reminder = temp;
		if (ft_strchr(reminder, '\n'))
		{
			result = extract_line_from_reminder();
			update_reminder();
			return (result);
		}
	}
}

int	main(void)
{
	int fd = open("./text.txt", O_RDONLY);
	char *str;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;

		printf("%s", str);
		free(str);
	}
	printf("\n\n");

	return (0);
}