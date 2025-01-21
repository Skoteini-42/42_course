/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:31:20 by fpapadak          #+#    #+#             */
/*   Updated: 2025/01/21 17:59:57 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

int		main(int argc, char **argv, char **envp);
void	arg_error(char *str);
void	free_array(char **array);
void	perror_exit(char *str);
char	**parse_command(char *str);
char	*get_path_env(char **envp);
char	**get_path_dir(char *path_env);
char	*get_cmd_path(char *cmd, char **path_dir);
char	*resolve_cmd_path(char *cmd, char **envp);
void	execute_pipeline(char **argv, char **envp, int *pipefd);
void	execute_cmd(char *cmd_path, char **cmd_args, char **envp);
void	execute_first_child(char **argv, char **envp, int *pipefd, int infile);
void	execute_second_child(char **argv, char **envp, int *pipefd, int outfile);

#endif
