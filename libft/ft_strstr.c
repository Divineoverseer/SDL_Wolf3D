/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:08:35 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/20 17:40:10 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*a;
	char	*b;

	b = (char *)needle;
	if (*b == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *b)
		{
			a = (char *)haystack;
			if (ft_strncmp(a, b, ft_strlen(b)) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return ((char *)0);
}
