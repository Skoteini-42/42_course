/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:16:48 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/26 11:48:19 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		stash = (char *)malloc(sizeof(char) * 1);
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
	char		*line;
	static char *stash[FD_SIZE] = {NULL};
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_SIZE)
		return (NULL);
	stash[fd] = get_read(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
	{	
		if (stash[fd])
			return(free (stash[fd]), stash[fd] = NULL);
		return (NULL);
	}
	if (!stash[fd] || non_printable(stash[fd]))
		return(free (stash[fd]), stash[fd] = NULL, NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clear_stash(stash[fd]);
	if (!line)
		return (free (stash[fd]), NULL);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char *line;
	int	line_count = 0;
	
	fd1 = open("./test_files/test_lines.txt", O_RDONLY);
	fd2 = open("./test_files/test_multiple_lines.txt", O_RDONLY);
	fd3 = open("./test_files/test_empty_file.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror ("Error opening file");
		return (-1);
	}
	printf("file opened successfully, fd : %d\n", fd1);
	printf("file opened successfully, fd : %d\n", fd2);
	printf("file opened successfully, fd : %d\n", fd3);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %d : %s", ++line_count, line);
		free (line);
	}
	line_count = 0;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %d : %s", ++line_count, line);
		free (line);
	}
	line_count = 0;
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("Line %d : %s", ++line_count, line);
		free (line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
