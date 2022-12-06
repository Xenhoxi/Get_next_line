/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/06 19:25:33 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*freeall(char *str)
{
	if (str)
	{
		free(str);
		str = 0;
		return (NULL);
	}
	return (NULL);
}

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

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\0' || save[i] == '\n')
			return (1);
		i++;
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
	if (str[i] == '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (freeall(result));
	u = 0;
	while (u < i)
	{
		result[u] = str[u];
		u++;
	}
	result[u] = 0;
	if (result[0] == '\0')
		return (freeall(result));
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
	if (!str[i])
		return (freeall(str));
	i++;
	len_str = ft_strlen(str) - i;
	u = 0;
	result = malloc(sizeof(char) * len_str + 1);
	if (!result)
		return (freeall(result));
	while (u < len_str)
	{
		result[u] = str[i];
		u++;
		i++;
	}
	result[u] = 0;
	freeall(str);
	return (result);
}

char	*ft_strjoin(char *str, char *buffer, int len)
{
	int		u;
	int		i;
	char	*save;

	i = 0;
	u = 0;
	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return (freeall(save));
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
	save[u] = 0;
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*save;
	int			end;
	char		*result;
	int			u;

	end = 0;
	u = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
	{
		free(save);
		save = 0;
		return (save);
	}
	if (check_backslash(save))
			end = 1;
	while (!end && u > 0)
	{
		u = read(fd, buffer, BUFFER_SIZE);
		if (u == -1)
			freeall(save);
		save = ft_strjoin(save, buffer, (u + ft_strlen(save)));
		if (check_backslash(save))
			end = 1;
	}
	result = all_before_backslash_n(save);
	save = all_after_backslash_n(save);
	return (result);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*result;
// 	int		i;

// 	i = 0;
// 	fd = open("read.txt", O_RDONLY);
// 	while (i < 2)
// 	{
// 		result = get_next_line(fd);
// 		printf("%s", result);
// 		i++;
// 	}
// 	return (0);
// }
