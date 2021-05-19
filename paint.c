#include "cub3d.h"

void	ft_draw(t_info *info, t_mn *mn)
{
	int	y;
	int	x;

	y = 0;
	while (y < mn->conf.heigth)
	{
		x = 0;
		while (x < mn->conf.width)
		{
			info->img.data[y * mn->conf.width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
}

void	ft_paint_sprite(t_info *q, t_sp *sp, t_mn *mn)
{
	int	y;
	int	d;

	y = sp->drawStartY;
	while (y < sp->drawEndY)
	{
		d = (y - sp->VMOVEScreen) * 256 - mn->conf.heigth * 128 + sp->h * 128;
		sp->texY = ((d * TH) / sp->h) / 256;
		sp->color = q->texture[6][TW * sp->texY + sp->texX];
		if ((sp->color & 0x00FFFFFF) != 0)
			q->buf[y][sp->stripe] = sp->color;
		y++;
	}
}

void	ft_paint_walls(t_info *info, t_wall *wl, int x)
{
	int	y;

	y = wl->drawStart;
	while (y < wl->drawEnd)
	{
		wl->texY = (int)wl->texPos & (TH - 1);
		wl->texPos += wl->step;
		if (wl->side == 1)
		{
			if (wl->stepY > 0)
				wl->texNum = 0;
			if (wl->stepY < 0)
				wl->texNum = 1;
		}
		if (wl->side == 0)
		{
			if (wl->stepX > 0)
				wl->texNum = 2;
			if (wl->stepX < 0)
				wl->texNum = 3;
		}
		wl->color = info->texture[wl->texNum][TH * wl->texY + wl->texX];
		info->buf[y][x] = wl->color;
		y++;
	}
}