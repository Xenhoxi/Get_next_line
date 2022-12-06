/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/06 19:40:11 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeallspe(char *str)
{
	free(str);
	str = 0;
	return (str);
}

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
