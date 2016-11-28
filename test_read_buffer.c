/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:44:03 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 16:00:30 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_buffer(int fd);

int		main(int ac, char **av)
{
	int		fd;
	char	*str;

	if (ac != 2)
		return (0);
	if((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	str = "";
	while (str != NULL)
	{
		str = read_buffer(fd);
		printf("str=%s|\n", str);
	}
	return (0);
}
