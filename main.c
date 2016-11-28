/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:07:48 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 11:12:10 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	**line;
	int		fd1;
	int		fd2;
	int		n = 1;

	if (ac != 2)
		return (0);
	if ((fd1 = open (av[1], O_RDONLY)) == -1)
		return (0);
	line = (char**)malloc(sizeof(char**));
	while (n)
	{
		n = get_next_line(fd1, line);
		printf("return=%i\n", n);
		printf("-------------%s\n", *line);
	}
	//		printf("%s\n", *line);
	return (0);
}
