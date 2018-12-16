/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:10:40 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/20 17:34:47 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	nlen;

	b = (char *)needle;
	if (*b == 0)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (*haystack != 0 && len > 0)
	{
		if (nlen > len)
			return ((char *)0);
		if (*haystack == *b)
		{
			a = (char *)haystack;
			if (ft_strncmp(a, b, nlen) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return ((char *)0);
}
