/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/30 18:13:28 by ljerinec         ###   ########.fr       */
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
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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

char	*ft_strjoin(char *str, char *buffer, int len)
{
	int		u;
	int		i;
	char	*save;

	i = -1;
	u = 0;
	save = malloc(sizeof(char) * len);
	if (!save)
		return (NULL);
	if (str)
		while (str[++i])
			save[u++] = str[i];
	i = -1;
	while (buffer[++i])
		save[u++] = buffer[i];
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	int			i;
	static char	*save;
	int			end;

	i = 0;
	end = 0;
	save = NULL;
	while (!end)
	{
		i += read(fd, buffer, BUFFER_SIZE);
		save = ft_strjoin(save, buffer, i + 1);
		if (check_backslash(save))
			end = 1;
	}
	return (save);
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
