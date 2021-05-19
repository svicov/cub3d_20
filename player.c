#include "cub3d.h"

static	void	ft_player_direction(t_info *info, t_mn *mn, int i, int j)
{
	if (mn->map[i][j] == 'N')
	{
		info->dirX = 0;
		info->dirY = -1;
	}
	if (mn->map[i][j] == 'S')
	{
		info->dirX = 0;
		info->dirY = 1;
	}
	if (mn->map[i][j] == 'W')
	{
		info->dirX = -1;
		info->dirY = 0;
	}
	if (mn->map[i][j] == 'E')
	{
		info->dirX = 1;
		info->dirY = 0;
	}
	info->planeX = info->dirY * -0.66;
	info->planeY = info->dirX * 0.66;
}

void	ft_player_position(t_info *info, t_mn *mn, int i, int j)
{
	while (i < mn->num_s - mn->num_s0)
	{
		j = 0;
		while (mn->map[i][j])
		{
			if ((mn->map[i][j] == 'N')
			|| (mn->map[i][j] == 'S')
			|| (mn->map[i][j] == 'W')
			|| (mn->map[i][j] == 'E'))
			{
				info->posX = j + 0.5;
				info->posY = i + 0.5;
				ft_player_direction(info, mn, i, j);
				mn->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}