/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:13 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/29 18:07:48 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*iter;

	iter = (unsigned char *)s;
	while (n--)
		if (*iter != (unsigned char)c)
			iter++;
		else
			return (iter);
	return (NULL);
}
