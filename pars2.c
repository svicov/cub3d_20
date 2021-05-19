#include "cub3d.h"

int pars2(int fd, t_mn *mn)
{
	printf("pars2\n");
	char **tmp_tmap;
	int i, ii;
	char *line;
	int res_gnl;
	
	res_gnl = 1;
	mn->num_s = 0;
	mn->tmap = NULL;
			/* досчитывает файл в tmap  */
	while (res_gnl == 1)
	{
		tmp_tmap = (char **)malloc( (mn->num_s + 1) * sizeof(char *));
		i = 0;
		while (i < mn->num_s)
		{			
			*(tmp_tmap + i) = *(mn->tmap + i);
			i++;
		}		
		res_gnl = get_next_line(fd, &line);
		ft_maxlen(mn, &line);
		*(tmp_tmap + i) =(char *)malloc((ft_strlen(line) + 1) * sizeof(char)); 
		*(tmp_tmap + i) = line;
		mn->num_s++;
		if (!(mn->tmap))
			free(mn->tmap);
		mn->tmap = tmp_tmap;
	}
	printf("pars2-33 maxlen = %d\n", mn->maxlen);
	ii = 0;
	while (ii < mn->num_s)
	{
		printf("%d====|%s|\n", ii, *(mn->tmap + ii));
		ii++;
	}
	printf("nnnn  %d\n", mn->num_s);
	
	return (0);
}
