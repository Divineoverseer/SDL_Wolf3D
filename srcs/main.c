/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:01:22 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/12 21:01:24 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Wextra -Werror main.c ft_draw.c ft_draw_prep.c ft_events.c ft_pixel.c ../libft/libft.a -F ../frameworks -I ../frameworks/SDL2_image.framework/Versions/A/Headers -rpath ../frameworks -framework SDL2 -framework SDL2_image

#include "../includes/test.h"

void		ft_textures(t_sdl *sdl)
{
	sdl->ttr[0] = IMG_Load("../pics/eagle.png");
	sdl->ttr[1] = IMG_Load("../pics/redbrick.png");
	sdl->ttr[2] = IMG_Load("../pics/purplestone.png");
	sdl->ttr[3] = IMG_Load("../pics/greystone.png");
	sdl->ttr[4] = IMG_Load("../pics/bluestone.png");
	sdl->ttr[5] = IMG_Load("../pics/mossy.png");
	sdl->ttr[6] = IMG_Load("../pics/wood.png");
	sdl->ttr[7] = IMG_Load("../pics/colorstone.png");
	if (!sdl->ttr[0])
		write(1, "RIP\n", 1);
	return ;
}

void		ft_check_bounds(t_sdl *sdl)
{
	int		i[2];

	i[1] = -1;
	while (++i[1] < 24 && (i[0] = -1) != -2)
		while (++i[0] < 24)
		{
			if ((i[0] == 0 || i[0] == 23 || i[1] == 0 || i[1] == 23) &&
				sdl->wm[i[1]][i[0]] == 0)
				sdl->wm[i[1]][i[0]] = 2;
			if ((i[0] == 22 && i[1] == 22) || (i[0] == 21 && i[1] == 21) ||
				(i[0] == 21 && i[1] == 22) || (i[0] == 22 && i[1] == 21))
				sdl->wm[i[1]][i[0]] = 0;
		}
	return ;
}

void		ft_null_map(t_sdl *sdl)
{
	int		i[2];

	i[1] = -1;
	while (++i[1] < 24 && (i[0] = -1) != -2)
		while (++i[0] < 24)
			sdl->wm[i[1]][i[0]] = 0;
	return ;
}

void		ft_loadmap(int fd, t_sdl *sdl)
{
	int		i[3];
	char	**tab;
	char	*line;

	i[1] = -1;
	line = NULL;
	ft_null_map(sdl);
	while ((i[2] = get_next_line(fd, &line)) == 1)
	{
		if ((++i[1]) < 24 && (i[0] = -1) != -2)
		{
			tab = ft_strsplit(line, ' ');
			while (tab[++i[0]] && i[0] < MW)
				sdl->wm[i[1]][i[0]] = ft_atoi(tab[i[0]]);
			tab ? ft_freestrarr(tab) : 0;
		}
		line ? ft_strdel(&line) : 0;
	}
	line ? ft_strdel(&line) : 0;
	ft_check_bounds(sdl);
	i[1] = close(fd);
//	if (i[1] != 0 || i[2] != 0)
//		return (ft_retval("Map is missing.\n", i[1] != 0 ? i[1] : i[2]));
	return ;
}

void		ft_loadall(t_sdl *sdl)
{
	ft_loadmap(open(sdl->map, O_RDONLY), sdl);
	ft_textures(sdl);
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	sdl->win = SDL_CreateWindow(N, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	SDL_SetHintWithPriority(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1", SDL_HINT_OVERRIDE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	sdl->sur = SDL_GetWindowSurface(sdl->win);
	sdl->run = 1;
	sdl->dir[0] = BDX;
	sdl->dir[1] = BDY;
	sdl->pl[0] = BPLX;
	sdl->pl[1] = BPLY;
	sdl->pos[0] = 1.5;
	sdl->pos[1] = 1.5;
	return ;
}

int			main(int argc, char *argv[argc])
{
	t_sdl	sdl;

	sdl.map = argv[1];
	ft_loadall(&sdl);
	while (sdl.run)
	{
		while (SDL_PollEvent(&sdl.ev))
			if (ft_getev(&sdl) == 0)
				break ;
		ft_draw_prep(&sdl);
		SDL_UpdateWindowSurface(sdl.win);
	}
	SDL_DestroyWindow(sdl.win);
	SDL_Quit();
	IMG_Quit();
	return (0);
}
