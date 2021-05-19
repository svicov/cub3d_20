#include "cub3d.h"

int			valid_map(t_mn *mn)  /*  1- invalid  0 - valid   */
{
	int		i;
	int		j;

	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		i = 0;
		while (i < mn->maxlen)
		{
			if (mn->map[j][i] != '1')
			{
				if (pl_s_above(mn, i, j) && pl_s_below(mn, i, j) &&	 pl_s_right(mn, i, j) && pl_s_leftward(mn, i, j))
				 {
					 
				 }
				else
				{
					/*printf("++%d %d    \n", j, i);   */return (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int pl_s_above(t_mn *mn, int i, int j)
{
	int		q;

	q = 1;
	while ((j - q) >= 0)
	{
		if ((mn->map[j - q][i]) == '1')
			return (1); 
		q++;
	}
	return (0);
}

int		pl_s_below(t_mn *mn, int i, int j)
{
	int		q;

	q = 1;
	while ((j + q) < mn->num_s - mn->num_s0)
	{
		if ((mn->map[j + q][i]) == '1')
			return (1);
		q++;
	}
	return (0);
}

int		pl_s_right(t_mn *mn, int i, int j)
{
	int		q;

	q = 1;
	while ((i + q) < mn->maxlen)
	{
		if ((mn->map[j][i + q]) == '1')
			return (1);
		q++;
	}
	return (0);
}

int pl_s_leftward(t_mn *mn, int i, int j)
{
	int	q;

	q = 1;
	while ((i - q) >= 0)
	{
		if ((mn->map[j][i - q]) == '1')
			return (1);
		q++;
	}
	return (0);
}