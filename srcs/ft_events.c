/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:23:05 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/14 20:23:06 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void			ft_event3(t_sdl *sdl)
{
	sdl->dir[0] = BDX * sin(((sdl->xbuff * M_PI) / 900)) - BDY * cos(((sdl->xbuff * M_PI) / 900));
	sdl->dir[1] = BDX * cos(((sdl->xbuff * M_PI) / 900)) + BDY * sin(((sdl->xbuff * M_PI) / 900));
	sdl->pl[0] = BPLX * sin(((sdl->xbuff * M_PI) / 900)) - BPLY * cos(((sdl->xbuff * M_PI) / 900));
	sdl->pl[1] = BPLX * cos(((sdl->xbuff * M_PI) / 900)) + BPLY * sin(((sdl->xbuff * M_PI) / 900));
}

void			ft_event2(t_sdl *sdl)
{
	if (sdl->keys[97] == 1)
	{
		sdl->wm[(int)(sdl->pos[0] - ((sdl->dir[1] * sdl->movs) + sdl->sn[1]))][(int)sdl->pos[1]] == 0 ?
			(sdl->pos[0] -= sdl->dir[1] * sdl->movs) :
			(sdl->pos[0] += round(sdl->pos[0]) - sdl->pos[0] + sdl->sn[1]);
		sdl->wm[(int)sdl->pos[0]][(int)(sdl->pos[1] + ((sdl->dir[0] * sdl->movs) + sdl->sn[0]))] == 0 ?
			(sdl->pos[1] += sdl->dir[0] * sdl->movs) :
			(sdl->pos[1] += round(sdl->pos[1]) - sdl->pos[1] - sdl->sn[0]);
	}
	if (sdl->keys[100] == 1)
	{
		sdl->wm[(int)(sdl->pos[0] + ((sdl->dir[1] * sdl->movs) + sdl->sn[1]))][(int)sdl->pos[1]] == 0 ?
		(sdl->pos[0] += sdl->dir[1] * sdl->movs) :
		(sdl->pos[0] += round(sdl->pos[0]) - sdl->pos[0] - sdl->sn[1]);
		sdl->wm[(int)sdl->pos[0]][(int)(sdl->pos[1] - ((sdl->dir[0] * sdl->movs) + sdl->sn[0]))] == 0 ?
		(sdl->pos[1] -= sdl->dir[0] * sdl->movs) :
		(sdl->pos[1] += round(sdl->pos[1]) - sdl->pos[1] + sdl->sn[0]);
	}
	ft_event3(sdl);
	return ;
}

int				ft_event(t_sdl *sdl)
{
	sdl->dir[0] >= 0 ? (sdl->sn[0] = 0.04) : (sdl->sn[0] = -0.04);
	sdl->dir[1] >= 0 ? (sdl->sn[1] = 0.04) : (sdl->sn[1] = -0.04);
	if (sdl->keys[115] == 1)
	{
		sdl->wm[(int)(sdl->pos[0] - ((sdl->dir[0] * sdl->movs) + sdl->sn[0]))][(int)sdl->pos[1]] == 0 ?
		(sdl->pos[0] -= sdl->dir[0] * sdl->movs) :
		(sdl->pos[0] += round(sdl->pos[0]) - sdl->pos[0] + sdl->sn[0]);
		sdl->wm[(int)sdl->pos[0]][(int)(sdl->pos[1] - ((sdl->dir[1] * sdl->movs) + sdl->sn[1]))] == 0 ?
		(sdl->pos[1] -= sdl->dir[1] * sdl->movs) :
		(sdl->pos[1] += round(sdl->pos[1]) - sdl->pos[1] + sdl->sn[1]);
	}
	if (sdl->keys[119] == 1)
	{
		sdl->wm[(int)(sdl->pos[0] + ((sdl->dir[0] * sdl->movs) + sdl->sn[0]))][(int)sdl->pos[1]] == 0 ?
		(sdl->pos[0] += sdl->dir[0] * sdl->movs) :
		(sdl->pos[0] += round(sdl->pos[0]) - sdl->pos[0] - sdl->sn[0]);
		sdl->wm[(int)sdl->pos[0]][(int)(sdl->pos[1] + ((sdl->dir[1] * sdl->movs) + sdl->sn[1]))] == 0 ?
		(sdl->pos[1] += sdl->dir[1] * sdl->movs) :
		(sdl->pos[1] += round(sdl->pos[1]) - sdl->pos[1] - sdl->sn[1]);
	}
	ft_event2(sdl);
	return (0);
}

int				ft_getev(t_sdl *sdl)
{
	if (sdl->ev.type == SDL_KEYDOWN && sdl->ev.key.repeat == 0)
		sdl->ev.key.keysym.sym < 300 ? sdl->keys[sdl->ev.key.keysym.sym] = 1 : 0;
	else if (sdl->ev.type == SDL_KEYUP)
		sdl->ev.key.keysym.sym < 300 ? sdl->keys[sdl->ev.key.keysym.sym] = 0 : 0;
	else if (sdl->ev.type == SDL_MOUSEMOTION)
		sdl->xbuff += sdl->ev.motion.xrel;
	else if (sdl->ev.type == SDL_QUIT)
		sdl->run = 0;
	return (sdl->run);
}
