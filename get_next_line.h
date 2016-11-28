/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:52:40 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/27 18:47:20 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

# include <stdio.h>

# define BUFF_SIZE 6
# define CT(Pointeur) ((glist*)(Pointeur->content))

typedef	struct	get_list
{
	int			fd;
	char		*buff;
}				glist;

int		get_next_line(const int fd, char **line);
void	until_nl(t_list **start, int fd);
#endif
