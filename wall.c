#include "cub3d.h"

void	ft_fix_fisheye(t_info *info, t_wall *wl, t_mn *mn)
{
	if (wl->side == 0)
	{
		wl->pWDist = ((double)wl->mapX - info->posX + \
					(1 - wl->stepX) / 2) / wl->rayDirX;
	}
	else
	{
		wl->pWDist = ((double)wl->mapY - info->posY + \
					(1 - wl->stepY) / 2) / wl->rayDirY;
	}
	wl->lineHeight = (int)(mn->conf.heigth / wl->pWDist);
	wl->drawStart = -wl->lineHeight / 2 + mn->conf.heigth / 2;
	if (wl->drawStart < 0)
		wl->drawStart = 0;
	wl->drawEnd = wl->lineHeight / 2 + mn->conf.heigth / 2;
	if (wl->drawEnd >= mn->conf.heigth)
		wl->drawEnd = mn->conf.heigth - 1;
	if (wl->drawEnd < 0)
		wl->drawEnd = mn->conf.heigth - 1;
	wl->texNum = 0;
	if (wl->side == 0)
		wl->wallX = info->posY + wl->pWDist * wl->rayDirY;
	else
		wl->wallX = info->posX + wl->pWDist * wl->rayDirX;
}

void	ft_digital_differential_analyzer(t_info *info, t_wall *wl, t_mn *mn)
{
	while (wl->hit == 0)
	{
		if (wl->sideDistX < wl->sideDistY)
		{
			wl->sideDistX += wl->deltaDistX;
			wl->mapX += wl->stepX;
			wl->side = 0;
		}
		else
		{
			wl->sideDistY += wl->deltaDistY;
			wl->mapY += wl->stepY;
			wl->side = 1;
		}
		if (mn->map[wl->mapY][wl->mapX] == '1')
			wl->hit = 1;
	}
	ft_fix_fisheye(info, wl, mn);
}

void	ft_calculate_distance(t_info *info, t_wall *wl)
{
	wl->hit = 0;
	if (wl->rayDirX < 0)
	{
		wl->stepX = -1;
		wl->sideDistX = (info->posX - wl->mapX) * wl->deltaDistX;
	}
	else
	{
		wl->stepX = 1;
		wl->sideDistX = (wl->mapX + 1.0 - info->posX) * wl->deltaDistX;
	}
	if (wl->rayDirY < 0)
	{
		wl->stepY = -1;
		wl->sideDistY = (info->posY - wl->mapY) * wl->deltaDistY;
	}
	else
	{
		wl->stepY = 1;
		wl->sideDistY = (wl->mapY + 1.0 - info->posY) * wl->deltaDistY;
	}
}

void	ft_setup_walls(t_info *info, t_wall *wl, t_mn *mn, int x)
{
	wl->cameraX = 2 * x / (double)mn->conf.width - 1;
	wl->rayDirX = info->dirX + info->planeX * wl->cameraX;
	wl->rayDirY = info->dirY + info->planeY * wl->cameraX;
	wl->mapX = (int)info->posX;
	wl->mapY = (int)info->posY;
	wl->deltaDistX = fabs(1 / wl->rayDirX);
	wl->deltaDistY = fabs(1 / wl->rayDirY);
	ft_calculate_distance(info, wl);
}

void	ft_wall_calculate(t_info *info, t_wall *wl, t_mn *mn)
{
	int	x;

	x = 0;
	while (x < mn->conf.width)
	{
		ft_setup_walls(info, wl, mn, x);
		ft_digital_differential_analyzer(info, wl, mn);
		wl->wallX -= floor(wl->wallX);
		wl->texX = (int)(wl->wallX * (double)TW);
		if (wl->side == 0 && wl->rayDirX > 0)
			wl->texX = TW - wl->texX - 1;
		if (wl->side == 1 && wl->rayDirY < 0)
			wl->texX = TW - wl->texX - 1;
		wl->step = 1.0 * TH / wl->lineHeight;
		wl->texPos = (wl->drawStart - mn->conf.heigth / 2 + \
						wl->lineHeight / 2) * wl->step;
		ft_paint_walls(info, wl, x);
		info->zBuffer[x] = wl->pWDist;
		x++;
	}
}