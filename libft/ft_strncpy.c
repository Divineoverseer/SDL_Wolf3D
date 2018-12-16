/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:19:01 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 01:06:25 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	while (len > 0 && *src != '\0')
	{
		*s++ = *src++;
		--len;
	}
	while (len > 0 && *s)
	{
		*s++ = '\0';
		--len;
	}
	return (dst);
}
