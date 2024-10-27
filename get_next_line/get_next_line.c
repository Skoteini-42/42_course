/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:53:05 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/25 11:15:08 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (stash[j] && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*stash_zero(char *stash)
{
	if (!stash)
	{
		stash = (char *)malloc(sizeof(1));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

static char	*get_read(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	stash = stash_zero(stash);
	if (!stash)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), NULL);
		if (bytes_read == 0)
			return (free (buffer), stash);
		buffer[bytes_read] = '\0';
		stash = join_buf(stash, buffer);
		if (!stash)
			return (free (buffer), NULL);
	}
	return (free (buffer), stash);
}

static int	non_printable(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		if (stash[i] < 32 || stash[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash || stash[0] == '\0')
	{
		stash = get_read(fd, stash);
		if (!stash || stash[0] == '\0')
		{
			if (stash)
				return (free (stash), stash = NULL);
			return (NULL);
		}
	}
	if (!stash || non_printable(stash))
		return (free (stash), stash = NULL, NULL);
	line = extract_line(stash);
	stash = clear_stash(stash);
	if (!stash)
		return (free (line), NULL);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;
	int	line_count = 0;
	
	fd = open("./test_files/test_lines.txt", O_RDONLY);
	if (fd < 0)
	{
		perror ("Error opening file");
		return (-1);
	}
//	printf("file opened successfully, fd : %d\n", fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d : %s", ++line_count, line);
		free (line);
	}
//	printf("get_next_line returned NULL, EOF or error\n");
	close(fd);
	return (0);
}*/
