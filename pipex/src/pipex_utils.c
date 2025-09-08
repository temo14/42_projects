/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:39:13 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/20 21:17:20 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_string_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**parse_cmd(char *cmd)
{
	char	**cmd_parts;

	cmd_parts = ft_split(cmd, ' ');
	return (cmd_parts);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	full = search_in_paths(cmd, paths);
	free_string_array(paths);
	return (full);
}

void	parse_and_execute(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = parse_cmd(cmd);
	if (!cmd_args || !cmd_args[0])
	{
		perror("Invalid command");
		exit(1);
	}
	path = find_path(cmd_args[0], envp);
	if (!path)
	{
		perror(cmd_args[0]);
		free_string_array(cmd_args);
		exit(127);
	}
	execve(path, cmd_args, envp);
	perror("execve failed");
	free(path);
	free_string_array(cmd_args);
	exit(1);
}
