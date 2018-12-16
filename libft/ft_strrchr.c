/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:24:33 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/22 17:21:56 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*result;

	result = (char *)0;
	while ((ch = *s))
	{
		if (ch == c)
			result = (char *)s;
		s++;
	}
	if (c == 0)
		result = (char *)s;
	return (result);
}
