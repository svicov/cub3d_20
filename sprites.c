#include "cub3d.h"

void ft_sprite_position(t_mn *mn)
{
	int i;
	int j;

	i = 0;
	mn->num_sp = 0;
	while (mn->map[i])
	{
		j = 0;
		while (mn->map[i][j])
		{
			if (mn->map[i][j] == '2')
			{
				mn->map_sp[mn->num_sp][0] = j + 0.5;
				mn->map_sp[mn->num_sp][1] = i + 0.5;
				mn->num_sp++;
			}
			j++;
		}
		i++;
	}
}

void ft_sort_order(t_pair *orders, int amount)
{
	int i;
	int j;
	t_pair tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < (amount - 1))
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void ft_sort_sprites(int *order, double *dist, int amount)
{
	int i;
	t_pair *spOites;

	i = 0;
	spOites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		spOites[i].first = dist[i];
		spOites[i].second = order[i];
		i++;
	}
	ft_sort_order(spOites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = spOites[amount - i - 1].first;
		order[i] = spOites[amount - i - 1].second;
		i++;
	}
	free(spOites);
}

void ft_sprite_distance(t_info *info, t_mn *mn, int *spO, double *spD)
{
	mn->num_sp = 0;
	while (mn->num_sp < mn->count_sp)
	{
		spO[mn->num_sp] = mn->num_sp;
		spD[mn->num_sp] = hypot(info->posX - mn->map[mn->num_sp][0],
								info->posY - mn->map[mn->num_sp][1]);
		mn->num_sp++;
	}
	ft_sort_sprites(spO, spD, mn->count_sp);
}

int ft_sprites(t_info *info, t_sp *sp, t_mn *mn, int *spO)
{
	double *spD;

	spO = (int *)malloc(sizeof(int) * mn->count_sp);
	spD = (double *)malloc(sizeof(double) * mn->count_sp);
	if (!spO || !spD)
		return (-1);
	ft_sprite_distance(info, mn, spO, spD); // ok
	mn->num_sp = 0;
	while (mn->num_sp < mn->count_sp)
	{
		ft_setup_sprites(info, sp, mn, spO); // ok
		while (sp->stripe < sp->drawEndX)
		{
			sp->texX = (int)((256 * (sp->stripe - (-sp->w / 2 + sp->scrnX)) * TW / sp->w) / 256);
			if (sp->stripe > 0 && sp->stripe < mn->conf.width && sp->tfY < info->zBuffer[sp->stripe] && sp->tfY > 0)
				ft_paint_sprite(info, sp, mn); // ok
			sp->stripe++;
		}
		mn->num_sp++;
	}
	free(spO);
	free(spD);
	return (0);
}