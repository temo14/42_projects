/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:26:54 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/20 21:16:06 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int fd_in, int pipefd[2], char *cmd, char **envp)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	parse_and_execute(cmd, envp);
	perror("execve failed");
	exit(1);
}

static void	child2_process(int fd_out, int pipefd[2], char *cmd, char **envp)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	close(fd_out);
	parse_and_execute(cmd, envp);
	perror("execve failed");
	exit(1);
}

static int	open_files(char *infile, char *outfile, int *fd_in, int *fd_out)
{
	*fd_in = open(infile, O_RDONLY);
	if (*fd_in < 0)
		return (perror("infile"), -1);
	*fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fd_out < 0)
		return (perror("outfile"), -1);
	return (0);
}

int	pipex(char *argv[], char *envp[])
{
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;

	if (open_files(argv[1], argv[4], &fd_in, &fd_out) < 0)
		return (1);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == 0)
		child1_process(fd_in, pipefd, argv[2], envp);
	pid2 = fork();
	if (pid2 == 0)
		child2_process(fd_out, pipefd, argv[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	close(fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
