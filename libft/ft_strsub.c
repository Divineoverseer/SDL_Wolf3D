/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:28:24 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 02:21:56 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len != 0 && s[start])
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = '\0';
	return (res);
}
