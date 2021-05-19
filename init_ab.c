# include "cub3d.h"

static	void	ft_init_wall(t_wall *wl)
{
	wl->cameraX = 0;
	wl->rayDirX = 0;
	wl->rayDirY = 0;
	wl->mapX = 0;
	wl->mapY = 0;
	wl->sideDistX = 0;
	wl->sideDistY = 0;
	wl->deltaDistX = 0;
	wl->deltaDistY = 0;
	wl->pWDist = 0;
	wl->stepX = 0;
	wl->stepY = 0;
	wl->hit = 0;
	wl->side = 0;
	wl->lineHeight = 0;
	wl->drawStart = 0;
	wl->drawEnd = 0;
	wl->texNum = 0;
	wl->wallX = 0;
	wl->texX = 0;
	wl->texY = 0;
	wl->step = 0;
	wl->texPos = 0;
	wl->color = 0;
}

int init_ab1(t_info *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->mv = 0.3;
	info->rt = 0.2;
	info->key_l = 0;
	info->key_r = 0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	ft_init_wall(&info->wl);
	return (0);
}