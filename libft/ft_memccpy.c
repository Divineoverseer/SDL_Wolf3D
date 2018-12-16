/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:08:04 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/22 20:50:42 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n)
	{
		d = (unsigned char *)dst;
		s = (const unsigned char *)src;
		while (n--)
			if ((*d++ = *s++) == (unsigned char)c)
				return (d);
	}
	return (0);
}
