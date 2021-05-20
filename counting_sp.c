#include "cub3d.h"

int counting1(t_mn *mn)
{
	int i;
	int j;

	mn->count_sp = 0;
	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		i = 0;
		while (i < mn->maxlen)
		{
			if (mn->map[j][i] == '2')
			{
				mn->count_sp++;
			}

			i++;
		}
		j++;
	}
	return (0);
}

int mall_sp(t_mn *mn)
{
	int i;

	if (mn->count_sp > 0)
	{
		mn->map_sp = (double **)malloc((mn->count_sp + 1) * sizeof(double *));
		if (mn->map_sp == NULL)
			return (-1);
		i = 0;
		while (i < mn->count_sp)
		{
			mn->map_sp[i] = (double *)malloc(2 * sizeof(double));
			if (mn->map_sp[i] == NULL)
				return (-1);
			i++;
		}
	}
	// ft_sprite_position(mn);
	return (0);
}

int position_sp(t_mn *mn)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		i = 0;
		while (i < mn->maxlen)
		{
			if (mn->map[j][i] == '2' && k < mn->count_sp)
			{
				mn->map_sp[k][0] = i + 0.5;
				mn->map_sp[k][1] = j + 0.5;
				k++;
			}
			i++;
		}
		j++;
	}

	k = 0;
	while (k < mn->count_sp)
	{
		printf("spr  %d    %f  %f", k, mn->map_sp[k][0], mn->map_sp[k][1]);
		k++;
	}

	return (0);
}