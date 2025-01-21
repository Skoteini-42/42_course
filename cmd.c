/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:13:55 by fpapadak          #+#    #+#             */
/*   Updated: 2025/01/21 17:42:59 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *str)
{
	char	**cmd;

	if (!str || !*str)
		return (NULL);
	cmd = ft_split(str, ' ');
	if (!cmd || !cmd[0])
		return (free_array(cmd), NULL);
	return (cmd);
}

char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	**get_path_dir(char *path_env)
{
	if (path_env)
		return (ft_split(path_env, ':'));
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **path_dir)
{
	char	*cmd_path;
	char	*temp;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path_dir && path_dir[i])
	{
		temp = ft_strjoin(path_dir[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}

char	*resolve_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**path_dir;
	char	*cmd_path;

	path_env = get_path_env(envp);
	path_dir = get_path_dir(path_env);
	cmd_path = get_cmd_path(cmd, path_dir);
	free_array(path_dir);
	return (cmd_path);
}
