#include "cub3d.h"

static	void	ft_rotate(t_info *q)
{
	double	oldDirX;
	double	oldPlaneX;

	if (q->key_r)
	{
		oldDirX = q->dirX;
		q->dirX = q->dirX * cos(-q->rt) - q->dirY * sin(-q->rt);
		q->dirY = oldDirX * sin(-q->rt) + q->dirY * cos(-q->rt);
		oldPlaneX = q->planeX;
		q->planeX = q->planeX * cos(-q->rt) - q->planeY * sin(-q->rt);
		q->planeY = oldPlaneX * sin(-q->rt) + q->planeY * cos(-q->rt);
	}
	if (q->key_l)
	{
		oldDirX = q->dirX;
		q->dirX = q->dirX * cos(q->rt) - q->dirY * sin(q->rt);
		q->dirY = oldDirX * sin(q->rt) + q->dirY * cos(q->rt);
		oldPlaneX = q->planeX;
		q->planeX = q->planeX * cos(q->rt) - q->planeY * sin(q->rt);
		q->planeY = oldPlaneX * sin(q->rt) + q->planeY * cos(q->rt);
	}
}

static	void	ft_move_left_right(t_info *q, t_mn *mn)
{
	if (q->key_a)
	{
		if (mn->map[(int)(q->posY - q->dirX * \
			q->mv)][(int)(q->posX)] != '1')
			q->posY -= q->dirX * q->mv;
		if (mn->map[(int)(q->posY)][(int)(q->posX + \
			q->dirY * q->mv)] != '1')
			q->posX += q->dirY * q->mv;
	}
	if (q->key_d)
	{
		if (mn->map[(int)(q->posY + q->dirX * q->mv)] \
		[(int)(q->posX)] != '1')
			q->posY += q->dirX * q->mv;
		if (mn->map[(int)(q->posY)][(int)(q->posX - \
		q->dirY * q->mv)] != '1')
			q->posX -= q->dirY * q->mv;
	}
}

void	ft_key_update(t_info *q, t_mn *mn)
{
	if (q->key_w)
	{
		if (mn->map[(int)(q->posY)] \
			[(int)(q->posX + q->dirX * q->mv)] != '1')
			q->posX += q->dirX * q->mv;
		if (mn->map[(int)(q->posY + q->dirY * q->mv)] \
			[(int)(q->posX)] != '1')
			q->posY += q->dirY * q->mv;
	}
	if (q->key_s)
	{
		if (mn->map[(int)(q->posY)] \
			[(int)(q->posX - q->dirX * q->mv)] != '1')
			q->posX -= q->dirX * q->mv;
		if (mn->map[(int)(q->posY - q->dirY * q->mv)] \
			[(int)(q->posX)] != '1')
			q->posY -= q->dirY * q->mv;
	}
	ft_move_left_right(q, mn);
	ft_rotate(q);
	if (q->key_esc)
		exit(0);
}
