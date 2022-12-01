/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/01 16:32:23 by ljerinec         ###   ########.fr       */
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
	if (!save)
		return (0);
	while (save[++i])
	{
		if (save[i] == '\0' || save[i] == '\n')
			return (1);
	}
	return (0);
}

char	*all_before_backslash_n(char *str)
{
	int		i;
	int		u;
	char	*result;

	i = 0;
	u = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	result = malloc(sizeof(char) * (i));
	if (!result)
		return (NULL);
	u = 0;
	while (u <= i)
	{
		result[u] = str[u];
		u++;
	}
	free(str);
	return (result);
}

char	*all_after_backslash_n(char *str)
{
	int		i;
	int		u;
	char	*result;
	int		len_str;

	i = 0;
	u = 0;
	result = NULL;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	len_str = ft_strlen(str) -1 - i;
	u = 0;
	i++;
	if (len_str != 0)
		result = malloc(sizeof(char) * len_str);
	if (!result || len_str == 0)
		return (NULL);
	while (u <= len_str)
	{
		result[u] = str[i];
		u++;
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *str, char *buffer, int len)
{
	int		u;
	int		i;
	char	*save;

	i = 0;
	u = 0;
	save = malloc(sizeof(char) * (len));
	if (str != NULL)
	{
		while (str[i] != '\n' && str[i] != '\0')
		{
			save[u] = str[i];
			i++;
			u++;
		}
	}
	i = 0;
	while (u < len)
	{
		save[u] = buffer[i];
		u++;
		i++;
	}
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	int			i;
	static char	*save;
	int			end;
	char		*result;
	int			u;

	i = 0;
	end = 0;
	u = 1;
	if (check_backslash(save))
			end = 1;
	while (!end && u)
	{
		u = read(fd, buffer, BUFFER_SIZE);
		i += u;
		save = ft_strjoin(save, buffer, i);
		if (check_backslash(save))
			end = 1;
	}
	result = all_before_backslash_n(save);
	save = all_after_backslash_n(save);
	return (result);
}

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("read.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	return (0);
}
