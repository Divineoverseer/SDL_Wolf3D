/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:46:22 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/26 18:38:59 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*res;
	size_t		ressize;
	const char	*end;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	end = s + ft_strlen(s) - 1;
	while (end > s && (*end == ' ' || *end == '\n' || *end == '\t'))
		end--;
	end++;
	ressize = (end - s);
	if (!(res = (char *)malloc(sizeof(char) * (ressize + 1))))
		return (NULL);
	ft_memcpy(res, s, (ressize + 1));
	res[ressize] = '\0';
	return (res);
}
