/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/09 18:46:49 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (freeall(str));
	u = -1;
	while (++u < i)
		result[u] = str[u];
	result[u] = 0;
	if (result[0] == '\0')
	{
		free(str);
		return (freeall(result));
	}
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
	{
		free(str);
		return (freeall(result));
	}
	while (u < len_str)
		result[u++] = str[i++];
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
		return (freeall(str));
	if (str != NULL)
		while (str[i] != '\n' && str[i] != '\0')
			save[u++] = str[i++];
	free(str);
	i = 0;
	while (u < len)
		save[u++] = buffer[i++];
	save[u] = 0;
	return (save);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*save;
	char		*result;
	int			u;

	u = BUFFER_SIZE;
	result = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
	{
		free(save);
		save = 0;
		return (save);
	}
	if (check_backslash(save, u))
		u = 0;
	while (u > 0)
	{
		u = read(fd, buffer, BUFFER_SIZE);
		if ((save != NULL && u > 0) || (save == NULL && u > 0))
			save = ft_strjoin(save, buffer, (u + ft_strlen(save)));
		if (!save)
			return (NULL);
		if (check_backslash(save, u))
			break ;
	}
	result = all_before_backslash_n(save);
	if (result == 0)
	{
		save = 0;
		return (0);
	}
	save = all_after_backslash_n(save);
	return (result);
}
