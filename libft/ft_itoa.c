/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:58 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 02:26:00 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int			dnum;
	int			sign;
	char		*res;
	long int	conv;

	dnum = 0;
	conv = n;
	if ((sign = n) < 0)
		conv = -conv;
	if (!(res = ft_memalloc((size_t)(ft_countd(conv) + 2))))
		return (NULL);
	if (conv == 0)
		res[dnum++] = '0';
	while (conv != 0)
	{
		res[dnum++] = ((conv % 10) > 9) ? ((conv % 10) - 10)
			+ 'a' : (conv % 10) + '0';
		conv = conv / 10;
	}
	if (sign < 0)
		res[dnum++] = '-';
	res[dnum] = '\0';
	ft_revers(res, dnum);
	return (res);
}
