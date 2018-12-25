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

unsigned int		ft_getpixel(SDL_Surface *sur, int x, int y)
{
	int				bpp;
	unsigned char	*p;

	bpp = sur->format->BytesPerPixel;
	p = (unsigned char *)sur->pixels + y * sur->pitch + x * bpp;
	if (bpp == 4)
		return (*(unsigned int *)p);
	else if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(unsigned short int *)p);
	else if (bpp == 3) 
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	return (0);
}

void				ft_putpixel(SDL_Surface *sur, int x, int y, unsigned int pixel)
{
	int				bpp;
	unsigned char	*p;

	bpp = sur->format->BytesPerPixel;
	p = (unsigned char *)sur->pixels + y * sur->pitch + x * bpp;
	if (bpp == 4)
		*(unsigned int *)p = pixel;
	else if (bpp == 1)
		*p = pixel;
	else if (bpp == 2)
		*(unsigned short int *)p = pixel;
	else if (bpp == 3)
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
