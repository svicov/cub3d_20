#include "cub3d.h"

int	ft_key_press(int key, t_info *info)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 1;
	else if (key == 0)
		info->key_a = 1;
	else if (key == 1)
		info->key_s = 1;
	else if (key == 2)
		info->key_d = 1;
	else if (key == 124)
		info->key_l = 1;
	else if (key == 123)
		info->key_r = 1;
	return (0);
}

int	ft_key_release(int key, t_info *info)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 0;
	else if (key == 0)
		info->key_a = 0;
	else if (key == 1)
		info->key_s = 0;
	else if (key == 2)
		info->key_d = 0;
	else if (key == 124)
		info->key_l = 0;
	else if (key == 123)
		info->key_r = 0;
	return (0);
}