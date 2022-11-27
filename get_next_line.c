/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:44:34 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/27 23:22:30 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		i;

	i = read(fd, buffer, BUFFER_SIZE);
	printf("%s", buffer);
	return (NULL);
}

int	main(void)
{
	int		fd;

	fd = open("read.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
