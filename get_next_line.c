/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/30 03:25:49 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*all_before_backslash_n(char *save)
{
	int		i;
	//char	*result;

	i = 0;
	while (save[i] != '\x03' || save[i] != '\0')
	{
		printf("%c", save[i]);
		i++;
	}
	//result = malloc(sizeof(char) * (i + 1));
	//if (!result)
	//	return (NULL);
	// i = 0;
	// while (save[i] != '\n' || save[i] != '\0')
	// {
	// 	result[i] = save[i];
	// 	i++;
	// }
	// result[i] = save[i];
	// result[i] = 0;
	return (NULL);
}

int	check_backslash(char *save)
{
	int	i;

	i = -1;
	while (save[++i])
	{
		if (save[i] == '\0' || save[i] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		u;
	int		i;
	int		lenmalloc;
	char	*save;

	i = -1;
	u = 0;
	lenmalloc = ft_strlen(str) + ft_strlen(buffer) + 1;
	save = malloc(sizeof(char) * lenmalloc);
	if (!save)
		return (NULL);
	while (str[++i])
		save[u++] = str[i];
	i = -1;
	while (buffer[++i])
		save[u++] = buffer[i];
	save[u] = '\0';
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		i;
	char	*save;
	int		end;
	char	*result;
	char	*test;

	i = 0;
	end = 0;
	save = malloc(sizeof(char));
	if (!save)
		return (NULL);
	save[0] = '\0';
	while (!end)
	{
		i += read(fd, buffer, BUFFER_SIZE);
		test = ft_strjoin(save, buffer);
		if (check_backslash(save))
			end = 1;
	}
	printf("%s", save);
	result = all_before_backslash_n(test);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("read.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	return (0);
}
