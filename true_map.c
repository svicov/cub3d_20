#include "cub3d.h"

int true_map(t_mn *mn)
{
	int	i;
	int j;
	
	j = 0;
	while (*(*(mn->tmap + j)) == '\0')
		j++;
	mn->num_s0 = j;
	j = 0;
	while (j < mn->num_s)
	{
		i = 0;
		while (mn->tmap[j][i])
		{
			if (!(ft_strchr("012 NSWE", mn->tmap[j][i]))) /*проверка на возмщжные символы */
				return (3);    /* закрыть при первом же неправильном символе*/
			if (ft_strchr("NSWE", mn->tmap[j][i]) && mn->player < 2) /* провка количества играков {012}  */
				mn->player++;
			i++;
		}
		j++;
	}
	printf("true_map-26  кол строк %d    длинна стр %d   нулевых строк %d\n",mn->num_s, mn->maxlen, mn->num_s0);
	printf("mn->player = %d\n", mn->player);

	return (0);
}

void rtue_mat2(t_mn *mn)
{	
	int i;
	int j;	
	mn->map = (char **)malloc((mn->num_s - mn->num_s0 +1) *sizeof(char *));
	mn->map[mn->num_s - mn->num_s0] = NULL;
	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		mn->map[j] = (char *)malloc(mn->maxlen +1);
		mn->map[j][mn->maxlen] = '\0';
		j++;
	}
	
	j = 0;
	while (j < mn->num_s - mn->num_s0)
	{
		i = 0;
		while(i < mn->maxlen)
			mn->map[j][i++] = '1';						
		j++;
	}

	j = 0;
	while (j < mn->num_s - mn->num_s0)
	{
		i = 0;
		while(i < mn->maxlen)
		{
			//printf()
			printf("%c",mn->map[j][i]);
			i++;
		}
		printf("\n");
						
		j++;
	}
	   //printf("\n");

	printf("true2-69\n");
	j = 0;
	while (j < mn->num_s - mn->num_s0)
	{
		i = 0;
		while(mn->tmap[j + mn->num_s0][i])
		{
			if (ft_strchr("012NSWE", mn->tmap[j+ mn->num_s0][i]))
				mn->map[j][i] = mn->tmap[j + mn->num_s0][i];
			i++;
		}
		j++;
	}
	j = 0;
	printf("\n\n\n");
	while (j < mn->num_s - mn->num_s0)
	{
		i = 0;		

		while(i < mn->maxlen)
		{
			//printf()
			printf("%c",mn->map[j][i]);
			i++;
		}
		printf("\n");
						
		j++;
	}
	printf("\n");

	if (valid_map(mn))
		printf("  ****   invaaa    map  !!!!!!*****\n");
	else
		printf("map Ok\nOk  Ok   Ok    Ok    Ok  ");
}
