/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:08:49 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/13 00:08:51 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BDX -1
# define BDY 0
# define BPLX 0
# define BPLY 0.66
# define H 720
# define MH 24
# define MW 24
# define TH 64
# define TW 64
# define N "test"
# define W 1280


typedef	struct	s_sdl
{
	double		dir[2];
	double		ftime;
	double		movs;
	double		pl[2];
	double		pos[2];
	double		sn[2];
	char		*map;
	int			end;
	int			keys[300];
	int			rel[2];
	int			run;
	int			sln;
	int			x;
	int			xbuff;
	int			wm[MH][MW];
	time_t		oldt;
	time_t		newt;
	SDL_Event	ev;
	SDL_Surface	*sur;
	SDL_Surface	*ttr[8];
	SDL_Window	*win;
	void		*mlx;
}				t_sdl;

typedef struct	s_site
{
	double		old;
	double		cam;
	double		pwd;
	double		ddist[2];
	double		fw[2];
	double		raydir[2];
	double		sidedist[2];
	double		vardist[3];
	int			col;
	int			draw[2];
	int			hit;
	int			lh;
	int			map[2];
	int			side;
	int			side2;
	int			step[2];
	int			x;
	int			y;
	t_sdl		*sdl;
}				t_site;

int				ft_draw_prep(t_sdl *sdl);
int				ft_getev(t_sdl *sdl);
int				ft_event(t_sdl *sdl);
unsigned int	ft_getpixel(SDL_Surface *sur, int x, int y);
void			ft_floor_texture(t_site *cd);
void			ft_wall_texture(t_site *cd);
void			ft_putpixel(SDL_Surface *sur, int x, int y, unsigned int pixel);

#endif
