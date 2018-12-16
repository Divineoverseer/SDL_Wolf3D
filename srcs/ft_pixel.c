/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:24:04 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/12/14 20:24:06 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void				ft_putpixel(t_sdl *sdl, int x, int y, unsigned int pixel)
{
	unsigned char	*p;

	p = (unsigned char *)sdl->sur->pixels + y * sdl->sur->pitch + x * sdl->bpp;
	if (sdl->bpp == 4)
		*(unsigned int *)p = pixel;
	else if (sdl->bpp == 1)
		*p = pixel;
	else if (sdl->bpp == 2)
		*(unsigned short int *)p = pixel;
	else if (sdl->bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
	return ;
}
