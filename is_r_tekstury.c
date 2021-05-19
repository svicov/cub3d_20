#include "cub3d.h"

int ft_main_loop(t_info *info, t_mn *mn)
{
	info->img.img = mlx_new_image(info->mlx, mn->conf.width, mn->conf.heigth);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);

	ft_floor_calculate(info, &info->fl, mn); // ok
	ft_wall_calculate(info, &info->wl, mn);  // ok
	ft_sprites(info, &info->sp, mn, NULL); // ok

	ft_draw(info, mn); // ok
	ft_key_update(info, mn); // ok
	// if (info->save == 1)
	// 	ft_create_bmp(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_mn mn;
	t_info info;
	int q;

	char *line;
	int fd;
	int res_gnl;

	if (argc > 3 || argc < 2)
		return (1);

	printf("ABI: %s\n", (*(argv + 1)));
	printf("P:  %s\n", (*(argv + 1) + ft_strlen(*(argv + 1)) - 4));
	if ((ft_strncmp((*(argv + 1) + ft_strlen(*(argv + 1)) - 4), ".cub", 4))) /*  проверка на расширение .cub  */
	{
		printf("incorrect file format \"%s\"\n", *(argv + 1));
		return (3);
	}

	fd = open(*(argv + 1), O_RDONLY);

	init_st_conf(&mn.conf);
	q = 0;
	while (q < 8)
	{
		res_gnl = get_next_line(fd, &line);
		if (res_gnl < 0)
		{
			printf("Error incorrect format file");
			return (2);
		}
		printf("ssssssssss   %s\n", line);
		pars1(&line, &mn);
		q++;
	}

	init_ab1(&info);

	printf("\n");
	printf("Width: %d\n", mn.conf.width);
	printf("Heigth: %d\n", mn.conf.heigth);
	printf("176 -- %s\n", mn.conf.no);
	printf("176 -- %s\n", mn.conf.so);
	printf("176 -- %s\n", mn.conf.we);
	printf("176 -- %s\n", mn.conf.ea);
	printf("176 -- %s\n", mn.conf.s);
	//  printf("F    %d  %d  %d\nC     %d  %d  %d\n", mn.conf.)

	//return (0);
	pars2(fd, &mn);
	printf("main -> true_map\n");
	true_map(&mn);
	printf("main -> true_map2\n");
	rtue_mat2(&mn);
	counting1(&mn);
	ft_player_position(&info, &mn, 0, 0);
	info.mlx = mlx_init();
	// if (info.save == 0)
	info.win = mlx_new_window(info.mlx, mn.conf.width, mn.conf.heigth, "Window");
	// else
	ft_main_loop(&info, &mn);

	mlx_hook(info.win, 2, 0, &ft_key_press, &info);
	mlx_hook(info.win, 3, 0, &ft_key_release, &info);
	mlx_loop_hook(info.mlx, &ft_main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}