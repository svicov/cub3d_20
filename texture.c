#include "cub3d.h"

void	ft_load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
				&img->size_l, &img->endian);
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	ft_load_texture(t_info *info, t_mn *mn)
{
	t_img	img;

	ft_load_image(info, info->texture[0], mn->conf.no, &img);
	ft_load_image(info, info->texture[1], mn->conf.so, &img);
	ft_load_image(info, info->texture[2], mn->conf.we, &img);
	ft_load_image(info, info->texture[3], mn->conf.ea, &img);
	// ft_load_image(info, info->texture[4], mn->conf.floor, &img);
	// ft_load_image(info, info->texture[5], mn->conf.ceiling, &img);
	ft_load_image(info, info->texture[6], mn->conf.s, &img);
}

int	ft_malloc_texture(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->texture = (int **)malloc(sizeof(int *) * 7);
	if (!info->texture)
		return (-1);
	while (++i < 7)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (TH * TW));
		if (!info->texture[i])
			return (-1);
	}
	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (++j < TH * TW)
			info->texture[i][j] = 0;
	}
	return (0);
}

int	ft_malloc_buf(t_info *info, t_mn *mn)
{
	int	i;
	int	j;

	info->buf = (int **)malloc(sizeof(int *) * mn->conf.heigth);
	if (!info->buf)
		return (-1);
	i = -1;
	while (++i < mn->conf.heigth)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * mn->conf.width);
		if (!info->buf[i])
			return (-1);
	}
	i = -1;
	while (++i < mn->conf.heigth)
	{
		j = -1;
		while (++j < mn->conf.width)
			info->buf[i][j] = 0;
	}
	return (0);
}

int	ft_malloc(t_info *info, t_mn *mn)
{
	info->zBuffer = (double *)malloc(sizeof(double) * mn->conf.width);
	if (!info->zBuffer)
		return (-1);
	ft_malloc_buf(info, mn);
	ft_malloc_texture(info);
	return (0);
}