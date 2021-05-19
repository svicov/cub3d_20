#include "cub3d.h"

int completion1(char **line, int i, t_mn *mn)   /*  парсер если встретился символы NO   */
{
	int k;

	i = i + 2;
	while(*(*line + i) == ' ')
		i++;	
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
		k++;
	mn->conf.no = malloc(k + 1);
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
	{		
		mn->conf.no[k] = *((*line) + i + k);
		k++;
	}
	mn->conf.no[k] = '\0';
	return (0);
}

int completion2(char **line, int i, t_mn *mn)  /* SO  */
{
	int k;

	i = i + 2;

	while(*(*line + i) == ' ')
		i++;
	
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
		k++;

	mn->conf.so = malloc(k + 1);
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
	{		
		mn->conf.so[k] = *((*line) + i + k);
		k++;
	}
	mn->conf.so[k] = '\0';
	return (0);
} 

int completion3(char **line, int i, t_mn *mn)   /* WE  */
{
	int k;

	i = i + 2;

	while(*(*line + i) == ' ')
		i++;
	
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
		k++;

	mn->conf.we = malloc(k + 1);
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
	{		
		mn->conf.we[k] = *((*line) + i + k);
		k++;
	}
	mn->conf.we[k] = '\0';
	return (0);
}

int completion4(char **line, int i, t_mn *mn)   /* WE  */
{
	int k;

	i = i + 2;

	while(*(*line + i) == ' ')
		i++;
	
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
		k++;

	mn->conf.ea = malloc(k + 1);
	k = 0;
	while( *(*line + i + k) != '\0' && *(*line + i + k) != ' ')
	{		
		mn->conf.ea[k] = *((*line) + i + k);
		k++;
	}
	mn->conf.ea[k] = '\0';
	return (0);
}
