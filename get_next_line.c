/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:58:10 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 19:14:25 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*is_fd(t_list **start, int fd)
{
	t_list		*curs;

	curs = *start;
	if (!start)
		return (NULL);
	while (curs)
	{
		if (CT(curs)->fd == fd)
			return (curs);
		curs = curs->next;
	}
	return (NULL);
}

char		*read_buffer(int fd)
{
	char	*buffer;
	int		n;
	char	*str;

	n = 1;
	buffer = (char*)ft_memalloc(BUFF_SIZE + 1);
	str = ft_strnew(0);
	while ((n = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, 10) != NULL)
			break ;
	}
	free(buffer);
	return ((n <= 0) ? NULL : str);
}

glist		*new_struct(int fd)
{
	glist		*new;

	new = (glist*)ft_memalloc(sizeof(glist));
	new->buff = ft_strdup(read_buffer(fd));
	new->fd = fd;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	t_list				*curs;
	static t_list		*start;
	int					i;
	int					end;

	i = 0;
	if ((curs = is_fd(&start, fd)) == NULL)
	{
		ft_lst_pushend(&start, ft_lstnew(new_struct(fd), sizeof(glist)));
		curs = is_fd(&start, fd);
	}
	if (ft_strchr(CT(curs)->buff, 10) == NULL)
		CT(curs)->buff = ft_strjoin_free(CT(curs)->buff, 0, read_buffer(fd), 0);
	if (!CT(curs)->buff)
		return (0);
	while (CT(curs)->buff[i] && CT(curs)->buff[i] != 10)
		i++;
	if (end != 0)
	{
		*line = ft_strsub(CT(curs)->buff, 0, i);
		end = ft_strlen(CT(curs)->buff);
		ft_memmove(CT(curs)->buff, &(CT(curs)->buff[i + 1]), end - i);
	}
	return (1);
}
