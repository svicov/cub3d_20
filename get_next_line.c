/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbombur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 04:12:36 by dbombur           #+#    #+#             */
/*   Updated: 2021/02/26 14:54:13 by dbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			con_lin_buf(char **line, char *buf)
{
	size_t			l;
	char			*tl;
	size_t			red_b;
	size_t			i;

	red_b = BUFFER_SIZE;
	tl = ft_strdup(*line);
	if (tl == NULL)
		return (-1);
	free(*line);
	*line = ft_strjoin(tl, buf);
	if (*line == NULL)
		return (-1);
	free(tl);
	l = red_b - ft_strlen(buf);
	i = l;
	ft_memmove(buf, buf + ft_strlen(buf) + 1, l);
	while (i <= BUFFER_SIZE)
	{
		*(buf + i) = '\0';
		i++;
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				b;
	char			*v_n;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!(*line = (char *)malloc(1 * sizeof(char))))
		return (-1);
	**line = '\0';
	b = BUFFER_SIZE;
	while (b && b != -1)
	{
		if (ft_strlen(buf))
		{
			if ((v_n = ft_strchr(buf, '\n')))
				*v_n = '\0';
			con_lin_buf(line, buf);
			if (v_n != NULL)
				return (1);
		}
		b = read(fd, buf, BUFFER_SIZE);
	}
	return (0);
}
