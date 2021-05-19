#include "cub3d.h"

void	ft_setup_sprites(t_info *info, t_sp *sp, t_mn *mn, int *spO)
{
	sp->X = mn->map_sp[spO[mn->num_sp]][0] - info->posX;
	sp->Y = mn->map_sp[spO[mn->num_sp]][1] - info->posY;
	sp->invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
	sp->tfX = sp->invDet * (info->dirY * sp->X - info->dirX * sp->Y);
	sp->tfY = sp->invDet * (-info->planeY * sp->X + info->planeX * sp->Y);
	sp->scrnX = (int)((mn->conf.width / 2) * (1 + sp->tfX / sp->tfY));
	sp->VMOVEScreen = (int)(VMOVE / sp->tfY);
	sp->h = (int)fabs((mn->conf.heigth / sp->tfY) / VDIV);
	sp->drawStartY = -sp->h / 2 + mn->conf.heigth / 2 + sp->VMOVEScreen;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = sp->h / 2 + mn->conf.heigth / 2 + sp->VMOVEScreen;
	if (sp->drawEndY >= mn->conf.heigth)
		sp->drawEndY = mn->conf.heigth - 1;
	sp->w = (int)fabs((mn->conf.heigth / sp->tfY) / UDIV);
	sp->drawStartX = -sp->w / 2 + sp->scrnX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = sp->w / 2 + sp->scrnX;
	if (sp->drawEndX >= mn->conf.width)
		sp->drawEndX = mn->conf.width - 1;
	sp->stripe = sp->drawStartX;
}