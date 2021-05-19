#include "cub3d.h"

void init_st_conf(t_conf *ddd)
{
	ddd->width = 0;
	ddd->heigth = 0;
	ddd->no = NULL;
	ddd->so = NULL;
	ddd->we = NULL;
	ddd->ea = NULL;
	ddd->s = NULL;
	ddd->f = 0;
	ddd->c = 0;
}

void init_zp(t_mn *mn)
{
	int i;

	i = 0 ;
	while (i < 8)
	{
		mn->zp[i] = 1;
		i++;
	}
	mn->player = 0; /* пока ни разу игрок ну встретился  */
	mn->maxlen = 0;
}

int digit_of_a_number(int n)
{
	int i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while(n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n > 1)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}