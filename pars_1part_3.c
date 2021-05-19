#include "cub3d.h"

int completion5(char **line, int i, t_mn *mn) /*  :S :   */
{
	int k;

	i = i + 2;

	while(*(*line + i) == ' ')
		i++;
	
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
		k++;

	mn->conf.s = malloc(k + 1);
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
	{		
		mn->conf.s[k] = *((*line) + i + k);
		k++;
	}
	mn->conf.s[k] = '\0';
	return (0);
}

int completion6(char **line, int i, t_mn *mn)
{
	int r;
	int hatoi;
			
	i = 2;    /* propusk probelov  */
	while((*(*line + i) ) == ' ')
		i++;
	hatoi = atoi(*line + i);
	i = i + digit_of_a_number(hatoi);
	mn->conf.f = hatoi << 16;
	if (*(*line + i) != ',')
		ft_error(4);
	i++;
	hatoi = atoi(*line + i);
	i = i + digit_of_a_number(hatoi);
	mn->conf.f = mn->conf.f + (hatoi << 8);
	if (*(*line + i) != ',')
		ft_error(4);
	i++;
	hatoi = atoi(*line + i);
	mn->conf.f = mn->conf.f + hatoi;
		printf("\n----0---0---f\n%d\n",mn->conf.f);
	return (0);
}

int completion7(char **line, int i, t_mn *mn)  /*  C cvet potolka   */
{
	int r;
	int hatoi;
			
	i = 2;    /* propusk probelov  */
	while((*(*line + i) ) == ' ')
		i++;
	hatoi = atoi(*line + i);
	i = i + digit_of_a_number(hatoi);
	mn->conf.c = hatoi << 16;
	if (*(*line + i) != ',')
		ft_error(4);
	i++;
	hatoi = atoi(*line + i);
	i = i + digit_of_a_number(hatoi);
	mn->conf.c = mn->conf.c + (hatoi << 8);
	if (*(*line + i) != ',')
		ft_error(4);
	i++;
	hatoi = atoi(*line + i);
	mn->conf.c = mn->conf.c + hatoi;
		printf("\n----0---0---c\n%d\n",mn->conf.c);
	return (0);
}
