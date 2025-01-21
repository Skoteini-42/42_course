/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:29:48 by fpapadak          #+#    #+#             */
/*   Updated: 2025/01/21 18:03:16 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infile;
	int	outfile;

	if (argc != 5)
		arg_error("pipex: invalid number of arguments");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror_exit("pipex");
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close(infile);
		perror_exit("pipex");
	}
	if (pipe(pipefd) < 0)
		perror_exit("pipex");
	execute_pipeline(argv, envp, pipefd, infile, outfile);
	close(infile);
	close(outfile);
	return (0);
}
