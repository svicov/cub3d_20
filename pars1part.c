#include "cub3d.h"



int completion0(char **line, int i, t_mn *mn)   /*   :парсер если встретился символы R_ :    */
{
	int k;

	i = 2;
	while((*(*line + i) ) == ' ')
		i++;
	k = 0;
	while(ft_isdigit(*(*line + i + k)))
		k++;
	mn->conf.width = atoi( *line + i);
	if (mn->conf.width == 0)
	{
		printf("incorrect format error2\n");
		return (2);
	}
	i = i + k;	
	while((*(*line) + i ) == ' ')
		i++;	
	mn->conf.heigth = atoi (*line + i);
	if (mn->conf.heigth == 0)
	{
		printf("incorrect format error2\n");
		return (2);
	}	
	return (0);
}

int completion(char **line, int i, int j, t_mn *mn)
{	
	if (j == 0)
		completion0(line, i, mn);
	if (j == 1)
		completion1(line, i, mn);
	if (j == 2)
	 	completion2(line, i, mn);
	if (j == 3)
	 	completion3(line, i, mn);
	if (j == 4)
	 	completion4(line, i, mn);
	if (j == 5)
	 	completion5(line, i, mn);
	if (j == 6)
	 	completion6(line, i, mn);
	if (j == 7)
	 	completion7(line, i, mn);
	return (0);
}

int pars1(char **line, t_mn *mn)
{
	int i;
	const char p_tek[8][2] = {"R ", "NO", "SO", "WE", "EA", "S ", "F ", "C "};
	int j;

	init_zp(mn);
	i = 0;
	while((*line)[i] == ' ')
		i++;
	j = 0;
	while(j < 8)  
	{
		if(!(ft_strncmp(*(p_tek + j), ((*line) + i), 2)))
		{			
			if (mn->zp[j] == 1)
			{
				mn->zp[j] = 0;
				completion(line, i, j, mn);
			}
			else
				return (2);
		}
		j++;
	}
	return (0);
}