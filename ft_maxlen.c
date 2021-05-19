#include "cub3d.h"

void ft_maxlen(t_mn *mn, char **line)
{
	int ln;

	ln = ft_strlen(*line);
	if (ln > mn->maxlen)
		mn->maxlen = ln;
}