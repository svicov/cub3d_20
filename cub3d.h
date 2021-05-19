#ifndef CUB3D_H
#define CUB3D_H

#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TW 64
# define TH 64
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct s_conf
{
	int width;
	int heigth;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	int f;
	int c;
	int r;
	int n;

} t_conf;

typedef struct s_mn
{
	t_conf conf;
	char **map;
	int	num_s;
	int num_s0;
	int	maxlen;
	char **tmap;
	int zp[8];
	int cols;
	int rows;
	int max_cols;
	int max_rows;
	int	player; /* встретился игрок и сколько раз < 3 */
	int count_sp;
	int num_sp;
	double	**map_sp;
	
} t_mn;

typedef struct s_pair
{
	double	first;
	int		second;
}t_pair;

typedef struct s_sp
{
	double	X;
	double	Y;
	double	invDet;
	double	tfX;
	double	tfY;
	int		scrnX;
	int		VMOVEScreen;
	int		h;
	int		w;
	int		drawStartY;
	int		drawStartX;
	int		drawEndY;
	int		drawEndX;

	int		stripe;
	int		texY;
	int		color;
	int		texX;
}t_sp;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
}t_img;

typedef struct s_floor
{
	int		p;
	double	rayDirX0;
	double	rayDirY0;
	double	rayDirX1;
	double	rayDirY1;
	double	posZ;
	double	rowD;
	double	stepX;
	double	stepY;
	double	X;
	double	Y;
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	int		Texture;
	int		color;
}t_floor;

typedef struct s_wall
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	pWDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	int		color;
}t_wall;

typedef struct s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	int		key_l;
	int		key_r;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_esc;
	int		**buf;
	double	*zBuffer;
	int		**texture;
	double	mv;
	double	rt;
	int		save;
	t_sp	sp;
	t_img	img;
	// t_file	file;
	t_floor	fl;
	t_wall	wl;
}t_info;



int 	init_ab1(t_info *info);
int		ft_main_loop(t_info *info, t_mn *mn);
void	ft_floor_calculate(t_info *info, t_floor *fl, t_mn *mn);
void	ft_wall_calculate(t_info *info, t_wall *wl, t_mn *mn);
void	ft_setup_sprites(t_info *info, t_sp *sp, t_mn *mn, int *spO);
void	ft_sprite_position(t_mn *mn);
void	ft_paint_walls(t_info *info, t_wall *wl, int x);
void	ft_paint_sprite(t_info *q, t_sp *sp, t_mn *mn);
void	ft_draw(t_info *info, t_mn *mn);
void	ft_key_update(t_info *q, t_mn *mn);
void	ft_player_position(t_info *info, t_mn *mn, int i, int j);
int		ft_sprites(t_info *info, t_sp *sp, t_mn *mn, int *spO);
int		ft_key_release(int key, t_info *info);
int		ft_key_press(int key, t_info *info);



// Функций которые используется в гнл
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memmove(void *dst, const void *src, size_t n);
int					get_next_line(int fd, char **line);
int					pars1(char **line, t_mn *mn);
void				init_st_conf(t_conf *ddd);
void				init_zp(t_mn *pzp);
int					digit_of_a_number(int n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					completion0(char **line, int i, t_mn *mn);
int					completion(char **line, int i, int j, t_mn *mn);
int					completion1(char **line, int i, t_mn *mn);
int					completion1(char **line, int i, t_mn *mn);
int					completion2(char **line, int i, t_mn *mn);
int					completion3(char **line, int i, t_mn *mn);
int					completion4(char **line, int i, t_mn *mn);
int					completion5(char **line, int i, t_mn *mn);
int					completion6(char **line, int i, t_mn *mn);
int					completion7(char **line, int i, t_mn *mn);
int pars2(int fd, t_mn *mn);
int true_map(t_mn *mn);
void ft_maxlen(t_mn *mn, char **line);
void rtue_mat2(t_mn *mn);
int ft_error(int i);
int			valid_map(t_mn *mn);
int pl_s_above(t_mn *mn, int i, int j);
int		pl_s_below(t_mn *mn, int i, int j);
int		pl_s_right(t_mn *mn, int i, int j);
int pl_s_leftward(t_mn *mn, int i, int j);
int counting1(t_mn *mn);
int mall_sp(t_mn *mn);
int	position_sp(t_mn *mn);



#endif