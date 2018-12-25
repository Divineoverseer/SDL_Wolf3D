/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 23:02:20 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/14 23:02:21 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void			ft_construct(t_site *cd)
{
	cd->lh = (H / cd->pwd);
	cd->draw[0] = -cd->lh / 2 + H / 2;
	if (cd->draw[0] < 0)
		cd->draw[0] = 0;
	cd->draw[1] = cd->lh / 2 + H / 2;
	if (cd->draw[1] >= H)
		cd->draw[1] = H - 1;
	ft_wall_texture(cd);
	ft_floor_texture(cd);
	return ;
}

void			ft_hit(t_site *cd)
{
	while (cd->hit == 0)
	{
		if (cd->sidedist[0] < cd->sidedist[1])
		{
			cd->side = 0;
			(1 / cd->raydir[0]) > 0 ? (cd->side2 = 1) :
			(cd->side2 = 0);
			cd->sidedist[0] += cd->ddist[0];
			cd->map[0] += cd->step[0];
		}
		else if (cd->sidedist[0] >= cd->sidedist[1])
		{
			cd->side = 1;
			(1 / cd->raydir[1]) > 0 ? (cd->side2 = 3) :
			(cd->side2 = 2);
			cd->sidedist[1] += cd->ddist[1];
			cd->map[1] += cd->step[1];
		}
		cd->sdl->wm[cd->map[0]][cd->map[1]] != 0 ? (cd->hit = 1) : 0;
	}
	return ;
}

void			ft_raydir(t_site *cd)
{
	if (cd->raydir[0] < 0 && (cd->step[0] = -1) != 0)
		cd->sidedist[0] = (cd->sdl->pos[0] - cd->map[0]) * cd->ddist[0];
	else if (cd->raydir >= 0 && (cd->step[0] = 1) != 0)
		cd->sidedist[0] = (cd->map[0] + 1.0 - cd->sdl->pos[0]) * cd->ddist[0];
	if (cd->raydir[1] < 0 && (cd->step[1] = -1) != 0)
		cd->sidedist[1] = (cd->sdl->pos[1] - cd->map[1]) * cd->ddist[1];
	else if (cd->raydir[1] >= 0 && (cd->step[1] = 1) != 0)
		cd->sidedist[1] = (cd->map[1] + 1.0 - cd->sdl->pos[1]) * cd->ddist[1];
	return ;
}

void			ft_screen_site(t_site *cd)
{
	while (++cd->x < W)
	{
		cd->cam = 2 * cd->x / (double)W - 1;
		cd->raydir[0] = cd->sdl->dir[0] + cd->sdl->pl[0] * cd->cam;
		cd->raydir[1] = cd->sdl->dir[1] + cd->sdl->pl[1] * cd->cam;
		cd->map[0] = (int)cd->sdl->pos[0];
		cd->map[1] = (int)cd->sdl->pos[1];
		cd->ddist[0] = fabs(1 / cd->raydir[0]);
		cd->ddist[1] = fabs(1 / cd->raydir[1]);
		cd->hit = 0;
		ft_raydir(cd);
		ft_hit(cd);
		cd->side == 0 ? (cd->pwd = (cd->map[0] - cd->sdl->pos[0] +
			(1 - cd->step[0]) / 2) / cd->raydir[0]) : (cd->pwd =
		(cd->map[1] - cd->sdl->pos[1] + (1 - cd->step[1]) / 2) / cd->raydir[1]);
		ft_construct(cd);
	}
	return ;
}

int				ft_draw_prep(t_sdl *sdl)
{
	t_site		cd;

	cd.x = -1;
	cd.sdl = sdl;
	ft_event(sdl);
	ft_screen_site(&cd);
	sdl->oldt = sdl->newt;
	sdl->newt = clock();
	sdl->ftime = (double)(sdl->newt - sdl->oldt) / CLOCKS_PER_SEC;
	(sdl->keys[32] == 1 && sdl->keys[97] == 0 && sdl->keys[115] == 0 &&
		sdl->keys[100] == 0) ? (sdl->movs = sdl->ftime * 7.0) :
	((sdl->keys[97] == 1 && (sdl->keys[115] == 1 || sdl->keys[119] == 1)) ||
		(sdl->keys[100] == 1 && (sdl->keys[115] == 1 || sdl->keys[119] == 1))) ?
	(sdl->movs = sdl->ftime * 3.0) : (sdl->movs = sdl->ftime * 4.0);
	return (0);
}
