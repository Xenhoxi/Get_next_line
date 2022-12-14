/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:23:10 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/09 21:30:40 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result;
	int		i;

	i = 0;
	fd = open("read.txt", O_RDONLY);
	while (i < 8)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
		i++;
	}
	close(fd);
	return (0);
}
