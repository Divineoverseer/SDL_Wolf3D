/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 00:16:34 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/15 00:16:36 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void		ft_put_floor(t_site *cd)
{
	double	curfloor[2];
	double	weight;
	int		floortex[2];
	int		y;

	y = cd->draw[1];
	while (++y < H)
	{
		cd->vardist[2] = H / (2.0 * y - H);
		weight = (cd->vardist[2] - cd->vardist[1]) /
		(cd->vardist[0] - cd->vardist[1]);
		curfloor[0] = weight * cd->fw[0] + (1.0 - weight) * cd->sdl->pos[0];
		curfloor[1] = weight * cd->fw[1] + (1.0 - weight) * cd->sdl->pos[1];
		floortex[0] = (int)(curfloor[0] * 64) % 64;
		floortex[1] = (int)(curfloor[1] * 64) % 64;
		ft_putpixel(cd->sdl->sur, cd->x, (y - 1), ((ft_getpixel(cd->sdl->ttr[3], floortex[0], floortex[1]) >> 1) & 8355711));
		ft_putpixel(cd->sdl->sur, cd->x, (H - y), ft_getpixel(cd->sdl->ttr[6], floortex[0], floortex[1]));
	}
	return ;
}

void		ft_floor_texture(t_site *cd)
{
	if (cd->side == 0 && cd->raydir[0] > 0)
	{
		cd->fw[0] = cd->map[0];
		cd->fw[1] = cd->map[1] + cd->old;
	}
	else if (cd->side == 0 && cd->raydir[0] < 0)
	{
		cd->fw[0] = cd->map[0] + 1.0;
		cd->fw[1] = cd->map[1] + cd->old;
	}
	else if (cd->side == 1 && cd->raydir[1] > 0)
	{
		cd->fw[0] = cd->map[0] + cd->old;
		cd->fw[1] = cd->map[1];
	}
	else
	{
		cd->fw[0] = cd->map[0] + cd->old;
		cd->fw[1] = cd->map[1] + 1.0;
	}
	cd->vardist[0] = cd->pwd;
	cd->vardist[1] = 0.0;
	ft_put_floor(cd);
	return ;
}

void		ft_wall_texture(t_site *cd)
{
	int		d;
	int		tex[2];
	int		texnum;

	texnum = ((abs(cd->sdl->wm[cd->map[0]][cd->map[1]])) + cd->side2) % 8;
	cd->side == 0 ? (cd->old = cd->sdl->pos[1] + cd->pwd * cd->raydir[1]) :
	(cd->old = cd->sdl->pos[0] + cd->pwd * cd->raydir[0]);
	cd->old -= floor((cd->old));
	tex[0] = (int)(cd->old * (double)(TW));
	if (cd->side == 0 && cd->raydir[0] > 0)
		tex[0] = TW - tex[0];
	if (cd->side == 1 && cd->raydir[1] < 0)
		tex[0] = TW - tex[0];
	cd->y = cd->draw[0] - 0.1;
	while (++cd->y < cd->draw[1])
	{
		d = cd->y * 256 - H * 128 + cd->lh * 128;
		tex[1] = ((d * TH) / cd->lh) / 256;
		cd->col = ft_getpixel(cd->sdl->ttr[texnum], tex[0], tex[1]);
		if ((cd->side2 % 2) == 0)
			cd->col = (cd->col >> 1) & 8355711;
		ft_putpixel(cd->sdl->sur, cd->x, cd->y, cd->col);
	}
	return ;
}
