/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:14:10 by fpapadak          #+#    #+#             */
/*   Updated: 2025/01/21 18:05:46 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_pipeline(char **argv, char **envp, int *pipefd, t_fds fds)
{
	int	first_child;
	int	second_child;

	first_child = fork();
	if (first_child < 0)
		perror_exit("pipex: error: fork failed");
	if (first_child == 0)
		execute_first_child(argv, envp, pipefd, fds.infile);
	second_child = fork();
	if (second_child < 0)
		perror_exit("pipex: error: fork failed");
	if (second_child == 0)
		execute_second_child(argv, envp, pipefd, fds.outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(first_child, NULL, 0);
	waitpid(second_child, NULL, 0);
}

void	execute_cmd(char *cmd_path, char **cmd_args, char **envp)
{
	if (!cmd_path)
	{
		ft_putstr_fd(cmd_args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		free_array(cmd_args);
		exit (127);
	}
	execve(cmd_path, cmd_args, envp);
	ft_putstr_fd(cmd_args[0], STDERR_FILENO);
	ft_putstr_fd(":", STDERR_FILENO);
	perror("");
	free_array(cmd_args);
	exit (1);
}

void	execute_first_child(char **argv, char **envp, int *pipefd, int infile)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(infile, STDIN_FILENO) < 0)
		perror_exit("pipex: error duplicating input file descriptor");
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		perror_exit("pipex: error duplicating pipe write-end");
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = parse_command(argv[2]);
	if (!cmd_args || !cmd_args[0])
	{
	 	ft_putstr_fd(" : command not found\n", STDERR_FILENO);
		exit (127);
	}
	cmd_path = resolve_cmd_path(cmd_args[0], envp);
	execute_cmd(cmd_path, cmd_args, envp);
}

void	execute_second_child(char **argv, char **envp, int *pipefd, int outfile)
{
	char	**cmd_args;
	char	*cmd_path;

	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		perror_exit("pipex: error duplicating pipe read-end");
	if (dup2(outfile, STDOUT_FILENO) < 0)
		perror_exit("pipex: error duplicating output file descriptor");
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = parse_command(argv[3]);
	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd(" : command not found\n", STDERR_FILENO);
		exit (127);
	}
	cmd_path = resolve_cmd_path(cmd_args[0], envp);
	execute_cmd(cmd_path, cmd_args, envp);
}
