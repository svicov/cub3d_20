#include "cub3d.h"

void	ft_floor_draw(t_info *info, t_floor *fl, t_mn *mn, int y)
{
	int	x;

	x = 0;
	while (x < mn->conf.width)
	{
		fl->cellX = (int)(fl->X);
		fl->cellY = (int)(fl->Y);
		fl->tx = (int)(TW * (fl->X - fl->cellX)) & (TW - 1);
		fl->ty = (int)(TH * (fl->Y - fl->cellY)) & (TH - 1);
		fl->X += fl->stepX;
		fl->Y += fl->stepY;
		// fl->color = info->texture[4][TW * fl->ty + fl->tx];
		fl->color = 0xffffff;
		info->buf[y][x] = fl->color;
		// fl->color = info->texture[5][TW * fl->ty + fl->tx];
		fl->color = 0x000000;
		info->buf[mn->conf.heigth - y - 1][x] = fl->color;
		x++;
	}
}

void	ft_floor_calculate(t_info *info, t_floor *fl, t_mn *mn)
{
	int	y;

	y = mn->conf.heigth / 2 + 1;
	while (y < mn->conf.heigth)
	{
		fl->rayDirX0 = info->dirX - info->planeX;
		fl->rayDirY0 = info->dirY - info->planeY;
		fl->rayDirX1 = info->dirX + info->planeX;
		fl->rayDirY1 = info->dirY + info->planeY;
		fl->p = y - mn->conf.heigth/ 2;
		fl->posZ = 0.5 * mn->conf.heigth;
		fl->rowD = fl->posZ / fl->p;
		fl->stepX = fl->rowD * (fl->rayDirX1 - fl->rayDirX0) / mn->conf.width;
		fl->stepY = fl->rowD * (fl->rayDirY1 - fl->rayDirY0) / mn->conf.width;
		fl->X = info->posX + fl->rowD * fl->rayDirX0;
		fl->Y = info->posY + fl->rowD * fl->rayDirY0;
		ft_floor_draw(info, fl, mn, y);
		y++;
	}
}